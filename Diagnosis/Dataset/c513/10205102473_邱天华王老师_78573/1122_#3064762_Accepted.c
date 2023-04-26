#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  ll long long 
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        ll k;
        int s[20]={0};
        int w=0;
        int flag=1;      
        scanf("%lld",&k);
         if(k==0)
        {
            printf("0\n");
            continue;
        }
        while(k!=0)
        {
            s[w]=k%2333;
            k/=2333;
            w++;
        }
        w--;
        for(w;w>=0;w--)
            printf("%d ",s[w]);
        printf("\n");
    }
    return 0;
}