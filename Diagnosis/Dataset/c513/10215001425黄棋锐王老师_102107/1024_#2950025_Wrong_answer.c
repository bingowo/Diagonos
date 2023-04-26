#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct{
	char name[15];
	int score;
} student;

 int cmp(const void*a,const void*b){
 	student* aa=(student*)a;
 	student* bb=(student*)b;
 	return bb->score-aa->score;
 }
 int main()
 {
 	 int k,T;
 	 scanf("%d",&T);
 	 for(k=0;k<T;k++)
	  {   int N=0,M=0,G=0;
	      int point[12]={0};
	      scanf("%d %d %d\n",&N,&M,&G);
	  		int i,j;
	  		for(i=1;i<=M;i++){
	  			scanf("%d",&point[i]);
//	  			if(i==M) printf("\n");//*******************
			  }
	  		student stu[501];
	  		for(i=0;i<N;i++){
	  			int count=0;
	  			int out=0;
	  			stu[i].score=0;
	  			scanf("%s %d",stu[i].name,&count);
	  			for(j=0;j<count;j++){
	  				scanf("%d",&out);
	  				stu[i].score+=point[out];
				  }
			  }
			  qsort(stu,N,sizeof(stu[0]),cmp);
 	 			printf("case #%d:\n",k);
 	 			for(i=0;i<N;i++)
				  {
 	 			     if(stu[i].score>=G)	
				    {
				       printf("%s %d",stu[i].name,stu[i].score);
 	 				    printf("\n");
				    }
				  }
	  }
		return 0;
}