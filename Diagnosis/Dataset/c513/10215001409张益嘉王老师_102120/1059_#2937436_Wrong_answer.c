#include <stdio.h>
#include <stdlib.h>

int maxyue(int a,int b)
{
    if((a==0)||(b==0)) return 0;
    if(a>=b)
    {
        if(a%b==0) return b;
        else
        {
            a%=b;
            return maxyue(a,b);
        }
    }
    else return maxyue(b,a);
}

int cmp(const void*a,const void*b)
{
    int aa=*((int*)a);
    int bb=*((int*)b);

    if(aa>bb) return 1;
    else if(aa<bb) return 1;
    else return 0;
}

int main()
{
    int n,s,i,a[1010],re,cha,zi=0,mu=0,yue,h=0;
    memset(a,0,sizeof(int)*1010);
    scanf("%d%d",&n,&s);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);

    for(i=1;i<n;i++)
    {
        if(s<=0) break;
        cha=(a[i]-a[i-1])*i;
        if(s>=cha)
        {
            s-=cha;
            h=a[i];
        }
        else
        {
            //int mid=s;

            yue=maxyue(s,i);
            zi=s/yue;
            mu=i/yue;
            s=s/i;

        }
    }
    if(s>0)
    {
        h+=(s/n);
        s=s%n;
        yue=maxyue(s,n);
        if(yue!=0)
        {
            zi=s/yue;
            mu=n/yue;
        }

    }
    if(mu==0) printf("%d",h);
    else if(h==0) printf("%d/%d",zi,mu);
    else printf("%d+%d/%d",h,zi,mu);

    return 0;

}
