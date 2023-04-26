#include <stdio.h>
#include <string.h>

int fpos(char* s,char *t)
{
	int i,j=0;
	for (i=0;i<strlen(t)&&j<strlen(s);i++){
		if(s[j]==t[i]){
			j++;
		}
		else{
			j=0;
		}
	}
	if(j==strlen(s)){
		return i-1;
	}
	else{
		return -1;
	}
}
int tpos(char *s,char *t)
{
	int len1=strlen(s)-1,len2=strlen(t)-1;
	for (;len2>-1&&len1>-1;len2--){
		if(s[len1]==t[len2]){
			len1--;
		}
		else{
			len1=strlen(s)-1;
		}
	}
	if(len1==-1){
		return len2+1;
	}
	else{
		return -1;
	}
}

void solve(int T)
{
	char s1[81],s2[81],s[81];
	scanf("%s%s%s",s1,s2,s);
	int pos1,pos2,pos3,pos4;
	pos1=fpos(s1,s);
	pos2=fpos(s2,s);
	pos3=tpos(s1,s);
	pos4=tpos(s2,s);
	if((pos1==-1&&pos3==-1)||(pos2==-1&&pos4==-1)){
		printf("0\n");
	}
	if(pos4>pos1){
		printf("%d\n",pos4-pos1-1);
	}
	else if(pos3>pos2){
		printf("%d\n",pos3-pos2-1);
	}
	
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