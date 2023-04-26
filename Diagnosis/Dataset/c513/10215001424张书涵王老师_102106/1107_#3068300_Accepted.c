#include <stdio.h>
#include <stdlib.h>

void light_change(int change_num,int light[3][3],int i,int j)
{
    int change_or_not=0;
    change_or_not=change_num%2;
    if(change_or_not==1)
    {
        light[i][j]=1-light[i][j];
        if((i-1)>=0)
            light[i-1][j]=1-light[i-1][j];
        if((i+1)<3)
            light[i+1][j]=1-light[i+1][j];
        if((j-1)>=0)
            light[i][j-1]=1-light[i][j-1];
        if((j+1)<3)
            light[i][j+1]=1-light[i][j+1];
    }
}

int main()
{
    int T,question_num;
    scanf("%d",&T);
    for(question_num=0;question_num<T;question_num++)
    {
        int change_num[3][3]={0};
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                scanf("%d",&change_num[i][j]);
        }
        int light[3][3];
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                light[i][j]=1;
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                light_change(change_num[i][j],light,i,j);
        }
        printf("case #%d:\n",question_num);
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                printf("%d ",light[i][j]);
            printf("\n");
        }
    }
}