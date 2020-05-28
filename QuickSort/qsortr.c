#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 
#define SIZE 200000

int partition(int arr[], int start, int end) {
    int i = start + 1;
    int j = end;
    int t = 0;

    
    srand(time(NULL));
    int r = start+(rand()%(end-start+1));
    swap(arr[start], arr[r], t);


    if (i > j) {
        return 0;
    }
    else {
        int p = arr[start];
        while (i < j) {
            while (p >= arr[i] && i < end) {
                i++;
                
            }
            while (p <= arr[j] && j > start) {
                j--;
                
            }
            if (i < j) {
                swap(arr[i], arr[j], t);
            }
        }

        if (arr[j] < p) {
            swap(arr[start], arr[j], t);
            
        }
        return j;
    }

}

int qsortr(int arr[], int start, int end)
{
    int count = 0;
    if (start < end) {
        int pivot = partition(arr, start, end);
        count = end - start;
        count += qsortr(arr, start, pivot - 1);
        count+= qsortr(arr, pivot + 1, end);
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
    int count = qsortr(a, 0, SIZE - 1);
    
    printf("Pivot is random.\n");
    printf("Number of comparison: %d\n", count);
    free(a);
    return 0;
}

