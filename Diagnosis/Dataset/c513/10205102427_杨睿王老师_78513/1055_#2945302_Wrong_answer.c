#include <stdio.h>
#include <string.h>
char s[1000000];
char ans[1000000];
char res[1000000];
int fun(char a,int l){
	for(int p=0;p<l;p++){
		if(s[p]==a) return 0;
	}
	return 1;
}

int main()
{
	char ch;
	int l=0;
	int ls=0;
	int cnt=1;
	int result=0;
	memset(s,'\0',1000000);
	memset(ans,'\0',1000000);
	memset(res,'\0',1000000);
	while((ch=getchar())!='\n'){
		s[l]=ch;
		l++;		
	}
	if(l==1){
		printf("%s",s);
		return 0;
	}
	int i=0,j=0;
	while(i<l){
		ans[ls]=s[i];
		ls++;
		//printf("test-fun:%d\n",fun(s[i+1],i));
		if(fun(s[i+1],i)==1){
			i++;
			ans[ls]=s[i];
			//printf("test-ans:%s\n",ans);
			cnt++;
		}
		else{
			//printf("test-ans:%s\n",ans);
			if(cnt>result){
				result=cnt;
				strcpy(res,ans);ls=0;
				memset(ans,'\0',1000000);
			}
			else{
				cnt=1;
				ls=0;
				memset(ans,'\0',1000000);
			}
			if(s[i]!=s[i+1]){
				ans[ls]=s[i];
				ls++;
				i++;
				ans[ls]=s[i];
			}
			else{
				i++;
			}
		}
	}
	if(cnt>result){
		result=cnt;
		strcpy(res,ans);
	}
	printf("%s",res);
}