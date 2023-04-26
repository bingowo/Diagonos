#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int m,count=0;
        scanf("%d",&m);
        for(int k=1;k<=m;k++)
        {while(k%5==0)
        {count++;
        k/=5;}}
        printf("case #%d:\n",i);
        printf("%d\n",count);
    }
    return 0;
}