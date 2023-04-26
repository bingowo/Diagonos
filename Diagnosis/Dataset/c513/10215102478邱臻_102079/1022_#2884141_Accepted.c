#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	char *p1,*p2,*domain1,*domain2;
	int i=0;
	p1=*((char **)a);p2=*((char **)b);
	while(*(p1+i)!='@')i++;
	domain1=p1+i+1;
	i=0;
	while(*(p2+i)!='@')i++;
	domain2=p2+i+1;
	if(strcmp(domain1,domain2)==0)return strcmp(p2,p1);
	else return strcmp(domain1,domain2);
}

int main() {
	char** email;
	int n,len,i;
	scanf("%d",&n);   //电子邮件的个数
    email=(char**)malloc(n*sizeof(char*));  //动态分配指针数组
	char s[1000001],*p;
	for(i=0;i<n;i++){
		scanf("%s",s);
		len=strlen(s);
		p=(char*)malloc(len+1);
		strcpy(p,s);
		*(email+i)=p;
	} 
	qsort(email,n,sizeof(char*),cmp);
	for(i=0;i<n;i++)printf("%s\n",email[i]);
	for(i=0;i<n;i++){
		p=email[i];free(p);
	}
	free(email);
	return 0;
}