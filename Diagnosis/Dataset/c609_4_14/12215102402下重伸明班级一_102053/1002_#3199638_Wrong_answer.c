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
        for(int z=0;z<=l;z++)
        {
            r=0;
            if(ming[z]>r)
            {
                r=ming[z];
            }
        }
        printf("%d\n",r+1);
    }
    
    
}