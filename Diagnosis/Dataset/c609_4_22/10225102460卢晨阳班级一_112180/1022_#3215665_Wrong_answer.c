#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct email{
	char mail[10000];
	char name[10000];
	int loc;
}ema;

int cmp(const void*a,const void*b){
	ema*aa=(ema*)a;
	ema*bb=(ema*)b;
	if(aa->name==bb->name)
	return(strcmp(aa->mail,bb->mail));
	else
	return(strcmp(aa->name,bb->name));
}

int cmpp(const void*a,const void*b){
	ema*aa=(ema*)a;
	ema*bb=(ema*)b;
	if(aa->name!=bb->name)
	return((-1)*strcmp(aa->mail,bb->mail));
	else
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	ema s[10000];
	for(int i=0;i<n;i++){
		s[i].loc=0;
		for(int j=0;j<10000;j++){
			s[i].mail[j]=0;
			s[i].name[j]=0;
		}
	}
	for(int i=0;i<n;i++)
	scanf("%s",s[i].mail);
	for(int i=0;i<n;i++){
		for(int j=0;;j++){
			if(s[i].mail[j]=='@'){
				s[i].loc=j+1;
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;;j++){
			s[i].name[j]=s[i].mail[s[i].loc];
			s[i].loc++;
			if(s[i].mail[s[i].loc]=='\0')
			break;
		}
	}
	qsort(s,n,sizeof(s[0]),cmpp);
	qsort(s,n,sizeof(s[0]),cmp);
	for(int i=0;i<n;i++)
	printf("%s\n",s[i].mail);
	
	return 0;
 } 