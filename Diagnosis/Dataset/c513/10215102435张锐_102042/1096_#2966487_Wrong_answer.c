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
        int p1=0,p2=0;
        for(int k=0;k<j;k++)
        {
            int a=s[k][0],b=s[k][1];
            for(int kk=0;kk<=p1;kk++)
            {
                if(temp1[kk]==a) temp1[kk]=b;
                else if(kk==p1&&temp1[kk]!=a) {temp1[p1++]=b;break;}
            }
        }
        for(int k=j-1;k>=0;k--)
        {
            int a=s[k][0],b=s[k][1];
            for(int kk=0;kk<=p2;kk++)
            {
                if(temp2[kk]==a) temp2[kk]=b;
                else if(kk==p2&&temp2[kk]!=a) {temp2[p2++]=b;break;}
            }
        }
        int bo=0;
        for(int k=0;k<=p1;k++)
        {
            for(int kk=0;kk<=p2;kk++)
            {
                if(temp1[k]==temp2[kk]) {temp1[k]=0,temp2[kk]=0;break;}
                else if(kk==p2&&temp1[k]!=temp2[kk]) bo=1;
            }
        }
        for(int k=0;k<=p1;k++) {if(temp1[k]!=0) {bo=1;break;}}
        for(int k=0;k<=p2;k++) {if(temp2[k]!=0) {bo=1;break;}}
        if(bo==1) printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
    return 0;
}
