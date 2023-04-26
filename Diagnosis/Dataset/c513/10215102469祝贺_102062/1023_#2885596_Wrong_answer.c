#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define lim 1000005
char *s[100];
char buf[1000000];
int cmp(const void* a,const void* b){
    char *s1=*((char**)a),*s2=*((char**)b);
	long long n1=-1,n2=-1;
	for(int i=0;s1[i];i++){
		if(s1[i]>'9' || s1[i]<'0');
		else{
			if(n1==-1) n1=s1[i]-'0';
			else n1=n1*10+s1[i]-'0';
		}
		if(n1>=0 && (s1[i]>'9' || s1[i]<'0'))
			break;
	}
	for(int i=0;s2[i];i++){
		if(s2[i]>'9' || s2[i]<'0');
		else{
			n2=n2==-1?s2[i]-'0':n2*10+s2[i]-0;
		}
		if(n2>=0 && (s2[i]>'9' || s2[i]<'0'))
			break;
	}
	
	int ans;
	if(n1!=n2)return n1<n2?-1:1;
	else return strcmp(s1,s2)<0?-1:1;
}
int main()
{
	int i=0;
	while(scanf("%s",buf)==1){
		s[i]=(char*)malloc(sizeof(char)*strlen(buf));
		strcpy(s[i],buf);
		i++;
	}
	qsort(s,i,sizeof(char*),cmp);
	
	for(int index=0;index<i;index++){
		printf("%s ",s[index]);
		free(s[i]);
	}
	return 0;
}