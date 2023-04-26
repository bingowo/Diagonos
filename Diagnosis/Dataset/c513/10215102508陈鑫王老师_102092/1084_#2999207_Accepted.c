#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int num=pow(2,n);
        printf("case #%d:\n%d\n",i,num);
    }
    return 0;
}
