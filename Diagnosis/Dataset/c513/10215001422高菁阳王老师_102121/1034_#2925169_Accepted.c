#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double s[26];
int cmp(const void*a,const void*b){
	char ch1,ch2;
	int num1,num2;
	ch1=*((char*)a);
	ch2=*((char*)b);
	if(ch1>='a'&&ch1<='z') num1=ch1-'a'; else num1=ch1-'A';
	if(ch2>='a'&&ch2<='z') num2=ch2-'a'; else num2=ch2-'A';
	if(s[num2]>s[num1]) return 1;
	else if(fabs(s[num2]-s[num1])<1e-8)
	if(num1==num2) return ch2-ch1;
	else return num1-num2;
	else return -1;
}
int main(int argc, char *argv[]) {
	int n,k,len;
	char str[100];
	scanf("%d",&n);
	for(k=0;k<n;k++){
		for(int i=0;i<26;i++)
		scanf("%lf",&s[i]);
		scanf("%s",str);
		len=strlen(str);
		printf("case #%d:\n",k);
	qsort(str,len,sizeof(str[0]),cmp);
    printf("%s\n",str);
	}
	return 0;
}