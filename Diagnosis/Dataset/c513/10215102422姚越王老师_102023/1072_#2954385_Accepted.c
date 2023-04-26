#include<stdio.h>
typedef long long ll;
typedef struct{ll x,y,maha;char c;} point;
ll pow(int a,int b)
{
    ll ans=1;
    for(int i=0;i<b;++i)ans*=a;
    return ans;
}
ll getmaha(ll x,ll y)
{
    ll dx=x<0?-x:x,dy=y<0?-y:y;
    return dx+dy;
}
ll min(ll a,ll b,ll c,ll d)
{
    ll ans=a;
    if(b<ans)ans=b;
    if(c<ans)ans=c;
    if(d<ans)ans=d;
    return ans;
}
int main()
{
    ll x,y;scanf("%lld %lld",&x,&y);
    ll dx=x<0?-x:x,dy=y<0?-y:y,dis=dx+dy;
    if(!dis){printf("%d",0);return 0;}
    if(!(dis%2)){printf("%d",-1);return 0;}
    int step=1,i;
    for(i=1;i<64;i++)
        if(dis>pow(2,i-1)&&dis<pow(2,i))
        {
        	step=i;
        	break;
		}
	printf("%d\n",step);
    point p1,p2,p3,p4,ans; char b[100]; int cnt=0;
    while(step)
    {
        //printf("step=%d\n",step); 
		p1.x=x-pow(2,step-1);p1.y=y;p1.maha=getmaha(p1.x,p1.y); //向西移动
        p2.x=x+pow(2,step-1);p2.y=y;p2.maha=getmaha(p2.x,p2.y); //向东移动
        p3.x=x;p3.y=y-pow(2,step-1);p3.maha=getmaha(p3.x,p3.y); //向南移动
        p4.x=x;p4.y=y+pow(2,step-1);p4.maha=getmaha(p4.x,p4.y); //向北移动
        if(min(p1.maha,p2.maha,p3.maha,p4.maha)==p1.maha)
            {
                b[cnt++]='E';
                x=p1.x;y=p1.y;
                //printf("here1\n");
            }
        else if(min(p1.maha,p2.maha,p3.maha,p4.maha)==p2.maha)
            {
                b[cnt++]='W';
                x=p2.x;y=p2.y;
                //printf("here2\n");
            }
        else if(min(p1.maha,p2.maha,p3.maha,p4.maha)==p3.maha)
            {
                b[cnt++]='N';
                x=p3.x;y=p3.y;
                //printf("here3\n");
            }
        else
            {
                b[cnt++]='S';
                x=p4.x;y=p4.y;
                //printf("here4\n");
            }
        step--;
    }
    for(i=cnt-1;i>-1;i--)printf("%c",b[i]);
    return 0;
}