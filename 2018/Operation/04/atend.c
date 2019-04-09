#include <stdio.h>

void bin(unsigned n) 
{ 
    unsigned i; 
    for (i = 1 << 8; i > 0; i = i / 2) 
        (n & i)? printf("1"): printf("0"); 
} 

void print_decimal(unsigned long v){
    printf("%d\n",v);
}
void print_hexadecimal(unsigned long v){
     printf("%x\n",v);
}
void print_binary(unsigned long v){
    bin(v);
}

int main(int argc, char const *argv[])
{
    /* code */
    print_decimal(129);
    // Shows `129` to stdout
    print_hexadecimal(129);
    // Shows `0x00000081` to stdout
    print_binary(129);
    // Shows `0b10000001` to stdout
    return 0;
}
