#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void*a,const void*b){
	int *p1,*p2;
	p1=*(int(*)[4])a;p2=*(int(*)[4])b;
	if(*p1!=*p2)return *p1>*p2?-1:1;  //倒序排序
	else{
		if(*(p1+1)!=*(p2+1))return *(p1+1)>*(p2+1)?-1:1;
		else{
			if(*(p1+2)!=*(p2+2))return *(p1+2)>*(p2+2)?1:-1;
			else{
				return *(p1+3)<=*(p2+3)?-1:1;
			}
		}
	}
}
int main() {
	int n,m,i,j,a,b,c;
	int score[11][4];  //积分 胜场 负场 编号 
	scanf("%d%d",&n,&m);
	while(n!=0 && m!=0){
		for(i=0;i<11;i++){
			for(j=0;j<4;j++)score[i][j]=0;
		}
		for(i=0;i<n;i++)score[i][3]=i+1; 
		for(i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&c);
			if(c==1){  //a胜b
			    score[a-1][0]+=3;score[a-1][1]+=1;
				score[b-1][0]-=1;score[b-1][2]+=1;
			}
			else if(c==-1){
				score[b-1][0]+=3;score[b-1][1]+=1;
				score[a-1][0]-=1;score[a-1][2]+=1;
			}
			else if(c==0){
				score[a-1][0]+=1;score[b-1][0]+=1;
			}
		}
		qsort(score,n,sizeof(score[0]),cmp);
		for(i=0;i<n;i++)printf("%d ",score[i][3]);
		printf("\n");
		scanf("%d%d",&n,&m);
	}
	return 0;
}