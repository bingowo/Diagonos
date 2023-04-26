#include <stdio.h>
#include <string.h>

void print(int N,int R);
int main()
{
	int T,N,R,i;
	scanf("%d",&T);
	for (i=0;i<T;i++){
		scanf("%d %d",&N,&R);
		print(N,R);
	}
	return 0;
 } 
 
void print(int N,int R)
{
	int a,ret,i,j,k;
	char s[100],trans;
	a=N;
	if (a<0){
		a=-a;
	}
	for (i=0;a>0;i++){
		ret=a%R;
		a=a/R;
		if(ret>=0&&ret<=9){
			s[i]=ret+'0';
		}
		else{
			s[i]=ret+55;
		}
	}
	if(N<0){
		s[i++]='-'; 
	}
	s[i]='\0';
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		trans=s[i];
		s[i]=s[j];
		s[j]=trans;
	}
	printf("%s\n",s);
}