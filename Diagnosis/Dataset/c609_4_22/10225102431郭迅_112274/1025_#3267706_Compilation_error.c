#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int num;
	int time[2];
	int score;
 } compet;
compet Input(int n)
{
	//队伍编号，次数，分数 
	compet *p=(compet*)malloc(sizeof(compet)*n);
	for(int i=0;i<n;i++){
		(p+i)->num=i;
		(p+i)->time[0]=0;//胜 
		(p+i)->time[1]=0;//负 
		(p+i)->score=0;
	}
	return p;	
}
int cmp(const void *a,const void*b)
{
	compet *aa=(compet*)a;
	compet *bb=(compet*)b;
	int x=aa->score;
	int y=bb->score;
	if(x>y) return y-x;
	else if(x<y) return x-y;
	else{
		if(aa.time[0]>bb.time[0]) return bb.time[0]-aa.time[0];
		}
		else if(aa.time[0]<bb.time[0]) return aa.time[0]-bb.time[0];
		else{
			if(aa.time[1]>bb.time[1]) return aa.time[1]-bb.time[1];
			else if(aa.time[1]<bb.time[1]) return bb.time[1]-aa.time[1];
			else{
				return aa.num-bb.num;
			}
		}
	}
}
void Sort(compet *p,int n)
{
	qsort(p,n,sizeof(compet),cmp);
}
int main()
{
	int n,m;//m比赛次数 
	scanf("%d%d",&n,&m);
	compet *t=NULL;
	t=Input(n);//输入n支队伍的初始值 
	
	//输入数据啦
	int a,b,c;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(c==1) {
			t[a]->time[0]+=1;
			t[b]->time[1]+=1;
			t[a]->score+=3;
			t[b]->score-=1;
		}
		else if(c==-1) {
			t[b].time[0]+=1;
			t[a].time[1]+=1;
			t[b].score+=3;
			t[a].score-=1;
		}
		else{
			t[a].score+=1;
			t[b].score+=1;
		}
	} 
	
	Sort(t,n);//排序 
	
	for(int j=0;j<n-1;j++)
	{
		printf("%d ",t[j].num);
	}
	printf("%d\n",t[j]);
 } 
