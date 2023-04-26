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
           if(n == 0) 
           { printf("\n");  flag = 1; }
           else
           {
               if(arr[n])//余数重复出现
               { printf("\n%d-%d",arr[n],i);flag = 1; }
               else
               { printf("%d",n/m); n=n*10%m; }
           }
        }
    }
    return 0;
}