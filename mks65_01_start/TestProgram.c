#include<stdio.h>

double avg (double n1, double n2, double n3) {
    return (n1+n2+n3) / 3;
}

int main() {
    double n1 = 15, n2 = 20, n3 = 40;

    printf("Average is : %f\n", avg(n1,n2,n3));

    unsigned int a = 4294967295, b=-5;
    printf("Unsigned Int is %u\n", a+1);
    printf("Unsigned Int is %u\n", b);

    char c = 'a';
    printf("Char is %c\n", c+43);

    return 0;

}
