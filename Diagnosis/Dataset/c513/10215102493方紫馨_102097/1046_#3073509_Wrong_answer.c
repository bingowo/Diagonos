#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		char word[101];
		int cnt=0;
		while(1){
			scanf("%s",word);
			if(strcmp(word,"the")&&strcmp(word,"a")&&strcmp(word,"an")&&strcmp(word,"of")&&strcmp(word,"for")&&strcmp(word,"and")){
				cnt++;
			}
			if(getchar()=='\n'){
				break;
			}
		}
		printf("case #%d:\n",k);
		printf("%d\n",cnt);
	}
	
	return 0;
}