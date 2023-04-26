#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int s[100][2]={0};int j;
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&s[j][0],&s[j][1]);
        }
        int temp1[100]={0},temp2[100]={0};
        for(int k=0;k<100;k++) temp1[k]=k,temp2[k]=k;
        for(int k=0;k<j;k++)
        {
            int a=s[k][0],b=s[k][1];
            for(int kk=0;kk<100;kk++)
            {
                if(temp1[kk]==a) temp1[kk]=b;
            }
        }
        for(int k=j-1;k>=0;k--)
        {
            int a=s[k][0],b=s[k][1];
            for(int kk=0;kk<100;kk++)
            {
                if(temp2[kk]==a) temp2[kk]=b;
            }
        }
        int bo=0;
        for(int k=0;k<100;k++)
        {
            for(int kk=0;kk<100;kk++)
            {
                if(temp1[k]==temp2[kk]) break;
                else if(kk==99&&temp1[k]!=temp2[kk]) bo=1;
            }
        }
        for(int k=0;k<100;k++)
        {
            for(int kk=0;kk<100;kk++)
            {
                if(temp2[k]==temp1[kk]) break;
                else if(kk==99&&temp2[k]!=temp1[kk]) bo=1;
            }
        }
        if(bo==1) printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
    return 0;
}
