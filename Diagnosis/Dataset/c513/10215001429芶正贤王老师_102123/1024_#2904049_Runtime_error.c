/*1024*/
#include<stdio.h>

/* 问题数

每个问题： 
学生人数N  考试题目数M  分数线G
M个题目分别对应的分值
接下来N行：学号  解出题目总数S  这S个题目的题号   
*/ 

int main()
{
	int T;//问题数
	scanf("%d",&T);
	int index;
	long long int N_student;//学生数量
	int N_students[500];//存储学生数据 
	int N_quiz;//考试题目数
	int scores[10];
	int line;//分数线 
	char idnum[500];
	int Qright[500][11];//二维数组 正确的题数及题号 
	int sum[500]={0};
	int crossline = 0; 
	
	int i,j,r;
	
	for(index = 0;index < T;index++)
	{
		printf("case #%d\n",index);
		scanf("%lld %d %d",&N_student,&N_quiz,&line);//读入 学生人数N  考试题目数M  分数线G
		
		for(i = 0;i < N_quiz;i++)//读入 M个题目分别对应的分值
			scanf("%d",&scores[i]);
		
		for(j = 0;j < N_student;j++)//读入 N行：学号  解出题目总数S  这S个题目的题号 
		{
			
			scanf("%c %d",&idnum[j],&Qright[j][0]);//先读学号和对的题数 
			for(r = 1;r < Qright[j][0];r++)
			{
				scanf("%d",&Qright[j][r]);
				sum[j] += Qright[j][r];
			}
			if(sum[j] > line || sum[j] == line)
			crossline++;
			
		}
		printf("%d\n",crossline);
		
	}
	/*完成输入*/
	
	
	
	
}