#include <stdio.h>

int main ()
{
    int c;
    c = getchar();
    int q = 0;
    while(c != EOF)
    {
        if(c >= '0' && c <= '9')
        {
            putchar(c);
            q = 1;
        }
        else
        {
            if(q == 1)
            {
                printf("\n");
                q = 0;
            }
        }
        c = getchar();
    }
}
