#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* memory;
    int size;
} Int_array;

void print_array(Int_array array)
{
    printf("[");
    for (int i = 0; i < array.size - 1; i++)
    {
        int y = array.memory[i];
        printf("%d, ", y);
    }
    printf("%d]\n", array.memory[array.size - 1]);
}

Int_array map_inplace(int f(int), Int_array array)
{
    for (int i = 0; i < array.size; i++)
        array.memory[i] = f(array.memory[i]);
    return array;
}

Int_array map_alloc(int f(int), Int_array array)
{
    int* array22 = (int*) malloc(array.size*sizeof(int));
    Int_array array2 = {.memory = array22, .size = array.size};
    for (int i = 0; i < array.size; i++)
        array2.memory[i] = f(array.memory[i]);
    return array2;
}

Int_array filter_inplace(bool f(int), Int_array array)
{
    int w = 0;
    for (int i = 0; i < array.size; i++)
    {
        if(f(array.memory[i]))
        {
            array.memory[w] = array.memory[i];
            w++;
        }
    }
    array.size = w;
    return array;
}

Int_array filter_alloc(bool f(int), Int_array array)
{
    int w = 0;
    for (int i = 0; i < array.size; i++)
        if (f(array.memory[i]))
            w++;
    int* array22 = (int*) malloc(w*sizeof(int));
    Int_array array2 = {.memory = array22, .size = w};
     w = 0;
    for (int i = 0; i < array.size; i++)
    {
        if (f(array.memory[i]))
        {
            array2.memory[w] = array.memory[i];
            w++;
        }
    }
    array2.size = w;
    return array2;
}

int square(int n) { return n * n; }
bool is_odd(int n) { return n & 1; }

int main ()
{
    int array_mem[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Int_array array = {.memory = array_mem, .size = 8};
    print_array(map_alloc(square, array));
    print_array(filter_alloc(is_odd, array));
    print_array(map_inplace(square, array));
    print_array(filter_inplace(is_odd, array));
}
