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
    int lens=0;
    int m,n;
    char a[100];
    char b[100];
    char c[100];
    m=A/B;
    n=A%B;
    while(B>1)
    {
        B=B/3;
        lens++;
    }
    //printf("%d\n",m);
    int len1=0,len2=0;
    len1=_10to3(a,n,3,0);
    //printf("%d\n",len1);
    for(int i=len1;i<lens;i++)
    {
        a[i]='0';
    }
    /*
    for(int i=lens;i>=0;i--)
        printf("%c",a[i]);
    printf("\n");
    */
    if(n!=0)
    {
        a[lens]='.';
        lens++;
    }
    len2=_10to3(a,m,3,lens);
    if(m==0)
    {
        a[len2]='0';
        //len2++;
    }
    /*
    for(int i=len2;i>=0;i--)
        printf("%c",a[i]);
    printf("\n");
    */
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
    if(m==0)
    {
        c[k++]='0';
        //len2++;4 27
    }
    int j=0;
    while(c[j]=='0')
    {
        j++;
    }
    for(int i=k-1;i>=j;i--)
        printf("%c",c[i]);
    return 0;
}
