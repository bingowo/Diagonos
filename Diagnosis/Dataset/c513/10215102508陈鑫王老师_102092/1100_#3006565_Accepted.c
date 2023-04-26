#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct point
{
    int x;
    int y;
};
int main()
{
    char s[101];
    scanf("%s",s);
   struct point pos[101];
    pos[0].x=0;
    pos[0].y=0;
    for(int i=0;i<strlen(s);i++)
    {
        switch(s[i])
            {
            case 'U':
                {
                    pos[i+1].y=pos[i].y+1;
                    pos[i+1].x=pos[i].x;
                    break;
                }
            case 'D':
                {
                    pos[i+1].y=pos[i].y-1;
                    pos[i+1].x=pos[i].x;
                    break;
                }
            case 'L':
                {
                    pos[i+1].y=pos[i].y;
                    pos[i+1].x=pos[i].x-1;
                    break;
                }
            case 'R':
                {
                    pos[i+1].y=pos[i].y;
                    pos[i+1].x=pos[i].x+1;
                    break;
                }

            }
    }
    int x0=pos[strlen(s)].x,y0=pos[strlen(s)].y;
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int a,b,flag=0;
        scanf("%d %d",&a,&b);
        for(int j=0;j<=strlen(s);j++)
        {
            if(x0==0&&y0==0)
            {
                if(pos[j].x==a&&pos[j].y==b){flag=1;break;}
            }
            else if(x0==0&&y0!=0)
            {
                if(pos[j].x==a)
                {
                    if((b-pos[j].y)%y0==0&&(b-pos[j].y)/y0>=0){flag=1;break;}
                }
            }
            else if(x0!=0&&y0==0)
            {
                if(pos[j].y==b)
                {
                    if((a-pos[j].x)%x0==0&&(a-pos[j].x)/x0>=0){flag=1;break;}
                }
            }
            else
            {
                if((b-pos[j].y)%y0==0&&(b-pos[j].y)/y0>=0&&(a-pos[j].x)%x0==0&&(a-pos[j].x)/x0==(b-pos[j].y)/y0){flag=1;break;}
            }

        }
    if(flag)printf("Yes\n");
    else printf("No\n");
    }

    return 0;
}
