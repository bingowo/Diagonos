#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long int n;
        scanf("%d",&n);
        int temp[20];
        temp[0]=0;
        int j=0;
        while(n!=0)
        {
            temp[j]=n%2333;
            n=n/2333;
            j++;
        }
        j--;
        for(j;j>0;j--)  printf("%d ",temp[j]);
        printf("%d\n",temp[0]);
    }
    return 0;
}