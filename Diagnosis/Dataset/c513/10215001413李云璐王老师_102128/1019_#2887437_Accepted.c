#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
typedef struct{
    int number;
    int score;
    int win;
    int lose;}TEAM;

TEAM*Input(int num,int comp)
{
    TEAM*s;
    s=(TEAM*)malloc(num*sizeof(TEAM));
    for(int i=0;i<num;i++) s[i].number=i+1;


    for(int i=0;i<comp;i++)
    {
        int a,b,c;
      scanf("%d %d %d\n",&a,&b,&c);
      if(c==1)
        {s[a-1].score+=3;s[a-1].win+=3;
      s[b-1].lose++;s[b-1].score--;}
      if(c==-1)
        {s[b-1].score+=3;s[b-1].win+=3;
      s[a-1].lose++;s[a-1].score--;}
      if(c==0) {s[a-1].score++;s[b-1].score++;}
    }
return s;
}
void sort(TEAM*p,int n)
   {
       int compare(const void*a1,const void*a2)
       {
           TEAM a=*(TEAM*)a1;
           TEAM b=*(TEAM*)a2;
           if(a.score!=b.score) return b.score-a.score;
           else if(a.win!=b.win) return b.win-a.win;
           else if(a.lose!=b.lose) return a.lose-b.lose;
           else return a.number-b.number;

       }
       qsort(p,n,sizeof(TEAM),compare);
   }

int main()
{
    int num,comp;
   while((scanf("%d%d\n",&num,&comp))!=EOF)
   {
   TEAM *s=NULL;
   s=Input(num,comp);
   
   sort(s,num);
    for(int k=0;k<num;k++)
   {
       printf("%d ",s[k].number);
   }

   printf("\n");
     }

   return 0;


}
