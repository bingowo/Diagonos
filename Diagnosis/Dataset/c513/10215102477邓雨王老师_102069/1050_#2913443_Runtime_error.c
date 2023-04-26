#include<stdio.h>
#include<string.h>
int main(){
	int chance;
	scanf("%d",&chance);
	int i;
	for(i=0;i<chance;i++){
		char s[81];
		char s1[81];
		char s2[81];
		scanf("%s %s %s",s1,s2,s);
		char s3[81],s4[81]; //分别用来作为s2和s的反字符串
		int j;
		for(j=0;j<strlen(s2);j++){
			s3[j]=s2[strlen(s2)-1-j];
		} 
		for(j=0;j<strlen(s);j++){
			s4[j]=s[strlen(s)-1-j];
		}
	    char *p1=strstr(s,s1);
	    char *p2=strstr(s4,s3);
	    printf("case #%d:\n",i);
	    printf("%d\n",strlen(p2)-strlen(s2)-strlen(s)+strlen(p1)-strlen(s1));
}
return 0;
}