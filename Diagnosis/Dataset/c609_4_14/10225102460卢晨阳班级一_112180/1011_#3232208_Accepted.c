#include<stdio.h>
#include<string.h>

int main()
{
	char s[31];
	scanf("%s",s);
	int temp=0;
	long long ans=0,fz=0,fm=1;
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='.'){
			temp=i;
			break;
		}
		ans*=3;
		if(s[i]=='1') ans+=1;
		if(s[i]=='2') ans-=1;
	}
	for(int i=temp+1;i<strlen(s);i++){
		if(temp==0)break;
		fz*=3;
		fm*=3;
		if(s[i]=='1') fz+=1;
		if(s[i]=='2') fz-=1;
	}
	if(ans>0&&fz<0){
		ans--;
		fz+=fm;
	}
	if(ans<0&&fz>0){
		ans++;
		fz=fm-fz;
		if(ans==0)fz=-fz;
	}
	while(fz%3==0&&fz!=0){
		fz/=3;
		fm/=3;
	}
	if(fz!=0){
		if(ans==0)
		printf("%lld %lld\n",fz,fm);
		else
		printf("%lld %lld %lld\n",ans,fz,fm);
	}else{
		printf("%lld\n",ans);
	}
	return 0;
 } 