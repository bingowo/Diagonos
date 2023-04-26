#include<stdio.h>
#include<math.h>

int main()
{
    int n,num,i;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&num);
        printf("%case #%d:\n",i);
        printf("%d\n",(int)pow(2,num));
    }
    return 0;
}