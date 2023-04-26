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
	char c=getchar();
	int k;
	for(k=0;k<chance;k++){
		printf("case #%d:\n",k);
		char s[1000];
		gets(s);
		char s1[1000];
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
	char s2[1000];
	int t=0;
	int i=0;
	while(i<=strlen(s)){
		if(s[i]>='A'&&s[i]<='Z'){
			s2[i]=s1[t];
			t=t+1;
			i=i+1;
		}
		else{
			s2[i]=s[i];
			i=i+1;
		}
}
	printf("%s\n",s2);
	}	
} 