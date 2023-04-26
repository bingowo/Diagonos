#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char name[11];//学号 
	int num;//答对题数 
	int index[num];//题号 
	int score=0;
}stu;

stu *Input(int n,char a[])
{
	stu *p=(stu*)malloc(sizeof(stu)*n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",(p+i)->name);
		scanf("%d",&(p+i)->num);
		for(int j=0;j<(p+i)->num;j++){
			scanf("%d",&(p+i)->index[j]);
			int m=(p+i)->index[j];
			(p+i).score+=m*a[m];
	}
	return p;
}
}
int cmp(const void*a,const void*b)
{
	stu *aa=(stu*)a;
	stu *bb=(stu*)b;
	int x,y;
	x=aa->score;y=bb->score;
	if(x>y)return -1;
	else if(x<y)return 1;
	else{return strcmp(aa->name,bb->name);
	}
}
int main()
{
	int t;scanf("%d",&t);//问题数 
	for(int i=0;i<t;i++){
		int n,m,g,x=0;scanf("%d%d%d",&n,&m,&g);//学生，题目，分数线 
		int a[m];
		for(int j=0;j<m;j++){
			scanf("%d",&a[i]);
		}//题目分值 
		
	printf("case #%d:\n",i);
		
	stu *s=Input(n,a[m]);//输入每个同学的数据
	qsort(s,n,sizeof(stu),cmp);
	
	for(int q=0;q<n;q++){
		if(s[q].score>=g)x++;
		}
	printf("%d\n",x);
	
	for(int q=0;q<n;q++){
		if(s[q].score>=g){
			printf("%s %d\n",s[q].name,s[q].score);
		}
	}
 } 

 }