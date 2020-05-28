#include <stdio.h>
#include <stdlib.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 
#define SIZE 200000

int partition(int arr[], int start, int end) {
    int i = start;
    int j = end-1;
    int t = 0;
    if (i > j) {
        return 0;
    }
    else {
        int p = arr[end];
        while (i < j) {
            while (p >= arr[i] && i < end) {
                i++;
                
            }
            while (p < arr[j] && j > start) {
                j--;
                
            }
            if (i < j) {
                swap(arr[i], arr[j], t);
            }
        }
        if (arr[i] > p) {
            swap(arr[end], arr[i], t);
            
        }
        return i;
    }

}

int qsortl(int arr[], int start, int end)
{
    int count = 0;
    if (start < end) {
        int pivot = partition(arr, start, end);
        count = end - start;
        count+= qsortl(arr, start, pivot - 1);
        count+= qsortl(arr, pivot + 1, end);
    }
    return count;
}

void printArr(int arr[]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    srand(124);
    int* a = malloc(sizeof(int) * SIZE); \
        int i;
    if (a == NULL) {
        printf("malloc failed..\n");
        exit(1);
    }
    else {
        for (
            i = 0; i < SIZE; i++) {
            a[i] = rand();

        }
    }
    
    puts("");
    int count = qsortl(a, 0, SIZE - 1);
    
    printf("Pivot is Last.\n");
    printf("Number of comparison: %d\n", count);
    free(a);
    return 0;
}

