BASENAME := banjo

BUILD_DIR = build
REGION   := us
VERSION  := v10


ASM_DIRS  = asm
BIN_DIRS  = bin
SRC_DIRS  = src

S_FILES   = $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
C_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
H_FILES   = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.h))
BIN_FILES = $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))

O_FILES := $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
           $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(file:.bin=.o))

TARGET = $(BUILD_DIR)/$(BASENAME).$(REGION)
LD_SCRIPT = $(BASENAME).ld

CROSS = mips-linux-gnu-
AS = $(CROSS)as
CPP = cpp
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
PYTHON = python3
N64SPLAT = $(PYTHON) tools/n64splat/split.py

OPT_FLAGS := -O2 -g3
MIPSBIT := -mips2 -o32

INCLUDE_CFLAGS := -I . -I include -I include/2.0L -I include/2.0L/PR -I include/libc -I src/libultra/os -I src/libultra/audio

ASFLAGS = -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include

CFLAGS := -G 0 -Xfullwarn -Xcpluscomm -signed -g -nostdinc -non_shared -Wab,-r4300_mul
CFLAGS += -D_LANGUAGE_C -D_FINALROM -DF3DEX_GBI
CFLAGS += $(INCLUDE_CFLAGS)

LDFLAGS = -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(TARGET).map -T undefined_syms.$(REGION).$(VERSION).txt -T undefined_syms_auto.txt -T undefined_funcs_auto.txt  --no-check-sections

### Targets

default: all

all: dirs $(TARGET).z64 verify

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS) ,$(shell mkdir -p build/$(dir)))

clean:
	rm -rf asm
	rm -rf bin
	rm -rf build
	cd code 1 && make clean
	cd code 2 && make clean

extract: bin/bk_core1_code.$(REGION).$(VERSION).rzip.bin

decompress: core1/core1.$(REGION).$(VERSION).bin core2/core2.$(REGION).$(VERSION).bin

verify: $(TARGET).z64
	@echo "$$(cat $(BASENAME).$(REGION).$(VERSION).sha1)  $(TARGET).z64" | sha1sum --check

### Recipes

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	$(CPP) -P -DBUILD_DIR=$(BUILD_DIR) -o $@ $<

$(TARGET).elf: $(O_FILES) $(BUILD_DIR)/$(LD_SCRIPT)
	@$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $(OPT_FLAGS) $(MIPSBIT) -o $@ $<

$(BUILD_DIR)/%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) -O binary $< $@

$(TARGET).z64: $(TARGET).bin
	@cp $< $@

core1/core1.$(REGION).$(VERSION).bin: bin/bk_core1_code.$(REGION).$(VERSION).bin bin/bk_core1_data.$(REGION).$(VERSION).bin
	cat $^ > $@

core2/core2.$(REGION).$(VERSION).bin: bin/bk_core2_code.$(REGION).$(VERSION).bin bin/bk_core2_data.$(REGION).$(VERSION).bin
	cat $^ > $@

# decompress
bin/%.bin: bin/%.rzip.bin
	$(PYTHON) tools/rareunzip.py $< $@

# extract
bin/bk_core1_code.$(REGION).$(VERSION).rzip.bin: $(BASENAME).$(REGION).$(VERSION).yaml
	$(N64SPLAT) baserom.$(REGION).$(VERSION).z64 $(BASENAME).$(REGION).$(VERSION).yaml .
	make decompress
	cd code1 && make extract
	cd code2 && make extract

# settings
.PHONY: all clean default
SHELL = /bin/bash -e -o pipefail
