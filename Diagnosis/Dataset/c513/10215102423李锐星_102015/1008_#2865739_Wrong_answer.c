#include <stdio.h>
#include <string.h>
#include <math.h>

void trans(int a,char s[]);
int main()
{
	int T,i,x,y,ret,j,length,sign=0;
	char X[32],Y[32];
	scanf("%d",&T);
	for (i=0;i<T;i++){
		ret=0;
		scanf("%d %d",&x,&y);
		trans(x,X);
		trans(y,Y);
		if(strlen(X)<strlen(Y)){
			length=strlen(Y);
		}
		else{
			length=strlen(X);
			sign=1;
		}
		if(sign==0){
			for(j=strlen(X);j<length;j++){
				X[j]='0';
			}
			X[j]='\0';
		}
		else{
			for(j=strlen(Y);j<length;j++){
				Y[j]='0';
			}
			Y[j]='\0';
		}
		for (j=0;j<length;j++){
			if (X[j]!=Y[j]){
				ret+=1;
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}

void trans(int a,char s[])
{
	int i=0;
	if (a==0){
		s[i]='0';
		i++;
	}
	else{
		for(i;a>0;i++){
			s[i]=a%2+'0';
			a=a/2;
		}
	}
	s[i]='\0';
}