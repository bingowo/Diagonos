#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int absll(long long int a)
{
    return a>0?a:-a;
}
void fan(char s[])
{
    int len=strlen(s);
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        char c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
long long int maxxy(long long int x,long long int y)
{
    if(absll(x)>absll(y))return 1;
    else return 0;
}
int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    int r;
    if(x==0&&y==0)r=0;
    else if((absll(x)+absll(y))%2==0)
        r=-1;
    else
    {
        long long int ans=absll(x)+absll(y)+1;
        double b=log2(ans);
        int i=(int)b;
        for(int j=i;j<i+2;j++)
        {
            if(j>=b&&j<b+1){r=j;break;}
        }
    }
    printf("%d\n",r);
    if(r!=-1)
    {
        char ret[42]={0};
        int cnt=0;
        while(x!=0||y!=0)
        {
            if(maxxy(x,y))
            {
                if(x>0)
                {
                    x=x-pow(2,r-1);
                    ret[cnt++]='E';
                    r--;
                }
                else
                {
                    x=x+pow(2,r-1);
                    ret[cnt++]='W';
                    r--;
                }

            }
            else
            {
                if(y>0)
                {
                    y=y-pow(2,r-1);
                    ret[cnt++]='N';
                    r--;
                }
                else
                {
                    y=y+pow(2,r-1);
                    ret[cnt++]='S';
                    r--;
                }

            }
        }
        fan(ret);
        printf("%s",ret);
    }

return 0;
}
