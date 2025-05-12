cc=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall  -O0
LDFLAGS= -nostdlib -T stm32_ls.ld -Wl,-Map=final.map

all: gpio_intrupt.o stm32f446xx_gpio_driver.o stm32f446xx_SysTick_driver.o stm32_startup.o final.elf

gpio_intrupt.o:gpio_intrupt.c
	$(cc) $(CFLAGS) -o $@ $^
	
stm32f446xx_gpio_driver.o:stm32f446xx_gpio_driver.c
	$(cc) $(CFLAGS) -o $@ $^
	
stm32f446xx_SysTick_driver.o:stm32f446xx_SysTick_driver.c
	$(cc) $(CFLAGS) -o $@ $^
	
stm32_startup.o:stm32_startup.c
	$(cc) $(CFLAGS) -o $@ $^

final.elf:gpio_intrupt.o stm32f446xx_gpio_driver.o stm32f446xx_SysTick_driver.o stm32_startup.o
	$(cc) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf

load:
	openocd -f board/st_nucleo_f4.cfg
