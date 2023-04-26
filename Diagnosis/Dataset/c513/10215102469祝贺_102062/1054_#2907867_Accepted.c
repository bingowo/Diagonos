#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int myscanf(char(*s)[40]){
	int i=0,top=0;char c,buf[40]={0};
	while((c=getchar())==' ' || c=='\n');
	
	
	buf[top++]=c;
	while(c!='\n'){
	    while((c=getchar())!=' ' && c!='\n' && c!=EOF)
			buf[top++]=c;
	    buf[top]=0;
	    strcpy(s[i],buf);
	    if(top>0)i++;
	    top=0;
	}
	return i;
}
void place(int M,char(*s)[40],int ssp){
	int i=0;
	while(i<ssp){
		int wordsnum=1,begin=i;
		int len=strlen(s[i]);i++;
		int spacestack[70],sp=0;
		while(i<ssp && len+strlen(s[i])+1<=M){
			len+=strlen(s[i++])+1;
			spacestack[sp++]=1;
		}
		if(i<ssp){
			int space=M-len;
			for(int index=0;space>0;space--){
				if(index==sp)index=0;
				spacestack[index]++;
				index++;
			}
		}
			for(int index=begin;index<i;index++){
				printf("%s",s[index]);
				if(sp>0){
					for(int j=0;j<spacestack[sp-1];j++){
						printf(" ");
					}
				}
				sp--;
			}
			printf("\n");	
	}
}
int main(){
	int t;scanf("%d",&t);
	for(int m=0;m<t;m++){
		char s[2000][40];int ssp=0;
		int M;scanf("%d",&M);//getchar();
		ssp=myscanf(s);
		printf("case #%d:\n",m);
		place(M,s,ssp);
	} 
	return 0;
}