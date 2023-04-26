#include<stdio.h>
#include<string.h>
int main(){
	char a[100005];
	int len[100005]={0};
	int v[129]={0};
	int l=0;
	scanf("%s",a);
	for(int i=0;i<=128;i++) v[i]=-1;
	for(int i=0;i<strlen(a);i++){
		if(v[a[i]]<l){
			v[a[i]]=i;
			len[l]++;
		}
		else{
			len[v[a[i]]+1]=i-v[a[i]];
			l=v[a[i]]+1;
			v[a[i]]=i;
		}
	}
	int lenl=0,ans;
	for(int i=0;i<strlen(a);i++){
		//printf("%d\n",len[i]);
		if(len[i]>lenl){
			lenl=len[i];
			ans=i;
		}
	}
	for(int i=ans;i<ans+len[ans];i++){
		printf("%c",a[i]);
	}
}