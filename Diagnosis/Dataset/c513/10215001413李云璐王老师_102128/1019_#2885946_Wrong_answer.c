#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
   int num,comp;
   scanf("%d %d\n",&num,&comp);
  typedef struct{int number;int score;int win;int lose;}TEAM;
   TEAM s[num+1];
   for(int i=0;i<=num;i++)
   {
       s[i].score=0;
       s[i].win=0;
       s[i].lose=0;
       s[i].number=0;
   }
   for(int i=0;i<comp;i++)
   {
      int a,b,c;
      scanf("%d %d %d\n",&a,&b,&c);
      s[a].number=a;
      s[b].number=b;
      if(c==1)
        {s[a].score++;s[a].win++;
      s[b].lose++;s[b].score--;}
      if(c==-1)
        {s[b].score++;s[b].win++;
      s[a].lose++;s[a].score--;}
      if(c==0) {s[a].score++;s[b].score++;}

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
   sort(s,num);
   for(int k=1;k<=num;k++)
   {
       printf("%d ",s[k].number);
   }
   printf("\n");

   return 0;


}