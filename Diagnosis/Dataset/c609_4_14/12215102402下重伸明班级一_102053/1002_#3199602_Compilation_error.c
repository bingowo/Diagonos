#include<stdio.h>
int main()
{
    int t,a[32];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int j=0,k=0,count=1,ming[32]={0},sum,l=0;
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
               k++
           }
           else
           {
               k++;
               l++;
           }
        }
        for(int z=0;z<=l;z++)
        {
            int r=1;
            if(ming[z]>r)
            {
                r=ming[z];
            }
        }
        printf("%d/n",r);
    }
    
    
}