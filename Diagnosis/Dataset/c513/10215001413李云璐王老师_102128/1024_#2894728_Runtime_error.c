#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct
        {long long int number;
        int count;
        long long int score;}STUDENT;
        //建立
STUDENT*INPUT(int n,int m,int *a) 
{
    STUDENT*s;
    s=(STUDENT*)malloc(n*sizeof(STUDENT));
    for(int l=0;l<n;l++)
    {
      scanf("%lld %d",&s[l].number,&s[l].count);
      for(int y=0;y<s[l].count;y++)
          {
             int c;
             scanf("%lld",&c);
             s[l].score+=a[c-1];
          }
    }
    return s;
}//输入

void sort(STUDENT*a,int n)
        {
            long long int compare(const void*a1,const void*a2)
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
       int h[m+1];
    for(int k=0;k<m;k++)
    scanf("%d",&h[k]);
       STUDENT *p=NULL;
       p=INPUT(n,m,h);
       sort(p,n);
       int cot=0;
       for(int k=0;k<n;k++)
       {
           if(p[k].score>=g) cot++;
       }
       printf("case #%d:\n",i);
       printf("%d\n",cot);
       for(int k=0;k<cot;k++)
       {    long long int num=p[k].number,shu=0;
            while(num!=0)
            {
                shu++;
                num/=10;
            }
            if(shu<11) printf("0%lld %lld\n",p[k].number,p[k].score);
             else printf("%lld %lld\n",p[k].number,p[k].score);
       }
    }
       return 0;
}