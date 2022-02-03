#include <stdio.h>

int main() {
    // #1 Declaration / Initialization
    char c = 'a';
    int i = 2;
    long l = 3;

    // #2 Addresses in Hex / Decimal
    printf("Char: %p\t Int: %p\t Long: %p\t\n", &c, &i, &l);
    printf("Char: %lu\t Int: %lu\t Long: %lu\t\n\n", &c, &i, &l);

    // #3 Declaration/Initialization of Pointers
    char *cp = &c;
    int *ip = &i;
    long *lp = &l;

    // #4 Values of Pointers
    printf("Char: %p\t Int: %p\t Long: %p\t\n\n", cp, ip, lp);

    // #5 Update variables with pointers
    *cp='b';
    *ip=12312312;
    *lp=29034820;
    printf("Char: %c\t Int: %d\t Long: %ld\t\n\n", c, i, l);

    // #6 Unsigned int and char/int pointers
    unsigned int ui = 21930822;
    int *ip2 = &ui;
    char *cp2 = &ui;

    // #7 Value of Pointer + Dereferenced Pointer
    printf("ip2: %p ip2 points to: %u\n", ip2, *ip2);
    printf("cp2: %p cp2 points to: %c\n\n", cp2, *cp2);

    // #8 Unsigned Int in Decimal/Hex
    printf("Unsigned int in hexadecimal: %x\n", ui);
    printf("Unsigned int in decimal: %u\n\n", ui);

    // #9 Individual Bytes of unsigned int
    printf("Bytes in hexadecimal: %hhx %hhx %hhx %hhx\n", *cp2, *(cp2+1), *(cp2+2), *(cp2+3));
    printf("Bytes in decimal: %hhu %hhu %hhu %hhu\n\n", *cp2, *(cp2+1), *(cp2+2), *(cp2+3));

    // #10 Incrementing Each Byte
    (*cp2)++; printf("Hexadecimal: %x\t Decimal: %u\n", ui, ui);
    (*(cp2+1))++; printf("Hexadecimal: %x\t Decimal: %u\n", ui, ui);
    (*(cp2+2))++; printf("Hexadecimal: %x\t Decimal: %u\n", ui, ui);
    (*(cp2+3))++; printf("Hexadecimal: %x\t Decimal: %u\n", ui, ui);
    printf("Bytes in hexadecimal: %hhx %hhx %hhx %hhx\n", *cp2, *(cp2+1), *(cp2+2), *(cp2+3));
    printf("Bytes of decimal: %hhu %hhu %hhu %hhu\n\n", *cp2, *(cp2+1), *(cp2+2), *(cp2+3));

    // #11 Incrementing Each Byte by 16
    (*cp2)+=16; printf("Hexadecimal: %x\t Decimal: %u\n", ui, ui);
    (*(cp2+1))+=16; printf("Hexadecimal: %x\t Decimal: %u\n", ui, ui);
    (*(cp2+2))+=16; printf("Hexadecimal: %x\t Decimal: %u\n", ui, ui);
    (*(cp2+3))+=16; printf("Hexadecimal: %x\t Decimal: %u\n", ui, ui);
    printf("Bytes in hexadecimal: %hhx %hhx %hhx %hhx\n", *cp2, *(cp2+1), *(cp2+2), *(cp2+3));
    printf("Bytes of decimal: %hhu %hhu %hhu %hhu\n\n", *cp2, *(cp2+1), *(cp2+2), *(cp2+3));

    return 0;
}
