#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int mm=0; mm<cnt; mm++)
    {
        int L[3][3];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++) L[i][j]=1;
        }
        int num[3][3];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++) scanf("%d",&num[i][j]);
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(num[i][j]%2==1){
                    if(i-1>=0) L[i-1][j]=L[i-1][j]^1;
                    if(i+1<3) L[i+1][j]=L[i+1][j]^1;
                    if(j-1>=0) L[i][j-1]=L[i][j-1]^1;
                    if(j+1<3) L[i][j+1]=L[i][j+1]^1;
                    L[i][j]=L[i][j]^1;
                }
            }
        }
        printf("case #%d:\n",mm);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                printf("%d%c",L[i][j],j==2?'\n':' ');
            }
        }
    }
    return 0;
}