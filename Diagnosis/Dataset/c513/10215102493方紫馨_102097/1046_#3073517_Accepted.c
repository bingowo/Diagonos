#include<stdio.h>
#include<string.h>

int isword(char word[]){
	for(int i=0;i<strlen(word);i++){
		if(word[i]>='A'&&word[i]<='Z'){
			word[i]+='a'-'A';
		}
	}
	if(strcmp(word,"the")&&strcmp(word,"a")&&strcmp(word,"an")&&strcmp(word,"of")&&strcmp(word,"for")&&strcmp(word,"and")){
		return 1;
	}
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		char word[101];
		int cnt=0;
		while(1){
			scanf("%s",word);
			cnt+=isword(word);
			if(getchar()=='\n'){
				break;
			}
		}
		printf("case #%d:\n",k);
		printf("%d\n",cnt);
	}
	
	return 0;
}