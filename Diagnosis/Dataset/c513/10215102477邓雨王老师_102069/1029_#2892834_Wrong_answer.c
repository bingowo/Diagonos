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
	char c = getchar();
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
	    int t=0;
	    int k;
	    for(k=0;k<=strlen(s);k++){
		if(s[k]>='A'&&s[k]<='Z'){
			s2[k]=s1[k];
			t=t+1;
		}
		else{
			s2[k]=s[k];
		}
	}
	s2[k]='\0';
	printf("%s\n",&s2);
	}	
} 