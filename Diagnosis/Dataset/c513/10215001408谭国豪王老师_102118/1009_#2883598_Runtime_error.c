#include <stdio.h>
#include <stdlib.h>

int main()
{   int math(char*a);
    int trans(char*b,int j);
    int n,i,last[10],fenzi,fenmu,p;
    char c[10][20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        puts(c[i]);
    }
    for(i=0;i<n;i++)
    {   p=math(c[i]);
        fenmu=math(c[i])*4;
        fenzi=trans(c[i],p);
        last[i]=fenzi/fenmu;
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",last[i]);
    }
    return 0;
}
int math(char*a)
{
    int count=0;
    while(*(a+count))
    {
        count++;
    }
       return count;
}
int trans(char*b,int j)
{
    int t,total=0,now;

    for(t=0;t<j;t++)
    {
        now=(int)(*(b+t));
        while(now)
        {
            if(now%2==1)total++;
            now=now/2;
        }
    }
    return total;

}
