#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int T;
    scanf("%d ", &T);
    int sushu[25] = {2,3,5,7,11, 13,17,19,23,29, 31,37,41,43,47, 53,59,61,67,71, 73,79,83,89,97};
    for (int t = 0; t < T; t++){
        int A[26] = {0}, B[26] = {0}, C[26] = {0};
        char s[100] = {0};
        gets(s);
        int index = 0;
        int i;
        for (i = 0; i < strlen(s); i++){
            if (s[i] == ','){
                index++;
                continue;
            } 
            else if (s[i] == ' '){
                i++;
                break;
            }
            A[index] *= 10;
            A[index] += s[i] - '0';
        }
        for (int j = index; j >= 0; j--) A[25+j-index] = A[j];
        for (int j = 0; j < 25-index; j++) A[j] = 0;

        index = 0;
        for (i; i < strlen(s); i++){
            if (s[i] == ','){
                index++;
                continue;
            } 
            else if (s[i] == ' ') break;
            B[index] *= 10;
            B[index] += s[i] - '0';         
        }
        for (int j = index; j >= 0; j--) B[25+j-index] = B[j];
        for (int j = 0; j < 25-index; j++) B[j] = 0;      
        index = 0;

        int carry = 0;
        for (int i = 25; i >= 0; i--){
            C[i] = A[i] + B[i] + carry;
            carry = 0;
            if (C[i] >= sushu[25-i]){
                carry += C[i] / sushu[25-i];
                C[i] %= sushu[25-i];
            }
        }

        while (index < 26 && C[index] == 0) index++;
        printf("case #%d:\n", t);
        if (index == 26) printf("0");
        else{
            printf("%d", C[index]);
            for (int i = index+1; i <= 25; i++) printf(",%d", C[i]);
        }
        printf("\n");
    }
    return 0;
}