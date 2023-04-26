#include<stdio.h>
#include<string.h>
int main()
{
	char s[101];
	scanf("%s",s);
	char num[101];
	int a=0,sign=0,t=0,max=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[a++] = s[i];
			sign=1;
		}else{
			if(sign==0){
				continue;
			}
			if(sign==1){
				num[a]='\0';
				a=0;
				while(num[a++]=='0');
				t = strlen(num)-a+1;
				a=0;
				if(t>max)
					max=t;
				sign=0;
			}
		} 
	}
	num[a]='\0';
	a=0;
	while(num[a++]=='0');
	t = strlen(num)-a+1;
	if(t>max)
		max=t;
	printf("%d",max);
	
	return 0;
}