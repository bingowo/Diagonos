#include<stdio.h>
int main(){
    int n;
    int a[20]={0};
    a[0]=1;a[1]=2;a[2]=4;a[3]=7;
    for(int i=4;i<=n;i++)
        a[i]=2*a[i-1]-a[i-2]+a[i-3];
    while((scanf("%d",&n)!=EOF)&&(n!=-1))
    {

        printf("%d\n",a[n]);

    }
 


}
