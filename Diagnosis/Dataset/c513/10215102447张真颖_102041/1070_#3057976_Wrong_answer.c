#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int f1,f0;//记录每一组末尾为1和0的分别种类数
}TYPE;
TYPE arr[21]={0,0};

TYPE init(TYPE x)
{
    TYPE y={0,0};
    y.f1=x.f1;
    y.f0=x.f0;
    return y;
}

TYPE count(int n)
{
    if(n==1) return arr[1];
    else if(n==2) return arr[2];
    else
    {
        TYPE x1={0,0},x2={0,0};
        if(arr[n-1].f0==0)
            x1=init(count(n-1));
        else x1=init(arr[n-1]);
        if(arr[n-2].f0==0)
            x2=init(count(n-2));
        else x2=init(arr[n-2]);
        arr[n].f0=x1.f1+x1.f0;
        arr[n].f1=arr[n].f0-x2.f1;
        return arr[n];
    }
}

int main()
{
    int n=0;

    arr[1].f1=1,arr[0].f0=1;
    arr[2].f1=2,arr[2].f0=2;//初始化数组

    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        TYPE re=count(n);
        printf("%d\n",re.f1+re.f0);
    }
    return 0;
}