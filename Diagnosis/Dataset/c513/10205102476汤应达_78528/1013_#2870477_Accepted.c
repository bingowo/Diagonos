#include<stdio.h>
#include<string.h>

int main()
{
    char s[1000];int c[128],p,l;
    scanf("%s",&s);l=strlen(s);
    c['0']=0;c['1']=1;c['2']=-1;
    for(int i=0;i<l;i++) {if(s[i]=='.') {p=i;break;} else p=l;}

    long long res=0,ex=1,d=l-p,r=0,ex1=1;
    for(int i=p-1;i>=0;i--)
    {
        res+=c[s[i]]*ex;
        ex*=3;
    }
    for(int i=p+1;i<l;i++)
    {
        r=r*3+c[s[i]];
        ex1*=3;
    }

    if(r<0 && res>0) printf("%lld %lld %lld",res-1,ex1+r,ex1);
    else if(r<0 && res<0) printf("%lld %lld %lld",res,r,ex1);
    else if(r>0 && res<0) printf("%lld %lld %lld",res+1,ex1-r,ex1);
    else if(res==0 && r!=0) printf("%lld %lld",r,ex1);
    else if(r==0) printf("%lld",res);
    else printf("%lld %lld %lld",res,r,ex1);
    return 0;
}
