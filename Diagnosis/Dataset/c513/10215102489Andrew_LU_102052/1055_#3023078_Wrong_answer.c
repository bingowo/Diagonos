#include<stdio.h>
#include<string.h>	
char a[2000005];
int len[2000005]={0};
int main(){
	int v[309]={0};
	int l=0;
	scanf("%s",a);
	printf("%d",strlen(a));
	for(int i=0;i<=308;i++) v[i]=-1;
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
	int lenl=0,ans=0;
	for(int i=0;i<strlen(a);i++){
		//printf("%d\n",len[i]);
		if(len[i]>lenl){
			lenl=len[i];
			ans=i;
		}
	}
	//printf("%d\n",ans);
	for(int i=ans;i<ans+len[ans];i++){
		printf("%c",a[i]);
	}
}