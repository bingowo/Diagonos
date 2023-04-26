#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int j = 0; j < t; j++)
    {
        int n,m;
        scanf("%d %d", &n, &m);
        printf("case #%d:\n",j);
        printf("0.");
        int arr[100] = {0}, flag = 0;
        for(int i = 0; !flag; i++)
        {
           if(n != 0)
           {
               if(arr[n])//余数重复出现,计算结束
               { printf("\n%d-%d\n",arr[n],i);flag = 1; }
               else//计算商，储存余数对应的商的位置，计算下一轮的余数
               { printf("%d",n*10/m); arr[n]=i+1; n=n*10%m; }
           }
           else  //余数为零，计算结束
           { printf("\n");  flag = 1; }
        }
    }
    return 0;
}