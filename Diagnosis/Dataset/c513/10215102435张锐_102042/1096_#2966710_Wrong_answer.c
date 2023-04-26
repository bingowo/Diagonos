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
        int s[105][2]={0};int j;
        for(j=0;j<n;j++)
        {
            scanf("%d%d",&s[j][0],&s[j][1]);
        }
        int bo=0;
        for(int k=0;k<j;k++)
        {
            for(int kk=0;kk<j;kk++)
            {
                if(s[k][0]==s[kk][0]) bo=1;
            }
        }
        for(int k=0;k<j;k++)
        {
            for(int kk=0;kk<j;kk++)
            {
                if(k!=kk&&s[k][1]==s[kk][0]) bo=1;
            }
        }
        for(int k=0;k<j;k++)
        {
            for(int kk=0;kk<j;kk++)
            {
                if(s[k][1]==s[kk][1]) bo=1;
            }
        }
        if(bo==1) printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
    return 0;
}
