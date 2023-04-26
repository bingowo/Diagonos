#include<stdio.h>
int main()
{
    int T,N,R;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d\n",&N,&R);
        printf("%s",convertion(N,R));
    }
    return 0;
}

char conversion(int N,int R)
{
    int i=0;int a[];char b[];
    while(N>=R){
        a[i] = N%R;
        N = N/R;
        i++;
    }
    for(int j=0;j<i;j++){
        if (a[i-j]<10){
            b[j]=a[i-j]+'0';
        }
        else{
            b[j]=a[i-j]+'A';
        }
    }
    return b[];
}