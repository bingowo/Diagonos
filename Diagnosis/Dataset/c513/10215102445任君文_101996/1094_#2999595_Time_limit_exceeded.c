#include<stdio.h>
#include<stdlib.h>
#define L 120
int mymax(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}
int main()
{
    int i,j,k;
    int n,m1=0,m2=0,m=0,tm=0;
    int f=1,f1=1,f2=1;
    int tma[L]={0};
    int tmi[L]={0};
    int MAX[L]={0};
    int MIN[L]={0};
    int res[L]={0};
    int temp[L]={0};
    int s=0,t=0;
    char c;
    scanf("%d",&n);
    c=getchar();
    for(i=0;i<n;i++)
    {
        m=0;
        f=1;
        f1=1;
        f2=1;
        m1=0;
        m2=0;
        tm=0;
        for(j=0;j<L;j++)
        {
            temp[j]=0;
        }
        while((c=getchar())!='\n')
        {
            if(c=='-')
            {
                f=-1;
            }
            else if(('0'<=c)&&(c<='9'))
            {
                temp[m]=c-'0';
                m++;
            }
        }
        if(i==0)
        {
            f1=f;
            f2=f;
            m1=m;
            m2=m;
            for(j=0;j<m;j++)
            {
                MIN[j]=temp[j];
                MAX[j]=temp[j];
            }
        }
        else
        {
            if(f1==-1)
            {
                if(f==1)
                {
                    
                    tm=mymax(m,m1);
                    for(j=0;j<tm;j++)
                    {
                        MAX[j]=temp[j];
                    }
                    m1=m;
                    f1=f;
                }
                else if(f==-1)
                {
                    if(m<m1)
                    {
                        for(j=0;j<m1;j++)
                        {
                            MAX[j]=temp[j];
                        }
                        m1=m;
                    }
                    else if(m==m1)
                    {
                        for(j=0;j<m;j++)
                        {
                            if(temp[j]>MAX[j])
                            {
                                break;
                            }
                            else if(temp[j]<MAX[j])
                            {
                                for(k=0;k<m;k++)
                                {
                                    MAX[k]=temp[k];
                                }
                                f1=f;
                                break;
                            }
                        }
                    }
                }
            }
            else if(f1==1)
            {
                if(f==1)
                {
                    if(m>m1)
                    {
                        for(j=0;j<m;j++)
                        {
                            MAX[j]=temp[j];
                        }
                        m1=m;
                        f1=f;
                    }
                    else if(m==m1)
                    {
                        for(j=0;j<m;j++)
                        {
                            if(MAX[j]>temp[j])
                            {
                                break;
                            }
                            else if(MAX[j]<temp[j])
                            {
                                for(k=0;k<m;k++)
                                {
                                    MAX[k]=temp[k];
                                }
                                f1=f;
                                break;
                            }
                        }
                    }
                }
            }
            if(f2==1)
            {
                if(f==-1)
                {
                    tm=mymax(m2,m);
                    for(j=0;j<tm;j++)
                    {
                        MIN[j]=temp[j];
                    }
                    m2=m;
                    f2=f;
                }
                else if(f==1)
                {
                    if(m<m2)
                    {
                        for(j=0;j<m2;j++)
                        {
                            MIN[j]=temp[j];
                        }
                        m2=m;
                        f2=f;
                    }
                    else if(m==m2)
                    {
                        for(j=0;j<m;j++)
                        {
                            if(MIN[j]<temp[j])
                            {
                                break;
                            }
                            else if(MIN[j]>temp[j])
                            {
                                for(k=0;k<m;k++)
                                {
                                    MIN[k]=temp[k];
                                }
                                m2=m;
                                f2=f;
                                break;
                            }
                        }
                    }
                }
            }
            else if(f2==-1)
            {
                if(f==-1)
                {
                    if(m2<m)
                    {
                        for(j=0;j<m;j++)
                        {
                            MIN[j]=temp[j];
                        }
                        m2=m;
                        f2=f;
                    }
                    else if(m2==m)
                    {
                        for(j=0;j<m;j++)
                        {
                            if(MIN[j]>temp[j])
                            {
                                break;
                            }
                            else if(MIN[j]<temp[j])
                            {
                                for(k=0;k<m;k++)
                                {
                                    MIN[k]=temp[k];
                                }
                                m2=m;
                                f2=f;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    m=mymax(m1,m2);
    f=f1*f2;
    for(i=m1-1;i>=0;i++)
    {
        tma[m1-i-1]=MAX[i];
    }
    for(i=m2-1;i>=0;i++)
    {
        tmi[m2-i-1]=MIN[i];
    }
    if(f>0)
    {
        s=0;
        k=0;
        j=m;
        for(i=0;i<m;i++)
        {
            t=tma[i]-tmi[i]-s;
            if(t<0)
            {
                res[i]=10+t;
                s=1;
            }
            else
            {
                res[i]=t;
                s=0;
            }
        }
        for(i=m-1;i>=0;i--)
        {
            if(res[i]==0)
            {
                if(k==0)
                {
                    if(i==0)
                    {
                        break;
                    }
                    else
                    {
                        j--;
                    }
                }
            }
            else
            {
                k=1;
            }
        }
        m=j;
    }
    else if(f<0)
    {
        s=0;
        for(i=0;i<m;i++)
        {
           t=tmi[i]+tma[i]+s;
           res[i]=t%10;
           s=t/10;
        }
        if(s!=0)
        {
            res[m]=s;
            s=0;
            m++;
        }
    }
    for(i=m-1;i>=0;i--)
    {
        printf("%d",res[i]);
    }
    printf("\n");
    return 0;
}