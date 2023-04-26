#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char s[5005];
	int ti;	
}p;
int cmp1(const void *x, const void* y){
	if((*(p *)x).ti!=(*(p* )y).ti) return (*(p *)x).ti<(*(p* )y).ti;
	else return strcmp((*(p *)x).s,(*(p* )y).s)>0 ? 1:-1;
}
int main(){
	int t,n,i,j,k;
	scanf("%d",&t);
	for(j=0;j<t;j++){
		p p[105];
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",p[i].s);
			int di[27]={0};
			for(k=0;k<strlen(p[i].s);k++){
				if(di[p[i].s[k]-'A']==0){
					p[i].ti++;
					di[p[i].s[k]-'A']=1;
				}
			}
		}
		qsort((void *)p,n,sizeof(p[0]),cmp1);
		printf("case #%d:\n",j);
		for(i=0;i<n;i++){
			printf("%s\n",p[i].s);
		}
	}
}