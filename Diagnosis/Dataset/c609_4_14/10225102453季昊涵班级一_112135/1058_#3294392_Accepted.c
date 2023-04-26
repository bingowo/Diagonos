#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	char s[1005];
	int len=0,cnt=0,ans_pos=0;
	int flag=1,num[1005],ans[1005];
	scanf("%s",s);
	if(s[0]=='-')
	flag=-1;
	len=strlen(s);
	for(int i=len-1;i>=0;i--){
		if(s[i]=='-')
		break;
		num[++cnt]=s[i]-'0';
	}
	while(cnt){
		if(num[1]%2==1){
			if(flag==-1)
			num[1]++;
			else
			num[1]--;
			ans[++ans_pos]=1;
		}
		else
		ans[++ans_pos]=0;
		for(int i=cnt;i;i--){
			num[i-1]+=10*(num[i]%2);
			num[i]/=2;
		}
		while(cnt>0&&num[cnt]==0)
		cnt--;
		flag*=-1;
	}
	for(int i=ans_pos;i;i--){
		printf("%d",ans[i]);	
	}
	
	return 0;
}