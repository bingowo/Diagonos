#include <stdio.h>
#include <string.h>

int main()
{
	char s[101];
	scanf("%s",s);
	char t[101];
	int i=0;
	int j=0;
	int res=0;
	while(i<strlen(s)-1){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i+1]>='0'&&s[i+1]<='9'){
				t[j]=s[i];
				j++;
				i++;
			}
			else{
				t[j]=s[i];
				i++;
				t[j]='\0';
				if(res<strlen(t)){
					res=strlen(t);
				}
				t[0]='\0';
				j=0;
			}
		}
	}
	printf("%d\n",res);
	return 0;
 } 