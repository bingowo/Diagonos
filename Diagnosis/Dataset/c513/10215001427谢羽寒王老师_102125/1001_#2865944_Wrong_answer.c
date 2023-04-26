#include<stdio.h>

int main()
{
    int n,i,j,N=1000;
    int a[N],r[N];
    char d[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i],&r[i]);
    }
    for(i=0;i<n;i++){
    for(j=0;a[i]!=0;j++){
        d[j]=a[i]%r[i];
        a[i]=a[i]/r[i];
        if(d[j]>'9'){d[j]=d[j]-10+'A' ;}
        }
        for(;j>=0;j--){
            printf("%d",d[j]);
            d[j]='\0';
        }
    }
}