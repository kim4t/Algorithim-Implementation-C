#include <stdio.h>
#include <stdlib.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) 
#define SIZE 200000

int partition(int arr[], int start, int end) {
    int i = start + 1;
    int j = end;
    int m =  (start+end)/2;
    int median;
    int t = 0;

    
    int s[] = { start,m,end };
    int a; int b;
    for (a = 0; a < 3; a++) {
        for (b = 0; b < 2; b++) {
            if (arr[s[b]] > arr[s[b + 1]]) {
                swap(arr[s[b]], arr[s[b + 1]], t);
            }
        }
    }
    median = s[1];
    swap(arr[start], arr[median], t);


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

int qsortm(int arr[], int start, int end)
{
    int count = 0;
    if (start < end) {
        int pivot = partition(arr, start, end);
        count = end - start;
        count += qsortm(arr, start, pivot - 1);
        count += qsortm(arr, pivot + 1, end);
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
    int count = qsortm(a, 0, SIZE - 1);
    
    printf("Pivot is median.\n");
    printf("Number of comparison: %d\n", count);
    free(a);
    return 0;
}

