#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int x,r,j=0,k=0,ming[32]={0},sum,l=0;
        int a[32];
        scanf("%d",&x);
        while(x>0)
        {
            a[j]=x%2;
            x=x/2;
            j++;
        }
        while(k<j)
        {
           sum=a[k]+a[k+1] ;
           if(sum==1)
           {
               ming[l]++;
               k++;
           }
           else
           {
               k++;
               l++;
           }
        }
        r=0;
        for(int z=0;z<=l;z++)
        {
            
            if(ming[z]>r)
            {
                r=ming[z];
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",r+1);
    }
    
    
}