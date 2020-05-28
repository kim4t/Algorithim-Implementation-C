#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))   
#define SIZE 1000000
void bubble_sort(int* arr, int size);
void insertion_sort(int* arr, int size);
void selection_sort(int* arr, int size);
clock_t start, finish, used_time = 0;

void CalcTime()
{
    used_time = finish - start;
    printf("Time Spending : %f sec\n\n", (float)used_time / CLOCKS_PER_SEC);
}

int* makeArr(int size) {
    srand(1234);
    int* a = malloc(sizeof(int) * size);
    if (a == NULL) {
        printf("malloc failed..\n");
        exit(1);
    }
    else {
        for (int i = 0; i < size; i++) {
            a[i] = rand();

        }
    }
    return a;
}


int main() {
    
    int s = 50000;
    while (s <= SIZE) {
        int* arr = makeArr(s);
        printf("Size of data : %d\n\n", s);
        start = clock();
        bubble_sort(arr, s);
        finish = clock();
        printf("<Bubble Sort> ");
        CalcTime();
        free(arr);

        arr = makeArr(s);
        start = clock();
        insertion_sort(arr, s);
        finish = clock();
        printf("<Insertion Sort> ");
        CalcTime();
        free(arr);

        arr = makeArr(s);
        start = clock();
        selection_sort(arr, s);
        finish = clock();
        printf("<Selection Sort> ");
        CalcTime();
        printf("/////////////////////////////////////////////////////\n\n");
        s += 5000;
        free(arr);
    }
    
}