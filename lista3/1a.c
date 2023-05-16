#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);
    int t[80];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t[i]);
    }
    if (n < 3)
    {
        printf("brak");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int s = t[i] + t[j] + t[k];
                if (s == 0)
                {
                    printf("(%d, %d, %d)", t[i], t[j], t[k]);
                    return 0;
                }
            }
        }
    }
    printf("brak");
}
