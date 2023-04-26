#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        char a[3][3],b[5][5]={0};
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                scanf("%d",&a[j][k]);
            }
        }
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                b[j+1][k+1]+=a[j][k];
                b[j][k+1]+=a[j][k];
                b[j+1][k]+=a[j][k];
                b[j+2][k+1]+=a[j][k];
                b[j+1][k+2]+=a[j][k];
            }
        }
        for(int j=1;j<4;j++)
        {
            for(int k=1;k<4;k++)
            {
                printf("%d ",(b[j][k]+1)%2);
            }
            printf("\n");
        }
    }
}
