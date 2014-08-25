/*
 * TM4C123xD5 memory setup.
 */
MEMORY
{
  flash : org = 0x00000000, len = 64k
  ram : org = 0x20000000, len = 24k
}

INCLUDE rules.ld
