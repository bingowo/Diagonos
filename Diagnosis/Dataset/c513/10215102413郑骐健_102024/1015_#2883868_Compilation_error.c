#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int s[25];
long long smp(long long a,long long b)
{
    return (a%b == 0)?b:smp(b,a%b);
}
int main()
{
    memset(s,0,sizeof(int )*25);
    s[0] = 2;
    int point =1;
    for(int n = 3;n<30000;n++)
    {
        int judge = 1;
        for (int z =0;z<point;z++)
        {
            if(n%s[z] == 0)
            {
                judge = 0;
                break;
            }
        }
        if(judge) s[point++] = n;
            if(point == 25) break;
    }//储存素数
    /*for(int q = 0;q<25;q++)
    {
        printf("%lld ",s[q]);
    }*/
    int quiz;
    scanf("%d",&quiz);
    for(int i = 0;i<quiz;i++)
    {
        char p [30];
        int a[30];
        int b[30];
        scanf("%s",p);
        for(int n = strlen(p);n)
    }
    
    return 0;
}
