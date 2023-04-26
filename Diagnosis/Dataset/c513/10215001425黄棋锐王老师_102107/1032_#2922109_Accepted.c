#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int cmp(const void*a,const void*b){
	int*aa=(int*)a;
	int*bb=(int*)b;
	while(*aa!=-1&&*bb!=-1){
		int aaa=*aa;
		int bbb=*bb;
		if(aaa<bbb) return 1;
		else if(aaa>bbb) return -1;
		else aa++,bb++;
	}
	if(*aa==-1) return 1;
	else return -1;
}
int main(){
	  int i,T,N;
	  scanf("%d",&T);
	  for(i=0;i<T;i++){
	  	int line[1000][52]={0};
	  	scanf("%d",&N);
	  	int r,c;//r行，c列 
	  	for(r=0;r<N;r++){c=0;
	  		while(scanf("%d",&line[r][c])&&line[r][c]!=-1) c++;
		  }
		  qsort(line,N,sizeof(line[0]),cmp);//line[0]说明取两行元素比较，line[0][0]说明取同一行元素比较 
		  for(r=0;r<N;r++){
		  	for(c=0;line[r][c+1]!=-1;c++) printf("%d ",line[r][c]);
		  	printf("%d\n",line[r][c]);
		  }
	  }
	  
		
		return 0;
}