#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void *pa,const void *pb)
{
    int a,b;
    a=*((int *)pa);
    b=*((int *)pb);
    return a-b;
}
int find(char s1[],char s2[])
{
    int l1=strlen(s1);
    int l2=strlen(s2);
    char c1[l1];
    char c2[l2];
    int m[128];
    for(int i=0;i<128;i++)
    {
        m[i]=-1;
    }
    int num1=0;
    for(int i=0;i<l1;i++)
    {
        if(m[s1[i]]<0)
        {
            m[s1[i]]=1;
            c1[num1]=s1[i];
            num1++;
        }
    }
    c1[num1]='\0';
    for(int i=0;i<128;i++)
    {
        m[i]=-1;
    }
    int num2=0;
    for(int i=0;i<l2;i++)
    {
        if(m[s2[i]]<0)
        {
            m[s2[i]]=1;
            c2[num2]=s2[i];
            num2++;
        }
    }
    c2[num2]='\0';
    if(strlen(c1)!=strlen(c2))
    {
        return -1;
    }
    else
    {
        int t=0;
        for(int i=0;i<strlen(c1);i++)
        {
            if(c1[i]!=c2[i])
            {
                t++;
            }
        }
        if(t>0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    int number;
    scanf("%d",&number);
    char s[number][100];
    for(int i=0;i<number;i++)
    {
        scanf("%s",s[i]);
    }
    int n=0;
    for(int i=0;i<number;i++)
    {
        for(int j=i+1;j<number;j++)
        {
            n=n+find(s[i],s[j]);
        }
    }
    if(n<0)
    {
        printf("-1");
    }
    else
    {
        int a[number];
        for(int i=0;i<number;i++)
        {
            a[i]=strlen(s[i]);
        }
        qsort(a,number,sizeof(int),cmp);
        if(number%2==1)
        {
            int re=0;
            for(int i=0;i<number;i++)
            {
                re+=abs(a[i]-a[(number+1)/2-1]);
            }
            printf("%d",re);
        }
        else
        {
            int re1=0,re2=0;
            for(int i=0;i<number;i++)
            {
                re1+=abs(a[i]-a[number/2-1]);
                re2+=abs(a[i]-a[number/2]);
            }
            if(re1>re2)
            {
                printf("%d",re2);
            }
            else
            {
                printf("%d",re1);
            }
        }
    }
    return 0;
}