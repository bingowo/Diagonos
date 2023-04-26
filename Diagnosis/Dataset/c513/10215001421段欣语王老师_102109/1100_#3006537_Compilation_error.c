#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point
{int a,b;};

struct point pos[200];

char s[200];

int solution(int t,int r)
{
    if(t==0&&r!=0)return -2;
    if(t==0&&r==0)return -1;
    if(r%t!=0||r<t<0)return -2;
    return r/t;
}

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    pos[0].a=0;
    pos[0].b=0;
    for(int i=1;i<=len;i++)
    {
        switch(s[i-1])
        {
            case'U':pos[i].a=pos[i-1].a;pos[i].b=pos[i-1].b+1;break;
            case'D':pos[i].a=pos[i-1].a;pos[i].b=pos[i-1].b-1;break;
            case'L':pos[i].a=pos[i-1].a-1;pos[i].b=pos[i-1].b;break;
            case'R':pos[i].a=pos[i-1].a+1;pos[i].b=pos[i-1].b;break;
        }
        }
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int flag=0,a,b,m1,m2;
        scanf("%d%d",&a,&b);
        for(int j=0;j<=len;j++)
        {
            m1=solution(-pos[len].a,pos[j].a-a);
            m2=solution(-pos[len].b,pos[j].b-b);
            if(m1==-2||m2==-2)continue;
            if(m1==-1||m2==-1||m1==m2)
            {flag=1;break;}
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}