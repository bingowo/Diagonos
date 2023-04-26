#include <stdio.h>
#include <stdlib.h>
struct team
{
	int num;
	int score;
	int win;
	int lose;
};
int cmp(const void *a,const void *b)
{
	struct team* A=(struct team*)a;
	struct team* B=(struct team*)b;
	if(A->score!=B->score) return(B->score-A->score);
	else
	{
		if(A->win!=B->win) return(B->win-A->win);
		else
		{
			if(A->lose!=B->lose) return(A->lose-B->lose);
			else return(A->num-B->num);
		}
	}
}
int main()
{
	int n=1,m=1;
    while(n!=0 && m!=0)
    {
        scanf("%d %d",&n,&m);
        int a=0,b=0,c=0;
        struct team *L=(struct team*)malloc(n*sizeof(struct team)); 
        for(int i=0;i<n;i++)
        {
        	L[i].num=i+1;
        	L[i].win=0;
        	L[i].lose=0;
        	L[i].score=0;
		}
        for(int i=0;i<m;i++)
        {
        	scanf("%d %d %d",&a,&b,&c);
            if(c==1) {L[a-1].score+=3;L[a-1].win+=1;L[b-1].score-=1;L[b-1].lose+=1;}
            else if(c==-1){L[a-1].score-=1;L[a-1].lose+=1;L[b-1].score+=3;L[b-1].win+=1;}
            else {L[a-1].score+=1;L[b-1].score+=1;}
		}
		qsort(L,n,sizeof(struct team),cmp);
		for(int i=0;i<n;i++)
		{
			if(i!=n-1) printf("%d ",L[i].num);
			else printf("%d\n",L[i].num);
		}
		free(L); 
	}
	return 0;
}