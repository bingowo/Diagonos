#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int isvalid(char a[]){
	char s[][5]={"the","a","an","of","for","and"};
	for(int i=0;i<6;i++){
		if(strcmp(a,s[i])==0)
			return -1;
	}
	return 1;	
}
int main()
{
	int T;
	char s[101];
	scanf("%d",&T);
	getchar();
	for(int i=0;i<T;i++){		
		gets(s);
		int cnt=0;
		int a=0;
		char word[15]={'\0'};	
		for(int j=0;j<strlen(s);j++){					
			if(s[j]==' '){				
				word[a]='\0';
				a=0;
				if(isvalid(word))
					cnt++;
				continue;
			}			
			word[a]=s[j];
			a++;			
		}
		printf("case #%d:\n",i);
		printf("%d\n",cnt);
	}
	return 0;
}