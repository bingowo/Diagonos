#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char A[550],B[550];
    int N;
    scanf("%s",A);scanf("%s",B);scanf("%d",&N);
    if(strchr(A,'.')==NULL){
        A[strlen(A)]='.';A[strlen(A)]='0';
    }
    if(strchr(B,'.')==NULL){
        B[strlen(B)]='.';B[strlen(B)]='0';
    }
    printf("%lf",atof(A)-atof(B));
    return 0;
}
