#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char s[100];
        int a[26]={0},b[26]={0},c[26]={0};
        scanf("%s",s);
        char *p=s;
        int a1,b1,i=0;
        while(*p)
    {   
       if(*p!=',') a[i]=*p-'0',i++;
       p++;
    }
    a1=i;
        scanf("%s",s);
        p=s;
        i=0;
    while(*p)
    {   
       if(*p!=',') b[i]=*p-'0',i++;
       p++;
    }
    b1=i;
        int prime[26]=
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
       
       for(int t=0;t<a1/2;t++)
    {
        int me=a[t];
        a[t]=a[a1-1-t];
        a[a1-1-t]=me;
    }
    for(int t=0;t<b1/2;t++)
    {
        int me=b[t];
        b[t]=b[b1-1-t];
        b[b1-1-t]=me;
    }//调换位置
    if(a1>b1)
    {
        for(int i=b1;i<a1;i++)
            b[i]=0;//补零
        int j=0,count=a1,m;
        for(m=0,n=0;m<a1;m++,n++)
            {c[m]=(a[m]+b[m]+j)%prime[n];
            j=(a[m]+b[m]+j)/prime[n];}
            if((a[m-1]+b[m-1]+j)>=prime[n-1]) {c[m]=(a[m-1]+b[m-1]+j)/prime[n-1];count++;}
        for(int i=0,i<count/2;i++)
        {
            int me=c[i];
            c[i]=c[count-1-i];
            c[count-1-i]=me;
        }
    }
    if(a1<b1)
    {
        for(int i=a1;i<b1;i++)
            a[i]=0;
        int j=0,count=bl,m;
        for(m=0,n=0;m<b1;m++,n++)
            {c[m]=(a[m]+b[m]+j)%prime[n];
            j=(a[m]+b[m]+j)/prime[n];}
            if((a[m-1]+b[m-1]+j)>=prime[n-1]) {c[m]=(a[m-1]+b[m-1]+j)/prime[n-1];count++;}
    }
    for(int i=0,i<count/2;i++)
        {
            int me=c[i];
            c[i]=c[count-1-i];
            c[count-1-i]=me;
        }

        printf("case #%d:\n",i);
        for(int i=0;i<count;i++)
        {
           printf("%d,",c[i]);
        }
        printf("\n");
    }
    return 0;
}