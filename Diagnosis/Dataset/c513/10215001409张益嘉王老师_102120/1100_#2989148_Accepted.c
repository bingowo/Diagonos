#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
}Point;

int firstpl(char s[],Point pos[])
{
    int i=0,j=0,k,len=strlen(s),co=1;
    pos[0].x=i;
    pos[0].y=j;
    for(k=0;k<len;k++)
    {
        switch(s[k])
        {
            case 'U':{j++;pos[co].x=i;pos[co].y=j;co++;}break;
            case 'D':{j--;pos[co].x=i;pos[co].y=j;co++;}break;
            case 'R':{i++;pos[co].x=i;pos[co].y=j;co++;}break;
            case 'L':{i--;pos[co].x=i;pos[co].y=j;co++;}break;
            default:break;
        }
    }
    return co;
}

int solution(int zi,int mu)
{
    //printf("zi=%d,mu=%d\n",zi,mu);
    if((mu==0)&&(zi!=0)) return -2;
    else if((zi==0)&&(mu==0)) return -1;
    else if((zi/mu<0)||(zi%mu!=0)) return -2;
    else return zi/mu;
}

int main()
{
    char s[120];
    memset(s,0,sizeof(char)*120);
    scanf("%s",s);
    int q,i,co,j,isyes;
    scanf("%d",&q);
    Point pos[120];
    co=firstpl(s,pos);
    int x0=pos[co-1].x;
    int y0=pos[co-1].y;
    //printf("x0=%d,y0=%d\n",x0,y0);
    //printf("co=%d\n",co);
    for(j=0;j<q;j++)
    {
        int a,b;
        //printf("s=%s\n",s);
        scanf("%d%d",&a,&b);
        isyes=0;
        for(i=0;i<co;i++)
        {
            int m1,m2;
            m1=solution(a-pos[i].x,x0);
            m2=solution(b-pos[i].y,y0);
            //printf("m1=%d,m2=%d\n",m1,m2);
            if((m1==-2)||(m2==-2))continue;
            else if((m1==-1)||(m2==-1)||(m1==m2)) isyes=1;
        }
        if(isyes) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
