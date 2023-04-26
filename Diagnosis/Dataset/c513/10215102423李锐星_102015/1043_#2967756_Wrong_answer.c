#include <stdio.h>
#include <string.h>

int d(char *s,char *t)
{
	int i,k=0;
	t[0]=s[0];
	for (i=1;i<strlen(s);i++){
		if(s[i]==s[i-1]){
			t[k]='\0';
		}
		else{
			k++;
			t[k]=s[i];
		}
	}
	k++;
	t[k]='\0';
	return strlen(s)-strlen(t);
}

int cal(char *s)
{
	int len=strlen(s);
	if(len==0){
		return 1;
	}
	else if(len==1||len==2){
		return 2;
	}
	else{
		for (int i=0;i<len-2;i++){
			if(s[i]==s[i+2]){
				return 4;
			}
		}
	}
	return 2;
}

void solve(int T)
{
	char s[101],t[101];
	scanf("%s",s);
	int number;
	number=d(s,t);
	number+=cal(t);
	printf("%d\n",number);
}
int main()
{
	int T;
	scanf("%d",&T);
	int i;
	for (i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve(i);
	}
	return 0;
}