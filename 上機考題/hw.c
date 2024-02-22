#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int R = 2e5;
int N;

int comp(const void* p, const void*q){
    long long A = *(long long*)p;
    long long B = *(long long*)q;
    if(A > B) return 1;
    else if(A < B) return -1;
    else return 0;
}

void swap(long long* p, long long* q){
    long long temp = *p;
    *p = *q;
    *q = temp;
}

bool isBeautiful(long long* arr, int size) {
    if(size < 3) return true; //isBeautiful by default
    for(int i = 1; i < size - 1; i++) {
        if ((arr[i] - arr[i - 1]) * (arr[i + 1] - arr[ i ]) >= 0) return false;
    }
    return true;
}

void beautifulPermutations(long long* arr, bool* used, long long* current, long long** result, int depth, int* count){
    if(depth == N) { //edge condition
        if(isBeautiful(current, N)) {
            result[*count] = malloc(N * sizeof(long long));
            for(int i = 0; i < N; i++) {
                result[*count][i] = current[i];
            }
            (*count)++;
        }
        return;
    }
    for(int i = 0; i < N; i++) {
        if(!used[i]) {
            if(i > 0 && arr[i] == arr[i-1] && !used[i-1]) continue; //condition that won't repeat the same permutations

            used[i] = true;
            current[depth] = arr[i];
            beautifulPermutations(arr, used, current, result, depth + 1, count);
            used[i] = false; 
        }
    }
}
int main() {
    scanf("%d", &N);
    long long* arr = malloc(N * sizeof(long long));
    bool* used = calloc(N, sizeof(bool));
    long long* current = malloc(N * sizeof(long long));
    long long** result = malloc(R * sizeof(long long*));
    int count = 0;

    for(int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    qsort(arr, N, sizeof(long long), comp);

    beautifulPermutations(arr, used, current, result, 0, &count);

    for(int i = 0; i < count; i++) {
        for(int j = 0; j < N; j++) {
            printf("%lld ", result[i][j]);
        }
        printf("\n");
        free(result[i]); 
    }

    printf("%d\n", count);
    free(arr);
    free(used);
    free(current);
    free(result);

    return 0;
}