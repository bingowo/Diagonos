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
	int lena=strlen(a);
	for(int i=0;i<lena;i++){
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
	if(len<lena-l){
		len=lena-l;
		loc=l;
	}
	for(int i=loc;i<loc+len;i++){
		printf("%c",a[i]);
	}
}