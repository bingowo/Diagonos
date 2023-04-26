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
int main()
{
    char a[100];
    scanf("%s",a);
    point s;
    s.a=0;
    s.b=0;
    for(int i=0;i<strlen(a);i++)
    {
        execute(a[i],&s);
        }
        long long q, i,j;
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            point c,d;
            d.a=0;
            d.b=0;
            int flag=0;
            scanf("%lld%lld",&c.a,&c.b);
            if(c.a==0&&c.b==0)
            {printf("Yes\n");continue;}
            for(j=0;j<strlen(a);j++)
            {execute(a[j],&d);
            if(s.a&&s.b)
            {if((c.a-d.a)%s.a==0&&(c.b-d.b)%s.b==0&&(c.a-d.a)/s.a==(c.b-d.b)/s.b&&(c.a-d.a)/s.a>=0&&(c.b-d.b)/s.b>=0) {printf("Yes\n");flag++;break;}}
            if(s.a&&s.b==0){if((c.a-d.a)%s.a==0&&(c.b-d.b)==0(c.a-d.a)%s.a==0&&(c.a-d.a)/s.a>=0) {printf("Yes\n");flag++;break;}}
            if(s.a==0&&s.b){if((c.a-d.a)==0&&(c.b-d.b)%s.b==0&&(c.b-d.b)/s.b>=0) {printf("Yes\n");flag++;break;}}
            if(s.a==0&&s.b==0){if((c.a-d.a)==0&&(c.b-d.b)==0) {printf("Yes\n");flag++;break;}}}
            if(flag) continue;
            printf("No\n");
        }

}
