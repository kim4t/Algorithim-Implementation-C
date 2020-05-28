#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>     /* for INT_MAX */
#define N 10            /* max matrix size is 10 x 10 */
#define INF INT_MAX     /* infinity?  */

typedef struct edge {
    int fromv;
    int tov;
    int weight;
} edge;
edge edgs[N];

void getdata(int amtrx[][N], int* sz, int* stv) {
    int i, j, nsz, nedg, fr, to, vtx, wt;

    scanf("%d %d %d", &nsz, &nedg, &vtx);
    for (i = 0; i < nsz; i++) {
        for (j = 0; j < nsz; j++) {
            amtrx[i][j] = INF;
        }
    }
    for (i = 0; i < nedg; i++) {
        scanf("%d %d %d", &fr, &to, &wt);
        amtrx[fr][to] = wt;
        amtrx[to][fr] = wt;
    }
    *sz = nsz;
    *stv = vtx;

}

void prims(int amtrx[][N], int n, edge edgs[], int stv) {
 
    int i, j, row, col;
    int select[N];
    for (i = 0; i < n; i++)
        select[i] = 0;
    int s = 0;
    select[stv] = 1;
    while (s < N - 1) {
        int min = INF;
        for (i = 0; i < n; i++) {
            if (select[i] == 1) {
                for (j = 0; j < n; j++) {
                    if (select[j] == 0 && amtrx[i][j] < min) {
                        min = amtrx[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }
        select[col] = 1;
        edge new_edg;
        new_edg.fromv = row;
        new_edg.tov = col;
        new_edg.weight = min;
        edgs[s] = new_edg;
        s += 1;
    }
}

void printpaths(edge edgs[], int n) {
    
    int i, total = 0;
    for (i = 0; i < n - 1; i++) {
        total += edgs[i].weight;
                fprintf(stderr, "%d  %d  %d\n", edgs[i].fromv, edgs[i].tov, edgs[i].weight);
    }
        fprintf(stderr, "total cost: %d\n", total);
}

int main(void) {
    int amtrix[N][N];
    int sz, stv;

    getdata(amtrix, &sz, &stv);
    
    prims(amtrix, sz, edgs, stv);
    printpaths(edgs, sz);

    return 0;


}
