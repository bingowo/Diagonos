#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int p[26];
int cmp(const void* a,const void*b){
	char *s1,*s2;
	char ch1,ch2;
	s1=*(char(*)[21])a;s2=*(char(*)[21])b;
	while(*s1 & *s2){
		ch1=(*s1)>='a'?*s1-32:*s1;
		ch2=(*s2)>='a'?*s2-32:*s2;
		if(p[ch1-'A']!=p[ch2-'A'])return p[ch1-'A']-p[ch2-'A'];
		else {
			s1++;s2++;
		}
	}
	if(*s1==0)return -1;
	else return 1;
}
int main(){
	char alpha[27];
	char a[100][21];
	int i,j;
	int count=0,k=0,status=0;
	char c;
	while(scanf("%s",alpha)!=EOF){
		for(i=0;i<26;i++){
			p[alpha[i]-'A']=i;
		}
		getchar();
		do{
			c=getchar();
			if(c!=' ' && c!='\n'){
				a[count][k++]=c;status=1;
			}
			else if(status){
				a[count][k]='\0';count++;k=0;status=0;
			}
		}while(c!='\n');
		qsort(a,count,sizeof(a[0]),cmp);
		for(i=0;i<count;i++){
			printf("%s",a[i]);
			if(i==count-1)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}