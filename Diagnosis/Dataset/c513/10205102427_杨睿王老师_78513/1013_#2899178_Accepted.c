#include <stdio.h>
#include <math.h>
int GCD(int a,int b){
	return b == 0 ? a:GCD(b,a%b);
}
int main()
{
	char n[31];
	char ch;
	int l=0,mark=-1;
	int s[31];
	while((ch=getchar())!='\n'){
		n[l]=ch;
		s[l]=ch-48;
		if(n[l]=='.') mark=l;
		l++;
	}
	//printf("\n%d\n",mark);
	int flag=0;
	if(mark==-1){
		mark=l;
		flag=1;
	}
	int i,j;
	long long int ans=0;
	for(i=0;i<mark-1;i++){
		if(s[i]==2) s[i]=-1;
		ans=(ans+s[i])*3;
	}
	if(s[i]==2) s[i]=-1;
	ans+=s[mark-1];
	if(flag==1){
		printf("%lld",ans);
		return 0;	
	}
	long long int fm=pow(3,l-mark-1);
	long long int anss=0;
	for(i=mark+1;i<l-1;i++){
		if(s[i]==2) s[i]=-1;
		anss=(anss+s[i])*3;		
	}
	if(s[i]==2) s[i]=-1;	
	anss+=s[l-1];
	if(ans==0){
		printf("%lld %lld\n",anss,fm);		
		return 0;
	}

	if(ans>0 && anss<0){
		ans--;
		anss=fm+anss;
	}
	if(ans<0 && anss>0){
		ans++;
		anss=fm-anss;
	}
	if(ans<0 && anss<0){
		anss=-anss;
	}
	int gcd=GCD(anss,fm);
	anss/=gcd;
	fm/=gcd;
	printf("%lld %lld %lld",ans,anss,fm);	
}