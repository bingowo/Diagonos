/*另一解法 阴间测试点注意用累乘法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long mypow(int a,int b)
{
    long long sum=1;
    for(int i=0;i<b;i++)
    {
        sum=sum*a;
    }
    return sum;
}

long long myabs(long long a)
{
    if(a<0)
        return -a;
    else
        return a;
}

void approxi(int *a,int *b)
{
    for(int i=2;i<=a;i++)
    {
        if((*a % i==0)&&(*b % i==0))
        {
            *a=*a/i;
            *b=*b/i;
            i=i-1;
        }
    }
}
int main()
{
        
        char c[100]={'\0'};
        scanf("%s",&c);
        int b=strlen(c);
        long long sum=0;
        int point=b;
        for(int j=0;j<b;j++)
        {
            if(c[j]=='.')
                point=j;
        }
        for(int j=0;j<point;j++)
        {
            if(c[j]=='2')
                sum=sum-mypow(3,point-j-1);
            else if(c[j]=='1')
                sum=sum+mypow(3,point-j-1);
        }
        if(point==b)
        printf("%lld",sum);
        else if(point<b)
        {
            long long nume=0;
            for(int j=point+1;j<strlen(c);j++)
            {
            if(c[j]=='2')
                nume=nume-mypow(3,strlen(c)-j);
            else if(c[j]=='1')
                nume=nume+mypow(3,strlen(c)-j);
            }
            long long deno=myabs(mypow(3,strlen(c)-point));
            int flagnume=1;
            if(nume<0) flagnume=-1;
            if((nume<0)&&(sum>0))
            {
                nume=deno+nume;
                sum=sum-1;
            }
            if((nume>0)&&(sum<0))
            {
                nume=deno-nume;
                sum=sum+1;
            }
            if(nume<0)
                nume=-nume;
            for(int i=2;i<=nume;i++)
            {
                if((nume % i==0)&&(deno % i==0))
                {
                    nume=nume/i;
                    deno=deno/i;
                    i=i-1;
                }
            }
            if(sum!=0) printf("%lld %lld %lld",sum,nume,deno);
            else if((sum==0)&&(flagnume==1)) printf("%lld %lld",nume,deno);
            else if((sum==0)&&(flagnume==-1)) printf("%lld %lld",-nume,deno);
        }
    return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long GCD(long long m,long long n)
{
    return n%m==0?m:GCD(n%m,m);
}
//无小数
void solveInt(char* s) {
	long long ans = 0;
	int len = strlen(s);
	for (int i = 0;i < len;++i) {
		ans *= 3;
		if (s[i] == '1')ans ++;
		if (s[i] == '0')ans += 0;
		if (s[i] == '2')ans--;
	}
	printf("%lld", ans);
}

void solveDouble(char* s) {
	long long ans=0, mu=1, zi=0;
	int len = strlen(s);int dot;
	for (int i = 0;i < len;++i) {
		if (s[i] == '.')dot = i;
	}
	for (int i = 0;i < dot;++i) {
		ans *= 3;
		if (s[i] == '1')ans++;
		if (s[i] == '2')ans--;
	}
	for (int j = dot+1;j < len;++j) {
		mu *= 3;zi *= 3;
		if (s[j] == '1')zi++;
		if (s[j] == '2')zi--;
	}
	if (zi < 0 && ans != 0) {
		zi += mu;
		ans--;
	}
	else if (zi > 0 && ans < 0) {
		ans++;zi = mu - zi;
	}
	else{;}
	long long m = mu / GCD(mu, zi);
	long long z = zi / GCD(mu, zi);
	//long long m = mu / GCD(mu, zi);
	//long long z = zi / GCD(mu, zi);
	if(m<0){m=-m;z=-z;}
	if(ans==0)printf("%lld %lld", z, m);
	else printf("%lld %lld %lld", ans, z, m);
}
int main() {
	char s[31] ={'\0'};
	scanf("%s",s);
	//printf("%ld\n",strlen(s));
	if(strchr(s,'.')==0)solveInt(s);
	else solveDouble(s);
	return 0;
}