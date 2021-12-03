#include <stdio.h>
#include <stdlib.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int main(void){
    FILE *file;
    file = fopen("graph.gv", "w");
    fprintf(file, "graph {\n");

    int v1 = 0, v2 = 0, a, b, i, j;

    printf("N1 = : ");
    scanf("%d", &v1);
    int **mas1 = (int**)malloc(v1 * sizeof(int*));
    for(i = 0; i < v1; i++) mas1[i] = (int*)malloc(v1 * sizeof(int));
    printf ("M1:\n");
    for(i = 0; i < v1; i++) for(j = 0; j < v1; j++) scanf("%d", &mas1[i][j]);
    printf("N2 = : ");
    scanf("%d", &v2);
    int **mas2 = (int**)malloc(v2 * sizeof(int*));
    for(i = 0; i < v2; i++) mas2[i] = (int*)malloc(v2 * sizeof(int));
    printf ("M2:\n");
    for(i = 0; i < v2; i++) for(j = 0; j < v2; j++) scanf("%d", &mas2[i][j]);

    a = MIN (v1, v2);
    b = MAX (v1, v2);
    int **mas3 = (int**)malloc(b * sizeof(int*));
    for(i = 0; i < b; i++) mas3[i] = (int*)malloc(b * sizeof(int));
    for(int i = 0; i < a; ++i){
        for(int j = 0; j < a; ++j){
            if (i >= j){
                mas3[i][j] = MAX(mas1[i][j], mas2[i][j]);
                mas3[j][i] = mas3[i][j];
            }
        }
    }
    if (v1 < v2){
        for(int i = a; i < b; ++i){
            for(int j = 0; j < b; ++j){
                if (i >= j){
                    mas3[i][j] = mas2[i][j];
                    mas3[j][i] = mas3[i][j];
                }
            }
        }
        for(int i = 0; i < b; ++i){
            for(int j = a; j < b; ++j){
                if (i >= j){
                    mas3[i][j] = mas2[i][j];
                    mas3[j][i] = mas3[i][j];
                }
            }
        }
    }
    else{
        for(int i = a; i < b; ++i){
            for(int j = 0; j < b; ++j){
                if (i >= j){
                    mas3[i][j] = mas1[i][j];
                    mas3[j][i] = mas3[i][j];
                }
            }
        }
        for(int i = 0; i < b; ++i){
            for(int j = a; j < b; ++j){
                if (i >= j){
                    mas3[i][j] = mas1[i][j];
                    mas3[j][i] = mas3[i][j];
                }
            }
        }
    }

    /*printf ("M1:\n");
    for(i = 0; i < v1; i++) {
        for(j = 0; j < v1; j++) {
            printf("%2d", mas1[i][j]);
        }
        printf("\n");
    }
    printf ("M2:\n");
    for(i = 0; i < v2; i++) {
        for(j = 0; j < v2; j++) {
            printf("%2d", mas2[i][j]);
        }
        printf("\n");
    }
    printf ("M3:\n");
    for(i = 0; i < b; i++) {
        for(j = 0; j < b; j++) {
            printf("%2d", mas3[i][j]);
        }
        printf("\n");
    }*/

    for(int i = 0; i < b; ++i){
        for(int j = i; j < b; ++j){
            int c = mas3[i][j];
            while(c > 0){
                fprintf(file, "%d -- %d;\n", i + 1, j + 1);
                c--;
            }
        }
    }

    fprintf(file, "}\n");
    fclose(file);
    system("dot -Tpng graph.gv -o graph.png");
    system("graph.png");
    return 0;
}
