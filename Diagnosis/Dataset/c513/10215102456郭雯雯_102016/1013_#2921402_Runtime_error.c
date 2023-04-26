#include<stdio.h>
#include<string.h>

long long measure(long long x, long long y)//求最大公约数
{
	long long z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;
	}
	return z;
}
int main(){
    char s[31];
    scanf("%s",s);
    long long zh=0,zi=0,mu=1;
    int l=strlen(s),i;
    for(i=0;i<l&&s[i]!='.';i++){//整数
        if(s[i]=='1')zh=(zh+1)*3;
        if(s[i]=='2')zh=(zh-1)*3;
        if(s[i]=='0')zh*=3;
    }
    if(s[i]=='.'){
        i++;
        for(;i<l;i++){//小数
            mu*=3;
            if(s[i]=='1')zi=(zi+1)*3;
            if(s[i]=='2')zi=(zi-1)*3;
            if(s[i]=='0')zi*=3;
        }
    }
    if(zi<0){
        zi+=mu;
        zh-=1;
    }
    long long go=measure(mu,zi);
    mu/=go;zi/=go;
    if(zh==0)printf("%lld %lld\n",zi,mu);
    if(zi==0)printf("%lld\n",zh);
    if(zh<0)printf("-%lld %lld %lld",zh,zi,mu);
    return 0;
}