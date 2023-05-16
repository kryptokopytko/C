#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

typedef union {
    struct { double x, y, z; };
    double c[3];
} vec3d;

vec3d vec3d_of(double   x,   double   y,   double   z)
{
    vec3d a;
    a.x = x;
    a.y = y;
    a.z = z;
    return a;
}

vec3d vec3d_trace(vec3d u)
{
    printf("[%lf, %lf, %lf]\n", u.x, u.y, u.z);
    return u;
}

vec3d vec3d_sum(vec3d u, vec3d v)
{
    vec3d s;
    s.x = u.x + v.x;
    s.y = u.y + v.y;
    s.z = u.z + v.z;
    return s;
}

vec3d vec3d_diff(vec3d u, vec3d v)
{
    vec3d s;
    s.x = u.x - v.x;
    s.y = u.y - v.y;
    s.z = u.z - v.z;
    return s;
}

double vec3d_dot(vec3d u, vec3d v)
{
    double s = 0;
    s += u.x * v.x;
    s += u.y * v.y;
    s += u.z * v.z;
    return s;
}

double vec3d_length(vec3d u)
{
    return sqrt(vec3d_dot(u, u));
}

bool   nearly_equal(vec3d  u,  vec3d  v,   double  eps)
{
    double x = vec3d_length(u) - vec3d_length(v);
    if (x < 0)
        x *= -1;
    if (x < eps)
        return 1;
    return 0;
}
                                            //u1 v2 u2 v1
                                            //u2 v0 u0 v2
                                            //u0 v1 u1 v0
vec3d   vec3d_cross(vec3d   u,   vec3d   v) //[bz − cy, cx − az, ay − bx]
{
    vec3d a;
    for (int i = 0; i < 3; i++)
       a.c[i] = u.c[(i+1)%3]* v.c[(i+2)%3] - u.c[(i+2)%3] * v.c[(i+1)%3];
    return a;
}

void test_vec3d_cross()
{
    assert(nearly_equal(
    vec3d_cross(vec3d_of(3.,2.,-2.), vec3d_of(1.,0.,5.)),
    vec3d_of(10., -17., -2.),
    1e-12));
}

int main( )
{
    //if(nearly_equal(vec3d_of(1, 1, 1), vec3d_of(1, 1, 1), 0.1)) printf("O");
    test_vec3d_cross();
}
