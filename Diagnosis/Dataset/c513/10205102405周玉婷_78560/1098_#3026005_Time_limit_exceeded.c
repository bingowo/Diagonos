#include <stdio.h>

int map[101];
void MAP(int i,char c)
{
        switch(c)
        {
        case 'R':
        map[i]=1;break;
        case 'B':
        map[i]=2;break;
        case 'Y':
        map[i]=3;break;
        case 'G':
        map[i]=4;break;
        case '!':
        map[i]=0;break;
        }
        return ;
}


void count(int len,int* num)
{
int flag=1;
    while(flag==1)
    {
    flag=0;
    for(int i=0; i<len-3; i++)
    {
        int sum=map[i]+map[i+1]+map[i+2]+map[i+3];
        int res=10-sum;
        if(res==0) continue;//没有坏的灯
        else if(res<=4)//有且只有1个灯坏了
        {
            if(map[i]==0) map[i]=res;
            else if(map[i+1]==0) map[i+1]=res;
            else if(map[i+2]==0) map[i+2]=res;
            else map[i+3]=res;
            num[res]=num[res]+1;
            flag=1;
        }
        else {flag=1;continue;}//有多个灯连续坏了，暂无法判断
    }
    }
    return ;
}
int main()
{    
    int t;
    scanf("%d",&t);
    for(int j=0; j<t; j++)
    {/************ input *************/
    int len=0;
    char c=getchar();
    c=getchar();
    for(int i=0; c!='\n'; i++)//将灯映射成数字
    {
        MAP(i,c);
        len++;
        c=getchar();
    }
   /************** compute *************/
    int num[5]={0};//记录各种灯坏的个数
    count(len,num);
   /************** output **************/
    printf("case #%d:\n",j);
    for(int i=1; i<5; i++)
    {
        printf("%d%c",num[i],i==4?'\n':' ');
    }
    }
    return 0;
}