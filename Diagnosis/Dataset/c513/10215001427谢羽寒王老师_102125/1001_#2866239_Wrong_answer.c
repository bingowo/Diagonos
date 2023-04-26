#include<stdio.h>

int main()
{
    int n,i,j,N=1000;
    int a,r;
    int d[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&a,&r);
        
        for(j=0;a!=0;j++){
        d[j]=a%r;
        a=a/r;
        if(d[j]>9){d[j]=d[j]-10+'A' ;}
        }
        for(;j>=0;j--){
            printf("%c",d[j]);
            d[j]='\0';
        }
    
    }
    
    
}