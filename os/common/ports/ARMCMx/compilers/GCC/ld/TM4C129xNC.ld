/*
 * TM4C123xH6 memory setup.
 */
MEMORY
{
  flash : org = 0x00000000, len = 1024k
  ram : org = 0x20000000, len = 256k
}

INCLUDE rules.ld
