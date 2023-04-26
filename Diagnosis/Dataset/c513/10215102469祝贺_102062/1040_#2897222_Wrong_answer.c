#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char buf[3][3];
int cmp1(const void*a, const void* b){
	char* s1=(char*)a,*s2=(char*)b;
	return strcmp(s1,s2)<0?-1:1;
}
void findson();
void findparent();
int main(){
	for(int i=0;i<3;i++) scanf("%s",&buf[i]);
	if(strcmp(buf[2],"?")==0) findson();
	else findparent();
	return 0;
}
void findson(){
	printf("%s %s ",buf[0],buf[1]);
	qsort(buf,2,sizeof(buf[0]),cmp1);
	if(strcmp(buf[0],"A")==0 && strcmp(buf[1],"A")==0) printf("{A,O}");
	else if(strcmp(buf[0],"AB")==0 && strcmp(buf[1],"AB")==0) printf("{A,AB,B}");
	else if(strcmp(buf[0],"B")==0 && strcmp(buf[1],"B")==0) printf("{B,O}");
	else if(strcmp(buf[0],"O")==0 && strcmp(buf[1],"O")==0) printf("{O}");
	else if(strcmp(buf[0],"A")==0 && strcmp(buf[1],"O")==0) printf("{A,O}");
	else if(strcmp(buf[0],"AB")==0 && strcmp(buf[1],"O")==0) printf("{A,B}");
	else if(strcmp(buf[0],"B")==0 && strcmp(buf[1],"O")==0) printf("{B,O}");
	else if(strcmp(buf[0],"AB")==0 && strcmp(buf[1],"B")==0) printf("{A,AB,B}");
	else if(strcmp(buf[0],"A")==0 && strcmp(buf[1],"B")==0) printf("{A,AB,B,O}");
	else if(strcmp(buf[0],"A")==0 && strcmp(buf[1],"AB")==0) printf("{A,AB,B}");
}
void findparent(){
	int i=0;
	if(strcmp(buf[0],"?")!=0) printf("%s ",buf[i]);
	else i++;
	if(strcmp(buf[2],"A")==0 && strcmp(buf[i],"A")==0) printf("{A,AB,B,O} ");
	else if(strcmp(buf[2],"A")==0 && strcmp(buf[i],"AB")==0) printf("{A,AB,B,O} ");
	else if(strcmp(buf[2],"A")==0 && strcmp(buf[i],"B")==0) printf("{A,AB} ");
	else if(strcmp(buf[2],"A")==0 && strcmp(buf[i],"O")==0) printf("{A,AB} ");
	else if(strcmp(buf[2],"B")==0 && strcmp(buf[i],"A")==0) printf("{B,AB} ");
	else if(strcmp(buf[2],"B")==0 && strcmp(buf[i],"B")==0) printf("{A,AB,B,O} ");
	else if(strcmp(buf[2],"B")==0 && strcmp(buf[i],"AB")==0) printf("{A,AB,B,O} ");
	else if(strcmp(buf[2],"B")==0 && strcmp(buf[i],"O")==0) printf("{AB,B} ");
	else if(strcmp(buf[2],"AB")==0 && strcmp(buf[i],"A")==0) printf("{AB,B} ");
	else if(strcmp(buf[2],"AB")==0 && strcmp(buf[i],"B")==0) printf("{A,AB} ");
	else if(strcmp(buf[2],"AB")==0 && strcmp(buf[i],"AB")==0) printf("{A,AB,B} ");
	else if(strcmp(buf[2],"AB")==0 && strcmp(buf[i],"O")==0) printf("impossible ");
	else if(strcmp(buf[2],"O")==0 && strcmp(buf[i],"A")==0) printf("{A,B,O} ");
	else if(strcmp(buf[2],"O")==0 && strcmp(buf[i],"B")==0) printf("{A,B,O} ");
	else if(strcmp(buf[2],"O")==0 && strcmp(buf[i],"O")==0) printf("{A,B,O} ");
	else if(strcmp(buf[2],"O")==0 && strcmp(buf[i],"AB")==0) printf("impossible ");
	
	if(i==1) printf("%s ",buf[i]);
	printf("%s ",buf[2]);
}
