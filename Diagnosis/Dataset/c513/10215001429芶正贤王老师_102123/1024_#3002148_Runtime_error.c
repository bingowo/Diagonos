#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char schoolid[11];         //学号
    int S;                     //解出的题目数
    int Qright[10];            //做对的题号
    int sum ;                 //总分
}Grades;


int cmpfunc(const void * a,const void * b)
    //先sum降序，后id升序
{
    Grades *x = (Grades*)a;
    Grades *y = (Grades*)b;
    if(x -> sum != y -> sum)
        return (x->sum - y->sum);
    else
        return strcmp(y -> schoolid,x -> schoolid);
}

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
        
        Grades students[500];
        
        for(j=0;j<N_student;j++)
        {
             students[j].sum = 0;
             scanf("%s",students[j].schoolid);
             scanf("%d",&students[j].S);
             for(r=0;r<students[j].S;r++)
             {
                 scanf("%d",&students[j].Qright[r]);
                 students[j].sum += scores[students[j].Qright[r]];
             }
        }
        
        int crossline=0;
        int k=0;
        Grades ans[500];
        printf("case #%d:\n",index);
        for(i = 0;i<N_student;i++)
        {
            if(students[i].sum > line)
            {
                crossline++;
                strcpy( ans[k].schoolid , students[i].schoolid );
                ans[k].sum = students[k].sum;
                k++;
            }
        }
        qsort(ans,k,sizeof(Grades),cmpfunc);
        for(i = 0;i<k;i++)
        {
            printf("%s %d\n",ans[i].schoolid,ans[i].sum);
        }
    }
    return 0;
}