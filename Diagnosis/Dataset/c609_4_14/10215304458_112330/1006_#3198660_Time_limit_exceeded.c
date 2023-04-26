#include<stdio.h>
#include<string.h>
int main(){
	long long ans,t,i,len,j,q,p,cnt,flag[70],num[70];;
	char s[70];
	scanf("%d",&t);
	for(i=0;i<t;++i){
		scanf("%s",s);
		memset(flag,0,sizeof(flag));
		memset(num,0,sizeof(num));
		len=strlen(s);
		ans=0;
		p=0;
		for(j=0;j<len;++j){
			if(s[j]>='0'&&s[j]<='9') s[j]-='0';
			else if(s[j]>='a'&&s[j]<='z') s[j]-='a'-10;
			else s[j]-='A'-36;
		}
		flag[s[0]]=1;
		num[s[0]]=1;
		cnt=1;
		q=1;
		for(j=1;j<len;++j){
			if(!flag[s[j]]){
				++cnt;
				flag[s[j]]=1;
				num[s[j]]=p;
				if(!p) p=2;
				else ++p;
			}
		}
		if(cnt==1) ++cnt;
		for(j=len-1;~j;--j){
			ans+=num[s[j]]*q;
			q*=cnt;
		}
		printf("case #%lld:\n%lld\n",i,ans);
	}
    return 0;
}