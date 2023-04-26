#include<stdio.h>
int main(void)
{
    int light[3][3]={0};
    int map[3][3]={1};
    int t=0,i=0,j=0,p=0;
    scanf("%d\n",&t);
    for(i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        for(j=0;j<3;j++)
        {
            for(p=0;p<3;p++)
            {
                light[j][p]=map[j][p]+map[j+1][p]+map[j][p+1]+map[j-1][p]+map[j][p-1];
                if(light[j][p]%2==0) printf("1%c",p==2?'\n':' ');
                else printf("0%c",p==2?'\n':' ');
            }
        }
    }
    return 0;
}