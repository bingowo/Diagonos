#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int cmp(const void*a,const void *b){
int sum1,sum2,len1,len2;
long long int i=0,j=0;
char *str1,*str2;
str1=(char *)a;
str2=(char *)b;
len1=strlen(str1);
len2=strlen(str2);
	for(i=0,j=0;i<len1,j<len2;i++,j++){
		if(str1[i]>str2[j]) return 1;
		if(str1[i]<str2[j]) return -1;
		if(str1[i]==str2[j]) continue;
		if(str1[i]==' '&&str2[j]!=' ') return -1;
		if(str1[i]!=' '&&str2[j]==' ') return 1;
	}
}
int main()
{
    int n,m,k=0,count=0,j=0;
    long long int num;
    scanf("%d\n",&n);
    for(k=0;k<n;k++){
        scanf("%d\n",&m);
        count=m;
		num=pow(10,9);
		char s[m][num];
     while(k<m){
     	gets(s[k]);
     	k++;
	 }
    qsort(s,m,sizeof s[0],cmp);
    for(j=0;j<count-1;j++)
	printf("%s ",s[j]);
	printf("%s\n",s[count-1]);}
    return 0;
}