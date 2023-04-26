#include <stdio.h>
#include <ctype.h>
#define N 501
typedef struct { int cnt; int cntf; int v[N]; int vf[N] ;} BIGINT ;

BIGINT INPUT()  //int 转换成BIGINT
{
    char temp;
    int flag=1;
    BIGINT R= {0,0,{0},{0}};
    while(1)
    {
        temp=getchar();
        if(temp=='.')
        {
            flag=0;
            continue;
        }
        else if (temp==' ')break;
        else if(flag==1)
        R.v[R.cnt++]=temp-'0';
        else if(flag==0)
        R.vf[R.cntf++]=temp-'0';
    }
    if(R.cnt==0)
    {
        R.cnt++;
    }
    return R;
}

BIGINT add(BIGINT S, BIGINT T)     //两个大整数相乘

{
    int a,b,min,j=0;
    if(S.cnt<T.cnt)
    {
        a=T.cnt;
        min=S.cnt;
    }
    else
    {
        a=S.cnt;
        min=T.cnt;
    }
    if(S.cntf<T.cntf)
    {
        b=T.cntf;
    }
    else b=S.cntf;
    BIGINT R= {0,b,{0},{0}};
    for(int i=b-1;i>0;i--)
    {
        R.vf[i]=R.vf[i]+S.vf[i]+T.vf[i];
        if(R.vf[i]>9)
        {
            R.vf[i-1]++;
            R.vf[i]=R.vf[i]-10;
        }
    }
    R.vf[0]=R.vf[0]+S.vf[0]+T.vf[0];
    if(R.vf[0]>9)
    {
        R.vf[0]=R.vf[0]-10;
        j=1;
    }


    for(int i=0;i<a;i++)
    {
        if(i==0)
        {
            R.v[0]=R.v[0]+S.v[S.cnt-1]+T.v[T.cnt-1]+j;
            R.cnt++;
            if(R.v[0]>9)
            {
                R.v[1]++;
                R.v[0]=R.v[0]-10;
            }
        }
        else if(i<min)
        {
            R.v[i]=R.v[i]+S.v[S.cnt-i-1]+T.v[T.cnt-i-1];
            R.cnt++;
            if(R.v[i]>9)
            {
                R.v[i+1]++;
                R.v[i]=R.v[i]-10;
            }
        }
        else
        {
            if(S.cnt-i-1<0)
            {
                R.v[i]=R.v[i]+T.v[T.cnt-i-1];
                R.cnt++;
            if(R.v[i]>9)
            {
                R.v[i+1]++;
                R.v[i]=R.v[i]-10;
            }
            }
            else
            {
                R.v[i]=R.v[i]+S.v[S.cnt-i-1];
                R.cnt++;
            if(R.v[i]>9)
            {
                R.v[i+1]++;
                R.v[i]=R.v[i]-10;
            }
            }

        }
    }

    return R;
}

BIGINT si(BIGINT R,int n)
{int j=0;
    if(R.vf[n]>4)
    {
        R.vf[n-1]++;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(R.vf[i]>9)
        {
            R.vf[i-1]++;
            R.vf[i]=R.vf[i]-10;
            if(i==0)j=1;
        }

    }
    if(j==1)
    {
        R.v[0]++;
        for(int i=0;i<R.cnt;i++)
        {
            if(R.v[i]>10)
            {
                R.v[i]=R.v[i]-10;
                R.v[i+1]++;
            }
        }
    }

    return R;
}

int main()
{
    int n;
    BIGINT a;
    BIGINT b;
    BIGINT ans;
    a=INPUT();
    b=INPUT();
    scanf("%d",&n);
    ans=add(a,b);
    ans=si(ans,n);
    int i=ans.cnt;
    while(1)
    {
        if(ans.v[i]==0)i--;
        else break;
    }
    if(i<0)
    {
        printf("0");
    }
    for(i;i>=0;i--)
    {
        printf("%d",ans.v[i]);
    }

    printf(".");

    for(int j=0;j<n;j++)
    {

        printf("%d",ans.vf[j]);
    }

}
