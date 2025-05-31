BUILD_TYPE = Debug
SRC_DIR = Logic
BUILD_DIR = build/$(BUILD_TYPE)
EXECUTABLE = build/$(BUILD_TYPE)/scilla.elf

OPENOCD = openocd
OPENOCD_COMMON_FLAGS = -f interface/stlink.cfg -f target/stm32g4x.cfg

CMAKE = cmake
CMAKE_DEFINES = -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)
CMAKE_BUILD_JOBS = 4

TRICE = trice
TRICE_PORT = /dev/ttyACM0
TRICE_BAUD = 115200

.PHONY: build
build:
	$(CMAKE) $(CMAKE_DEFINES) -S . -B $(BUILD_DIR)
	$(CMAKE) --build $(BUILD_DIR) -j $(CMAKE_BUILD_JOBS)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: openocd_launch
openocd_launch:
	$(OPENOCD) $(OPENOCD_COMMON_FLAGS)

.PHONY: flash
flash:
	$(OPENOCD) $(OPENOCD_COMMON_FLAGS) -c "program $(EXECUTABLE) verify reset exit"

.PHONY: trice_insert
trice_insert:
	$(TRICE) insert -src $(SRC_DIR)/

.PHONY: trice_launch
trice_launch:
	$(TRICE) log -p $(TRICE_PORT) -baud $(TRICE_BAUD) -prefix none -liFmt none
