#include<stdio.h>



int main()
{
    while(1)
    {
        int l;
        scanf("%d",&l);
        if(l == -1)
            break;
        int d00[22]={0},d01[22]={0},d1[22]={0};
        d00[2]=1,d01[2]=1,d1[2]=2;
        d00[3]=2,d01[3]=2,d1[3]=3;
        for(int j=4;j<21;j++)
        {
            d00[j]=d00[j-1]+d01[j-1];
            d01[j]=d1[j-1];
            d1[j]=d00[j-1]+d1[j-1];
        }
        int ans;
        if(l==1)
            ans=2;
        else if(l==2)
            ans=4;
        else
            ans=d00[l]+d01[l]+d1[l];
        
        printf("%d\n",ans);
    }
    
    return 0;
}
