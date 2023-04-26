#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

int main(){
	int B,C,flag=0,i,a[128],n,n1=0,n2=0,zs[10000],xs[10000];
	long long A,fz,fm,weight;
	a['1']=1;
	a['2']=-1;
	a['0']=0;
	char s[10000];
	scanf("%s",&s);
	n=strlen(s);
	for(i=0;i<n;i++){
		if(flag==0){
			if(s[i]=='.'){
				flag=1;
				continue;
			}
			zs[n1]=a[s[i]];
			
			//printf("%d",zs[n1]);
			n1++;
		}
		else{
			//printf("ok"); 
			xs[n2]=a[s[i]];
			n2++;
		}
	}
	A=0;
	weight=1;
	for(i=n1-1;i>=0;i--){
		A+=weight*zs[i];
		weight*=3;
	}
	//printf("%d",A);
	fm=1;
	weight=1;
	fz=0;
	for(int k=0;k<n2;k++){
		fm*=3;
	}
	for(i=n2-1;i>=0;i--){
		fz+=weight*xs[i];
		weight*=3;
	}
	for(int j=fz;j>=1;j--){
		if((fz%j==0)&&(fm%j==0)){
			fz=fz/j;
			fm=fm/j;
		}
	}
	if((fz*A>0)&&(A!=0)){
		printf("%d %d %d",A,fz,fm);
	}
	else if(A==0){
		printf("%d %d",fz,fm);
	}
	else if(fz==0){
		printf("%d",A);
	}
	else if((A*fz<0)&&(A>0)){
		printf("%d %d %d",A-1,fm+fz,fm);
	}
	else{
		printf("%d %d %d",A+1,fm-fz,fm);
	}
	return 0;
}