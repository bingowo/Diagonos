#include<stdio.h>
#include<string.h>
typedef struct{
	char d[121];
	int len;
	int flag;
}post;
int main(){
	int N;
	post p[51],u[51],l[51];
	scanf("%d",&N);
	for(int v=0;v<N;v++) {
	scanf("%s",&p[v].d);
	if(!strcmp(p[v].d,"-")) p[v].flag=-1;
	else p[v].flag=1;
}
   int x=0,y=0;
   for(int l=0;l<N;l++){
   	if(p[l].flag==1) u[x++].d=p[l].d;
   	else if(p[l].flag==-1) l[y++]=p[l].d;
   }
   
   
	
	
}