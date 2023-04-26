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
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		printf("case #%d:\n",i);
		char s[201];
		scanf("%s",&s);
		char s1[201];
		int j=0;
		while(s[j]!='\0'){
			int m=0;
			if(s[j]>='A'&&s[j]<='Z'){
				s1[m]=s[j];
				j=j+1;
				m=m+1;
			}
			else j++;
		}
		s1[j]='\0';
		qsort(s1,strlen(s1),sizeof(s1[0]),cmp);
	int t=0;
	for(j=0;j<strlen(s);j++){
		if(s[j]>='A'&&s[j]<='Z') printf("%s",s1[t++]);
		else printf("%s",s[j]);
	}
	}	
} 