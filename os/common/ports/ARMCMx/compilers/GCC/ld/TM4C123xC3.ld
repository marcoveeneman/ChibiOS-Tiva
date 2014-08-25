/*
 * TM4C123xC3 memory setup.
 */
MEMORY
{
  flash : org = 0x00000000, len = 32k
  ram : org = 0x20000000, len = 12k
}

INCLUDE rules.ld
