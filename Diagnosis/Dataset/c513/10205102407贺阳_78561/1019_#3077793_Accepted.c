#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
	{
		int x;
		int jifen;
		int win;
		int los;
	}qd;
int cmp(const void* c,const void* d);
int main()
{
	

	while(1)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		if(n==0) break;
		qd s[n];
		int i=0;
		for(;i<n;i++)
		{
			s[i].jifen=0;
			s[i].win=0;
			s[i].los=0;
			s[i].x=i+1;
		}
		i=0;
		for(;i<m;i++)
		{
			int t[3];
			scanf("%d %d %d",&t[0],&t[1],&t[2]);
			t[0]=t[0]-1;
			t[1]=t[1]-1;

			if(t[2]==1)
			{
				s[t[0]].jifen+=3;
				s[t[0]].win+=1;
			
				s[t[1]].jifen-=1;
				s[t[1]].los+=1;
			}
			else if(t[2]==-1)
			{
				s[t[1]].jifen+=3;
				s[t[1]].win+=1;
			
				s[t[0]].jifen-=1;
				s[t[0]].los+=1;
			}
			else
			{
				s[t[1]].jifen+=1;
				s[t[0]].jifen+=1;
			}
		}
		qsort(s,n,sizeof(qd),cmp);
		i=0;
		for(;i<n;i++)
		{
			if(i<n-1) printf("%d ",s[i].x);
			else printf("%d\n",s[i].x);
		}
	}
	
	return 0;
}
int cmp(const void* c,const void* d)
{
	qd a=*(qd*)c;
	qd b=*(qd*)d;
	if(a.jifen!=b.jifen) return (b.jifen-a.jifen);
	else if(b.win!=a.win) return (b.win-a.win);
	else if(b.los!=a.los) return (a.los-b.los);
	else return(a.x-b.x);
}
