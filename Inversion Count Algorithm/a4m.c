#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double merge(int data[], int p, int q, int r, int length) {
    int i = p, j = q + 1, k = p;
    double inversion = 0;
   
    int* tmp = malloc(length * sizeof(int));
    
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) {
            tmp[k++] = data[i++];
            
        }
        else {
            tmp[k++] = data[j++];
            inversion += q - i+1;
        }
    }
    while (i <= q) tmp[k++] = data[i++];
    while (j <= r) tmp[k++] = data[j++];
    int a;
    for (a = p; a <= r; a++) data[a] = tmp[a];

  
    free(tmp);
    return inversion;
}


double mergeSort(int data[], int p, int r, int length) {
    double inversion = 0;
    int q;
    if (p < r) {
        q = (p + r) / 2;
        inversion += mergeSort(data, p, q, length);
        inversion += mergeSort(data, q + 1, r, length);
        inversion+= merge(data, p, q, r, length);
    }
    return inversion;
}

int main(int argc, char* argv[]) {
    srand(124);
    int i, length;

    if (argc < 2) {
        printf("Usage: %s <data-set-size>", argv[0]);

        exit(1);
    }
    length = atoi(argv[1]);
        int* a = (int*)malloc(length * sizeof(int));
        if (a == NULL) {
            printf("malloc failed..\n");
            exit(1);
        }
        else {
            for (
                i = 0; i < length; i++) {
                a[i] = rand();

            }
        }
        double inversion = 0;
        puts("");
        inversion = mergeSort(a, 0, length - 1, length);
        printf("Inversions found: %.0f\n", inversion);
        free(a);
    
    return 0;
}
