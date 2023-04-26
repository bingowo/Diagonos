#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(){
	int Roma[128];
	Roma['I']=1;Roma['V']=5;Roma['X']=10;
	Roma['L']=50;Roma['C']=100;Roma['D']=500;Roma['M']=1000;
	char s[55];
	scanf("%s",s);
	int flag=1;//所得数要乘的10的次方
	int i=0,cnt=0;
	long long data[1000];
	for(i=0;i<strlen(s);i++){
		switch(s[i]){
			case '(':flag=flag*1000;break;
			case ')':flag=flag/1000;break;
			default :data[cnt++]=Roma[s[i]]*flag;break;
		}
	}
	long long ans=0;//求和
	for(i=0;i<cnt-1;i++){//注意最后一位必为正数 
		if(data[i]<data[i+1]) ans-=data[i];
		else ans+=data[i];
	}
	ans+=data[i];
	printf("%lld",ans);
	return 0;
}