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
        zh*=3;
        if(s[i]=='1')zh+=1;
        if(s[i]=='2')zh-=1;
    }
    if(s[i]=='.'){
        i++;
        for(;i<l;i++){//小数
            mu*=3;zi*=3;
            if(s[i]=='1')zi+=1;
            if(s[i]=='2')zi-=1;
        }
    }
    long long go;
    if(zi==0){
        if(zh>0)printf("%lld\n",zh);
        else printf("%lld\n",zh);
    }
    else{
        if(zh==0){
            go=measure(abs(mu),abs(zi));
            mu/=go;zi/=go;
            if(zi>0)printf("%lld %lld\n",zi,mu);
            else printf("%lld %lld\n",zi,mu);
        }
        else if(zh>0){
            if(zi>0){
                go=measure(abs(mu),abs(zi));
                mu/=go;zi/=go;
                printf("%lld %lld %lld",zh,zi,mu);
            }
            else{
                zi+=mu;zh-=1;
                go=measure(abs(mu),abs(zi));
                mu/=go;zi/=go;
                printf("%lld %lld %lld",zh,zi,mu);
            }
        }
        else{
            if(zi>0){
                zi=mu-zi;zh+=1;
                go=measure(abs(mu),abs(zi));
                mu/=go;zi/=go;
                printf("%lld %lld %lld",zh,zi,mu);
            }
            if(zi<0){
                go=measure(abs(mu),abs(zi));
                mu/=go;zi/=go;
                printf("%lld %lld %lld",zh,zi,mu);
            }
        }
    }
}