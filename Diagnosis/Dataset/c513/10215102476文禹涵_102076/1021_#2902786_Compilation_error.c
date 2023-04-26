#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int cmp(const void *a,const void *b) {
    char p[10000];
    char *s1,*s2;
	char ch1,ch2;
	s1 = *(char(*)[21])a;
	s2 = *(char(*)[21])b;
	while(*s1 && *s2) {
	ch1=(*s1)>='a'?*s1-32:*s1;    
	ch2=(*s2)>='a'?*s2-32:*s2;      
	if(p[ch1-'A'] != p[ch2-'A'])     
	return p[ch1-'A']-p[ch2-'A'];
	else {s1++;s2++;} }
	if(*s1==0) return -1;
	else return 1; 
}

int main()
{
	int p[26];
	char s[27];
	while(scanf("%s\n",s)!=EOF) {
	    for(int i=0; i<26; i++)
		p[s[i]-'A']=i;
	char str[2200];
	char a[100][21];
	char ch;
	gets(str);
	int count = 0, i = 0,k = 0;
	while(1) {
	   int j=0;
	   while(str[i]!=' '&&str[i])
	    a[count][j++]=str[i++];
		a[count][j]='\0';
		count++;
		if(!str[i]) break; else i++; 
		}
	qsort(a,count,sizeof(a[0]),cmp);
	for(k=0;k<count-1;k++){
	    printf("%s",a[k]);}
	}
	printf("%s\n",a[k]);
	return 0;
}