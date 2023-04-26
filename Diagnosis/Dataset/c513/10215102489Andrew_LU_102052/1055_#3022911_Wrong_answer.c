#include<stdio.h>
#include<string.h>
int main(){
	char a[100005];
	int len[100005]={0};
	int v[129]={0};
	int l=0;
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++){
		if(v[a[i]]==0){
			v[a[i]]=1;
			len[l]++;
		}
		else{
			for(int j=l;j<i;j++){
				if(a[j]==a[i]){
					len[j+1]=len[l]-(j-l+1);
					l=j+1;
					break;
				}
				else v[a[j]]=0;
			}
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