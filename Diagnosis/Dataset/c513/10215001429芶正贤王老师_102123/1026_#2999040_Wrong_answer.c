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
    int max;
    
    for(i = n;i > 0;i--)
    {
        for(j = 0;j<i-1;j++)
        {
            if(array[j] > array[j+1])
                max = j;
            else 
                max = j+1;
        }
        if(max != i)
        {
            hold = array[i];
            array[i] = array[max];
            array[max] = hold;
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