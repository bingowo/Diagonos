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
    int len1=0,lens=0,len2=0;//len1-小数除去0部分；lens-小数总位；len2-整数有数位
    char a[100],b[100],c[100];
    m=A/B;
    n=A%B;
    //处理小数部分，不足位补0
    len1=_10to3(a,n,3,0);
    while(B>1)
    {
        B=B/3;
        if(n!=0)
           lens++;
    }
    for(int i=len1;i<lens;i++)
    {
        a[i]='0';
    }
    //中间加‘.’
    if(n!=0)
    {
        a[lens]='.';
        lens++;
    }
    //处理整数有数部分
    len2=_10to3(a,m,3,lens);

    /*
    for(int i=len2-1;i>=0;i--)
        printf("%c",a[i]);
    printf("\n");
    */

    //a[]有数位全部+1，放入数组b[]中；考虑最后一位进位cnt1
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


    //b[]有数位全部-1，放入数组c[]中；如果b[]最高位有进位，因为原来不是有数位，不用-1，直接copy到c[]中
    int cnt3=0;
    for(int i=0;i<len2;i++)
    {
        if(b[i]!='.')
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
    //如果整数部分为0（且在+1过程中无进位，即在结果中整数部分仍为0）
    if(m==0)
    {
        if(cnt1==0)
          c[k++]='0';
    }
    //将小数部分多余0去掉
    int j=0;
    while(c[j]=='0'&&j<len1)
    {
        j++;
    }
    //输出c[]
    for(int i=k-1;i>=j;i--)
        printf("%c",c[i]);
    return 0;
}
