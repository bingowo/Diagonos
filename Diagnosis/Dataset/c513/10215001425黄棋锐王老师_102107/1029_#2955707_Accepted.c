#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void*a,const void *b)
{
	return *(char*)a-*(char*)b;
}
 int main()
 {  int k,T;
 	scanf("%d\n",&T);
	 for(k=0;k<T;k++)
	 {  char s[202]={'\0'};
	 		gets(s);
	 	char s1[202]={'\0'};
	 	int i=0,j=0;
	 	for(i=0;i<strlen(s);i++){
	 		if('A'<=s[i]&&s[i]<='Z') s1[j++]=s[i];
		 }
		 printf("case #%d:\n",k);
		 if(j>0){
		 	qsort(s1,strlen(s1),sizeof(char),cmp);
		 	i=0,j=0;
		 	while(i<strlen(s))
		 	{   
		 		for(;i<strlen(s)&&s[i]==' ';i++) printf("%c",s[i]);
		 		for(;i<strlen(s)&&s[i]!=' ';i++)
				 {
		 			if(j<strlen(s1)&&'A'<=s[i]&&s[i]<='Z') printf("%c",s1[j++]);
					 else printf("%c",s[i]);	
				 }
				 for(;i<strlen(s)&&s[i]==' ';i++)printf("%c",s[i]);
			 }
		 }
		else printf("%s",s);
	 	printf("\n");
	 } 
		return 0;
}