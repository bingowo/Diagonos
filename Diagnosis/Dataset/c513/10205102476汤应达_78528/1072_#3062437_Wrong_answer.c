#include<stdio.h>
#include<math.h>

char path[20];

int get_path(int x,int y,int s,int p,int steps)
{
    int len=(int)pow(2,steps);
    if(x==s && y==p) return steps;
    if(abs(x)<=abs(s) && abs(y)<=abs(p))
    {
        int l=get_path(x,y+len,s,p,steps+1),min=2147483647;
        if(l!=-1 && min>l) {min=l;path[steps]='N';}
        l=get_path(x,y-len,s,p,steps+1);
        if(l!=-1 && min>l) {min=l;path[steps]='S';}
        l=get_path(x-len,y,s,p,steps+1);
        if(l!=-1 && min>l) {min=l;path[steps]='W';}
        l=get_path(x+len,y,s,p,steps+1);
        if(l!=-1 && min>l) {min=l;path[steps]='E';}
        if(min==2147483647) min=-1;
        return min;
    }
    else return -1;
}

int main()
{
    int x,y,steps;scanf("%d%d",&x,&y);
    if((abs(x)+abs(y))%2==0) printf("%d",-1);
    else if(x==0 && y==0) printf("%d",0);
    else
    {
        steps=get_path(0,0,x,y,0);
        printf("\n");
        printf("%d\n",steps);
        for(int i=0;i<steps;i++) printf("%c",path[i]);
    }

    return 0;
}