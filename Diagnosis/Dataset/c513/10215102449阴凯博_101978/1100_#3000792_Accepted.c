#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int a,b;
}POINT;

int solution(int t,int r)
{
    if (t==0 && r!=0) return -2;
    if (t==0 && r==0) return -1;
    if (r%t!=0 || r/t<0) return -2;
    return r/t;
}

int main()
{
    POINT pos[200];
    char s[200];
    int len,i;
    scanf("%s",s); len=strlen(s);
    pos[0].a=0; pos[0].b=0;
    for (i=1;i<=len;i++)
    {
        switch(s[i-1])
        {
        case 'U':
            pos[i].a=pos[i-1].a; pos[i].b=pos[i-1].b+1;
            break;
        case 'D':
            pos[i].a=pos[i-1].a; pos[i].b=pos[i-1].b-1;
            break;
        case 'L':
            pos[i].a=pos[i-1].a-1; pos[i].b=pos[i-1].b;
            break;
        case'R':
            pos[i].a=pos[i-1].a+1; pos[i].b=pos[i-1].b;
            break;
        }
    }
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++)
    {
        int flag=0, a, b;
        scanf("%d %d",&a,&b);
        for (int j=0;j<len;j++)
        {
            int m1=solution(-pos[len].a,pos[j].a-a);
            int m2=solution(-pos[len].b,pos[j].b-b);
            if (m1==-2 || m2==-2) continue;
            if (m1==-1 || m2==-1 || m1==m2)
            {
                flag=1;
                break;
            }
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
