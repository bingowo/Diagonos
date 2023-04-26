#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int f=0;f<t;f++)
    {
        int a[3][3],b[3][3];
        for(int k=0;k<3;k++)
        {
            for(int kk=0;kk<3;kk++)
            {
                a[k][kk]=1;
            }
        }
        for(int k=0;k<3;k++)
        {
            for(int kk=0;kk<3;kk++)
            {
                scanf("%d",&b[k][kk]);
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                while(b[i][j])
                {
                    b[i][j]--;a[i][j]++;
                    if(i+1<3) a[i+1][j]++;
                    if(j+1<3) a[i][j+1]++;
                    if(i-1>=0) a[i-1][j]++;
                    if(j-1>=0) a[i][j-1]++;
                }
            }
        }
        printf("case #%d:\n",f);
        for(int k=0;k<3;k++)
        {
            for(int kk=0;kk<3;kk++)
            {
                if(a[k][kk]%2==0) printf("0");
                if(a[k][kk]%2==1) printf("1");
                if(kk!=2) printf(" ");
                if(kk==2) printf("\n");
            }
        }
    }
    return 0;
}
