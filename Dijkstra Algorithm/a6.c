#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>     /* for INT_MAX */
#define N 10            /* max matrix size is 10 x 10 */
#define INF INT_MAX     /* infinity?  */

int d[N];

void getdata(int amtrix[][N], int* n) {
    int i, j, nsz, nedg, fr, to, wt, svr;

    scanf("%d %d %d", &nsz, &nedg, &svr);
    for (i = 0; i < nsz; i++) {
        for (j = 0; j < nsz; j++) {
            if (i == j) {
                amtrix[i][j] = 0;
            }
            else {
                amtrix[i][j] = INF;
            }
        }
    }
    
    for (i = 0; i < nedg; i++) {
        scanf("%d %d %d", &fr, &to, &wt);
        amtrix[fr][to] = wt;
    }
    *n = nsz;
     
    
}

void printpaths(int n, int d[]) {
    int i;
    for (i = 1; i < n; i++) {
        printf("%d\t%d\t",0,i);
      
        if (d[i] == INF) {
            printf("%s\n", "INF  (No PATH)");
        }
        else {
            printf("%d\n", d[i]);
        }
    }
    
}



void dijkstras(int amtrix[][N], int n) {
    int v[N];
    int i, j;
    puts("");
    
    for (i = 0; i <n; i++) {
            d[i] = amtrix[0][i];
            v[i] = 0;
    }

    puts("");
    for (i = 0; i < n - 2; i++) {
        int current = 0;
        int min = INF;

        for (j = 0; j < n; j++) {
            if (d[j] < min && v[j] == 0) {
                min = d[j];
                current = j;
            }
        }
        v[current] = 1;
       
        for (j = 0; j < n; j++) {
            if (v[j] == 0) {
                if (d[current] + amtrix[current][j] > 0) {
                    if (d[current] + amtrix[current][j] < d[j]) {
                    
                        d[j] = d[current] + amtrix[current][j];
                       
                    }
                }
             
            }
        }
        
    }
    
    
}



int main(void) {
    int amtrix[N][N];
    int n;
    puts("");
    getdata(amtrix, &n);
    
    
    dijkstras(amtrix, n);
    printpaths(n, d);
    return 0;


}
