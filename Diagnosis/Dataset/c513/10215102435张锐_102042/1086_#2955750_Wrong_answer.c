#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sub(int *a1,int *b1,int *a2,int *b2,int len)
{
    int last=0;
    for(int i=len-1;i>=0;i--)
    {
        int temp=a2[i]-b2[i]-last;
        if(temp>=0) a2[i]=temp,last=0;
        else {a2[i]=temp+10,last=1;}
    }
    for(int i=599;i>=0;i--)
    {
        int temp=a1[i]-b1[i]-last;
        if(temp>=0) a1[i]=temp,last=0;
        else a1[i]=temp+10,last=1;
    }
}
void add(int *a1,int *b1,int *a2,int *b2,int len)
{
    int last=0;
    for(int i=len-1;i>=0;i--)
    {
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
    int a1[600]={0},a2[600]={0},b1[600]={0},b2[600]={0};
    int len1=strlen(a),len2=strlen(b);int p1,p2;
    for(p1=0;p1<len1;p1++)
    {
        if(a[p1]=='.') {len1--;break;}
    }
    if(1)
    {
        for(int i=599,j=p1-1;j>=0;i--,j--)
        {
            a1[i]=a[j]-'0';
        }
        for(int i=0,j=p1+1;j<strlen(a);i++,j++)
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
        for(int i=599,j=p2-1;j>=0;i--,j--)
        {
            b1[i]=b[j]-'0';
        }
        for(int i=0,j=p2+1;j<strlen(b);i++,j++)
        {
            b2[i]=b[j]-'0';
        }
    }
    int len;
    if(len1-p1>=len2-p2) len=len1-p1;
    else len=len2-p2;
    sub(a1,b1,a2,b2,len);
    if(n<len&&a2[n]>=5)
    {
        int t1[600]={0},t2[600]={0};
        t2[n-1]=1;
        add(a1,t1,a2,t2,len);
    }
    int bo=0;
    for(int i=0;i<600;i++)
    {
        if(a1[i]!=0) bo=1;
        if(bo) printf("%d",a1[i]);
    }
    if(bo==0) printf("0");
    printf(".");
    for(int i=0,j=0;j<n;j++,i++)
    {
        if(i<len) printf("%d",a2[i]);
        else if(i>=len) printf("0");
    }
    return 0;
}
