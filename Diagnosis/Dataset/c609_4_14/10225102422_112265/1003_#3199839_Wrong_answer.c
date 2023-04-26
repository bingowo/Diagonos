#include<stdio.h>
int main()
{
    int n;
    int exchange[10];
    scanf("%d",&n);
    int i,j,index;
    for(i=0;i<n;i++)
    {
        long long num;
        while(num!=0)
        {
            exchange[j]=num%2333;
            num=num/2333;
            j++;
        }
        for(index=j-1;index>=0;index--)
        printf("%d ",exchange[index]);
        printf("\n");
        j=0;
    }
    return 0;
}