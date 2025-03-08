# taken form https://github.com/YosysHQ/picorv32/blob/main/Makefile
PYTHON = python3
RISCV_GNU_TOOLCHAIN_INSTALL_PREFIX = /opt/riscv32
TOOLCHAIN_PREFIX = $(RISCV_GNU_TOOLCHAIN_INSTALL_PREFIX)i/bin/riscv32-unknown-elf-
GCC_WARNS  = -Werror -Wall -Wextra -Wshadow -Wundef -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings
GCC_WARNS += -Wredundant-decls -Wstrict-prototypes -Wmissing-prototypes -pedantic # -Wconversion
FIRMWARE_OBJS = firmware/start.o firmware/print.o
ABI = ilp32
ARCH = rv32i
MAX_LENGTH = 32768

PICORV32_PATH = ../../picorv32

# firmware to run pico

firmware/firmware.elf: $(FIRMWARE_OBJS) $(TEST_OBJS) firmware/sections.lds main.o
	$(TOOLCHAIN_PREFIX)gcc -Os -mabi=ilp32 -march=rv32i -ffreestanding -nostdlib -falign-functions=4 -o $@ \
		-Wl,--build-id=none,-Bstatic,-T,firmware/sections.lds,-Map,firmware/firmware.map \
		$(FIRMWARE_OBJS) main.o -lgcc
	chmod -x $@

firmware/firmware.hex: firmware/firmware.bin firmware/makehex.py
	$(PYTHON) firmware/makehex.py $< $(MAX_LENGTH) > $@

#firmware/firmware.hex: firmware/firmware.elf
#	$(TOOLCHAIN_PREFIX)objcopy -O verilog $^ $@

firmware/firmware.bin: firmware/firmware.elf
	$(TOOLCHAIN_PREFIX)objcopy -O binary $< $@
	chmod -x $@

firmware/start.o: firmware/start.S
	$(TOOLCHAIN_PREFIX)gcc -c -mabi=$(ABI) -march=$(ARCH) -o $@ $<

firmware/%.o: firmware/%.c
	$(TOOLCHAIN_PREFIX)gcc -c -mabi=$(ABI) -march=$(ARCH) -Os --std=c99 $(GCC_WARNS) -ffreestanding -nostdlib -o $@ $<

firmware/elf_dump.txt: firmware/firmware.elf
	$(TOOLCHAIN_PREFIX)objdump -S $^ > $@

firmware/symbols_dump.txt: firmware/firmware.elf
	$(TOOLCHAIN_PREFIX)objdump -t $^ > $@

# main program
main.o: bubble_sort.c
	$(TOOLCHAIN_PREFIX)gcc -c -mabi=$(ABI) -march=$(ARCH) -o $@ $<

clean:
	rm -f firmware/*.o tests/*.o *.o firmware/*.bin firmware/*.bin firmware/*.map firmware/*.hex firmware/*.elf main.o firmware/*.txt
