#include <stdio.h>
#include <stdlib.h>

struct Array
{

    int A[10];
    int length;
    int size;
};

void Display(struct Array arr)
{

    printf("Elements in the array are:\n");
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}

// void Append


int main()
{

   struct Array arr;




    return 0;
}