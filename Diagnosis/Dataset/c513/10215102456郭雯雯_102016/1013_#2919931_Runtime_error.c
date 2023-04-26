#include<stdio.h>
#include<string.h>

int measure(int x, int y)//求最大公约数
{
	int z = y;
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
        zi=mu-zi;
        zh-=1;
    }
    int go=measure(mu,zi);
    mu/=go;zi/=go;
    if(zh==0)printf("%d %d",zi,mu);
    if(zi==0)printf("%d",zh);
    if(zh<0)printf("-%d %d %d",zh,zi,mu);
    return 0;
}