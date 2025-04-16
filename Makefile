OPENOCD = openocd
EXECUTABLE = build/platforms/platform-prefix/src/platform-build/nucleo-g431kb.elf

openocd_server:
	$(OPENOCD) -f interface/stlink.cfg -f target/stm32g4x.cfg

flash:
	$(OPENOCD) -f interface/stlink.cfg -f target/stm32g4x.cfg \
		-c "program $(EXECUTABLE) verify reset exit"
