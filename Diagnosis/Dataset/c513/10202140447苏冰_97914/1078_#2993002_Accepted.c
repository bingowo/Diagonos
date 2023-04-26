#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1002
#define INF 1000009
typedef struct
{
    int v;
    int fz;
    int fm;
}Number;
int min(int a,int b)
{
    if(a<=b) return a;
    return b;
}
int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
int cmp(const void*a,const void*b)
{
    int* p=(int*)a;
    int* q=(int*)b;
    return *p-*q;
}
void full_final(Number s,Number*a,int lpos,int rpos, int dir)
{
    //剩下的水都放到这个山谷，不会填满
    int arr[N];
    int t=0;
    for(int i=lpos;i!=rpos+dir;i+=dir)
    {
        arr[t]=a[i].v;
        t++;
    }
    qsort(arr,t,sizeof(int),cmp);
    int cnt;
    for(int i=1;i<t;i++)
    {
        int c=(arr[i]-arr[i-1])*i;
        if(s.v<c)
        {
            cnt=i;
            break;
        }
        else
        {
            s.v-=c;
        }
    }
    int fz=s.v*s.fm+s.fz;
    int fm=s.fm*cnt;
    int highzs=arr[cnt-1]+fz/fm;
    fz%=fm;
    int g=gcd(fz,fm);
    fz/=g;fm/=g;
    for(int i=lpos;i!=rpos+dir;i+=dir)
    {
        if(a[i].v<=highzs)
        {
            a[i].v=highzs;
            a[i].fz=fz;
            a[i].fm=fm;
        }
    }
}
Number full_sub(Number s,Number*a,int lpos,int rpos,int dir)
{
    int tpos=lpos;
    while(tpos!=rpos && a[tpos+dir].v<=a[tpos].v) tpos+=dir;
    while(tpos!=rpos && a[tpos+dir].v>=a[tpos].v) tpos+=dir;//找坑
    int high=min(a[lpos].v,a[tpos].v);
    int v=0;
    for(int i=lpos;i!=tpos+dir;i+=dir)//填坑所需要的水量
    {
        if(a[i].v<high) v+=high-a[i].v;
    }
    if(s.v>=v)//能填满坑
    {
        for(int i=lpos;i!=tpos+dir;i+=dir)
        {
            if(a[i].v<high) a[i].v=high;
        }
        s.v-=v;
        return s;
    }
    full_final(s,a,lpos,tpos,dir);//水量s全部用来填坑,实现思路与下雨一样
    Number ret;
    ret.v=0;
    ret.fz=0;
    ret.fm=1;
    return ret;
}
void full(Number s,Number*a,int lpos,int rpos,int dir)
{
    //从lpos一直到rpos,用水量填充一个个坑
    //dir=-1表示填充左边的，1表示填充右边的
    //从离放水位置最近的坑开始一个一个填水
    while(s.v>0 || s.fz>0)
    {
        s=full_sub(s,a,lpos,rpos,dir);
        //每次填一个坑，返回剩余的水量
    }
}
int water_lowest(Number*a,int s,int base,int lpos,int rpos)
{
    int width=rpos-lpos-1;
    int high=min(a[lpos].v,a[rpos].v)-base;
    int v=width*high;//凹槽中需要的水量
    if(s>=v)//能放满凹槽，剩余水量进行下一次放水
    {
        for(int i=lpos+1;i<=rpos-1;i++)
        {
            a[i].v=base+high;
        }
        return s-v;
    }
    else//水量不能放满凹槽
    {
        int whigh=base+s/width;//可以填满一个格
        int r=s%width;//剩下的需要平分给每个格的总水量
        int fz=r,fm=width;
        int g=gcd(fz,fm);
        fz/=g;fm/=g;
        for(int i=lpos+1;i<=rpos-1;i++)
        {
            a[i].v=whigh;
            a[i].fz=fz;
            a[i].fm=fm;
        }
        return 0;//没有剩下的水量，不再需要放水了
    }
}
int water_sub(Number*a,int s,int n,int pos)
{
    int base=a[pos].v;
    int lpos,rpos;
    int lv=0,rv=0;
    for(int i=pos-1;i>=0;i--)//计算左边需要的水量
    {
        lpos=i;
        if(a[i].v>base) break;
        lv+=base-a[i].v;
    }
    for(int i=pos+1;i<=n+1;i++)//计算右边需要的水量
    {
        rpos=i;
        if(a[i].v>base) break;
        rv+=base-a[i].v;
    }
    int v=lv+rv;
    if(v==0)//该位置地面高度最低，水放在凹槽里面
    {
        return water_lowest(a,s,base,lpos,rpos);
    }
    if(v<=s)//先将左右的坑填满，剩余水量重新放水
    {
        for(int i=lpos+1;i<=rpos-1;i++)
        {
            a[i].v=base;
        }
        return s-v;
    }
    if(v>s)//放水量不能够填满左右的坑
    {
        Number half;//先考虑一半水量能不能填满一边的坑
        half.v=s/2;//水向两边平分
        half.fz=s%2;
        half.fm=2;
        if(half.v>=lv)//一半水量填满左边的坑
        {
            for(int i=lpos+1;i<=pos-1;i++)
            {
                a[i].v=base;
            }
            half.v=s-lv;
            half.fz=0;
            half.fm=1;
            full(half,a,pos,rpos,1);//剩余水量填满右边
            return 0;
        }
        else if(half.v>=rv)//一半水量填满右边的坑
        {
            for(int i=pos+1;i<=rpos-1;i++)
            {
                a[i].v=base;
            }
            half.v=s-rv;
            half.fz=0;
            half.fm=1;
            full(half,a,pos,lpos,-1);//剩余水量填满左边
            return 0;
        }
        else//两边的都没有办法填满
        {
            full(half,a,pos,lpos,-1);//一半水量填左边
            full(half,a,pos,rpos,1);//一半水量填右边
            return 0;
        }
    }
}
void pour_water(Number*a,int s,int n,int p)
{
    while(s>0)
    {
        s=water_sub(a,s,n,p);
    }
}
int main()
{
    int n,s,pos;
    Number a[N];
    scanf("%d %d %d",&n,&s,&pos);
    a[0].v=INF;a[n+1].v=INF;//设置两边是无穷高
    a[0].fz=a[n+1].fz=0;
    a[0].fm=a[n+1].fm=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].v);
        a[i].fz=0;a[i].fm=1;
    }
    pour_water(a,s,n,pos);
    for(int i=1;i<=n;i++)
    {
        if(a[i].v==0 && a[i].fz>0)
        {
            printf("%d/%d",a[i].fz,a[i].fm);
        }
        else
        {
            printf("%d",a[i].v);
            if(a[i].fz>0)
            {
                printf("+%d/%d",a[i].fz,a[i].fm);
            }
        }
        printf("%c",(i==n)?'\n':' ');
    }
    return 0;
}

