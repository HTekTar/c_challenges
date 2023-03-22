#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool Palindrom(const char* str, int len){
    size_t l = 0, r = len -1;
    while(l < r){
        if(str[l++] != str[r--]) return false;
    }
    return true;
}

void primeNums(){
    printf("Input positive upper bound for the prime number range\n");
    unsigned int n;
    scanf("%u", &n);

    bool *isPrime = malloc(n*sizeof(bool));
    memset(isPrime, 1, n*sizeof(bool));
    int k = 2;
    while(k < n){
        if(isPrime[k] == 1){
            int i = 2;
            while(i*k < n){
                isPrime[i*k] = 0;
                i++;
            }
        }
        k++;
    }
    for(int i = 0; i < n; i++){
        if(isPrime[i] == 1)printf("%d ", i);
    }
    free(isPrime);
}

int binary_search(int *nums, unsigned int len, int target){
    int l = 0, r = len - 1;
    while(l <= r){
        int i = (r+l)/2;
        if(nums[i] == target) return i;
        else if(nums[i] > target) r = i-1;
        else l = i+1;
    }
    return -1;
}

void fizbuzz(){
    for(int i=0; i<20; i++){
        i % 3 == 0 ?
        i % 5 == 0 ?printf("fizzbuzz"):printf("fizz"):
        i % 5 == 0 ? printf("buzz"): printf("%i", i);
        printf("\n");
    }
}

void inputMatrix(char name, unsigned int m, unsigned int n, float* x){
    for(unsigned int i = 0; i < m; i++){
        for(unsigned  int j=0; j<n; j++){
            printf("input %c(%u, %u): ", name, i+1, j+1);
            scanf("%f", x + (i*n + j));
        }
    }
}

void printMatrix(unsigned int m, unsigned int n, float* x) {
    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < n; j++) {
            printf("%f ", x[i*n + j]);
        }
        printf("\n");
    }
}

float evalMatElem(
        int col, int row,
        unsigned int nm,
        int m_x, int n_y,
        float *x, float *y){
    float r = 0.0f;
    unsigned  int i = 0;
    while(i < nm){
        r += x[i + row*m_x] * y[col + i*n_y];
        ++i;
    }
    return r;
}

void matrixMul(){
    unsigned int m_x, nm, n_y;
    //ask for dimension of matrix x
    printf("enter number of rows for first matrix: ");
    scanf("%u", &m_x);
    printf("enter number of columns for first(number of rows for second) matrix: ");
    scanf("%u", &nm);
    printf("enter number of columns for second matrix");
    scanf("%u", &n_y);

    //allocate memory for matrices x and y
    float *x = malloc(m_x*nm*sizeof(float));
    float *y = malloc(nm*n_y*sizeof(float)) ;
    float *xy = malloc(m_x * n_y* sizeof(float));

    inputMatrix('x', m_x, nm, x);
    inputMatrix('y', nm, n_y, y);
    printMatrix(m_x, nm, x);
    for(int i = 0; i < m_x; i++){
        for(int j=0; j<n_y; j++){
            xy[i*nm + j] = evalMatElem(j, i, nm, m_x, n_y, x, y);
        }
    }

    printMatrix(m_x, n_y, xy);

    free(x);
    free(y);
    free(xy);
}

void merge_sort(int *nums, unsigned int len){
    if(len <= 1) return;
    int *arr = malloc(len*sizeof(int));
    merge_sort(nums, len/2);
    merge_sort(nums+len/2, len/2);
    int l = 0, r = len/2;
    int i = 0;
    while(l < len/2 && r < len){
        if(nums[l] > nums[r]){
            arr[i++] = nums[r++];
        }
        else{
            arr[i++] = nums[l++];
        }
    }
    while(l < len/2){
        arr[i++] = nums[l++];
    }
    while(r < len){
        arr[i++] = nums[r++];
    }
    for(int j=0; j<len; j++){
        nums[j] = arr[j];
    }
    free(arr);
}

