#include <stdio.h>

void naglowek(char jeden, char zero)
{
    for (int i = 7; i >= 0; i--)
    {
        if (i & 4)
            printf("%c", jeden);
        else
            printf("%c", zero);
        if (i & 2)
            printf("%c", jeden);
        else
            printf("%c", zero);
        if (i & 1)
            printf("%c  ", jeden);
        else
            printf("%c  ", zero);
    }
    printf("\n ");
}
//0 4 2 6 1 5 3 7
unsigned short odbicie(unsigned short n)
{
    int t[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 7; i >= 0; i--)
    {
        if (n & 1)
            t[i] = 1;
        else
            t[i] = 0;
        n >>= 1;
    }
    int odb[8];
    for(int i = 7; i >= 0; i--)
        odb[7-i] = t[i];
    int tab[8] = {1, 16, 4, 64, 2, 32, 8, 128};
    unsigned short o = 0;
    for (int i = 0; i < 8; i++)
    {
        if(odb[i] & 1)
            o |= tab[i];
    }
    return o;
}

unsigned short negatyw(unsigned short n)
{
    unsigned short neg = 0;
    unsigned short y = 128;
    for (int i = 0; i < 8; i++)
    {
        if (n & 1)
            neg = neg;
        else
            neg |= y;
        y >>= 1;
        n >>= 1;
    }
    return neg;
}

int main()
{
    unsigned short n;
    scanf("%hu", &n);
    n = (n << 8) >> 8;
    unsigned short m = n;
    char t[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    char jeden = '.';
    char zero = '#';
    naglowek(jeden, zero);
    for (int i = 7; i >= 0; i--)
    {
        if (n & 1)
            t[i] = jeden;
        else
            t[i] = zero;
        n >>= 1;
    }
    n = m;
    for (int i = 0; i < 8; i++)
        printf("%c    ", t[i]);

    printf("\n\n%hu", odbicie(n));
    printf(" %hu ", negatyw(n));
    printf("%hu", odbicie(negatyw(n)));
}
