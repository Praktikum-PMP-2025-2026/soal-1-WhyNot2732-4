/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5
 *   Hari dan Tanggal    : Senin, 11 Mei 2026
 *   Nama (NIM)          : R. Damar Prawiro Kusumo Sudradjat (13224109)
 *   Nama File           : soal1.c
 *   Deskripsi           : Menghitung derajat setiap simpul, simpul yang memiliki derajat maksimum, dan mencari simpul yang terisolasi
 * dari input user berupa matriks adjacency 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    char input[100];
    char* tok;
    int temp, max, maxId, iso;
    max = -1;
    iso = 0;

    fgets(input, 100, stdin);
    tok = strtok(input, " ");
    N = atoi(tok);

    int mat[N][N];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            tok = strtok(NULL, " ");
            mat[i][j] = atoi(tok);
        }
    }
    
    for (int i = 0; i < N; i++){
        temp = 0;
        for (int j = 0; j < N; j++){
            temp += mat[i][j];
        }
        printf("DEGREE %d %d\n", i, temp);
        if (max < temp){
            maxId = i;
            max = temp;
        }
    }

    printf("MAX_VERTEX %d\n", maxId);

    printf("ISOLATED ");  
    
    for (int i = 0; i < N; i++){
        temp = 0;
        for (int j = 0; j < N; j++){
            temp += mat[i][j];
        }
        if (temp == 0){
            printf("%d", i);
            iso++;
            if (i != N-1){
                printf(" ");
            }
        }
    }
    if (iso == 0){
        printf("NONE");
    }
    
    printf("\n");
    return 0;
}

/*
REFERENSI:
https://www.geeksforgeeks.org/cpp/strtok-strtok_r-functions-c-examples/
https://www.geeksforgeeks.org/c/implementation-of-graph-in-c/
*/
