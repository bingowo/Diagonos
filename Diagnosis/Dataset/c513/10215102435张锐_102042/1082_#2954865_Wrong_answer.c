#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(int *a1,int *b1,int *a2,int *b2,int len)
{
    int last=0;
    for(int i=499;i>=0;i--)
    {
        if(500-i>len) break;
        int temp=a2[i]+b2[i]+last;
        if(temp<10) a2[i]=temp,last=0;
        else {a2[i]=temp-10,last=1;}
    }
    for(int i=499;i>=0;i--)
    {
        int temp=a1[i]+b1[i]+last;
        if(temp<10) a1[i]=temp,last=0;
        else a1[i]=temp-10,last=1;
    }
}
int main()
{
    char a[600],b[600];int n;
    scanf("%s",a);scanf("%s",b);scanf("%d",&n);
    int a1[500]={0},a2[500]={0},b1[500]={0},b2[500]={0};
    int len1=strlen(a),len2=strlen(b);int p1,p2;
    for(p1=0;p1<len1;p1++)
    {
        if(a[p1]=='.') {len1--;break;}
    }
    if(1)
    {
        for(int i=499,j=p1-1;j>=0;i--,j--)
        {
            a1[i]=a[j]-'0';
        }
        for(int i=499,j=strlen(a)-1;j>p1;i--,j--)
        {
            a2[i]=a[j]-'0';
        }
    }
    for(p2=0;p2<len2;p2++)
    {
        if(b[p2]=='.') {len2--;break;}
    }
    if(1)
    {
        for(int i=499,j=p2-1;j>=0;i--,j--)
        {
            b1[i]=b[j]-'0';
        }
        for(int i=499,j=strlen(b)-1;j>p2;i--,j--)
        {
            b2[i]=b[j]-'0';
        }
    }
    int len;
    if(len1-p1>=len2-p2) len=len1-p1;
    else len=len2-p2;
    add(a1,b1,a2,b2,len);
    for(p1=0;p1<500;p1++)
    {
        if(a1[p1]!=0) break;
    }
    for(p2=0;p2<500;p2++)
    {
        if(a2[p2]!=0) break;
    }
    if(p2+n<500&&a2[p2+n]>=5)
    {
        char t1[500]={0},t2[500]={0};
        t2[p2+n-2]=1;
        add(a1,t1,a2,t2,len);
    }
    for(int i=p1;i<500;i++) printf("%d",a1[i]);
    if(p1==500) printf("0");
    printf(".");
    for(int i=p2,j=0;j<n;j++,i++)
    {
        if(i<500) printf("%d",a2[i]);
        else if(i>=500) printf("0");
    }
    return 0;
}
