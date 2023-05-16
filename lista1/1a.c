#include <stdio.h>

int main ()
{
    int r;
    scanf("%d", &r);
    int lcal = 0; // liczba kwadratow mieszczacych sie w calosci
    int lcz = 0; // liczba kwadratow mieszczacych sie w czesci
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            int d1 = i*i + j*j;
            int d2 = (i+1)*(i+1) + (j+1)*(j+1);
            if (d2 <= r*r)
                lcal++;
            else
                if (d1 <= r*r)
                    lcz++;
        }
    }
    float dol = lcal;
    float gora = lcz + lcal;
    dol /= (r*r);
    gora /= (r*r);
    printf ("%f %f", dol*4, gora*4);
}
