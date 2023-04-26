#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long x,y,mhd;
struct node
{
	long long x,y;
	char steps[100];
	int len;
	long long wei;
};
long long dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};
struct node q[10000000];
int main(void)
{
	scanf("%lld %lld",&x,&y);
	mhd = llabs(x)+llabs(y);
	if(mhd%2==0){
		if(x==0 && y==0)
			printf("0");
		else printf("-1");
		return 0;
	}
	int step = 0;
	long long wei = 1;
	while(wei<mhd){
		step++;
		wei*=2;
	}
	printf("%d\n",step);
	struct node ans;
	int head = 0,tail = 1;
	q[0].x = 0,q[0].y = 0,q[0].len = 0,q[0].wei = 1,q[0].steps[0] = '\0';
	while(head!=tail){
		struct node cur = q[head];
		head++;
		if(cur.x==x && cur.y==y){
			ans = cur;
			break;
		}
		for(int i=0;i<4;i++){
			struct node next;
			next.x = cur.x+dx[i]*cur.wei;
			next.y = cur.y+dy[i]*cur.wei;
			next.wei = cur.wei * 2;
			strcpy(next.steps,cur.steps);
			if(i==0) next.steps[cur.len] = 'E';
			if(i==1) next.steps[cur.len] = 'W';
			if(i==2) next.steps[cur.len] = 'N';
			if(i==3) next.steps[cur.len] = 'S';
			next.steps[cur.len+1] = '\0';
			next.len = cur.len+1;
			q[tail++] = next;
		}
	}
	printf("%s",ans.steps);
	return 0;
} 