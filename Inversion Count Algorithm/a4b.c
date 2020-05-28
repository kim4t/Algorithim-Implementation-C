#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double bruteForce(int arr[], int length) {
    double inversion = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (arr[i] > arr[j]) {
                inversion++;
            }
        }
    }
    return inversion;
}


int main(int argc, char *argv[]) {
    srand(124);
    int i, length;
    if (argc < 2) {
        printf("Usage: %s <data-set-size>", argv[0]);
       
        exit(1);
    }
    length = atoi(argv[1]);
    int* a = malloc(length * sizeof(int));
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
    inversion = bruteForce(a, length);

    puts("");
    printf("Inversions found: %.0f\n", inversion);
    free(a);
    return 0;
}

