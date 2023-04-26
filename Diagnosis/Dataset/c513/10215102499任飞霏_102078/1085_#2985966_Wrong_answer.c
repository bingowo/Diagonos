#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500

void minus(int a[],int b[])
{
    int i;
    for(i=L;i>=0;i--){
        a[i]-=b[i];
        if(a[i]<0){
            a[i-1]--;
            a[i]+=10;
        }
    }
}

void output(int a[])
{
    int i=0;
    while(i<L && a[i]==0)i++;
    while(i<L)printf("%d",a[i++]);
    printf("\n");
}

int main()
{
    char s1[L+1]={0},s2[L+1]={0};
    while(scanf("%s%s",s1,s2)==2){
        int A[L+1]={0},B[L+1]={0};
        int i,j;
        for(i=strlen(s1),j=L;i>=0;i--,j--){
            A[j]=s1[i]-'0';
        }
        for(i=strlen(s2),j=L;i>=0;i--,j--){
            B[j]=s2[i]-'0';
        }
        int m=0,n=0;
        while(A[m]==B[n]&&m<L&&n<L){
            m++;
            n++;
        }
        int flag=A[m]-B[n];
        if(flag>0){
            minus(A,B);
            output(A);
        }
        else if(flag==0){
            printf("0");
        }
        else{
            minus(B,A);
            printf("-");
            output(B);
        }
    }
    return 0;
}
