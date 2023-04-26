#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int _10to3(char a[],int n,int r,int len)
{
    int temp;
    while(n>0)
    {
        temp=n%r;
        n=n/r;
        a[len++]=temp+'0';
    }
    //0存放最低位，len-1是最高位
    return len;
}
int main()
{
    int A,B;
    scanf("%d %d",&A,&B);
    int m,n;
    char a[100];
    char b[100];
    char c[100];
    m=A/B;
    n=A%B;
    int len=0,len2=0;
    len=_10to3(a,n,3,0);
    if(n!=0)
    {
        a[len]='.';
        len++;
    }
    len2=_10to3(a,m,3,len);
    if(m==0)
        a[len]='0';
    int cnt1=0,cnt2=0,k=0;
    for(int i=0;i<len2;i++)
    {
        if(a[i]!='.')
        {
            cnt2=(a[i]-'0'+1+cnt1)%3;
            cnt1=(a[i]-'0'+1+cnt1)/3;
            b[k++]=cnt2+'0';
        }
        else
            b[k++]=a[i];
    }
    if(cnt1)
        b[k++]=cnt1+'0';
    /*
    for(int i=k-1;i>=0;i--)
        printf("%c",b[i]);
    printf("\n");
    */
    int cnt3=0;
    for(int i=0;i<len2;i++)
    {
        if(a[i]!='.')
        {
            cnt3=b[i]-'0'-1;
            if(cnt3==-1)
                cnt3=2;
            c[i]=cnt3+'0';
        }
        else
            c[i]=b[i];
    }
    if(k>len2)
        c[k-1]=b[k-1];
    for(int i=k-1;i>=0;i--)
        printf("%c",c[i]);
    return 0;
}
