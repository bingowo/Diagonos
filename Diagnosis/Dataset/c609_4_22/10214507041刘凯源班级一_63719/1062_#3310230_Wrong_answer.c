#include<stdio.h>
#include<stdlib.h>
//164ovo
typedef struct operation{
	int cnt[101];
}OP;

OP stack[211];
int allcnt[101]={0};
int len,sz=0;
const int debug=0;

void push(OP op1){
	int is_all_zero=1;
	for(int i=1;i<=len;i++)if(op1.cnt[i]!=0){is_all_zero=0;break;}
	if(is_all_zero)return;
	stack[sz]=op1;
	sz++;
	for(int i=1;i<=len;i++)allcnt[i]+=op1.cnt[i];
}

OP top(){return stack[sz-1];}

void pop(){sz--;
	for(int i=1;i<=len;i++)allcnt[i]-=stack[sz].cnt[i];
}

int must_pop_before_push(OP op1){
	for(int i=1;i<=len;i++)if(allcnt[i]>op1.cnt[i])return 1;
	return 0;
}

int sov()
{
	int ca,res=0,i,j,k,l;
	scanf("%d%d",&ca,&len);
	OP opcur,opprev,opnext;
	while(ca--)
	{
		for(i=1;i<=len;i++)
		{
			scanf("%d",&opcur.cnt[i]);
			opprev.cnt[i]=0;
			opnext.cnt[i]=0;
		}
		while(must_pop_before_push(opcur))
		{
			for(i=1;i<=len;i++)res+=opprev.cnt[i];
			opprev=top();
			pop();
		}
		for(i=1;i<=len;i++)
		{
			j=opcur.cnt[i]-(allcnt[i]+opprev.cnt[i]);
			res+=(j>0?j:-j);
			if(j>0)
			{
				opnext.cnt[i]=j;
			}
			else
			{
				opprev.cnt[i]+=j;
			}
		}
		push(opprev);
		push(opnext);
		if(debug){//debug_output
			printf("\nAfter operation: res=%d  stack_size=%d\n",res,sz);
			printf("Stack sum:\n     ");
			for(j=1;j<=len;j++)printf(" %d",allcnt[j]);
			printf("\nStack content:\n");
			for(i=0;i<sz;i++)
			{
				printf("[%d]  ",i);
				for(j=1;j<=len;j++)
				{
					printf(" %d",stack[i].cnt[j]);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	for(i=1;i<=len;i++)res+=allcnt[i];
	return res;
}

signed main()
{
	printf("%d",sov());
	return 0;
}