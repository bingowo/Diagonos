#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void revise(char *a)
{
    int i;char c;
    for(i = 0;i<strlen(a)/2;i++)
        {c = a[i];
        a[i] = a[strlen(a)-1-i];
        a[strlen(a)-1-i] = c;
        }
}
int main()
{
    char A[501],B[501],C[501];
    while(scanf("%s %s",A,B)!=EOF)
    {
        char flag = '+';
        if(strcmp(A,B)==0) printf("0\n");
        else
        {if(strcmp(A,B)<0)
        {
        flag = '-';
        strcpy(C,A);strcpy(A,B);strcpy(B,C);
        }
        revise(A);revise(B);
        int i,j = 0,res[501],carry = 0;
        for(i = 0;i<strlen(A)&&i<strlen(B);i++)
        {
            if(A[i]-B[i]-carry>=0) {res[j++] = A[i]-B[i]-carry;carry = 0;}
            else {res[j++] = A[i]-B[i]+10-carry;carry = 1;}
        }
        while(i<strlen(A))
        {
            if(A[i]-'0'-carry>=0) {res[j++] = A[i] - '0'- carry;carry = 0;}
            else {res[j++] = A[i]-'0'+10-carry;carry = 1;}
            i++;
        }
        while(i<strlen(B))
        {
            if(B[i]-'0'-carry>=0) {res[j++] = B[i] - '0'- carry;carry = 0;}
            else {res[j++] = B[i]-'0'+10-carry;carry = 1;}
            i++;
        }
        while(res[j-1]==0) j--;
        if(flag=='-') printf("-");
        for(i=j-1;i>=0;i--)
            printf("%d",res[i]);
        printf("\n");}
    }
    return 0;
}
