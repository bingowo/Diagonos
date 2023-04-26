#include<stdio.h>
int main()
{
    int T,n,r;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d%d",&n,&r);
        char ans[100];
        int a=0,j=0;
        while(n){
            a=n%r;
            n/=r;
            if(a>9)a=a-32;
            ans[j++]=a;
        }
        for(int k=j-1;k>=0;k--)
        {
            printf("%c",ans[k]);
        }
        printf("\n");
    }
    return 0;
}