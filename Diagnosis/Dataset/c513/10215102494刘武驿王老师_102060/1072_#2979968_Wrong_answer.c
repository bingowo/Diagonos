#include<stdio.h>
#include<string.h>
#include<math.h>
long long int jue(long long int a)
{
    return a>0? a:-a;
}
long long int max(long long int a,long long int b)
{
    return jue(a)>jue(b)?a:b;
}
int main()
{
    long long int a,b;
    scanf("%lld %lld",&a,&b);
    long long int dis=((a>0)?a:-a) + ((b>0)?b:-b);
    if(dis%2==0)
    {
        printf("-1");
        return 0;
    }
    int step=0;
    long long int n=1;
    while(n<dis+1)
    {
        n*=2;
        step+=1;
    }
    char path[100];
    int i=0;
    step--;
    while(step+1)
    {
        if(max(a,b)==a)
        {
            if(a<0)
            {
                a+=pow(2,step);
                step--;
                path[i++]='W';
                continue;
            }
            else
            {
                a-=pow(2,step);
                step--;
                path[i++]='E';
                continue;
            }
        }
        else
        {
            if(b<0)
            {
                b+=pow(2,step);
                step--;
                path[i++]='S';
                continue;
            }
            else
            {
                b-=pow(2,step);
                step--;
                path[i++]='N';
                continue;
            }
        }
    }
    for(int j=i-1;j>=0;j--) printf("%c",path[j]);
}