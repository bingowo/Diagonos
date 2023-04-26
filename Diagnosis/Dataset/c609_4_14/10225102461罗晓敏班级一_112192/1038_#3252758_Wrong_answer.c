#include <stdio.h>
#include <stdlib.h>
int duru(char **p){
	int k,j;char *temp;
	for(k=0;;k++){
			temp=(char*)malloc(30*sizeof(char));char c;
			for(j=0;c=getchar();j++){
				if(c!=','&&c!='.'&&c!='?'&&c!='!'&&c!=' '&&c!='\n')temp[j]=c;
				else if(c==','||c=='.'||c=='?'||c=='!'||c==' '||c=='\n'){
					temp[j]='\0';
					*(p+k)=temp;
					break;
				}
			}
			if(c=='\n'){
				break;
			}
		}
		return k;
}
int cmp(const void* a,const void* b){
	return strcmp(*(char**)a,*(char**)b);
}
int main(){
	int t,i;scanf("%d",&t);getchar();
	for(i=0;i<t;i++){ 
		char **p=(char**)malloc(500*sizeof(char*));
		int k=duru(p),j;
		qsort(p,k,sizeof(char*),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<k;j++){
			if(strcmp(p[j],p[j+1])!=0){
				printf("%s ",p[j]);
			}
			free(p[j]);
		}
		free(p);
	}
}
