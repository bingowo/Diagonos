#include<stdio.h>
#include<math.h>
int main()
{
    int T,N[10000],R[10000];int i;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%d %d\n",&N[i],&R[i]);
    }
    for(i=0;i<T;i++){
        trans(N[i],R[i]);
    }
    return 0;
}

trans(int N,int R)
{
    int n;
    n=fabs(N);
    int i=0;int a[10000];char b[10000];int j;
    while(n>0){
        a[i] = n%R;
        n = n/R;
        i++;
    }
    for(j=0;j<i;j++){
        if (a[i-j-1]<10){
            b[j]=a[i-j-1]+'0';
        }
        else{
            b[j]=a[i-j-1]-10+'A';
        }
    }
    b[i] = '\0';
    if(N<0){
        printf("-%s\n",b);
    }
    else{
        printf("%s\n",b);
    }
}