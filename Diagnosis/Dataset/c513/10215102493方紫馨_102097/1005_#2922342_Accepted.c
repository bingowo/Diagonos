#include<stdio.h>
#include<string.h>
//高精度除法 8
void divide(char s[],char ret[]){
	int len = strlen(s);
	int r=s[0]-'0',i=2;
	ret[0]='0',ret[1]='.';
	while(r!=0||i<len||i==2){		
		int a;
		if(i<len){
			a=(r*10+s[i]-'0');
		}			
		else
			a=(r*10);
		
		ret[i] = a/8+'0';	
		r=a%8;
		i++;
	}
	ret[i]='\0';
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		char octal[155],dec[155],t[155],ret[155];
		scanf("%s",octal);
		int len=strlen(octal);
		t[0]=octal[len-1],t[1]='\0';
		divide(t,ret);
		for(int i=len-2;i>1;i--){
			strcpy(t,ret);
			t[0]=octal[i];
			divide(t,ret);
		}
		printf("case #%d:\n",i);
		printf("%s\n",ret);
		
	}
	return 0;
}