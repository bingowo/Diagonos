#include<stdio.h>
#include<math.h>
typedef struct
{
    long long num;//学号
    int score1;
    int score2;
    int score3;
    int average;
}student;
int cmp1(const void * a, const void * b)//按第一种成绩排序
{
    student s1=*(student *)a;
    student s2=*(student *)b;
    if (s1.score1 != s2.score1)
        return s1.score1 - s2.score1 > 0 ? -1 :1;
    else
        return s1.num - s2.num;
}
int cmp2(const void * a, const void * b)//按第二种成绩排序
{
    student s1=*(student *)a;
    student s2=*(student *)b;
    if (s1.score2 != s2.score2)
        return s1.score2 - s2.score2 > 0 ? -1 :1;
    else
        return s1.num - s2.num;
}
int cmp3(const void * a, const void * b)//按第三种成绩排序
{
    student s1=*(student *)a;
    student s2=*(student *)b;
    if (s1.score3 != s2.score3)
        return s1.score3 - s2.score3 > 0 ? -1 :1;
    else
        return s1.num - s2.num;
}
int cmpa(const void * a, const void * b)//按平均成绩排序
{
    student s1=*(student *)a;
    student s2=*(student *)b;
    if (s1.average != s2.average)
        return s1.average - s2.average > 0 ? -1 :1;
    else
        return s1.num - s2.num;
}
int main(){
int T;int  n;int  i;int j;
student stu[101];
scanf("%d",&T); 
for (i = 0; i < T; i++){
    scanf("%d",&n);
    for (j = 0; j < n; j++){
        scanf("%lld%d%d%d",&stu[j].num,&stu[j].score1,&
        stu[j].score2,&stu[j].score3);
        stu[j].average = round((stu[j].score1 + 
        stu[j].score2 + stu[j].score3) / 3.0); 
    }
    printf("case #%d:\n",i);
    qsort(stu,n,sizeof(stu[0]),cmpa);//按照平均值排序
    printf("A:\n");
    printf("%lld\n",stu[0].num);
    for(int j=1;j<n;j++){//输入可能存在的相同成绩的数据
        if(stu[j].average==stu[j-1].average) 
            printf("%lld\n",stu[j].num);
        else break; }
    qsort(stu,n,sizeof(stu[0]),cmp1);
    printf("C:\n");
    printf("%lld\n",stu[0].num);
    for(int j=1;j<n;j++){
        if(stu[j].score1==stu[j-1].score1) 
        printf("%lld\n",stu[j].num);
        else break;} 
    qsort(stu,n,sizeof(stu[0]),cmp2);
    printf("M:\n");
    printf("%lld\n",stu[0].num);
    for(int j=1;j<n;j++){
        if(stu[j].score2==stu[j-1].score2)
        printf("%lld\n",stu[j].num);
        else break;} 
    qsort(stu,n,sizeof(stu[0]),cmp3);
    printf("E:\n");
    printf("%lld\n",stu[0].num);
    for(int j=1;j<n;j++){
        if(stu[j].score3==stu[j-1].score3) 
            printf("%lld\n",stu[j].num);
        else break;}
    }
    return 0;
}