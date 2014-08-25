/*
 * TM4C123xE6 memory setup.
 */
MEMORY
{
  flash : org = 0x00000000, len = 128k
  ram : org = 0x20000000, len = 32k
}

INCLUDE rules.ld
