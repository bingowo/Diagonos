#include<stdio.h>
int main
{
    int a[1001]={0};
    char c;
    scanf("%c",&c);
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        a[x]=1;
    }
    if(c=='A')
    {
        for(int i=0;i<1001;i++)
        {
            if(a[i]==1)printf("%d ",i);
            
        }
        
    }
    else if(c=='D')
    {
         for(int i=0;i<1001;i++)
        {
            if(a[i]==1)printf("%d ",i);
            
        }
    }
    
    
    
    
}