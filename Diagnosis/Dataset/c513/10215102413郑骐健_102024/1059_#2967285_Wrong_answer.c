#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmp(const void*p1,const void*p2)
{
    int p_1 = *(int*)p1;
    int p_2 = *(int*)p2;
    return (p_1<p_2)?-1:1;
}
long long stm(long long a,long long b)
{
    return (a%b==0)?b:stm(b,a%b);
}

int main()
{
    int *p = (int*)malloc(sizeof(int)*10000);
    memset(p,0,sizeof(int)*10000);
    long long v_w;
    int len;
    scanf("%d%lld",&len,&v_w);
    for(int i =0;i<len;i++)
    {
        scanf("%d",p+i);
    }
    qsort(p,len,sizeof(int),cmp);
    long long (*s)[3] =(long long(*)[3])malloc(sizeof(long long)*3*1500);
    memset(s,0,sizeof(long long)*4500);
    int po = 1;//指向p
    while(p[po]==p[po-1])
    {
        po++;
    }
    int n =1;
    s[0][0] = p[0];
    s[0][1] = 0;
    s[0][2] =po;
    while(po<len)
    {
        int po_=po;
        s[n][0] = p[po];
        po++;
        while(p[po]==p[po-1])po++;
        s[n][2] = s[n-1][2]+po - po_;
        s[n][1] = s[n-1][1]+s[n-1][2]*(s[n][0] - s[n-1][0]);
        n++;
    }

    int point =0;
    while(v_w >s[point][1]&&point<n)point++;
    if(point ==n)
    {
            long long in =0,up =0,down =0;
            v_w -=s[point-1][1];
            in+=s[point-1][0];
            in = in+v_w/s[point-1][2];
            if(v_w%s[point-1][2]==0)
            {
                printf("%lld",in);
            }
            else{
                    up = v_w%s[point-1][2];
            down = s[point-1][2];
            long long mid = stm(down,up);
            printf("%lld+%lld/%lld",in,up/mid,down/mid);
            }
    }
    else
    {
        if(v_w==s[point][1])printf("%lld",s[point][0]);
        else
        {
            long long in =0,up =0,down =0;
            v_w -=s[point-1][1];
            in+=s[point-1][0];
            in = in+v_w/s[point-1][2];
                  if(v_w%s[point-1][2]==0)
            {
                printf("%lld",in);
            }
            else{
                    up = v_w%s[point-1][2];
            down = s[point-1][2];
            long long mid = stm(down,up);
            printf("%lld+%lld/%lld",in,up/mid,down/mid);
            }
        }
    }
    free(s);
    free(p);
    return 0;
}
