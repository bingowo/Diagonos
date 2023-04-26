#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
int Big(int l,int m)
{
	int i=2;
	for(i=2;l%i==0&&m%i==0;i++);
	return i-1;	
}

int Bin1(char a)
{
	int m=0;
	while(a!=0){
	if(a&1){m++;a=a>>1;
	}
	else {a=a>>1;}}
	return m;
}
int main()
{
	int n,i=0;
	scanf("%d",&n);
	getchar();
	char s[n][120];
	for(i=0;i<n;i++){
		gets(s[i]);
		
	} 
	for(i=0;i<n;i++){
		int l=8*strlen(s[i]);
		printf("%d\n",l);
		int j,m=0;
		for(j=0;j<strlen(s[i])-1;j++){
			m+=Bin1(s[i][j]);
		}
		int a=Big(l,m);

		if(a==1);
		else{l/=a;m/=a;
		}
		printf("%d/%d",m,l);
		}
	}
	 
