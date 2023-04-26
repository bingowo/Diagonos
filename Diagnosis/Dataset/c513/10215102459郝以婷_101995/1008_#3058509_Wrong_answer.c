#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,x,y,a[21]={0},b[21]={0},count1,count2,j,count0,t;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        count0=0;
        scanf("%d %d",&x,&y);
        j=0;
        do
        {
            t=x%2;
            x=x/2;
            a[j++]=t;
        }while(x!=0);
        if(j==0)
            count1=1;
        else
            count1=j;
        for(j=0;y!=0;j++)
        {
            t=y%2;
            y=y/2;
            b[j]=t;
        }
        if(j==0)
            count2=1;
        else
            count2=j;
        if(count1<count2)
        {
            t=count1;
            count1=count2;
            count2=t;
        }
        for(j=0;j<count2;j++)
        {
            if(a[j]!=b[j])
                count0++;
        }
        count0=count0+count1-count2;
        printf("%d\n",count0);
    }
    return 0;
}
