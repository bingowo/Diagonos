#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		printf("case #%d:\n",i);
		int num,sign=0;
		for(int i=8;i>1;i--){
			scanf("%d",&num);
			if(num!=0){
				if(sign!=0&&num>0)
					printf("+");
				sign=1;
				if(num==1)
					printf("x^%d",i);
				else if(num==-1)
					printf("-x^%d",i);
				else
					printf("%dx^%d",num,i);
			}
		}
		scanf("%d",&num);
		if(num!=0){
			if(num>0)
				printf("+");
			sign=1;
			if(num==1)
				printf("x",i);
			else if(num==-1)
				printf("-x",i);
			else
				printf("%dx",num,i);
		}
		scanf("%d",&num);
		if(sign==0)
			printf("%d",num);
		else if(num!=0){
			if(num>0)
				printf("+%d",num);
			else
				printf("%d",num);
		}
			
				
		printf("\n");	
	}
	
	return 0;
}