#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int x;
    int y;
}point;
point p[150];
int x1=0,y1=0;
void weizhi(char s[150])
{
    int i=0;
    for(i=0;s[i];i++)
    {   p[i].x=0;p[i].y=0;
        switch(s[i])
        {
            case 'U':if(i==0){p[i].x=0;p[i].y=1;}else{p[i].x=p[i-1].x;p[i].y=p[i-1].y+1;}break;
            case 'D':if(i==0){p[i].x=0;p[i].y=-1;}else{p[i].x=p[i-1].x;p[i].y=p[i-1].y-1;}break;
            case 'L':if(i==0){p[i].x=-1;p[i].y=0;}else{p[i].x=p[i-1].x-1;p[i].y=p[i-1].y;}break;
            case 'R':if(i==0){p[i].x=1;p[i].y=0;}else{p[i].x=p[i-1].x+1;p[i].y=p[i-1].y;}break;
        }
    }
    return;
}
int solution(int t,int r)
{
    if (t==0&&r!=0) return -2;
    if (t==0&&r==0) return -1;
    if (r%t!=0||r/t<0) return -2;
    return r/t;
}

int main()
{
    char s[150]={0};
    scanf("%s",s);
    weizhi(s);
    int n=0,i=0;
    int j=strlen(s)-1;
    x1=p[j].x;y1=p[j].y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int a=0,b=0,l=0,flag=0,m1=0,m2=0;
        scanf("%d %d",&a,&b);
        for(l=0;l<=j;l++)
        {    m1=solution(-p[j].x,p[l].x-a);
            m2=solution(-p[j].y,p[l].y-b);
            if (m1 == -2||m2 == -2) continue;
            if (m1 == -1||m2 == -1||m1 == m2)
            {   flag=1;  break;  }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}
