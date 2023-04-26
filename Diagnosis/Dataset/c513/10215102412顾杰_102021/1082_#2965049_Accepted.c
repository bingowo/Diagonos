#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
    int i,la,ra,lb,rb,l,r,n,carry;
    char s[502],*p,*p0;
    int a[1001],b[1001],ans[1001];
    for(i=0;i<1001;i++){a[i]=0;b[i]=0;ans[i]=0;}
        memset(s,0,502);
        scanf("%s",s);
        for(p=s;*p!='.'&&*p;p++);
        p0=p;la=500;
        p--;
        while(p>=s)a[la--]=*(p--)-'0';
        p=p0+1;ra=501;
        while(*p)a[ra++]=*(p++)-'0';
        memset(s,0,502);
        scanf("%s",s);
        for(p=s;*p!='.'&&*p;p++);
        p0=p;lb=500;
        p--;
        while(p>=s)b[lb--]=*(p--)-'0';//l,r都超1位
        p=p0+1;rb=501;
        while(*p)b[rb++]=*(p++)-'0';
        scanf("%d",&n);
    l=la<lb?la:lb;r=ra>rb?ra:rb;
    for(i=r-1;i>=l;i--)
    {
        ans[i]+=a[i]+b[i];
        if(ans[i]>=10){ans[i]-=10;ans[i-1]++;}
    }

    if(ans[501+n]>=5)carry=1;
    else carry=0;
    int*po=ans+501+n-1;
    while(carry)
    {
        *po+=carry;
        carry=*po/10;
        *po%=10;
        po--;
    }

    po=ans;
    while(*po==0)po++;
    if(po>=ans+501){printf("0");po=ans+501;}
    for(;po<ans+501;po++)printf("%d",*po);
    printf(".");
    for(;po<ans+501+n;po++)printf("%d",*po);
}


