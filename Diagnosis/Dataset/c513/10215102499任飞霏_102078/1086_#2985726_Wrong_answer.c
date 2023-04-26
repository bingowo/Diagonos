#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500

int input(int a[])
{
    char s[L+1]={0};
    scanf("%s",s);
    int i=0,j,k;
    while(s[i]&&s[i]!='.')i++;
    for(j=i-1,k=L;j>=0;j--,k--){
        a[k]=s[j]-'0';
    }
    for(j=i+1,k=L+1;j<strlen(s);j++,k++){
        a[k]=s[j]-'0';
    }
}

void minus(int a[],int b[],int N)
{
    int i;
    for(i=2*L;i>L+N;i--){
        a[i] -= b[i];
        if(a[i]<0){
            a[i-1]--;
            a[i]+=10;
        }
    }
    if(a[i+1]>=5)a[i]++;
    for(i=L+N;i>0;i--){
        a[i]-=b[i];
        if(a[i]<0){
            a[i-1]--;
            a[i]+=10;
        }
    }
}

void output(int a[],int N)
{
    int i=0;
    while(i<L && a[i]==0)i++;
    if(i>L)printf("%d",0);
    else{
        while(i<=L)printf("%d",a[i++]);
    }
    printf("%c",'.');
    while(i<=L+N)printf("%d",a[i++]);
    printf("\n");
}

int main()
{
    int A[2*L+1]={0},B[2*L+1]={0},N,flag=0;
    int lena=input(A);
    int lenb=input(B);
    if(lena <lenb)flag=1;
    else if(lena==lenb){
        int i,j;
        for(i=0,j=0;A[i]==B[j];i++,j++);
        if(A[i]<B[j])flag=1;
    }

    scanf("%d",&N);
    if(flag=0){
        minus(A,B,N);
        output(A,N);
    }
    else{
        minus(B,A,N);
        printf("-");
        output(B,N);
    }
    return 0;
}
