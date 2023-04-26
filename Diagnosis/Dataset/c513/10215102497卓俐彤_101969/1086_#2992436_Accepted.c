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

int compare(int a[],int b[]){
    for(int i=0;i<2*L+1;i++){
        if(a[i]<b[i])return -1;
        else if(a[i]>b[i])return 1;
    }
    return 1;
}

void sub(int a[],int b[],int n){
    int i;
    for(i=2*L;i>L+n;i--){
        a[i]-=b[i];
        if(a[i]<0){
            a[i-1]-=1;
            a[i]+=10;
        }
    }
    if(a[i+1]>=5)a[i]++;
    for(i=L+n;i>0;i--){
        a[i]-=b[i];
        if(a[i]<0){
            a[i-1]-=1;
            a[i]+=10;
        }
    }
}

void output(int a[],int n){
    int i=0;
    while(i<=L&&!a[i])i++;
    if(i>L)printf("0");
    else{
        while(i<=L)printf("%d",a[i++]);
    }
    printf(".");
    while(i<=L+n)printf("%d",a[i++]);
    printf("\n");
}

int main(){
    int A[2*L+1]={0},B[2*L+1]={0};
    input(A);
    input(B);
    int N;
    scanf("%d",&N);
    int flag=compare(A,B);
    if(flag==-1){
        printf("-");
        sub(B,A,N);
        output(B,N);
    }else{
        sub(A,B,N);
        output(A,N);
    }
    
    return 0;
}
