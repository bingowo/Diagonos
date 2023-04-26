#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i=0;
    char arr[10][30];
    int rslt[10];
    scanf("%d",&t);
    while(i<t){scanf("%s",*(arr+i));i++;}
    for(int j=0;j<i;j++)
    {
        int sum=arr[j][0]-'0';
        for(int k=1;arr[j][k];k++)
        {
            sum=arr[j][k]=='-'?sum*3-1:sum*3+arr[j][k]-'0';
        }
        rslt[j]=sum;
    }
    //while(--i>=0)printf("%s",arr[i]);
    for(i=0;i<t;i++)printf("case #%d:\n%d\n",i,rslt[i]);
    return 0;
}
