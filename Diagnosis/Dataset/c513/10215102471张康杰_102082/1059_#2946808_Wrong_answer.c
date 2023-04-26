#include <stdio.h>
#include <stdlib.h>
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
    int n,s,*valley,i,drop;
    //drop是相邻两高度的落差,breath是相同高度
    //地形延续的长度

    double height = 0;
    //输出height

    //输入部分
    scanf("%d %d",&n,&s);
    valley = (int*)malloc(n*sizeof(int));
    for(i = 0;i < n;i++)
    {
        scanf("%d",&valley[i]);
    }

    qsort(valley,n,sizeof(int),cmp);

    for(i = 1;i < n;i++)
    {
        int breadth = 1,volumn;
        drop = valley[i] - valley[i - 1];
        if(drop == 0)
            breadth++;
        volumn = breadth*drop;
        if(s >= volumn)
        {
            height += drop;
            s -= volumn;
        }
        else
        {
            height += s/(i + 1);
            break;
        }
        int int_part = (int)height;
        double double_part = height - int_part;
        if(double_part == 0)
        {
            printf("%d",int_part);
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
        

    }




}