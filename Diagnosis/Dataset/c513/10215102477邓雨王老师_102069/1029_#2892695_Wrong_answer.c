#include<stdio.h>
#include<string.h>
int cmp(const void*a,const void*b){
	char x,y;
	x=*(char*)a;
	y=*(char*)b;
	if(x>=y) return 1;
	else return -1;
}
int main(){
	int chance;
	scanf("%d\n",&chance);
	int i;
	for(i=0;i<chance;i++){
		printf("case #%d:\n",i);
		char s[300];
		gets(s);
		char s1[300];
		int j=0;
		int m=0;
		while(s[j]!='\0'){
			if(s[j]>='A'&&s[j]<='Z'){
				s1[m]=s[j];
				j=j+1;
				m=m+1;
			}
			else j++;
		}
		s1[j]='\0';
	qsort(s1,strlen(s1),sizeof(char),cmp);
	char s2[300];
	for(i=0;i<strlen(s);i++){
		if(s[i]>='A'&&s[i]<='Z'){
			s2[i]=s1[i];
		}
		else{
			s2[i]=s[i];
		}
	}
	printf("%s\n",&s2);
	}	
} 