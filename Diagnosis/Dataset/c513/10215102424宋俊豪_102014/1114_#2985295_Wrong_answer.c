#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void sol(int a[],int n)
{
    int id=0;
    for(int i=1; i<=sqrt((double)n)+1; i++)
    {
        if(n%i==0)
            {a[id++]=i;}
    }
}
void read(char s[],int n[])
{
    while(*s)
    {
        int f1=0,f=1,a=0,i=0;
        if(*s=='+')s++;
        else if(*s=='-') f=-1,s++;
        while(isdigit(*s))
        {
            f1=1;
            a=a*10+*s-'0';
            s++;
        }
        if(a==0&&f1!=1)a=1;
        if(*s!='x')
        {
            n[0]=a*f;
            return;
        }
        else s++;
        if(*s=='^') s++;
        while(isdigit(*s))
        {
            i=i*10+*s-'0';
            s++;
        }
        if(i==0)i=1;
        n[i]=a*f;
    }

}
int main()
{
    int f=0,a[5]= {0};
    char s[20];
    scanf("%s",s);
    read(s,a);
    if(a[0]==0)
    {
        if(a[1]>0)
            printf("1 0 %d %d",a[2],a[1]);
        else
            printf("1 %d %d 0",a[1],a[2]);
        f=1;
    }
    else if(a[0]>0)
    {
        int t,n1[20]= {0};
        f=0;
        int n2[20]= {0};
        sol(n1,a[2]);
        sol(n2,a[0]);
        for(int i=0; n1[i]; i++)
        {
            for(int j=0; n2[j]; j++)
            {
                t=n1[i]*a[0]/n2[j]+a[2]/n1[i]*n2[j];
                if(t==a[1])
                {
                    f=1;
                    if(n1[i]==a[2]/n1[i])
                    {
                        if(a[0]/n2[j]>n2[j])
                        {
                            printf("%d %d %d %d",n1[i],n2[j],n1[i],a[0]/n2[j]);
                        }
                        else
                        {
                            printf("%d %d %d %d",n1[i],a[0]/n2[j],n1[i],n2[j]);
                        }
                    }
                    else
                    {
                        printf("%d %d %d %d",n1[i],a[0]/n2[j],a[2]/n1[i],n2[j]);
                    }
                }
                else if(-t==a[1])
                {
                    f=1;
                    if(n1[i]==a[2]/n1[i])
                    {
                        if(a[0]/n2[j]<n2[j])
                        {
                            printf("%d %d %d %d",n1[i],-n2[j],n1[i],-a[0]/n2[j]);
                        }
                        else
                        {
                            printf("%d %d %d %d",n1[i],-a[0]/n2[j],n1[i],-n2[j]);
                        }
                    }
                    else
                    {
                        printf("%d %d %d %d",n1[i],-n2[j],a[2]/n1[i],-a[0]/n2[j]);
                    }
                }
                if(f==1)
                    break;
            }
            if(f==1)
                break;
        }
    }
    else
    {
        int t,n1[20]= {0};
        f=0;
        int n2[20]= {0};
        a[0]=-a[0];
        sol(n1,a[2]);
        sol(n2,a[0]);
        for(int i=0; n1[i]; i++)
        {
            for(int j=0; n2[j]; j++)
            {
                t=n1[i]*a[0]/n2[j]-a[2]/n1[i]*n2[j];
                if(t==a[1])
                {
                    f=1;
                    if(n1[i]==a[2]/n1[i])
                    {

                        printf("%d %d %d %d",n1[i],-n2[j],n1[i],a[0]/n2[j]);
                    }
                    else
                    {
                        printf("%d %d %d %d",n1[i],-n2[j],a[2]/n1[i],a[0]/n2[j]);
                    }
                }
                else if(-t==a[1])
                {
                    f=1;
                    if(n1[i]==a[2]/n1[i])
                    {
                        printf("%d %d %d %d",n1[i],-a[0]/n2[j],n1[i],n2[j]);
                    }
                    else
                    {
                        printf("%d %d %d %d",n1[i],-a[0]/n2[j],a[2]/n1[i],n2[j]);
                    }
                }
                if(f==1)
                    break;
            }
            if(f==1)
                break;
        }
    }
    if(f==0)
        printf("No Answer!");
    return 0;
}
