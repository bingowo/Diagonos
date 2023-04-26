#include<stdio.h>
#include<string.h>
int main()
{
	char s[50];
	scanf("%s",s);
	int ret=1,cnt=1;
	for(int i=1;i<strlen(s);i++){
		if(s[i]==s[i-1]){
			if(cnt>ret)
				ret=cnt;
			cnt=1;			
		}else{
			cnt++;
		}
	}
	if(cnt>ret)
		ret=cnt;
	printf("%d",ret);
	
	return 0;
}