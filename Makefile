BUILD_TYPE = Debug
BUILD_DIR = build/$(BUILD_TYPE)
EXECUTABLE = build/$(BUILD_TYPE)/scilla.elf

OPENOCD = openocd
OPENOCD_COMMON_FLAGS = -f interface/stlink.cfg -f target/stm32g4x.cfg

CMAKE = cmake
CMAKE_DEFINES = -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)
CMAKE_BUILD_JOBS = 4

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
