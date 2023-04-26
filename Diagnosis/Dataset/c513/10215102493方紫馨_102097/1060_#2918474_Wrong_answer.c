#include<stdio.h>
#include<string.h>

int main()
{
	char s[101];
	scanf("%s",s);
	
	int len = strlen(s);
	int cnt=0,max=0;
	
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(cnt==0&&s[i]=='0')
				continue;
			cnt++;
		}			
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
			if(cnt>max)
				max = cnt;
			cnt = 0;
		}
	}
	
	printf("%d",max);
	return 0;
}