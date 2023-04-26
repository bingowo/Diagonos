#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct{
	char str[15];
	int len;
}word;
word dict[53][4000];
int sp[53];
char buf[20];
int cmp(const void*a, const void*b){
	word* s1=(word*)a,*s2=(word*)b;
	return s1->len<s2->len?1:-1;
}
int divide (char*s,int p){
	char alpha=s[p];int tag=0;
	if(islower(alpha))alpha=alpha-'a';
	else if(isupper(alpha))alpha=alpha-'A'+26;
	else alpha=52;
	for(int i=0;i<sp[alpha];i++){
		if(strncmp(s+p,dict[alpha][i].str,dict[alpha][i].len)==0){
			if(p==0)printf("%s",dict[alpha][i].str);
			else printf(" %s",dict[alpha][i].str);
			tag=1;p+=dict[alpha][i].len;
			break;
		}
	}
	if(tag==0){
		if(p==0)printf("%c",s[p]);
		else printf(" %c",s[p]);
		tag=1;p+=1;
	}
	return p;
}
int main(){
	int t;scanf("%d",&t);
	memset(sp,0,53*sizeof(int));
	for(int i=0;i<t;i++){
		scanf("%s",buf);
		if(islower(buf[0])){
			strcpy(dict[buf[0]-'a'][sp[buf[0]-'a']].str,buf);
			dict[buf[0]-'a'][sp[buf[0]-'a']].len=strlen(buf);
			sp[buf[0]-'a']++;
		}
		else if(isupper(buf[0])){
			strcpy(dict[buf[0]-'A'+26][sp[buf[0]-'A'+26]].str,buf);
			dict[buf[0]-'A'+26][sp[buf[0]-'A'+26]].len=strlen(buf);
			sp[buf[0]-'A'+26]++;
		}
		else {
			strcpy(dict[52][sp[52]].str,buf);
			dict[52][sp[52]].len=strlen(buf);
			sp[52]++;
		}
	}
	for(int i=0;i<53;i++){
		qsort(dict[i],sp[i],sizeof(word),cmp);
	}
	char s[5010];scanf("%s",s);
	int p=0;
	while(p<strlen(s)){
		p=divide(s,p);
	}
	printf("\n");
	return 0;
}