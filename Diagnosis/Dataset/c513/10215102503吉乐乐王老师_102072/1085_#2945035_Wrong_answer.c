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
int main(){
    char a[N]="\0",b[N]="\0";
    while(scanf("%s %s",a,b)==2){
        int A[N],B[N];
        for(int i=0;i<N;i++){
            A[i]=B[i]=-1;
        }
        int lena=stoi(a,A);
        int lenb=stoi(b,B);
        int sigh=1;
        if(lena>lenb){
            sigh=-1;
            for(int i=0;i<N;i++){
                A[i]=B[i]=-1;}
            lena=stoi(b,A);
            lenb=stoi(a,B);
        }
        if(lena==lenb){
            for(int i=lena;i<N;i++){
                if(A[i]<B[i]){
                    sigh=-1;
                    for(int i=0;i<N;i++){
                    A[i]=B[i]=-1;}
                    lena=stoi(b,A);
                    lenb=stoi(a,B);
                    break;
                }
            }
        }
        for(int i=N-1;i>=lenb;i--){
            if(A[i]<B[i]){
                A[i]+=10;
                A[i-1]-=1;
            }
            A[i]=A[i]-B[i];
        }
        for(int i=lenb;i>lena;i--){
            if(A[i]<0){
                A[i]+=10;
                A[i-1]-=1;
            }
        }
        while(A[lena]==0)lena++;
        if(sigh==-1)putchar('-');
        if(lena==N)printf("0");
        while(lena<N)printf("%d",A[lena++]);
        putchar('\n');
    }
}