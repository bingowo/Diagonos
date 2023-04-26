#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point
{
    int a,b;
}p[200];

int solution(int t,int r) //单个方程求解m
{
    if(t==0&&r!=0) return -2; //无解
    if(t==0&&r==0) return -1; //任意解
    if(r%t!=0||r/t<0) return -2; //非法解
    return r/t;
}
int main()
{
    char s[200];
    scanf("%s",s);
    int len=strlen(s);
    p[0].a=0;p[0].b=0;
    int i,j;
    for(i=1;i<=len;i++)
    {
        switch(s[i-1])
        {
            case 'U':
                p[i].a=p[i-1].a;
                p[i].b=p[i-1].b+1;
                break;
            case 'D':
                p[i].a=p[i-1].a;
                p[i].b=p[i-1].b-1;
                break;
            case 'L':
                p[i].a=p[i-1].a-1;
                p[i].b=p[i-1].b;
                break;
            case 'R':
                p[i].a=p[i-1].a+1;
                p[i].b=p[i-1].b;
                break;
        }
    }
    int q,a,b;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        int flag=0;
        scanf("%d %d",&a,&b);
        for(j=0;j<=len;j++)
        {
            int m1=solution(-p[len].a,p[j].a-a);
            int m2=solution(-p[len].b,p[j].b-b);
            if(m1==-2||m2==-2) continue;
            if(m1==-1||m2==-1||m1==m2)
            {
                flag=1;break;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
