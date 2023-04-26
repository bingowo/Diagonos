#include<stdio.h>
#include<string.h>
int sgn(long long int n)
{
    if(n>0) return 1;
    if(n<0) return -1;
    return 0;
}
int main()
{
    char s[200];
    scanf("%s",s);
    long long int dx=0,dy=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='U') dy++;
        if(s[i]=='D') dy--;
        if(s[i]=='L') dx--;
        if(s[i]=='R') dx++;
    }
    int n;
    scanf("%d",&n);
    long long int x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&x,&y);
        long long int tx=0,ty=0;
        int test=0;
        if(x==0&&y==0)
        {
            printf("Yes\n");
            continue;
        }
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]=='U') ty++;
            if(s[j]=='D') ty--;
            if(s[j]=='L') tx--;
            if(s[j]=='R') tx++;
            long long int p,q;
            p=x-tx;
            q=y-ty;
            if(dx==0&&dy==0)
            {
                if (x-tx==0&&y-ty==0)
                {
                    test=1;
                    break;
                }
            }
            else if(dx==0||dy==0)
            {
                if(dx==0)
                {
                    if(x-tx==0&&(y-ty)%dy==0)
                    {
                        if(sgn(y-ty)==sgn(dy)||y-ty==0)
                        {
                        test=1;
                        break;
                        }
                    }
                }
                else
                {
                    if(y-ty==0&&(x-tx)%dx==0)
                    {
                        if(sgn(x-tx)==sgn(dx)||x-tx==0)
                        {
                        test=1;
                        break;
                        }
                    }
                }
            }
            else
            {
                if((x-tx)%dx==0&&(y-ty)%dy==0)
                {
                    if((sgn(x-tx)==sgn(dx))&&(sgn(y-ty)==sgn(dy)))
                    {
                        test=1;
                        break;
                    }
                }
            }

        }
        if(test==1) printf("Yes\n");
        else printf("No\n");
    }
}