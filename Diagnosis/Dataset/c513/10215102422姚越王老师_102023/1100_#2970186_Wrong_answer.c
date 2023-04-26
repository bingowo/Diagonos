#include<stdio.h>
#define C 110
typedef struct{int x,y;} point;
int abs(int x){return x<0?-x:x;}
int main()
{
    int T,i,cnt=0;
    char s[110];scanf("%s",s);scanf("%d",&T);
    point a[C];int x0=0,y0=0,dx,dy;
    a[cnt].x=0;a[cnt].y=0;cnt++;
    for(i=0;s[i];++i)
    {
        switch (s[i])
        {
            case 'U':{y0+=1;a[cnt].x=a[cnt-1].x;a[cnt].y=a[cnt-1].y+1;break;}
            case 'D':{y0-=1;a[cnt].x=a[cnt-1].x;a[cnt].y=a[cnt-1].y-1;break;}
            case 'L':{x0-=1;a[cnt].x=a[cnt-1].x-1;a[cnt].y=a[cnt-1].y;break;}
            case 'R':{x0+=1;a[cnt].x=a[cnt-1].x+1;a[cnt].y=a[cnt-1].y;break;}
        }
        cnt++;    
    }
    dx=x0;dy=y0;
    int x,y;
    for(int cas=0;cas<T;++cas)
    {
        scanf("%d %d",&x,&y);
        int tmp,flag=0;
        if(dx==0&&dy==0)
        {
            for(i=0;i<cnt;++i)
            {
                if(x==a[i].x&&y==a[i].y)
                {
                    flag=1;
                    break;
                }
            }
        }
        else if(dx&&dy==0)
        {
            if(dx>0)
            {
                for(i=0;i<cnt;++i)
                {
                    tmp=x-a[i].x;
                    if(!(tmp%dx)&&tmp>=0&&y==a[i].y)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            else
            {
                for(i=0;i<cnt;++i)
                {
                    tmp=x-a[i].x;
                    if(!(tmp%dx)&&tmp<=0&&y==a[i].y)
                    {
                        flag=1;
                        break;
                    }
                }
            }
        }
        else if(dx==0&&dy)
        {
            if(dy>0)
            {
                for(i=0;i<cnt;++i)
                {   
                    tmp=y-a[i].y;
                    if(!(tmp%dy)&&tmp>=0&&x==a[i].x)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            else
            {
                for(i=0;i<cnt;++i)
                {   
                    tmp=y-a[i].y;
                    if(!(tmp%dy)&&tmp<=0&&x==a[i].x)
                    {
                        flag=1;
                        break;
                    }
                }
            }
        }
        else if(dx&&dy)
		{
			for(i=0;i<cnt;++i)
			{
				tmp=x-a[i].x;
                if(dx>0)
                {
                    if(!(tmp%dx)&&tmp>=0)
                    {
                        tmp=y+((dy>0)?-1:1)*dy*tmp/dx;
                        if(tmp==a[i].y){flag=1;break;}
                    }
                }
                else
                {
                    if(!(tmp%dx)&&tmp<=0)
                    {
                        tmp=y+((dy>0)?-1:1)*dy*tmp/dx;
                        if(tmp==a[i].y){flag=1;break;}
                    }
                }
			}
		}	
		if(flag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}