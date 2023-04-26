#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct address{
	char total[300];
	char name[100];
	char vt[100];
};
int cmp(const void*a,const void*b){
	struct address p1,p2;
	p1=*(struct address*)a;p2=*(struct address*)b;
	if(strcmp(p1.name,p2.name)==0){
		return strcmp(p1.vt,p2.vt)>0?1:-1;
	}
	else return strcmp(p1.name,p2.name)>0?1:-1;
}
int main() {
	int i,j,z,flag,n;
	char str[300];
	struct address s[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",str);
		if(str[4]==':')strcpy(s[i].total,str);
		z=0;flag=0;
		for(j=0;j<strlen(s[i].total);j++){
			if(s[i].total[j]=='/' && flag==0)flag=1;
			else if(s[i].total[j]!='/' && flag==1){
				s[i].name[z++]=s[i].total[j];
				if(s[i].total[j+1]=='/'){
					flag=3;z=0;
				}
			}
			else if(flag==3){
				s[i].vt[z++]=s[i].total[j];
			}
		}
	}
	qsort(s,n,sizeof(s[0]),cmp);
	for(i=0;i<n;i++){
		printf("%s\n",s[i].total);
	} 
	return 0;
}