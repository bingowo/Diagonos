#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	char s[55];
	int ti;	
}tt;
int cmp1(const void *x, const void* y){
	if((*(tt *)x).ti!=(*(tt* )y).ti) return (*(tt *)x).ti<(*(tt* )y).ti;
	else return strcmp((*(tt *)x).s,(*(tt* )y).s)>0;
}
int main(){
	int t,n,i,j,k;
	scanf("%d",&t);
	for(j=0;j<t;j++){
		tt p[105];
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",p[i].s);
			int di[27]={0};
			p[i].ti=0;
			for(k=0;k<strlen(p[i].s);k++){
				if(di[p[i].s[k]-'A']==0){
					p[i].ti++;
					di[p[i].s[k]-'A']=1;
				}
			}
			//printf("%d\n",p[i].ti);
		}
		qsort((void *)p,n,sizeof(p[0]),cmp1);
		printf("case #%d:\n",j);
		for(i=0;i<n;i++){
			printf("%s\n",p[i].s);
		}
	}
}

