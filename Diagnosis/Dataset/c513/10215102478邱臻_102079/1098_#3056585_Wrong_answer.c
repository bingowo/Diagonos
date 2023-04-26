#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct lamp{
	char name;
	int number;
};
int main() {
	int t,i,j,z,k;
	char s[101];
	struct lamp result[4];
	int sign[4],flag[100];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s",s);
		for(j=0;j<4;j++){sign[j]=0;result[j].number=0;}  //彩灯数量回复初始化 
		flag['R']=0;flag['B']=0;flag['Y']=0;flag['G']=0;
		printf("case #%d:\n",i);
		if(strchr(s,'!')==NULL){
			for(z=0;z<t;z++)sign[z]=0;
		}  //没有坏掉的彩灯
		else {
			for(z=0,k=0;z<strlen(s);z++){
				if(s[z]=='!')result[k].number++;
				else {result[k].name=s[z];flag[s[z]]=1;}  //记录彩灯总的情况 
				if(k==3)k=0;
				else k++;
			}
			for(z=0;z<4;z++){
				if(result[z].name!='R' || result[z].name!='B' || result[z].name!='Y' || result[z].name!='G'){
					if(flag['R']==0){result[z].name='R';flag['R']=1;}
					else if(flag['Y']==0){result[z].name='Y';flag['Y']=1;}
					else if(flag['B']==0){result[z].name='B';flag['B']=1;}
					else if(flag['G']==0){result[z].name='G';flag['G']=1;}
				}
				if(result[z].name=='R')sign[0]=result[z].number;
				else if(result[z].name=='B')sign[1]=result[z].number;
				else if(result[z].name=='Y')sign[2]=result[z].number;
				else if(result[z].name=='G')sign[3]=result[z].number;
			}
		}
		for(z=0;z<4;z++)printf("%d ",sign[z]);
		printf("\n");
	}
	return 0;
}