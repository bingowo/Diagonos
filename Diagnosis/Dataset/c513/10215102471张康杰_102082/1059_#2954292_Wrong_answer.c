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
    int remainder = a % b;
    a = b;
    b = remainder;
    while(remainder != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;

    }
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

    double height = 0;
    //输出height

    //输入部分
    scanf("%d %d",&n,&s);
    valley = (int*)malloc(n*sizeof(int));
    val = (int*)malloc(n*sizeof(VAL));
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
        height += s/val[i].breadth;
    else
    {
        while(s > val[i].breadth * val[i].drop)
        {
            s -= val[i].breadth * val[i].drop;
            height += val[i].drop;
            i++;
        }
        height += s/val[i].breadth;
    }
    height += valley[0];


    //小数处理部分
    int int_part = (int)height;
    double double_part = height - int_part;
    if(double_part == 0)
    {
        printf("%d",int_part);
        free(valley);
        return 0;
    }
    int mother = 1,son;
    while(double_part < 1)
    {
        double_part *= 10;
        mother *= 10;
    }
    son = double_part;
    int common = GCD(mother, son);
    printf("%d+%d/%d",height,son/common,mother/common);
    free(valley);
    return 0;
}