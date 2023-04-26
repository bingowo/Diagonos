#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define num 1005
#define max 1000009
typedef struct
{
    int v;
    int fz;
    int fm;
}number;
int cmd(int a,int b);
int water_lowest(number*p,int s,int pos,int r_pos,int l_pos);
int sub_water(number*p,int s,int pos,int n);
void pourwater(number* p,int s,int pos,int n );
int cmp(const void*p1,const void *p2);
number full_next(number*p,number half,int l_pos,int r_pos,int dir );
void full_final(number*p,number v,int l_pos,int r_pos,int dir);
void pourwater(number* p,int s,int pos,int n );


int cmd(int a,int b)
{
    return (a%b ==0)?b:cmd(b,a%b);
}


//返回平地灌水后剩余的水量
int water_lowest(number*p,int s,int pos,int r_pos,int l_pos)
{
    int h=(p[r_pos].v<p[l_pos].v)?p[r_pos].v:p[l_pos].v;
    int len = r_pos- l_pos-1;
    if(s>=len*h)
    {
        s-=len*h;
        for(int i=l_pos+1;i<=r_pos-1;i++)p[i].v = h;
        return s;
    }
    else if(s<len*h)
    {
        int integer = s/len;
        s = s%len ;
        int fm = len/cmd(len,s);
        int fz = s/cmd(len,s);
          for(int i=l_pos+1;i<=r_pos-1;i++)
          {
              p[i].v = p[i].v+integer;
              p[i].fz = fz;
              p[i].fm = fm;
          }
        return 0;
    }
}
//返回填平后剩余的水量
int sub_water(number*p,int s,int pos,int n)
{
    int v_L=0,v_R=0,v;
    int base_h = p[pos].v;
    int hl_pos,hr_pos;
    for(int i=base_h;i>=0;i--)
    {
        if(p[i].v>base_h)
        {
            hl_pos = p[i].v;
            break;
        }
        else
        {
            v_R+=base_h - p[i].v;
        }
    }
    for(int i =base_h;i<=n+1;i++)
    {
        if(p[i].v>base_h)
        {
            hr_pos = p[i].v;
            break;
        }
        else
        {
            v_R+=base_h - p[i].v;
        }
    }

    v = v_L+v_R;
    //平地灌水情况
    if(v==0)
    {
        return water_lowest(p,s,pos,hl_pos,hr_pos);
    }
    //灌满了还多
    else if(v<=s)
    {
    s = s-v;
    for(int k = hl_pos+1;k<=hr_pos-1;k++)p[k].v = base_h;
    return s;
    }
    //灌不满
    else if(v>s)
    {
    number s_h;
    s_h.v =s/2;
    s_h.fm = 2;
    s_h.fz = s%2;
    //灌满了左边灌右边
    if(s_h.v>=v_L)
    {
        for(int a=hl_pos+1;a<=pos;a++)p[a].v = base_h;
        s_h.v = s-v_L;
        s_h.fz = 0;
        s_h.fm = 1;
        full(p,s_h,pos,hr_pos,1);

    }
    else if(s_h.v>=v_R)
    {
        for(int a=hr_pos-1;a>=pos;a--)p[a].v = base_h;
         s_h.v = s-v_R;
        s_h.fz = 0;
        s_h.fm = 1;
        full(p,s_h,pos,hl_pos,-1);

    }
    else
    {
        full(p,s_h,pos,hl_pos,-1);
        full(p,s_h,pos,hr_pos,1);
    }

    }
}
//dir =-1填左边，=1填右边
//填坑
void full(number*p,number half,int l_pos,int r_pos,int pos,int dir)
{
    while(half.fz>0||half.v>0)
    {
        half = full_next(p,half,l_pos,r_pos,dir);
    }
}

number full_next(number*p,number half,int l_pos,int r_pos,int dir )
{
    //填右边

       int t_pos = l_pos;
       while(t_pos!=r_pos&&p[t_pos+dir].v<=p[t_pos].v)t_pos+=dir;
       while(t_pos!=r_pos&&p[t_pos+dir].v>=p[t_pos].v)t_pos+=dir;
       int high = (p[l_pos].v<p[t_pos].v)?p[l_pos].v:p[t_pos].v;
       int v=0;
       for(int i = l_pos+dir;i!=t_pos;i+=dir)
       {
           if (p[i].v < high) v+=high -p[i].v;
       }
       if(half.v>=v)
       {
           for(int q= l_pos;q!=t_pos;q+=dir)
           {
               if(p[q].v<high)p[q].v = high;
           }
           half.v-=v;
           return half;
       }
        full_final(p,half,l_pos,r_pos,dir);

}
int cmp(const void*p1,const void *p2)
{
int a = *(int*)p1;
int b = *(int*)p2;
return (a<b)?-1:1;
}



void full_final(number*p,number v,int l_pos,int r_pos,int dir)
{
    int arr[num];
    int t=0;
    for(int i =l_pos;i!=r_pos+dir;i+=dir)
    {
        arr[t++]=p[i].v;
    }
    qsort(arr,t,sizeof(int),cmp);
    int cnt;
    for(int z=1;z<t;z++){
        int c= (arr[z] - arr[z-1])*z;
        if(v.v<c){
            cnt = z;
            break;
        }
        else
        {
            v.v-=c;
        }
    }
    int fz = v.v *v.fm+v.fz;
    int fm = v.fm*cnt;
    int high = arr[cnt-1]+fz/fm;
    fz=fz%fm;
    int g = cmd(fm,fz);
    fz = fz/g;
    fm = fm/g;
    for(int i=l_pos;i!=r_pos+dir;i+=dir)
    {
        if(p[i].v<=high)
        {
            p[i].v = high;
            p[i].fz=fz;
            p[i].fm = fm;
        }
    }


}

void pourwater(number* p,int s,int pos,int n )
{
    while (s>0)
    {
        s = sub_water(p,s,pos,n);
    }
}
int main()
{
    //接收数据
    int l,s,p;
    scanf("%d%d%d",&l,&s,&p);
    number a[num];
    a[0].v =max;
    a[0].fz = 0;
    a[0].fm = 1;
    a[l+1].v=max;
    a[l+1].fm = 1;
    a[l+1].fz = 0;
    for(int i =1;i<l+1;i++)
    {
        scanf("%d",&a[i].v);
        a[i].fz = 0;
        a[i].fm = 1;
    }
    //放水
    pourwater(a,s,p,l);

    //输出高度
    for(int o =1;o<=l;o++)
    {
        if(a[o].v==0&&a[o].fz!=0)printf("%d/%d ",a[o].fz,a[o].fm);
        else if(a[o].v==0&&a[o].fz==0)printf("0");
        else
        {
            printf("%d",a[o].v);
            if(a[o].fz!=0)printf("+%d/%d ",a[o].fz,a[o].fm);
            else printf(" ");
        }
    }
    return 0;
}
