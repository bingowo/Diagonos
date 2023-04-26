#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	char s[100];
	char part[100];
	int size[100];
	int sp;
}st;
long long f(st a,st b){
	long long ans=0;
	for(int i=0;i<a.sp;i++){
		long long temp=a.size[i]-b.size[i]>0?a.size[i]-b.size[i]:-a.size[i]+b.size[i];
		ans+=temp;
	}
	return ans;
}
int main(){
	int number;long long ret=-2;
	scanf("%d",&number);
	st str[number];
	for(int i=0;i<number;i++){
		scanf("%s",&str[i]);str[i].sp=0;
		for(int j=0;j<strlen(str[i].s);j++){
			if(str[i].sp==0){
				str[i].size[str[i].sp]=0;
				str[i].part[str[i].sp++]=str[i].s[j];
			} 
			else if(str[i].part[str[i].sp-1]==str[i].s[j]);
			else{
				str[i].size[str[i].sp]=0;
				str[i].part[str[i].sp++]=str[i].s[j];
				if(i!=0 && (str[i].sp>str[i-1].sp || str[i].part[str[i].sp-1]!=str[i-1].part[str[i].sp-1])){
					ret=-1;break;
				}
			}
			str[i].size[str[i].sp-1]++;
		}
		if(ret==-1)break;
	}
	if(ret==-1){
		printf("-1");
		return 0;
	}
	
	for(int i=0;i<number;i++){
		long long temp=0;
		for(int j=0;j<number;j++){
			if(j==i)continue;
			temp+=f(str[i],str[j]);
		}
		if(temp<ret || ret==-2)ret=temp;
	}
	printf("%lld",ret);
	return 0;
}