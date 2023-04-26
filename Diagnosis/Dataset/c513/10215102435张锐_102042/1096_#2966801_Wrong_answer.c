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
        int bo=0,a=0,b=0;
        for(int k=0;k<j;k++)
        {
            a=0;b=0;
            for(int kk=0;kk<j;kk++)
            {
                if(k!=kk&&s[k][0]==s[kk][0]) a++;
                if(s[k][0]==s[kk][1]) b++;
            }
            if(a>=1||b>=1) bo=1;
        }
        if(bo==1) printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
    return 0;
}
