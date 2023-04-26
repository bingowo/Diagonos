#include<stdio.h>
#include<string.h>
#define N 500
int stoi(char a[],int A[]){
    int n=strlen(a)-1;
    int m=N-1;
    while(n>=0){
        A[m]=a[n]-'0';
        m--,n--;
    }
    return m+1;
}
void swap(int A[],int B[]){
    for(int i=N-1;i>0;i--){
        int t=A[i];
        A[i]=B[i];
        B[i]=t;
    }
}
int main(){
    char a[N]="\0",b[N]="\0";
    while(scanf("%s",a)==1){
        getchar();
        scanf("%s",b);
        int A[N]={0},B[N]={0};
        int lena=stoi(a,A);
        int lenb=stoi(b,B);
        int sigh=1;
        if(lena>lenb){
            sigh=-1;
            swap(A,B);
        }
        if(lena==lenb){
            for(int i=lena;i<N;i++){
                if(A[i]<B[i]){
                    sigh=-1;swap(A,B);break;
                }
            }
        }
        int len=lena<lenb?lena:lenb;
        for(int i=N-1;i>=len;i--){
            if(A[i]<B[i]){
                A[i]+=10;
                A[i-1]-=1;
            }
            B[i]=A[i]-B[i];
        }
        if(sigh==-1)putchar('-');
        int i=0;
        while(B[i]==0)i++;
        while(i<N)printf("%d",B[i++]);
        putchar('\n');
    }
}