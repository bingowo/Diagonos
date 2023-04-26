#include<stdio.h>
int main()
{
    int T,N[10000],R[10000];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d\n",&N[i],&R[i]);
    }
    for(i=0;i<T;i++){
        conversion(N[i],R[i]);
    }
    return 0;
}

conversion(int N,int R)
{
    int i=0;int a[10000];char b[10000];
    while(N>0){
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
    b[j] = 0;
    printf("%s\n",b);
}