#include<stdio.h>
#include<string.h>

int main()
{
    long long int n;     //点数
    scanf("%lld",&n);
    getchar();
    long long int index;
    long long int array[n];
    long long int sum = 0;
    for(index = 0;index < n;index++)
        scanf("%lld",&array[index]);
    long long int i,j,hold;
    for(j = n-1;j>0;j--)             //冒泡排序，从小到大
    {
        for(i = 0;i<j;i++)
        {
            if(array[i] > array[i+1])
            {
                hold = array[i];
                array[i] = array[i+1];
                array[i+1] = hold;
            }
        }
    }
    long long int k,digit;
    digit = n/2;
    for(k=0;k<digit;k++)
    {
        sum += (array[2*k+1] - array[2*k]);
    }
    printf("%lld",sum);
    return 0;
}