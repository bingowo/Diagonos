#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int T;
    scanf("%d ", &T);
    int sushu[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59,61,67,73,79,83,89,97};
    for (int t = 0; t < T; t++){
        int A[26] = {0}, B[26] = {0}, C[26] = {0};
        int index = 0;
        while (1){
            char ch = getchar();
            if (ch == ',') continue;
            else if (ch == ' ') break;
            A[index++] = ch - '0';
        }
        for (int i = index-1; i >= 0; i--) A[25+i-index+1] = A[i];
        for (int i = 0; i <= 25-index; i++) A[i] = 0;
        index = 0;
        while (1){
            char ch = getchar();
            if (ch == ',') continue;
            if (ch == '\n') break;
            B[index++] = ch - '0';
        }
        for (int i = index-1; i >= 0; i--) B[25+i-index+1] = B[i];
        for (int i = 0; i <= 25-index; i++) B[i] = 0;
        int carry = 0;
        for (int i = 25; i >= 0; i--){
            C[i] = A[i] + B[i] + carry;
            carry = 0;
            if (C[i] >= sushu[25-i]){
                carry = 1;
                C[i] -= sushu[25-i];
            }
        }
        index = 0;
        while (C[index] == 0) index++;
        printf("case #%d:\n", t);
        printf("%d", C[index]);
        for (int i = index+1; i <= 25; i++) printf(",%d", C[i]);
        printf("\n");
    }
    return 0;
}