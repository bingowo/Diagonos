#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int drop;
    int breadth;
}VAL;


int cmp(const void*s1,const void*s2)
{
    return *(int*)s1 - *(int*)s2;
}
int GCD(int a,int b)
{
    int temp;
    if(a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    int remainder;
    do
    {
        remainder = a % b;
        if(remainder == 0)
            return b;
        a = b;
        b = remainder;
    }while(remainder != 0);
    return b;
}
int main()
{
    int n,s,*valley,i;
    VAL*val;
    //drop是相邻两高度的落差,breath是相同高度
    //地形延续的长度
    int count = 0;
    //count用于记录有几个高度差

    int height = 0;
    //输出height

    //输入部分
    scanf("%d %d",&n,&s);
    valley = (int*)malloc(n*sizeof(int));
    val = (VAL*)malloc(n*sizeof(VAL));
    for(i = 0;i < n;i++)
    {
        scanf("%d",&valley[i]);
    }

    qsort(valley,n,sizeof(int),cmp);

    for(i = 1;i < n;i++)
    {
        //高度处理
        //val[count].drop = valley[i] - valley[i - 1];
        //if(val[count].drop == 0)
        //    breadth++;
        if(valley[i] == valley[i - 1])
        {
            continue;
        }
        else
        {
            val[count].drop = valley[i] - valley[i - 1];
            val[count].breadth = i;
            count++;
        }
    }
    val[count].drop = 1000000;
    val[count].breadth = i; 
    i = 0;
    if(s <= val[i].drop * val[i].breadth)
    {
        int common = GCD(s,val[i].breadth);
        if(val[i].breadth/common == 1)
            printf("%d",valley[0] + (s/common)/(val[i].breadth/common));
        else
            printf("%d+%d/%d",valley[0],s/common,val[i].breadth/common);
        return 0;
    }
    else
    {
        while(s > val[i].breadth * val[i].drop)
        {
            s -= val[i].breadth * val[i].drop;
            height += val[i].drop;
            i++;
        }
    }
    height += valley[0];

    //小数处理部分
    int common = GCD(s, val[i].breadth);
    if(val[i].breadth/common == 1)
        printf("%d",valley[0] + (s/common)/(val[i].breadth/common));
    else
        printf("%d+%d/%d",valley[0],s/common,val[i].breadth/common);
    return 0;
    free(valley);
    free(val);
    return 0;
}
