#include<stdio.h>
#include<string.h>
typedef struct {
	int len;
	char word[15];
}data;
data ch[4000];
int n;
//如果找到返回1 
int find(char *a,int d){
	char t[15];
	strcpy(t,a);
	*(t+d) = '\0';
	for(int i=0;i<n;i++){
		if(ch[i].len==d){
			if(strcmp(t,ch[i].word)==0)
				return i;
		}
	}
	return -1;
}
int main()
{
	scanf("%d",&n);
	int i=0,a;
	for(;i<n;i++){
		scanf("%s",ch[i].word);
		ch[i].len = strlen(ch[i].word);
	}
	char s[5001];
	scanf("%s",s);	
	char *p = s;
	while(p<s+strlen(s)){
		
		int d = 14;
		while(d>=1&&(a=find(p,d))==-1)
			d--;
		if(d==0){
			if(p==s+strlen(s)-1)
				printf("%c\n",*p);
			else
				printf("%c ",*p);
			p++;
		}else{
			p+=d;
			if(p==s+strlen(s))				
				printf("%s\n",ch[a].word);	
			else
				printf("%s ",ch[a].word);	

		}
	}	
	return 0;
}