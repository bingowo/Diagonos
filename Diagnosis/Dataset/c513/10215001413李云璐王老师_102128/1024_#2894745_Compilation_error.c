#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct
        {char number[12];
        int count;
        int score;}STUDENT;
        //建立
STUDENT*INPUT(int n,int m,int *a) 
{
    STUDENT*s;
    s=(STUDENT*)malloc(n*sizeof(STUDENT));
    for(int l=0;l<n;l++)
    {
      scanf("%s %d",&s[l].number,&s[l].count);
      for(int y=0;y<s[l].count;y++)
          {
             int c;
             scanf("%d",&c);
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
                else if(a.number[0]!b.number[0]) return a.number[0]-b.number[0];
                else if(a.number[1]!=b.number[1]) return a.number[1]-b.number[1];
                else if(a.number[2]!=b.number[2]) return a.number[2]-b.number[2];
                else if(a.number[3]!=b.number[3]) return a.number[3]-b.number[3];
                else if(a.number[4]!=b.number[4]) return a.number[4]-b.number[4];
                else if(a.number[5]!=b.number[5]) return a.number[5]-b.number[5];
                else if(a.number[6]!=b.number[6]) return a.number[6]-b.number[6];
                else if(a.number[7]!=b.number[7]) return a.number[7]-b.number[7];
                else if(a.number[8]!=b.number[8]) return a.number[8]-b.number[8];
                else if(a.number[9]!=b.number[9]) return a.number[9]-b.number[9];
                else return a.number[10]-b.number[10];
               
                
                
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
       {     printf("%s %lld\n",p[k].number,p[k].score);
       }
    }
       return 0;
}