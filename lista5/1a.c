#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef int Pair;

Pair make_pair(int a, int b)
{
    a %= 8;
    b %= 8;
    a <<= 3;
    a += b;
    return a;
}

int get_first(Pair p)
{
    p >>= 3;
    return p;
}

int get_second(Pair p)
{
    p %= 8;
    return p;
}

Pair sum_pairs(Pair u, Pair v)
{
    int first = (get_first(u) + get_first(v)) % 8;
    int second = (get_second(u) + get_second(v)) % 8;
    return make_pair(first, second);
}

bool are_pairs_equal(Pair u, Pair v)
{
    return (u == v);
}

int main ()
{
    /*int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf ("%d", are_pairs_equal(make_pair(a, b), make_pair(c, d)));*/
    assert(are_pairs_equal(
        sum_pairs(make_pair(2, 5), make_pair(2, 4)),
        make_pair(4, 1)));
    assert(make_pair(12, 16) == 32);
    assert(get_first(make_pair(23, 6)) == 7);
    assert(get_second(make_pair(23, 6)) == 6);
    assert(sum_pairs(make_pair(1, 2), make_pair(2, 3)) == make_pair(3, 5));
    assert(are_pairs_equal(make_pair(4, 5), make_pair(12, 13)));
}
