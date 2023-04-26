#include<stdio.h>
#include<string.h>
int main()
{
	char cmd[5];
	int R[4];
	//enum CMD {IN,MOV,ADD,SUB,MUL,DIV,OUT};
	while(scanf("%s",cmd)!=EOF){
		if(strcmp(cmd,"IN")==0){
			char rg[4];
			scanf("%2s",rg);
			getchar();
			scanf("%d",&R[rg[0]-'A']);			
		}
		
		if(strcmp(cmd,"ADD")==0){
			char rg1[4],rg2[4];
			scanf("%2s,%2s",rg1,rg2);
			R[rg1[0]-'A']+=R[rg2[0]-'A'];		
		}
		
		if(strcmp(cmd,"SUB")==0){
			char rg1[4],rg2[4];
			scanf("%2s,%2s",rg1,rg2);
			R[rg1[0]-'A']-=R[rg2[0]-'A'];		
		}
		
		if(strcmp(cmd,"MUL")==0){
			char rg1[4],rg2[4];
			scanf("%2s,%2s",rg1,rg2);
			R[rg1[0]-'A']*=R[rg2[0]-'A'];		
		}
		
		if(strcmp(cmd,"DIV")==0){
			char rg1[4],rg2[4];
			scanf("%2s,%2s",rg1,rg2);
			R[rg1[0]-'A']/=R[rg2[0]-'A'];		
		}
		
		if(strcmp(cmd,"OUT")==0){
			char rg1[4];
			scanf("%2s",rg1);
			printf("%d\n",R[rg1[0]-'A']);		
		}		
	}
	
	return 0;
} 