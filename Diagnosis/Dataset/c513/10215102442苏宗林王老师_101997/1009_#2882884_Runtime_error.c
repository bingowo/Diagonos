#include<stdio.h>
#include<stdlib.h> 
#include<string.h>


int main(){
	int fm,i,n,j,a,fz;
	char s[10000],fdafdf[9];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		gets(fdafdf);
		gets(s);
		j=0;
		fz=0;
		while(s[j]!='\0'){
			a=s[j];
			for(int m=0;m<8;m++){
				fz+=((a>>m)&1);
			}
			j++;
		}
		fm=(sizeof(s))*8;
		for(int k=fz;k>=1;k--){
			if((fz%k==0)&&(fm%k==0)){
				fz=fz/k;
				fm=fm/k;
			}
		}
		printf("%d/%d",fz,fm);
	}
	return 0;
}