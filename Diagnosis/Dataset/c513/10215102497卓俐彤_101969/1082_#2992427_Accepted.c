#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 500

void input(int a[]){
    char s[L+1];
    scanf("%s",s);
    int i=0;
    while(s[i]&&s[i]!='.')i++;
    for(int j=i-1,k=L;j>=0;j--,k--)a[k]=s[j]-'0';
    for(int j=i+1,k=L+1;j<strlen(s);j++,k++)a[k]=s[j]-'0';
}

void add(int a[],int b[],int n){
    int i;
    for(i=2*L;i>L+n;i--){
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
    if(a[i+1]>=5)a[i]++;
    for(i=L+n;i>0;i--){
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
}
int main(){
    int A[2*L+1]={0},B[2*L+1]={0};
    input(A);
    input(B);
    int N;
    scanf("%d",&N);
    add(A,B,N);
    int i=0;
    while(i<=L&&!A[i])i++;
    if(i>L)printf("0");
    else{
        while(i<=L)printf("%d",A[i++]);
    }
    printf(".");
    while(i<=L+N)printf("%d",A[i++]);
    printf("\n");
    return 0;
}
