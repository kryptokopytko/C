#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct IntListNodeAux IntListNode;
typedef IntListNode* IntList;

struct IntListNodeAux {
    int head;
    IntList tail;
};

IntList array_to_list_alloc(int *memory, int size)
{
    if (size == 0)
    {
        IntList xs = NULL;
        return xs;
    }
    IntList xs = (IntList)malloc(sizeof(struct IntListNodeAux));
    IntList a = xs;
    for (int i = 0; i < size - 1; i++)
    {
        a -> head = memory[i];
        IntList b = (IntList)malloc(sizeof(struct IntListNodeAux));
        a -> tail = b;
        a = b;
    }
    a -> head = memory[size-1];
    a -> tail = NULL;
    return xs;
}

void print_list(IntList xs)
{
    printf("[");
    while (xs -> tail != NULL)
    {
        printf("%d, ", xs -> head);
        xs = xs -> tail;
    }
    printf("%d]\n", xs -> head);
}

int length(IntList xs)
{
    int s = 0;
    while (xs -> tail != NULL)
    {
        s++;
        xs = xs -> tail;
    }
    return s+1;
}

int sum(IntList xs)
{
    int s = 0;
    while (xs -> tail != NULL)
    {
        s += xs -> head;
        xs = xs -> tail;
    }
    return s + xs -> head;
}

int addition(int a, int b) { return a + b; }
int multiplication(int a, int b) { return a * b; }

int fold(int op(int, int), int acc, IntList xs)
{
    if (xs == NULL)
        return acc;
    if (xs -> tail == NULL)
        return op(xs -> head, acc);
    int a = xs -> head;
    xs = xs -> tail;
    return op(a, fold(op, acc, xs));
}

IntList list_plus(const IntList xs, const IntList ys)
{
    if (xs == NULL)
        return ys;
    if (ys == NULL)
        return xs;
    IntList list_plus = (IntList)malloc(sizeof(struct IntListNodeAux));
    IntList a = list_plus;
    IntList xxs = xs;
    while(xxs -> tail != NULL)
    {
        a -> head = xxs -> head;
        IntList b = (IntList)malloc(sizeof(struct IntListNodeAux));
        a -> tail = b;
        a = b;
        xxs = xxs -> tail;
    }
    a -> head = xxs -> head;
    a -> tail = (IntList)malloc(sizeof(struct IntListNodeAux));
    IntList yys = ys;
    while(yys -> tail != NULL)
    {
        a -> head = yys -> head;
        IntList b = (IntList)malloc(sizeof(struct IntListNodeAux));
        a -> tail = b;
        a = b;
        yys = yys -> tail;
    }
    a -> head = yys -> head;
    a -> tail = NULL;
    return list_plus;
}

IntList reverse_inplace(IntList xs)
{
    IntList koncowa = xs;
    IntList poczatkowa = xs;
    int l = 0; //dlugosc xs
    if (xs == NULL)
        return NULL;
    while(koncowa -> tail != NULL)
    {
        l++;
        koncowa = koncowa -> tail;
    }
    int glowa = koncowa -> head;
    koncowa -> head = poczatkowa -> head;
    poczatkowa -> head = glowa;
    int lkonc = l - 1;
    for (int i = 1; i <= l - i - 1; i++)
    {
        koncowa = xs;
        for (int i = 0; i < lkonc; i++)
            koncowa = koncowa -> tail;

        poczatkowa = poczatkowa -> tail;
        glowa = koncowa -> head;
        koncowa -> head = poczatkowa -> head;

        poczatkowa -> head = glowa;
        lkonc--;

    }
    return xs;
}

int main ()
{
   int arr[] = {3, 1, 4, 1, 5, 9, 2};
    IntList xs = array_to_list_alloc(arr + 1, 5);
    print_list(xs);
    printf("%d %d ", length(xs), sum(xs));
    printf("%d %d\n", fold(addition, 0, xs), fold(multiplication, 1, xs));
    print_list(list_plus(xs, xs));
    xs = reverse_inplace(xs);
print_list(xs);
}
