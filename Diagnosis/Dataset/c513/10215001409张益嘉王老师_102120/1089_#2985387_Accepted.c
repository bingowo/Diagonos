#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int shu[20];
    int wei;
}bigint;

int n;

bigint reverse(bigint a)
{
    int i,c;
    for(i=0;i<(a.wei/2);i++)
    {
        c=a.shu[i];
        a.shu[i]=a.shu[a.wei-i-1];
        a.shu[a.wei-1-i]=c;
    }
    return a;
}

bigint zhuanbigint(char *s)
{
    int len=strlen(s),i,j;
    bigint re;
    memset(re.shu,0,sizeof(int)*20);
    for(i=0,j=len-1;i<n;i++,j--)
    {
        if(j<0) re.shu[i]=0;
        else re.shu[i]=s[j]-'0';
    }
    re.wei=n;
    return re;
}

bigint cheng(bigint a,int x)
{
    bigint re;
    memset(re.shu,0,sizeof(int)*20);
    int i,jin=0,mid;
    for(i=0;i<n;i++)
    {
        mid=a.shu[i]*x+jin;
        re.shu[i]=mid%10;
        jin=mid/10;
    }
    re.wei=n;
    return re;
}

bigint moveadd0(bigint a,int k)
{
    int i,j;
    bigint re;
    for(i=n-1,j=n-1-k;i>=0;i--,j--)
    {
        if(j<0) re.shu[i]=0;
        else re.shu[i]=a.shu[j];
    }
    re.wei=n;
    return re;
}

bigint jia(bigint re,bigint mid)
{
    int i,du,jin=0;
    for(i=0;i<n;i++)
    {
        du=re.shu[i]+mid.shu[i]+jin;
        re.shu[i]=du%10;
        jin=du/10;
    }
    re.wei=n;
    return re;
}



bigint pingfang(bigint m,bigint a)
{
    int i,j,co=0;
    bigint re,mid;
    memset(re.shu,0,sizeof(int)*20);
    re.wei=n;
    int x[20];
    for(i=0;i<n;i++)
    {
        x[i]=a.shu[i];
    }
    for(i=0;i<n;i++)
    {
        mid=cheng(m,x[i]);
        mid=moveadd0(mid,i);
        re=jia(re,mid);
    }

    return re;

}

int main()
{
    int i,t;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        char aa[20];
        bigint a,m;
        int b,j;
        scanf("%s%d%d",aa,&b,&n);
        //printf("b=%d\n",b);
        a=zhuanbigint(aa);
        //b=zhuanbigint(bb);
        //a=reverse(a);
        m=a;
        for(j=0;j<b-1;j++)
        {
            m=pingfang(m,a);
            /*printf("test第%d次平方后:\n  m=",j);
            for(int jj=n-1;jj>=0;jj--) printf("%d",m.shu[jj]);
            printf("\n");*/
        }
        m=reverse(m);

        printf("case #%d:\n",i);
        for(j=0;j<n;j++) printf("%d",m.shu[j]);
        printf("\n");

    }

}
