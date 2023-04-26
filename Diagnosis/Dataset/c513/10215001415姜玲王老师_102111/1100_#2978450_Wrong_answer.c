#include <stdio.h>
#include <stdlib.h>
typedef struct{long long a;long long b;}point;
void execute(char c,point*d)
{
    if(c=='U') d->b++;
    if(c=='D') d->b--;
    if(c=='L') d->a--;
    if(c=='R') d->a++;
}
long long min(long long c,long long d)
{if(c>d) return d;
return c;}
int main()
{
    char f[101];
    scanf("%s",f);
    point s;
    s.a=0;
    s.b=0;
    for(int z=0;z<strlen(f);z++)
    {
        execute(f[z],&s);
    }
        long long q, i,j;
        scanf("%lld",&q);
        for(i=0;i<q;i++)
        {
            point c,d;
            d.a=0;
            d.b=0;
            int flag=0;
            long long y;
            scanf("%lld%lld",&c.a,&c.b);
            if(s.a&&s.b){y=min(c.a/s.a,c.b/s.b);c.a=c.a-y*s.a;c.b=c.b-y*s.b;}
            if(c.a==0&&c.b==0){printf("Yes\n");continue;}
            for(j=0;j<strlen(f);j++)
            {execute(f[j],&d);
            if(d.a==c.a&&d.b==c.b){printf("Yes\n");flag++;break;}
            }
            if(flag) continue;
            printf("No\n");
        }

}
