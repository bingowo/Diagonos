#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char order[101]={'\0'};
    scanf("%s",&order);
    int x=0,xmax=0,xmin=0,y=0,ymax=0,ymin=0;
    for(int i=0;i<strlen(order);i++)
    {
        if(order[i]=='L') x=x-1;
        else if(order[i]=='R') x=x+1;
        else if(order[i]=='U') y=y+1;
        else if(order[i]=='D') y=y-1;
        if(x>xmax) xmax=x;
        if(x<xmin) xmin=x;
        if(y>ymax) ymax=y;
        if(y<ymin) ymin=y;
    }
    int xmove=xmax+xmin;
    int ymove=ymax+ymin;
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        //printf("case #%d:\n",i);
        int xgoal,ygoal;
        scanf("%d %d",&xgoal,&ygoal);
        x=0;
        y=0;
        int j=0;
        int flag=1;
        while(((x!=xgoal)||(y!=ygoal))&&(flag==1))
        {
            if(order[i]=='L') x=x-1;
            else if(order[i]=='R') x=x+1;
            else if(order[i]=='U') y=y+1;
            else if(order[i]=='D') y=y-1;
            i++;
            if(i==strlen(order))
            {
                i=0;
                if(!(((xgoal>=xmin)&&(xgoal<=xmax))||(xgoal*xmove>0))) flag=0;
                if(!(((ygoal>=ymin)&&(ygoal<=ymax))||(ygoal*ymove>0))) flag=0;
            }
            //printf("x:%d y:%d\n",x,y);
        }
        if(flag==1)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
