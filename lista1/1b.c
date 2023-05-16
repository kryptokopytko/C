#include <stdio.h>

int main ()
{
    float xs[3] = {0.00, 0.00, 0.00};
    printf("xs[0] = %.2f \nxs[1] = %.2f \nxs[2] = %.2f \n", xs[0], xs[1], xs[2]);
    while (1)
    {
        int l;
        float w;
        scanf ("%d %f", &l, &w);
        xs[l] += w;
        printf("xs[0] = %.2f \nxs[1] = %.2f \nxs[2] = %.2f \n", xs[0], xs[1], xs[2]);
    }
}
