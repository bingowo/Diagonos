#include<stdio.h>

int main()
{
	char s[55];
	int cnt=1,max=0;
	int i=0;
	while(scanf("%c",&s[i])!=-1&&s[i]!='\n'){
		if(i!=0){
			if(s[i]!=s[i-1])
			cnt++;
			else
			cnt=1;
		}
		i++;
		if(cnt>=max)
		max=cnt;	
	}
	printf("%d\n",max);
}