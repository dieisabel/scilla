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
	@echo "Start generating build files"
	$(CMAKE) $(CMAKE_DEFINES) -S . -B $(BUILD_DIR)
	@echo "Start building"
	$(CMAKE) --build $(BUILD_DIR) -j $(CMAKE_BUILD_JOBS)

.PHONY: clean
clean:
	@echo "Cleaning"
	rm -rf $(BUILD_DIR)/*

.PHONY: openocd_server
openocd_server:
	@echo "Start running OpenOCD server"
	$(OPENOCD) $(OPENOCD_COMMON_FLAGS)

.PHONY: flash
flash:
	@echo "Start flashing"
	$(OPENOCD) $(OPENOCD_COMMON_FLAGS) -c "program $(EXECUTABLE) verify reset exit"

.PHONY: run_trice
insert_trice_ids:
	@echo "Start running trice"
	$(TRICE) insert -src $(SRC_DIR)/

.PHONY: launch_logger
launch_logger:
	@echo "Launching logger"
	$(TRICE) log -p $(TRICE_PORT) -baud $(TRICE_BAUD)
