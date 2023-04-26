#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int dp[19],num[19];
long long pow(int a,int n){
	long long ans=a;int i=1;
	if(n==0)return 1;
	if(n==1)return a;
	while(i*2<=n){
		ans=ans*ans;
		i*=2;
	}
	for(;i<n;i++){
		ans=ans*a;
	}
	return ans;
}
long long add(int *p){
	
}

int main()
{	
	for(int i=0;i<19;i++)dp[i]=0;
	long long x,y;scanf("%lld%lld",&x,&y);
	long long ret=1;
	if(x<y){
		for(long long t=x,i=0;t!=0;t/=10,i++)dp[i]=t%10;
    	int mod=x%9,p=0;
    	for(long long t=y,i=0;t!=0;t/=10,i++){num[i]=t%10;p=i;}
    	p++;
    	
    	while(p>0){
    	    int carry=1,t=0;long long emol=0;
        	while(carry!=0 && t<p && dp[p-1]<num[p-1]){
        			if(dp[t]==8){
        				dp[t]=0;
        				carry=1;
        				t++;emol+=1;
        			}
        			else {
        				dp[t]++;
        				carry=0;
        				t++;
        			}
        	}
        	while(p-1>=0 && dp[p-1]==num[p-1])p--;
    		mod+=emol+1;
    		if((mod%=9)!=0)ret++;
    		else mod=0;
    	}
	}
	printf("%lld",ret);
	return 0;
}