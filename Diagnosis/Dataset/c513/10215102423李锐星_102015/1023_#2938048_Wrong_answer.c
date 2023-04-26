#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char str1[31];
}STR1;
typedef struct{
	char str2[31];
	char str3[31];
	char str4[31];
}STR2;

void trans(STR2 a)
{
	int j=0,k=0;
	for (int i=0;i<strlen(a.str2);i++){
		if (a.str2[i]>='0'&&a.str2[i]<='8'){
			a.str4[k]=a.str2[i];
			k++;
		}
		else{
			a.str3[j]=a.str2[i];
			j++;
		}
	}
}

int cmpletter(const void* a,const void* b)
{
	STR1 x,y;
	x=*(STR1*)a;
	y=*(STR1*)b;
	return strcmp(x.str1,y.str1);
}

int cmpnumber(const void* a,const void* b)
{
	STR2 x,y;
	x=*(STR2*)a;
	y=*(STR2*)b;
	trans(x);
	trans(y);
	if(strcmp(x.str4,y.str4)==0){
		return strcmp(x.str3,y.str3);
	} 
	return strcmp(x.str4,y.str4);
}



int main()
{
	char s[31];
	STR1 s1[100];
	STR2 s2[100];
	int m=0,n=0;
	while(scanf("%s",s)!=EOF){
		int x=0,y=0;
		for(int i=0;i<strlen(s);i++){
			if (s[i]>='0'&&s[i]<='8'){
				s2[m].str2[x]=s[i];
				x++;
				m++;
			}
			else{
				s1[n].str1[y]=s[i];
				y++;
				n++;
			}
		}
	}
	qsort(s1,n,sizeof(STR1),cmpletter);
	qsort(s2,m,sizeof(STR2),cmpnumber);
	for (int i=0;i<n;i++){
		printf("%s ",s1[i].str1);
	}
	for (int i=0;i<m-1;i++){
		printf("%s ",s2[i].str2);
	}
	printf("%s\n",s2[m-1].str2);
	return 0;
}