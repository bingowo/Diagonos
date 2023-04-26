#include<stdio.h>
#include<math.h>
#include<string.h> 

void anti(char s[],char t[],int d){
	for(int i=0;i<d;i++){
		if(s[i]=='0')
			t[i]='1';
		if(s[i]=='1')
			t[i]='0';	
	}
}


int main()
{
	int i,d=1;
	const int N=pow(2,14);
	scanf("%d",&i);
	char s[2*N+1];
	s[0]='0';
	for(int j=0;j<i;j++){
		char t[N+1];
		anti(s,t,d);
		strncpy(s+d,t,d);
		d*=2;
	}
	s[d+1]='\0';
	printf("%s",s);
	return 0;
 } 