#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* f(int* a,char c)
{
    for(int i=0;i<8;i++){
        int x=c&1;
        if (x==0) (*a)++;
        else (*(a+1))++;
        c=c>>1;
    }
    return a;
}

int* F(int* p)
{
    int n=2;
    int max=1;
    int x=*p,y=*(p+1);
    if(x%y==0){
        *p=x/y;
        *(p+1)=1;
    }
    else{
        for(;n*n<=x;n++){
            if((x%n==0)&&(y%n==0)) max=n;
        }
        *p=x/max;
        *(p+1)=y/max;
    }
    return p;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char c;
        int zero=0,one=0;
        while((c=getchar())!='\n'){
            int zero1=0,one1=0;
            int arr[2];
            int* a1;
            arr[0]=zero1;
            arr[1]=one1;
            a1=f(arr,c);
            zero+=*(a1);
            one+=*(a1+1);
        }
        int arr1[2];
        int* a2;
        arr1[0]=zero+one;
        arr1[1]=one;
        a2=F(arr1);
        printf("%d/%d\n",*(a2+1),*a2);
    }
    return 0;
}
