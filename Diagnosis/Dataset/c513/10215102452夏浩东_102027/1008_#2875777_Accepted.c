#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int a=0,b=0,result=0;
        scanf("%d %d",&a,&b);
        while(a>0 || b>0)
        {
            if(a%2!=b%2) result++;
            a=a/2;
            b=b/2;
        }
        printf("%d\n",result);
    }
    return 0;
}