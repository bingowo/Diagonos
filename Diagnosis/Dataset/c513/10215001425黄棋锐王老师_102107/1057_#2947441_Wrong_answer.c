#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void order(char*s,int n){
	char t;
	t=s[n];
	for(;n>=1;n--) s[n]=s[n-1];
	s[0]=t;
}
char ch(char c){
	if('a'<=c&&c<='z') c='A'+c-'a';
	return c;
}
 int main()
 {
 	 char w[1002]={'\0'};
 	 char c;
 	 int j=0;
 	 for(;(c=getchar())==' ';);
 	 do{
 	 	c=ch(c);
 	 	w[j]=c;
 	 	if(w[j]>w[0]) order(w,j);
 	 	j++;
	  }while((c=getchar())!=EOF);
	  w[j]='\0';
	  printf("%s",w);
		return 0;
}