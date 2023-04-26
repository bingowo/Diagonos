#include <stdio.h>
#include <string.h>
#include <ctype.h>

void A(int a[],int i)
{
    int j,k,temp;
    for(j=0;j<i;j++){
        for(k=j+1;k<=i;k++){
            if(a[j]>a[k]){
            temp=a[j];
            a[j]=a[k];
            a[k]=temp;
            }
        }
    }
}

void D(int a[],int i)
{
    int j,k,temp;
    for(j=0;j<i;j++){
         for(k=j+1;k<=i;k++){
            if(a[j]<a[k]){
            temp=a[j];
            a[j]=a[k];
            a[k]=temp;
            }
         }
    }
}

int main()
{
    char n;
    int a[109];
    int i=0,j;
    scanf("%c",&n);
    while(scanf("%d",&a[i])){
        if(getchar()=='\n')break;
        i++;
    }
    if(n=='A')A(a,i);
    else D(a,i);
    printf("%d ",a[0]);
    for(j=1;j<=i;j++){
        if(a[j]!=a[j-1])printf("%d ",a[j]);
    }
    return 0;
}