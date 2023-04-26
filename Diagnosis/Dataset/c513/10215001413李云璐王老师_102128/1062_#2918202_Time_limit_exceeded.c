#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int bushu(int a)
{
    if(a==0) return 0;
    if(a==1) return 1;
    if(a==2) return 2;
    if(a==3) return 4;
    if(a==4) return 8;
    if(a>4) return bushu(a-1)+bushu(a-2)+bushu(a-3)+bushu(a-4);
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d\n",&a);
        b=bushu(a);
        printf("case #%d:\n",i);
        printf("%d\n",b);
    }
    return 0;
}