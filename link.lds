SECTIONS
{

  . = 0x80300000;

  __start_copy = .;

  __start_code = .;
  .text : { *(.text) }
  __end_code = .;

  __start_data = .;
  .rodata : { *(.rodata) }
  .data :   { *(.data) }
  __end_data = .;

  __end_copy = .;

  __start_bss = .;
  .bss : { *(.bss) }
  __end_bss = .;

}
