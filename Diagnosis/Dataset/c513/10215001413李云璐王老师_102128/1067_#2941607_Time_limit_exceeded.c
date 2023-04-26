#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int tb(x)
{
    
        if(x==0) return 0;
        if(x==1) return 1;
        if(x==2) return 1;
        if(x==3) return 2;
        if(x>3)  return 2*tb(x-1)-tb(x-4);
        
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,t;
        scanf("%d",&x);
        t=tb(x);
        printf("case #%d:\n",i);
        printf("%d\n",t);
    }
    return 0;
}