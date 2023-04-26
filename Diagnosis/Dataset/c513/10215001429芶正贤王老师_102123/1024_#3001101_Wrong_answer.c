/*1024*/
#include<stdio.h>

int main()
{
	int T;//问题数
	scanf("%d",&T);
	int index;
	for(index = 0;index < T;index++)
	{
        int i,j,r;               //循环用字母
        
        int N_student;           //学生人数
        int N_quiz;              //考试题目数
        int line;                //分数线
        scanf("%d %d %d",&N_student,&N_quiz,&line);//读入 学生人数N  考试题目数M  分数线G                 第一次读入！！
        getchar();
        
        int scores[10];          //N_quiz道题目的分值
        for(i = 0;i < N_quiz;i++)//读入 M个题目分别对应的分值
			scanf("%d",&scores[i]);   //第二次读入！！！
        
		int N_students[500];     //存储学生数据 ???
		
		char idnum[500][11];          //学号
        int N_Qright[500];       //解出的题目总数
        int a[500][10];            //题号
        int sum[500] = {0};      //每个小朋友的总分
        int crossline = 0;         //过线人数
        for(j = 0;j < N_student;j++) //第j个小朋友
        {
            scanf("%s",idnum + j);
            scanf("%d",&N_Qright[j]);
            for(r=0;r<N_Qright[j];r++)  //循环输入题目号
            {
                scanf("%d",&a[j][r]);
                sum[j] += scores[a[j][r]];    //uncertain
            }
            if(sum[j] > line || sum[j] == line)
                crossline++;
        }
        
        printf("case #%d:\n",index);     //序号
        printf("%d\n",crossline);        //过线人数
    }
        return 0;
	
}