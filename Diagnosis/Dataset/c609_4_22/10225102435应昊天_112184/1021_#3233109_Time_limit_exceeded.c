#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int pos(char c);
int cmp(const void* a,const void* b);
static char tab[27];
int main(){
	scanf("%s",tab);
	char p[101][21];
	int cnt = 0;                   //字符串个数 
	int len = 0;
	int flag = 1;
	char c;
	while(flag){
		scanf("%s",tab);
		while((c = getchar()) != '\n' && c != EOF){
			if(!isspace(c))
				p[cnt][len++] = c;
			else{
				p[cnt][len] = '\0';
				cnt++;
				len = 0;
			}
		}
		p[cnt][len] = '\0';
		for(int i = 0;i <= cnt;i++)
			printf("%s%c",p[i],(i==cnt-1 ? '\n' : ' '));
		qsort(p,cnt,sizeof(p[0]),cmp);
		/*for(int i = 0;i <= cnt;i++)
			printf("%s%c",p[i],(i==cnt-1 ? '\n' : ' '));*/
		if(c == EOF)
			flag = 0;
		cnt = 0;
		len = 0;
		for(int j = 0;j < sizeof(p)/sizeof(p[0]);j++){
			memset(p[j],0,sizeof(p[j]));
		}
	}
	return 0;
}
int pos(char c){
	c = toupper(c);
	int i;
	for(i = 0;i < 26;i++){
		if(tab[i] == c)
			break;
	}
	return i;
}
int cmp(const void* a,const void* b){
	char* aa = (char*)a;
	char* bb = (char*)b;
	int cnt = 0;
	int ret;
	while(cnt < strlen(aa) && cnt < strlen(bb)){
		if(pos(aa[cnt]) < pos(bb[cnt])){
			ret = -1;	
			break;
		}
		else if(pos(aa[cnt]) > pos(bb[cnt])){
			ret = 1;
			break;
		}
		else 
			continue;
	}
	return ret;
}
	 