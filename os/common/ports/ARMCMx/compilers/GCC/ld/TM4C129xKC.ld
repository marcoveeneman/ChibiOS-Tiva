/*
 * TM4C129xKC memory setup.
 */
MEMORY
{
  flash : org = 0x00000000, len = 512k
  ram : org = 0x20000000, len = 256k
}

INCLUDE rules.ld
