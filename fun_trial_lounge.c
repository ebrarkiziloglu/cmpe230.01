#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXDIMENSION 10

float(* transposeMatrix(int r, int c, float matrix[r][c]))[];
float (*matrix_sum(int r, int c, float matrix1[r][c], float matrix2[r][c]))[];
void printMatrix(int r, int c, float (*ptr)[]);
float scalar_sum(float x, float y);
float scalar_sub(float x, float y);
float scalar_multp(float x, float y);
int isInt(float x);

int main(){
    // int a[5 * 6];

    float a[3][3] = {{0,1,2}, {3,4,5}, {6,7,8}};
    float b[3][3] = {{10,11,12}, {13,14,15}, {16,17,18}};
    printf("a is:\n");
    printMatrix(3, 3, a);
//    printf("\n\n");
//    printf("b is:\n");
//    printMatrix(3, 3, b);
//    printf("\n\ntranspose is:\n");
//    printMatrix(4, 3, transposeMatrix(3, 4, a));
    float (*c)[]= transposeMatrix(3, 3, b);
    printf("\n\ntranspose is:\n");
    printMatrix(3, 3, c);
    printf("\n\nsum is:\n");
    printMatrix(3,3, matrix_sum(3,3,a, c));
    return 0;
}



float scalar_sum(float x, float y){
    return x+y;
}

float scalar_sub(float x, float y){
    return x-y;
}

float scalar_multp(float x, float y){
    return x*y;
}

float (*matrix_sum(int r, int c, float matrix1[r][c], float matrix2[r][c]))[]{
    int i, j;
    float matrix_res[r][c];

    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            matrix_res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return matrix_res;
}

float(* transposeMatrix(int r, int c, float matrix[r][c]))[]{
    float tr[c][r];

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            tr[j][i] = matrix[i][j];
        }
    }
    return tr;
}


void printMatrix(int r, int c, float matrix[r][c]){
    float temp;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            temp = matrix[i][j];
            if(isInt(temp)==1)
                printf("%d ", (int)temp);
            else
                printf("%f ", temp);
            // printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int isInt(float x){
    int n = (int)x;
    double check = x-n;
    if(check>0)
        return 0;
    return 1;
}
