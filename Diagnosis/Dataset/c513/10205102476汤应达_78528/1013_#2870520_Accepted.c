#include<stdio.h>
#include<string.h>

int main()
{
    char num[31];scanf("%s",num);
    int c[128],l=strlen(num),p=0;c['0']=0,c['1']=1,c['2']=-1;
    long long z=0,ex=1,ex1=1,x=0;
    while(num[p]!='.' && p<l) p++;
    for(int i=p-1;i>=0;i--)
    {
        z+=c[num[i]]*ex;
        ex*=3;
    }
    for(int i=p+1;i<l;i++)
    {
        x=x*3+c[num[i]];
        ex1*=3;
    }

    if(x<0 && z>0) printf("%lld %lld %lld",z-1,ex1+x,ex1);
    else if(x<0 && z<0) printf("%lld %lld %lld",z,x,ex1);
    else if(x>0 && z<0) printf("%lld %lld %lld",z+1,ex1-x,ex1);
    else if(z==0 && x!=0) printf("%lld %lld",x,ex1);
    else if(x==0) printf("%lld",z);
    else printf("%lld %lld %lld",z,x,ex1);

    return 0;
}