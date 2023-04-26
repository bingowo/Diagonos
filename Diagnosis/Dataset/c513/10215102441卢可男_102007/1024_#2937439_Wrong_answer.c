#include<stdio.h>
#include<stdlib.h>
#define L 11//学号长度
#define Q 11//题目数+1
 struct student
{
    char ID[L];
    int amount;
    int tihao[Q];
    int sum;
} a[500], b[500];//定义结构体

int cmp(const void*a,const void*b)//
{
	struct student* pa=(struct student*)a,* pb=(struct student*)b;
	if(pb->sum>pa->sum) return 1;
	if(pa->sum>pb->sum) return-1;
	if(xuehao(pa->ID,pb->ID)==1) return 1;
	if(xuehao(pa->ID,pb->ID)==-1) return -1;
	return 0;
}
void Sort(struct student *ps,int n)
{
    qsort(ps,n,sizeof(ps[0]),cmp);
}
int xuehao(char*a,char*b)
{
    for(int i=0;i<L;i++)
    {
        if(a[i]>b[i]) return 1;
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {

        int i,N,M,G;//学生人数，题目数，分时线
        scanf("%d %d %d",&N,&M,&G);
        int A[Q]={0};
        for (i=1;i<=M;i++)
        {
            scanf("%d ",&A[i]);//每道题的分值
        }
        int c=0;
        for(int h=0;h<N;h++)//每位学生的信息输入
        {
            int sum=0;
            scanf("%s %d ",a[h].ID,&a[h].amount);
            for(int r=0;r<a[h].amount;r++)

            {scanf("%d",&a[h].tihao[r]);
             sum+=A[a[h].tihao[r]];
            }
            if (sum>=G)
            {
                a[h].sum=sum;
                b[c]=a[h];
                c=c+1;

            }


        }

        Sort(b,c);

        printf("case #%d:\n",j);
        printf("%d\n",c);
       for(int p=0;p<c;p++)
        {
            printf("%s %d\n",b[p].ID,b[p].sum);
        }

     }

        return 0;
}
