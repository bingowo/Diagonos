#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int f(int x,int y)
{
    int cnt=0;
    for(int i=0;i<32;i++)
    {
        if((x&1)!=(y&1))cnt++;
        x>>=1;y>>=1;
    }


    return cnt;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
       // printf("case #%d:\n",i);
       int x,y;
       scanf("%d%d",&x,&y);
       printf("%d\n",f(x,y));
    }

}
