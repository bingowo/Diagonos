#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        int data=pow(2,m);
        printf("case #%d:\n",i);
        printf("%d\n",data);
    }
    return 0;
}