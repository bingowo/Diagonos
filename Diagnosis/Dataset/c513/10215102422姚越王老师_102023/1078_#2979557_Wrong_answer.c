#include<stdio.h>
#define C 1010
typedef struct{int h,flag;} pos;
int GCD(int a,int b){return a%b?GCD(b,a%b):b;}
int main()
{
    int n,s,p,i,j,d=0,jump=0,flag1=0,flag2=0,div;scanf("%d %d %d",&n,&s,&p);
    pos a[C];for(i=1;i<=n;++i){scanf("%d",&a[i].h);a[i].flag=0;}
    a[0].h=a[i].h=10000000;
    while(s>=2)
    {
        switch (d)
        {
            case 0:
            {
                for(i=p-1;i>=0;--i)if(a[i].h>a[i+1].h)break;
                for(j=p+1;j<=n+1;++j)if(a[j].h>a[j-1].h)break;
                if(i==0&&a[1].h==a[p].h)flag1=1;
                if(j==n+1&&a[n].h==a[p].h)flag2=1;
                if(flag1&&flag2)jump=1;
                else if(flag1){d=1;a[j-1].h++;a[j-1].flag=1;s--;}
                else if(flag2){d=2;a[i+1].h++;a[i+1].flag=1;s--;}
                else {a[i+1].h++;a[i+1].flag=1;a[j-1].h++;a[j-1].flag=1;s-=2;}
                break;
            }
            case 1:
            {
                for(j=p+1;j<=n+1;++j)if(a[j].h>a[j-1].h)break;
                if(j==n+1&&a[n].h==a[p].h){flag2=1;jump=1;}
                else {a[j-1].h++;a[j-1].flag=1;s--;}
                break;
            }
            case 2:
            {
                for(i=p-1;i>=0;--i)if(a[i].h>a[i+1].h)break;
                if(i==0&&a[1].h==a[p].h){flag1=1;jump=1;}
                else {a[i+1].h++;a[i+1].flag=1;s--;}
                break;
            }
        }
        if(jump)break;
    }
    if(jump)//地面平了
    {
        if(s)//地面平了有水剩余
        {
            div=GCD(s,n);s/=div;n/=div;
            for(i=1;i<=n;++i)printf("%d+%d/%d ",a[1],s,n);
            return 0;
        }
        else if(!s)//地面平了没有水剩余
        {
            for(i=1;i<=n;++i)printf("%d ",a[1]);
            return 0;
        }
    }
    else//地面没平
    {
        if(flag1&&!flag2)//左边流平了，只往右边流
        {
            for(j=p+1;j<=n+1;++j)if(a[j].h>a[j-1].h&&a[j].flag)break;
            int start=j-2,end=j,length=0,water=s?1:0,div;
            while(start>=0&&a[start].h==a[start+1].h)start--;
            while(end<=n+1&&a[end].flag==1){end++;water++;}
            length=end-start-1;div=GCD(water,length);water/=div;length/=div;
            for(i=1;i<=n;++i)
            {
                if(i>start&&i<end)printf("%d+%d/%d ",a[i].h,water,length);
                else printf("%d ",a[i].h);
            }
            return 0;
        }
        else if(!flag1&&flag2)//右边流平了，只往左边流
        {
            for(i=p-1;i>=0;--i)if(a[i].h>a[i+1].h&&a[i].flag)break;
            int start=i,end=i+2,length=0,water=s?1:0,div;
            while(start>=0&&a[start].flag==1){start--;water++;}
            while(end<=n+1&&a[end].h==a[end-1].h)end++;
            length=end-start-1;div=GCD(length,water);water/=div;length/=div;
            for(i=1;i<=n;++i)
            {
                if(i>start&&i<end)printf("%d+%d/%d ",a[i].h,water,length);
                else printf("%d ",a[i].h);
            }
            return 0;
        }
        else if(!flag1&&!flag2)
        {
            for(i=p-1;i>=0;--i)if(a[i].h>a[i+1].h&&a[i].flag)break;
            int start1=i,end1=i+2,length1=0,water1=s?1:0,div;
            while(start1>=0&&a[start1].flag==1){start1--;water1+=2;}
            while(end1<=n+1&&a[end1].h==a[end1-1].h)end1++;
            length1=(end1-start1-1)*2;div=GCD(length1,water1);water1/=div;length1/=div;
            for(j=p+1;j<=n+1;++j)if(a[j].h>a[j-1].h&&a[j].flag)break;
            int start2=j-2,end2=j,length2=0,water2=s?1:0;
            while(start2>=0&&a[start2].h==a[start2+1].h)start2--;
            while(end2<=n+1&&a[end2].flag==1){end2++;water2+=2;}
            length2=(end2-start2-1)*2;div=GCD(water2,length2);water2/=div;length2/=div;
            for(i=1;i<=n;++i)
            {
                if(i>start1&&i<end1)printf("%d+%d/%d ",a[i].h,water1,length1);
                else if(i>start2&&i<end2)printf("%d+%d/%d ",a[i].h,water2,length2);
                else printf("%d ",a[i].h);
            }
            return 0;
        }
    }
}

