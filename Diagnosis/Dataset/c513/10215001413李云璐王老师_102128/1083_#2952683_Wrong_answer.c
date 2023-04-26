#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int wu(int l)
{
    if(l==0) return 1;
    if(l==1) return 5;
    if(l==2) return 25;
    if(l==3) return 125;
    if(l==4) return 625;
    if(l==5) return 3125;
}
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
               if(k%wu(l)==0) count+=l;
           }
               
           
        }
        printf("case #%d:\n",i);
        printf("%d\n",count);
    }
    return 0;
}