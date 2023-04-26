#include <stdio.h>
#include <stdlib.h>

int cmpa(const void *a,const void *b)
{
    int a0=(int*)a;
    int b0=(int*)b;
    return a0-b0;
}
int cmpd(const void *a,const void *b)
{
    int a0=(int*)a;
    int b0=(int*)b;
    return b0-a0;
}
int main()
{
    int n,i;
    int a[1000];
    char x;
    scanf("%c",&x);
    n=0;
    while(scanf("%d",&i)!=EOF){
        a[n]=i;
        n++;
    }
    if(x=='A')
        qsort(a,n,sizeof(a[0]),cmpa);
    else
        qsort(a,n,sizeof(a[0]),cmpd);
    printf("%d ",a[0]);
    while(n>1 && a[n-2]==a[n-1])
        n--;
    for(i=1;i<n;i++){
        if(a[i]!=a[i-1])
            printf("%d",a[i]);
        if(i==n-1)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}
