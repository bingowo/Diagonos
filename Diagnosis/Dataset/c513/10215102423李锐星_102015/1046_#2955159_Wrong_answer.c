#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d",&T);
	int i;
	char c;
	c=getchar();
	char s[101];
	for (i=0;i<T;i++){
		int cnt=0;
		int j=0;
		while((c=getchar())!='\n'){
			if(c!=' '){
				s[j]=c;
				j++;
			}
			else{
				s[j]='\0';
				j=0;
				if(strcmp(s,"the")!=0&&strcmp(s,"a")!=0&&strcmp(s,"an")!=0&&strcmp(s,"of")!=0&&strcmp(s,"for")!=0&&strcmp(s,"and")!=0){
					cnt++;
				}
			}
		}
		s[j]='\0';
		if(strcmp(s,"the")!=0&&strcmp(s,"a")!=0&&strcmp(s,"an")!=0&&strcmp(s,"of")!=0&&strcmp(s,"for")!=0&&strcmp(s,"and")!=0){
			cnt++;
		}
		printf("case #%d:\n",i);
		printf("%d\n",cnt);		
	}
	return 0;
}