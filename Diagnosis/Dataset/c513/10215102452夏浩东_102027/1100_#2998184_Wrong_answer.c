#include <stdio.h>
#include <string.h>
struct T{
    long long int dx;
    long long int dy;
};

int main()
{
    char s[101];
    int cnt=0;
    long long int dx=0,dy=0;
    scanf("%s %d",s,&cnt);
    int len=(int)strlen(s);
    struct T L[100];
    for(int i=0;i<len;i++)
    {
        if(s[i]=='U') dy++;
        else if(s[i]=='D') dy--;
        else if(s[i]=='R') dx++;
        else if(s[i]=='L') dx--;
        L[i].dx=dx;
        L[i].dy=dy;
    }
    long long int xmin=L[0].dx,xmax=L[0].dx,ymin=L[0].dy,ymax=L[0].dy;
    for(int i=0;i<len;i++)
    {
        xmin=L[i].dx<xmin ? L[i].dx:xmin;
        xmax=L[i].dx>xmax ? L[i].dx:xmax;
        ymin=L[i].dy<ymin ? L[i].dy:ymin;
        ymax=L[i].dy>ymax ? L[i].dy:ymax;
    }
    for(int mm=0;mm<cnt;mm++)
    {
        long long int x=0,y=0;
        int xflag=1,yflag=1,flag=0;
        scanf("%lld %lld",&x,&y);
        while(1)
        {
            for(int i=0;i<len;i++){
                if(L[i].dx==x && L[i].dy==y) {flag=1;break;}
                else if(L[i].dx==x && L[i].dy!=y) xflag=0;
                else if(L[i].dy==y && L[i].dx!=x) yflag=0;
            }
                
            if(flag==1) break;
            else if((xflag==0 && L[len-1].dx==0) || (yflag==0 && L[len-1].dy==0)) break;
            else if((x<xmin && L[len-1].dx>0) || (x>xmax && L[len-1].dx<0)) break;
            else if((y<ymin && L[len-1].dy>0) || (y>ymax && L[len-1].dy<0)) break;
            else {x=x-L[len-1].dx; y=y-L[len-1].dy;}
        }
        if(x==0 && y==0) flag=1;
        if(flag==0) printf("No\n");
        else printf("Yes\n");
    }
}