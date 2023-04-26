#include <stdio.h>
#include <stdlib.h>
/*typedef struct node
{
    int num;
    int cnt;
}X;*/
int cl(int a,int b)
{
    int cnt=0;
    while(a||b)
    {
        if(((a&1)!=(b&1)))
            cnt++;
        a=a>>1;
        b=b>>1;
    }
    return cnt;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i;i<t;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",cl(a,b));
    }
    return 0;
}
