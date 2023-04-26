#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    int arr[n];
    int i=0;
    for(;i<n;i++)
        scanf("%d ",&arr[i]);//输入需排列的数组
    int m=1;
    for(;m<n;m++)
    {
        int temp=arr[m];
        if(arr[m]>arr[m-1])
        {
            int j=m-1;
            for(;j>=0&&arr[j]<temp;j--)
            arr[j+1]=arr[j];//小数后移
            arr[j]=temp;//填充
        }

    }
    int l=0;
    for(int b=0;b<(i-1);b=b+2)
    {
        l=l+(arr[b]-arr[b+1]);
    }
    printf("%d",l);
    return 0;
}