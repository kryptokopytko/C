#include <stdio.h>

char ignore_until_opening()
{
    int c, d;
    c = getchar();
    d = getchar();
    while ((c != '[' || d != '[')&&(d != EOF))
    {
        c = d;
        d = getchar();
    }
    return d;
}

char copy_until_closing()
{
    int c, d;
    c = getchar();
    d = getchar();
    while (c != ']' || d != ']')
    {
        if (d == '|')
        {
            putchar(c);
            return d;
        }
        putchar(c);
        c = d;
        d = getchar();
    }
    return d;
}

char ignore_until_closing()
{
    int c, d;
    c = getchar();
    d = getchar();
    while ((c != ']' || d != ']')&&(d != EOF))
    {
        c = d;
        d = getchar();
    }
    return d;
}

int main ()
{
    int z = 0;
    while (z != EOF)
    {
        z = ignore_until_opening();
        if( z == '[')
        {
            char o = copy_until_closing();
            if (o == '|')
                if(ignore_until_closing()==']')
                    putchar('\n');
            if (o == ']')
                putchar ('\n');
        }
    }
}
