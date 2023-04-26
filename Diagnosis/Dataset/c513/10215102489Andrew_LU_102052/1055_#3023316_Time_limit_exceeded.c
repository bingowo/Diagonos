#include<stdio.h>
#include<string.h>	
char a[2000005];
int len=0;
int main(){
	int v[309]={0};
	int l=0;
	int loc;
	scanf("%s",a);
	for(int i=0;i<=308;i++) v[i]=-1;
	for(int i=0;i<strlen(a);i++){
		if(v[a[i]]<l){
			v[a[i]]=i;
		}
		else{
			if(len<i-l){
				len=i-l;
				loc=l;
			}
			l=v[a[i]]+1;
			v[a[i]]=i;
		}
	}
	if(len<strlen(a)-l){
		len=strlen(a)-l;
		loc=l;
	}
	for(int i=loc;i<loc+len;i++){
		printf("%c",a[i]);
	}
}