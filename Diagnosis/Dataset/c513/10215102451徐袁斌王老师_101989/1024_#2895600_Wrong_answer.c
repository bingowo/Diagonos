#include<stdio.h>
#include<math.h>
#include<string.h>
struct stu 
{
	char num[11];
	int score;
}; 
int cmp(const void *a,const void *b)
{
	struct stu *p1=(struct stu *)a;
	struct stu *p2=(struct stu *)b;
	if(p1->score!=p2->score)  {return p2->score-p1->score;}
	else {return strcmp(p1->num,p2->num);}
}
int main()
{
	int t,n,m,g,a[10],d[10]={0},j=0,b,i=0,k=0;
	scanf("%d",&t);
	struct stu c[500];
	struct stu *p=c;
	char ans[10][500][15]={0};
	for(int o=0;o<t;o++)
	{
		scanf("%d %d %d",&n,&m,&g);
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%s",p[i].num);
			scanf("%d",&j);
			for(k=0;k<j;k++)
			{
				scanf("%d",&b);
				p[i].score+=a[b-1];
			}
			if(p[i].score>=g) {d[o]++;}
		}
		qsort(p,n,sizeof(struct stu),cmp);
		for(int l=0;l<d[o];l++)
		{
			for(int v=0;v<11;v++)
			{ans[o][l][v]=p[l].num[v];}
			ans[o][l][11]=' ';
			ans[o][l][12]=(p+l)->score/10+48;
			if((p+l)->score>99)
			{
				ans[o][l][13]=((p+l)->score%100)/10+48;
				ans[o][l][14]=(p+l)->score%10+48;
			}
			else{ans[o][l][13]=(p+l)->score%10+48;}
			
		}
		for(k=0;k<n;k++)
		{
			p[k].score=0;
		}
	}
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n",i);
		printf("%d\n",d[i]);
		for(j=0;j<d[i];j++)
		{
			for(int k=0;k<14;k++)
			{
				printf("%c",ans[i][j][k]);
			}
			if(ans[i][j][14]!='\0'){printf("%c",ans[i][j][14]);}
			printf("\n");
		}
	}
	
	
	

	
	return 0;
	
	
 } 