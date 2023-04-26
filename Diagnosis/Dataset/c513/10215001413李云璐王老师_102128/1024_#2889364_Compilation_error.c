#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct
        {int number;
        int count;
        int score;}STUDENT;
        //建立
STUDENT*INPUT(int n,int m) 
{
    int a[m+1];
    for(int k=0;k<m;k++)
    scanf("%d",&a[k]);
    STUDENT*s;
    s=(STUDENT*)malloc(n*sizeof(STUDENT));
    for(int l=0;l<n;l++)
    {
      scanf("%d %d",&s[l].number,&s[l].count);
      for(int y=0;y<s[l].count;y++)
          {
             int c;
             scanf("%d",c);
             s[l].score+=a[c-1];
          }
    }
    return s;
}//输入

void sort(STUDENT*a,int n)
        {
            int compare(const void*a1,const void*a2)
            {
                STUDENT a=*(STUDENT*)a1;
                STUDENT b=*(STUDENT*)a2;
                if(a.score!=b.score) return b.score-a.score;
                else return a.number-b.number;
            }
            qsort(a,n,sizeof(STUDENT),compare);
        }
        //排序
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
       int n,m,g;
       scanf("%d %d %d\n",&n,&m,&g);
       STUDENT *p=NULL;
       p=INPUT(n,m);
       sort(p,n);
       int cot=0;
       for(int k=0;k<n;k++)
       {
           if(p[k].score>=g) cot++;
       }
       printf("case #%d:\n",i);
       printf("%d\n",count);
       for(int k=0;k<count;k++)
       {
           printf("%d %d\n",p[k].number,p[k].score);
       }
    }
       return 0;
}