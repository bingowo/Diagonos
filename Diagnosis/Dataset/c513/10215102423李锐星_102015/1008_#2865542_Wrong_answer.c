#include <stdio.h>
#include <string.h>
#include <math.h>

void trans(int a,char s[]);
int main()
{
	int T,i,x,y,ret=0,j;
	char X[32],Y[32];
	scanf("%d",&T);
	for (i=0;i<T;i++){
		scanf("%d %d",&x,&y);
		trans(x,X);
		trans(y,Y);
		ret=abs(strlen(X)-strlen(Y));
		for (j=0;j<strlen(X)&&j<strlen(Y);j++){
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