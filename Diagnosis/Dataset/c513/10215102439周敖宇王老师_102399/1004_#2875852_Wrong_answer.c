#include<stdio.h>
#include<math.h>
#include<string.h>
struct rt
{
    int b1;
    int b2;
};
struct rt ToTen(int *p,int num,int l)
{
    //printf("%d\n",*p);
    int k=0;
    struct rt ret;
    ret.b1=0;
    ret.b2=0;
    p=p+(l-num)*8;
    for(int i=1;i<=4;i++)
    {
        //printf("%d\n",ret.b1);
        ret.b1*=2;
        ret.b1+=*p;
        p++;
    }
    for(int i=1;i<=4;i++)
    {
        ret.b2*=2;
        ret.b2+=*p;
        p++;
    }
    return ret;
}
void ToInt(int x)
{
    int m[32],k=32,i;
    struct rt b;
    if(x>=0)
    {
        //memset(m,0,sizeof(m));
        for(int i=0;i<=31;i++)  m[i]=0;
        while(x>0)
        {
            m[--k]=x%2;
            x=x/2;
        }
    }
    else
    {
        //memset(m,1,sizeof(m));
        for(int i=0;i<=31;i++)  m[i]=1;
        x=-x-1;
        while(x>0)
        {
            m[--k]-=x%2;
            x=x/2;
        }
    }
    //printf("%d\n",m[0]);
    b=ToTen(m,1,4);
    printf("%x%x",b.b1,b.b2);
    for(i=2;i<=4;i++)
    {
        b=ToTen(m,i,4);
        printf(" %x%x",b.b1,b.b2);
    }
    printf("\n");
}
void ToDouble(double x)
{
    struct rt b;
    int m[64]={0};
    int z,e=1023,t=0,p;
    if(x<0)
    {
        m[0]=1;
        x=-x;
    }
    while(!(x>=1 && x<2))
    {
        if(x<1)
        {
            x*=2;
            e--;
        }
        if(x>=2)
        {
            x/=2;
            e++;
        }
    }
    p=11;
    while(e>0)
    {
        m[p]=e%2;
        e=e/2;
        p--;
    }
    p=12;
    x=x-1;
    while(x<1 && p<=63)
    {
        x*=2;
        if(x>=1)
        {
            m[p]=1;
            x=x-1;
        }
        p++;
    }
    b=ToTen(m,1,8);
    printf("%x%x",b.b1,b.b2);
    for(int i=2;i<=8;i++)
    {
        b=ToTen(m,i,8);
        printf(" %x%x",b.b1,b.b2);
    }
    printf("\n");
}
int main()
{
    char s[1000];
    int z=0,p=0,flag,t=0,a;
    double x=0;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='-')
        {
            p=1;
            a=-1;
        }
        else
        {
            p=0;
            a=1;
        }
        flag=1;
        z=0;
        x=0;
        t=0;
        while(s[p]!='\0')
        {
            if(s[p]=='.')
            {
                flag=-1;
            }
            else
            {
                if(flag==1)
                {
                    z=z*10+(s[p]-'0');
                }
                else
                {
                    t++;
                    x+=(s[p]-'0')/pow(10,t);
                }
            }
            p++;
        }
        if(flag==1)
        {
            ToInt(z*a);
        }
        else
        {
            x=x+z;
            if(x==0)
            {
                printf("00 00 00 00 00 00 00 00\n");
            }
            else
            {
                ToDouble(x*a);
            }
        }
    }
    return 0;
}