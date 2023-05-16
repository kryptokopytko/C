#include <stdio.h>

int main ()
{
    int n, m;
    scanf("%d", &n);
    char t[82];
    scanf("%s", t+1);
    for (int i = 1; i <= 80; i++)
    {
        if (t[i] == '\0')
        {
            m = i;
            break;
        }
    }
    t[0] = '#';
    t[m] = '#';
    char tab[82];
    for (int j = 0; j < n; j++)
    {
        for(int i = 1; i < m; i++)
        {
            char left = t[i-1];
            char central = t[i];
            char right = t[i+1];
            if (left == central && central == right)
                tab[i] = '#';
            else
            {
                if (left == '#' && central == '#')
                    tab[i] = '#';
                else
                    tab[i] = '.';
            }
        }
        tab[0] = '#';
        tab[m] = '#';
        for (int i = 1; i < m; i++)
        {
            putchar(tab[i]);
            t[i] = tab[i];
        }
        putchar('\n');
    }

}
