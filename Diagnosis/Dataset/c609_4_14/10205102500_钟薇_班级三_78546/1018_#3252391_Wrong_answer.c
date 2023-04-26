#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    int i;
    scanf("%d",&n);
    long long int num[10000];
    for(i=0;i<n;i++)    scanf("%d",&num[i]);
    
    ///排序///
    int j;
    int flag=0;
    while (flag==0)
    {
        flag=1;
        for(j=0;j<i;j++)
        {
            if(num[j]>num[j+1])
            {
                int temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
                flag=0;
            }
        }
    }

    long long int sum=0;
    for(j=0;j<i;j=j+2)  sum=sum+abs(num[j]-num[j+1]);
    printf("%lld",sum);
    return 0;
}