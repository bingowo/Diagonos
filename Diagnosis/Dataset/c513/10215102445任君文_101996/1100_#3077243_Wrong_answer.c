#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct point
{
    int a,b;
};
int solution(int x,int a,int y,int b)
{
    if((x==a)&&(y==b))
        return 1;
    else
        return 0;
}
int main()
{
    int i,j;
    int m1,m2;
    int len=0,flag,q,a,b;
    struct point pos[200];
    char s[200];
    scanf("%s",s);
    len=strlen(s);
    pos[0].a=0;
    pos[0].b=0;
    for(i=1;i<=len;i++)
    {
        switch(s[i-1])
        {
            case 'U':pos[i].a=pos[i-1].a;pos[i].b=pos[i-1].b+1;break;
            case 'D':pos[i].a=pos[i-1].a;pos[i].b=pos[i-1].b-1;break;
            case 'L':pos[i].a=pos[i-1].a-1;pos[i].b=pos[i-1].b;break;
            case 'R':pos[i].a=pos[i-1].a+1;pos[i].b=pos[i-1].b;break;
        }
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        flag=0;
        scanf("%d%d",&a,&b);
        if((a==0)&&(b==0))
            printf("Yes\n");
        else
        {
            for(j=0; j<=len; j++)
            {
                m1=solution(pos[len].a,a,pos[j].b,b);
                if (m1==0) 
                    continue;
                if (m1!=0)
                { 
                    flag=1; 
                    break; 
                }
            }
            if(flag) 
                printf("Yes\n");
            else 
                printf("No\n");
        }
    }
    return 0;
}