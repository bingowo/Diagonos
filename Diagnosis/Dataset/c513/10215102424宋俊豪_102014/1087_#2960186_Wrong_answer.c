#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define L 100
int input(int a[])
{
    char s[101];
    scanf("%s",s);
    int i=0;
    while(s[i])
    {
        a[100+i]=s[i]-'0';
        i++;
    }
    return i;
}
void slo(int a[],int l)
{
    int j,i,t,f;
    int fir=100,last=100+l-1;
    if(l==1)
    {
        t=a[100]+1;
        a[100]=t%10;
        a[99]=(t)/10;
        return;
    }
    i=last;
    a[i]=a[i]+1;
    while(a[i]>=10)
    {
        t=a[i];
        a[i]=t%10;
        a[--i]+=t/10;
    }
    if(i<fir&&a[i]!=0)
        fir=i;
    i=fir;
        while(i<last)
        {   if(i==fir&&a[i]==9&&a[i+1]==9)
        {
            while(a[i]==9&&a[i+1]==9)
                i++;
            j=1;t=i+1;
            for(i;i>=fir-1;i--)
            {
                a[i]=j;
                j=(j+1)%2;
            }
            j=0;
            for(t;t<=last;t++)
            {
                a[t]=j;
                j=(j+1)%2;
            }
            break;

        }
            if(a[i]==a[i+1])
            {
                if(a[i]!=9)
                {
                    j=0;
                    a[i+1]++;
                    for(i=i+2; i<=last; i++)
                    {
                        a[i]=j;
                        j=(j+1)%2;
                    }
                }
                else
                {
                    a[i]=0;
                    a[i+1]=1;
                    a[i-1]++;
                    i--;j=i+3;
                    while(a[i]>=10)
                    {
                        t=a[i];
                        a[i]=t%10;
                        a[--i]+=t/10;
                    }
                    if(i<fir&&a[i]!=0)
                        fir=i;
                    t=j;
                    j=0;
                     for(t; t<=last; t++)
                    {
                        a[t]=j;
                        j=(j+1)%2;
                    }
                  i=fir-1;
        
                }

            }
            i++;
        }



    return;
}
void output(int a[],int len)
{
    int i=0;
    while(a[i]==0) i++;
    for(int j=i; j<=100+len-1; j++)
        printf("%d",a[j]);
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int len,a[2*L+1]= {0};
        printf("case #%d:\n",i);
        len=input(a);
        slo(a,len);
        output(a,len);
    }
}
