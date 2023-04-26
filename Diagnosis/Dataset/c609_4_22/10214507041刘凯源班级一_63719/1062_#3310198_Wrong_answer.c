#include<stdio.h>
#include<stdlib.h>

typedef struct operation{
	int cnt[101];
}OP;

int allcnt[201]={0};
int len;

OP stack[101];
int sz=0;

void push(OP op1){
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
	OP opcur,op2,opprev,opnext;
	while(ca--)
	{
		for(i=1;i<=len;i++)
		{
			scanf("%d",&opcur.cnt[i]);
		}
		for(i=1;i<=len;i++){
			opprev.cnt[i]=0;opnext.cnt[i]=0;op2.cnt[i]=0;}
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
	}
	for(i=1;i<=len;i++)res+=allcnt[i];
	return res;
}

signed main()
{
	printf("%d",sov());
	return 0;
}