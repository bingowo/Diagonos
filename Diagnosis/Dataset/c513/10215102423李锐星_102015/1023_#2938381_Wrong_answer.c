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
	if (strlen(x.num)==0&&strlen(y.num)==0){
		return strcmp(x.all,y.all);
	}
	if (strlen(x.num)==0&&strlen(y.num)!=0){
		return -1;
	}
	if (strlen(x.num)!=0&&strlen(y.num)==0){
		return 1;
	}
	if(x.sum==y.sum){
		return strcmp(x.all,y.all);
	}
	
	if(x.sum<y.sum){
		return -1;
	}
	return 1;
}

int main()
{
	STRING str[100];
	char s[31];
	int n=0;
	while(scanf("%s",s)!=EOF){
		int i,j=0,k=0;
		str[i].sum=0;
		for (i=0;i<strlen(s);i++){
			if(s[i]>='0'&&s[i]<='9'){
				str[n].num[k]=s[i];
				k++;
				str[n].sum+=str[n].sum*10+s[i]-'0';
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
		printf("%llu ",str[n].sum);
		printf("\n");
		n++;
	}
	qsort(str,n,sizeof(str[0]),cmp);
	for (int i=0;i<n;i++){
		printf("%s ",str[i].all);
	}
	return 0;
 } 