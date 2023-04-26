#include<stdio.h>
#include<string.h>
#include<math.h>
char s[10000];
int i=0;

void dire(long long x,long long y,long long r)
{
    long long a=llabs(x);//long long的绝对值用llabs
    long long b=llabs(y);
    if(r)
    {
        if(a>b)
        {
            if(x>0)
            {
                s[i++]='E';
                dire(x-pow(2,r-1),y,r-1);
            }
            else
            {
                s[i++]='W';
                dire(x+pow(2,r-1),y,r-1);
            }
        }
        else
        {
            if(y>0)
            {
                s[i++]='N';
                dire(x,y-pow(2,r-1),r-1);
            }
            else
            {
                s[i++]='S';
                dire(x,y+pow(2,r-1),r-1);
            }
        }
    }
}

int main()
{
    long long x,y,r;
    scanf("%lld%lld",&x,&y);
    long long sum=llabs(x)+llabs(y);
    if(x==0&&y==0) printf("0");
    else if(sum%2==0) printf("-1");//如果是偶数，则不能到达
    else
    {for(r=0;r<45;r++)
    {
        if(sum>=pow(2,r-1)&&sum<=pow(2,r)) break;
    }
    printf("%lld\n",r);
    dire(x,y,r);
    int j;
    char t;
    for(j=0;j<=(i-1)/2;j++)
    {
        t=s[j];
        s[j]=s[i-1-j];
        s[i-1-j]=t;
    }
    printf("%s\n",s);
    }
    return 0;
}
