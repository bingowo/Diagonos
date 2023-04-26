/*放水*/
#include<stdio.h>
#define C 1005
typedef struct{int h,fz,fm;}pos;
int GCD(int a,int b){return a%b?GCD(b,a%b):b;}
pos add(pos ax,int fz,int fm)
{
    pos a=ax;
    int tmp=a.fm*fm/GCD(a.fm,fm);
    int m1=tmp/a.fm,m2=tmp/fm;
    a.fz=a.fz*m1+fz*m2;
    int tmp2=GCD(a.fz,tmp);
    a.fz/=tmp2;a.fm=tmp/tmp2;
    if(a.fm==1){a.h+=a.fz;a.fz=0;}
    return a;
}
int main()
{
    int n,s,p,i,j;scanf("%d %d %d",&n,&s,&p);
    pos a[C];
    for(i=1;i<n+1;++i)
    {
        scanf("%d",&a[i].h);
        a[i].fz=0;a[i].fm=1;
    }
    a[0].h=a[i].h=2147483647;
    a[0].fz=a[i].fz=0;
    a[0].fm=a[i].fm=1;
    while(s)
    {
        int fl=1,fr=1,l_pos,r_pos,dw;
        for(i=p;i>0;--i)if(a[i-1].h>a[i].h)break;
        l_pos=i;
        for(j=i;j<p;++j)if(a[j+1].h!=a[j].h)break;
        if(j==p)fl=0;
        for(i=p;i<n+1;++i)if(a[i+1].h>a[i].h)break;
        r_pos=i;
        for(j=i;j>p;--j)if(a[j-1].h!=a[j].h)break;
        if(j==p)fr=0;
        if(fl&&fr)
        {
            int l_end,r_start,len;
            i=l_pos+1;while(a[i].h==a[i-1].h)i++;
            l_end=i-1;
            len=l_end-l_pos+1;
            for(i=l_pos;i<=l_end;++i)a[i]=add(a[i],1,2*len);
            i=r_pos-1;while(a[i].h==a[i+1].h)i--;
            r_start=i+1;
            len=r_pos-r_start+1;
            for(i=r_start;i<=r_pos;++i)a[i]=add(a[i],1,2*len);
            dw=1;
        }
        else if(!fl&&fr)
        {
            int r_start,len;
            i=r_pos-1;while(a[i].h==a[i+1].h)i--;
            r_start=i+1;
            len=r_pos-r_start+1;
            if(!a[r_pos].fz)
            {
                if(s>=len)
                {
                    for(i=r_start;i<=r_pos;++i)a[i].h++;
                    dw=len;
                }
                else
                {
                    for(i=r_start;i<=r_pos;++i)a[i]=add(a[i],s,len);
                    dw=s;
                }
            }
            else
            {
                int d=a[r_pos].fm-a[r_pos].fz;
                if(s>=d)
                {
                    for(i=r_start;i<=r_pos;++i)
                    {
                        a[i].h++;
                        a[i].fz=0;
                        a[i].fm=1;
                    }
                    dw=d;
                }
                else
                {
                    for(i=r_start;i<=r_pos;++i)a[i]=add(a[i],s,len);
                    dw=s;
                }
            }
        }
        else if(!fr&&fl)
        {
            int l_end,len;
            i=l_pos+1;while(a[i].h==a[i-1].h)i++;
            l_end=i-1;
            len=l_end-l_pos+1;
            if(!a[l_end].fz)
            {
                if(s>=len)
                {
                    for(i=l_pos;i<=l_end;++i)a[i].h++;
                    dw=len;
                }
                else
                {
                    for(i=l_pos;i<=l_end;++i)a[i]=add(a[i],s,len);
                    dw=s;
                }
            }
            else
            {
                int d=a[l_pos].fm-a[l_pos].fz;
                if(s>=d)
                {
                    for(i=l_pos;i<=l_end;++i)
                    {
                        a[i].h++;
                        a[i].fz=0;
                        a[i].fm=1;
                    }
                    dw=d;
                }
                else
                {
                    for(i=l_pos;i<=l_end;++i)a[i]=add(a[i],s,len);
                    dw=s;
                }
            }
        }
        else
        {
            int len=r_pos-l_pos+1;
            if(s>=len)
            {
                for(i=l_pos;i<=r_pos;++i)a[i].h++;
                dw=len;
            }
            else
            {
                for(i=l_pos;i<=r_pos;++i)a[i]=add(a[i],s,len);
                dw=s;
            }
        }
        s-=dw;
    }
    for(i=1;i<=n;++i)
    {
        if(a[i].fz)printf("%d+%d/%d ",a[i].h,a[i].fz,a[i].fm);
        else printf("%d ",a[i].h);
    }
    return 0;
}
