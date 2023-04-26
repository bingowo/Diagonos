#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int dc;
	char s[21];
}string;
int cmp(const void*p1,const void*p2){
	string a=*((string*)p1),b=*((string*)p2);
	if(a.dc!=b.dc){
		return b.dc-a.dc;
	}
	else{
		return strcmp(a.s,b.s);
	}
}
int main(int argc, char *argv[]) {
	int t,cas;
	scanf("%d",&t);
	for(cas=0;cas<t;cas++){
		int n,i;
		string l[100];
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",l[i].s);
			l[i].dc=0;
			int al[100];
			int da=0,j;
			for(j=65;j<=90;j++)
			{
				al[j]=0;
			}
			for(j=0;j<strlen(l[i].s);j++){
				if(al[l[i].s[j]]==0){
					al[l[i].s[j]]=1;
				}
			}
			for(j=65;j<=90;j++)
			{
				if(al[j]==1){
					l[i].dc++;
				}
			}
		}
		qsort(l,n,sizeof(l[0]),cmp);
		printf("case #%d:\n",cas);
		for(i=0;i<n;i++){
			printf("%s\n",l[i].s);
		}
	}
	return 0;
}