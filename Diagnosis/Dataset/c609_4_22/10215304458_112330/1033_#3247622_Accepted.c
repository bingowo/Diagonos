#include<stdio.h>
#include<string.h>
int main(){
	int i,j,k,t,q[10]={1};
	char base64[70];
	for(i=0;i<65;++i){
		if(i<26) base64[i]='A'+i;
		else if(i<52) base64[i]='a'+i-26;
		else if(i<62) base64[i]='0'+i-52;
		else if(i==62) base64[i]='+';
		else if(i==63) base64[i]='/';
		else base64[i]='=';
	}
	for(i=1;i<8;++i) q[i]=2*q[i-1];
	scanf("%d",&t);
	for(i=0;i<t;++i){
		int a1[1010],a2[300];
		char s[110];
		scanf("%s",s);
		printf("case #%d:\n",i);
		int len1=strlen(s);
		for(j=0;j<len1;++j){
			for(k=0;k<8;++k){
				a1[8*j+k]=s[j]>=q[7-k];
				if(s[j]>=q[7-k]) s[j]-=q[7-k];
			}
		}
		k=0;
		while((8*len1+k)%6){
			a1[8*len1+k]=0;
			++k;
		}
		int len2=(8*len1+k)/6;
		for(j=0;j<len2;++j){
			a2[j]=0;
			for(k=0;k<6;++k){
				a2[j]+=a1[6*j+k]*q[5-k];
			}
		}
		k=0;
		while((len2+k)%4){
			a2[len2+k]=64;
			++k;
		}
		for(j=0;j<(len2+k)/4*4;++j){
			printf("%c",base64[a2[j]]);
		}
		printf("\n");
	}
	return 0; 
}