#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int m,count=0;
        scanf("%d",&m);
        for(int k=5;k<=m;k++)
        {
           if(k%5==0)
           {
               for(int l=2;l<7;l++)
               if(k%pow(5,l)==0) count+=l;
               
               
           }
               
           
        }
        printf("case #%d:\n",i);
        printf("%d\n",count);
    }
    return 0;
}