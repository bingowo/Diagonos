#include <stdio.h>
#include <string.h>

solve(int T)
{
	int i,j,k=0;
	char list[65];
	for (i=0;i<26;i++){
		list[i]=i+'A';
	}
	for (i=26;i<52;i++){
		list[i]=i+71;
	}
	for (i=52;i<62;i++){
		list[i]=i+'0'-52;
	}
	list[62]='+';
	list[63]='/';
	char s[101];
	int num[1000];
	int t[8];
	scanf("%s",s);
	int len=strlen(s);
	for (i=0;i<len;i++){
		for (j=0;j<8;j++){
			t[j]=s[i]%2;
			s[i]/=2;
		}
		for (j=7;j>-1;j--){
			num[k]=t[j];
			k++;
		}
	}
	while(k%6!=0){
		num[k]=0;
		k++;
	}
	int cnt=0;\
	for (i=0;i<k;i+=6){
		int weight=32;
		int sum=0;
		for (j=i;weight>0;j++){
			sum+=num[j]*weight;
			weight/=2;
		}
		printf("%c",list[sum]);
		cnt++;
	}
	while(cnt%4!=0){
		printf("=");
		cnt++;
	}
	printf("\n");
	
	
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve(i);
	}
	return 0;
}