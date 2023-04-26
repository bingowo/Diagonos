#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define N 101

typedef struct a
{
    long long x;
    long long y;
}pos;


int solution(long long r,long long t);//判断是否有解
int main()
{
    char s[N];
    long long i,j;
    long long q;
    long long a,b;
    long long x0=0,y0=0;

    scanf("%s",s);
    int len=strlen(s);
    pos *p = (pos*)malloc(sizeof(pos)*(len+1));
    p[0].x=0;p[0].y=0;
    for (i=0;i<len;++i)
    {
       switch (s[i])
       {
           case 'U':
              p[i+1].y=p[i].y+1;
              y0+=1;   
              break;
           case 'D':
              p[i+1].y=p[i].y-1;
              y0-=1;
              break;
           case 'L':
              p[i+1].x=p[i].x-1;
              x0-=1;
              break;
           case 'R':
              p[i+1].x=p[i].x+1;
              x0+=1;
              break;
       }

    }
    scanf("%lld",&q);
    for (i=0;i<q;++i)
    {
        scanf("%lld %lld",&a,&b);
        long long m1,m2;
        int flag=0;
        for (j=0;j<=len;++j)
        {
            m1=solution(a-p[j].x,x0);
            m2=solution(b-p[j].y,y0);
            if (m1==-2 || m2==-2 )
            {
                continue;
            }
            else if (m1==-1 || m2==-1 || m1==m2)
            {
                flag=1;break;
            }
        }
        if (flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    free(p);
    return 0;
}

int solution(long long r,long long t)
{
    if (r!=0 && t==0) return -2;
    else if (r==0 && t==0) return -1;
    else if (r%t!=0 && r/t<0) return -2;
    return r/t;
}