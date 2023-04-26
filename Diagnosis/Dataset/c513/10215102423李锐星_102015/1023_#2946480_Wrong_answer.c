#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char all[31];
	char letter[31];
	char num[31];
	unsigned long long  sum;
}STRING;

int cmp(const void* a,const void* b)
{
	STRING x,y;
	x=*(STRING*)a;
	y=*(STRING*)b;
	int len1=strlen(x.num),len2=strlen(y.num);
	if(len1==0&&len2==0){
		return strcmp(x.all,y.all);
	}
	else if(len1==0&&len2!=0){
		return -1;
	}
	else if(len2==0&&len1==0){
		return 1;
	}
	else{
		if(x.sum<y.sum){
			return -1;
		}
		else if(x.sum>y.sum){
			return 1;
		}
		else{
			return strcmp(x.all,y.all);
		}
	}
}
int main()
{
	STRING str[100];
	char s[31];
	int n=0;
	while(scanf("%s",s)!=EOF){
		int i,j=0,k=0;
		str[n].sum=0;
		for (i=0;i<strlen(s);i++){
			if(s[i]>='0'&&s[i]<='9'){
				str[n].num[k]=s[i];
				k++;
				str[n].sum=str[n].sum*10+s[i]-'0';
			}
			else{
				str[n].letter[j]=s[i];
				j++;
			}
			str[n].all[i]=s[i];
		}
		str[n].num[k]='\0';
		str[n].letter[j]='\0';
		str[n].all[i]='\0';
		n++;
	}
	qsort(str,n,sizeof(str[0]),cmp);
	for (int i=0;i<n;i++){
		printf("%s ",str[i].all);
	}
	return 0;
 } 