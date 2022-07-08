#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int lv = 0xfedcba98 << 32;
    int av = 0xfedcba98 >> 36;
    unsigned uv = 0xfedcba98 >> 40;
    printf("%x\n", lv);
    printf("%x\n", av);
    printf("%x\n", uv);
    printf("expected1: %x\n", 0xfedcba98);
    printf("expected2: %x", 0x00fedcba);
}