#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int main() {
    char ans[100],*p=ans+1;memset(ans,0,100*sizeof(ans[0]));
    long long x,y,a,b,car=0;
    scanf("%lld%lld",&x,&y);
    a=x/y;b=x%y;
    if(!a)*p++='0';
    while(a)
    {
        *p=a%3+'0';
        a/=3;
        p++;
    }
    char* p0=ans+1,*p1=p-1,c;
    while(p0<p1){c=*p0;*p0=*p1;*p1=c;p0++;p1--;}
    p0=p;*p++='.';
    while(b)
    {
        y/=3;
        *p=b/y+'0';
        b%=y;
        p++;
    }
    p--;ans[0]='0';
    while(p>=ans)
    {if(*p!='.'){
        *p=*p+1+car;
        car=0;
        if(*p>='3'){*p-=3;car=1;}
        (*p)--;
        if(*p=='0'-1)*p='2';
        }
        p--;
    }
    if(*(p0+1)==0)*p0=0;
    if(ans[0]!='0')printf("%s",ans);
    else printf("%s",ans+1);
    return 0;
}
