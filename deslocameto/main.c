#include <stdio.h>
#include <stdlib.h>

void exibirBits(unsigned value);
unsigned retornaBits(unsigned value, int qtdBits);
unsigned inserirBits(unsigned value, unsigned bits);

int main()
{
    int i;
    unsigned z;
    char host[]="abcd";

    for(i=0; i<4; i++) {
        exibirBits(host[i]);
    }

    z=retornaBits('i',2);

    printf("Bits modificados\n");

    for(i=0; i<4; i++) {
        host[i]=inserirBits(host[i],z);
        exibirBits(host[i]);
    }

    return 0;
}

unsigned retornaBits(unsigned value, int qtdBits) {
    int c;
    unsigned t=0;
    unsigned mask = 1;
    for(c= 0; c<=qtdBits-1; c++) {
        if(value & mask) {
            t=t+(1<<c);
        }
        mask<<=1;
        //exibirBits(t);
    }
    return t;
}

unsigned inserirBits(unsigned value, unsigned bits) {
    value>>=2;
    value<<=2;
    value = value+bits;
    return value;
}

void exibirBits(unsigned value) {
    unsigned c;
    unsigned exibirMask = 1 << 7;
    printf("%10u =", value);
    for(c= 1; c<=8; c++) {
        putchar(value & exibirMask ? '1': '0');
        value <<=1;
        if(c%4 == 0)
            putchar(' ');
    }
    putchar('\n');
}
