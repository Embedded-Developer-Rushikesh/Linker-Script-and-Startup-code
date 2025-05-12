ENTRY(Reset_Handler)

_estack = ORIGIN(SRAM) + LENGTH(SRAM);

_Min_Heap_Size = 0x200; 
_Min_Stack_Size = 0x400;
MEMORY
{
	FLASH(rx): ORIGIN =0x8000000,LENGTH =512K
	SRAM(rwx): ORIGIN =0x20000000,LENGTH =128K
}

SECTIONS
{
	.isr_vector :
	{
		. = ALIGN(4);
		KEEP(*(.isr_vector)) 
		. = ALIGN(4);
	} >FLASH
	.text :
	{
		. = ALIGN(4);
		*(.text)
		*(.text*) 
		*(.rodata)
		. = ALIGN(4);
		_etext = .;
	}>FLASH
	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)         /* .rodata sections (constants, strings, etc.) */
		*(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
		. = ALIGN(4);
	} >FLASH
	  _sidata = LOADADDR(.data);
	.data :
	{
	    . = ALIGN(4);
		_sdata = .;
		*(.data)
		*(.data*)
		. = ALIGN(4);
		_edata = .;
	}>SRAM AT> FLASH
	
	.bss :
	{
		. = ALIGN(4);
		_sbss = .;
		__bss_start__ = _sbss;
		*(.bss)
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;         /* define a global symbol at bss end */
		__bss_end__ = _ebss;
	}>SRAM 
	
/* User_heap_stack section, used to check that there is enough "RAM" Ram  type memory left */
  ._user_heap_stack :
	{
		. = ALIGN(8);
		PROVIDE ( end = . );
		PROVIDE ( _end = . );
		. = . + _Min_Heap_Size;
		. = . + _Min_Stack_Size;
		. = ALIGN(8);
	} >SRAM
}