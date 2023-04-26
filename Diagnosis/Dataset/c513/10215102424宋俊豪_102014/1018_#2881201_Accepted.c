#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int slo2(long long int b[],int l)
{
    int r;
    int t=0;int max=0;
    for(int i=0; i<=l; i++)
    {
        int j=i;
        r=0;
        t=b[i];
        b[i]=b[i]%10;
        while(t/10!=0)
        {
            b[j]=b[j]+r;
            t=t/10;
            r=t%10;
            j++;
            if (j>max)
                max=j;

        }
        b[j]=b[j]+r;
        if (j>max)
                max=j;
    }
    r=0;
    for(int i=l;i<=max;i++)
    {   t=b[i];
        b[i]=(b[i]+r)%10;
        r=t/10;
    }
    if (r>0)
    {
        b[++max]=r;
    }

    return max;
}
int slo1(char s[],long long int a[])
{
    int i=0,cnt=0;
    a[cnt]=0;
    while(s[i]!='\0')
    {
        if (s[i]==',')
        {
            cnt++;
            a[cnt]=0;
        }
        else
            a[cnt]=a[cnt]*10+s[i]-'0';
        i++;
    }
    return cnt+1;
}
void reverse(long long int s[],int cnt)
{
    int c,i,j;
    for (i=0,j=cnt; i<j; i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
void prime(int p[])
{
    int cnt=0;
    p[cnt++]=1;
    p[cnt++]=2;
    p[cnt++]=3;
    for(int i=5; i<200; i+=2)
    {
        int t=0;
        for (int j=2; j<i; j++)
        {
            if (i%j==0)
            {
                t=1;
                break;
            }
        }
        if (t==0)
            p[cnt++]=i;
        if (cnt>30)
            break;
    }
}
int main()
{
    long long int a[200],len1,len2=0,temp;
    long long int b[100];
    for (int i=0;i<100;i++)
        b[i]=0;
    char s[100];
    int p[30];
    prime(p);
    scanf("%s",s);
    len1=slo1(s,a);
    reverse(a,len1-1);
    temp=a[len1-1]*p[len1-1];
    while (temp/10>0)
    {
        b[len2++]=temp%10;
        temp=temp/10;
    }
    b[len2]=temp%10;
    for (int j=len1-2; j>=0; j--)
    {
        b[0]=b[0]+a[j];
        for(int i=0; i<=len2; i++)
        {
            b[i]=b[i]*p[j];
        }
        len2=slo2(b,len2);
    }
    for(int j=len2; j>=0; j--)
    {
        printf("%d",b[j]);
    }
    return 0;

}
