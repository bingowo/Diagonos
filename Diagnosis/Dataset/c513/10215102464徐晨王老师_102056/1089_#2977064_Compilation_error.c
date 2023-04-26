#include <stdio.h>
#include <math.h>

void plus(int* a);

int main(){
    int T;
    scanf("%d",&t);
    for(int t=0;t<T;t++){
        char s[100];
        scanf("%s",s);
        int A[100]={0};
        for(int i=0;i<strlen(s);i++){
            A[100-i]=s[i]-48;
        }
        int B,N;
        scanf("%d%d",&B,&N);
        int aa[100]={0};
        for(int i=(101-N);i<=100;i++){
            aa[i]=A[i];
        }
        for(int i=1;i<B;i++){
            plus(aa);
            for(int j=0;i<=100-N;i++){
                aa[j]=0;
            }   
        }
    }
    return 0;
}

void plus(int* a){
    for(int k=100;k>=0;k++){
        a[k]=2*a[k];
    }
    for(int k=100;k>=0;k++){
        a[k]=2*a[k];
    }
}

