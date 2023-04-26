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
        while(m%5==0)
        {count++;
        m/=5;}
        printf("case #%d:\n",i);
        printf("%d\n",count);
    }
    return 0;
}