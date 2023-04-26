#include<stdio.h>
#include<stdlib.h>
struct queue{
	int num;
	int score;
	int win;
	int lose;
};
/*int cmp(const void*a,const void*b)
{
	struct queue qa=*(struct queue*)a;
	struct queue qb=*(struct queue*)b;
	if(qa.score!=qb.score){
		return(qa.score -qb.score );
	}
	else{
		if(qa.win!=qb.win)
		{
			return(qa.win -qb.win );
		}
		else{
			if(qa.lose!=qb.lose)
			{
			    return(qa.lose -qb.lose );	
			}
			else{
				return(qa.num -qb.num );
			}
		}
	}
}*/
int cmp(const void*a,const void*b)
{
	struct queue qa=*(struct queue*)a;
	struct queue qb=*(struct queue*)b;
	if(qa.score!=qb.score){
		if(qa.score>qb.score)return -1;
		else return 1;
		return 0;
	}
	else{
		if(qa.win!=qb.win)
		{
			if(qa.win>qb.win)return -1;
		    else return 1;
		    return 0;
		}
		else{
			if(qa.lose!=qb.lose)
			{
			    if(qa.lose<qb.lose)return -1;
			    else return 1;
			    return 0;	
			}
			else{
				if(qa.num<qb.num)return -1;
				else return 1;
				return 0;
			}
		}
	}
}
int main()
{
	int n,m;//n为队列数，m为比赛场数 
	scanf("%d%d",&n,&m);
	while(n!=0&&m!=0)
	{
		struct queue q[11];//不能动态定义为queue[n+1] 
		for(int k=1;k<=10;k++)//初始化 
		{
			q[k].num =k;
			q[k].score=0;
			q[k].lose =0;
			q[k].win =0;
		}
		for(int i=0;i<m;i++)//录入单组数据 
		{
			int number1,number2,c;
			scanf("%d%d",&number1,&number2);
			scanf("%d",&c);
			//q[number1].num=number1;
			//q[number2].num=number2;
			if(c==1){
				q[number1].score +=3;
				q[number2].score -=1;
				q[number1].win ++;
				q[number2].lose ++;
			}
			if(c==-1){
				q[number1].score -=1;
				q[number2].score +=3;
				q[number1].lose ++;
				q[number2].win ++;
			}
			if(c==0){
				q[number1].score +=1;
				q[number2].score +=1;
			}
		}
		/*for(int t=1;t<=n;t++){
			printf("score:(t)%d %d %d\n",t,q[t].num,q[t].score);
		}*/
		qsort(q+1,n,sizeof(q),cmp);//q+1？？？ 
		for(int k=1;k<n;k++){
			printf("%d ",q[k].num);
		}
		//printf("\n");
		printf("%d",q[n].num);
		scanf("%d%d",&n,&m);
	}
	return 0;
}