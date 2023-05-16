#include <stdio.h>

int last(int n)
{
    return ((1<<n)-1);
}

int write_utf8_char(char dst[], int n)
{
        if (n < (1<<7))
        {
            dst[0] = n;
            return 1;
        }
        if (n < (1<<11))
        {
                dst[0] = (last(2)<<6) | ( n>> 6);
                dst[1] = (      1<<7) | ( n     &last(6));
                return 2;
        }
        if (n < (1<<16))
        {
            dst[0] = (last(3)<<5) | ( n>>12);
            dst[1] = (      1<<7) | ((n>> 6)&last(6));
            dst[2] = (      1<<7) | ( n     &last(6));
            return 3;
        }
        if (n < (1<<21))
        {
            dst[0] = (last(4)<<4) | ( n>>18);
            dst[1] = (      1<<7) | ((n>>12)&last(6));
            dst[2] = (      1<<7) | ((n>> 6)&last(6));
            dst[3] = (      1<<7) | ( n     &last(6));
            return 4;
        }
        return 0;
}

void rewrite_string_as_utf8(char text[])
{
    char tz[20] = {'A', 'a', 'C', 'c', 'E', 'e', 'L', 'l', 'N', 'n', 'O', 'o', 'S', 's', 'X', 'x', 'Z', 'z'};
    int tl[20] = {260, 261, 262, 263, 280, 281, 321, 322, 323, 324, 211, 243, 346, 347, 377, 378, 379, 380};
    int k = 0;
    while (text[k] != '\0')
    {
        if (text[k] == '`')
        {
            char l = text[k+1];
            int n = 21;
            for (int i = 0; i < 18; i++)
            {
                if (tz[i] == l)
                    n = i;
            }
            if (n == 21)
            {
                k++;
                continue;
            }
            write_utf8_char(text+k, tl[n]);
            k += 2;
        }
        else
            k++;
    }
}

int main ()
{
    char text1[] = "za`z`o`l`c g`e`sl`a ja`x`n ZA`Z`O`L`C G`E`SL`A JA`X`N";
    char text2[] = u8"zażółć gęślą jaźń ZAŻÓŁĆ GĘŚLĄ JAŹŃ";
    rewrite_string_as_utf8(text1);
    printf("%s\n%s\n", text1, text2);
}
