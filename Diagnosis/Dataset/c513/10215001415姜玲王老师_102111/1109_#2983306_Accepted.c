#include <stdio.h>
#include <stdlib.h>

int main()
{
  int t,j;
  scanf("%d",&t);
  int a[9];
  for(int i=0;i<t;i++)
  {
   printf("case #%d:\n",i);
   int flag=0;
   for(j=0;j<8;j++)
   {
       scanf("%d",&a[j]);
       if(a[j]>0&&flag){printf("+");}
       if(a[j]&&j<7)
        {
          flag++;
          if(a[j]==1){printf("x^%d",8-j);}
          if(a[j]==-1){printf("-x^%d",8-j);}
          if(a[j]!=1&&a[j]!=-1){printf("%dx^%d",a[j],8-j);}
       }
       if(a[j]&&j==7)
       {
           flag++;
          if(a[j]==1){printf("x");}
          if(a[j]==-1){printf("-x");}
          if(a[j]!=1&&a[j]!=-1){printf("%dx",a[j]);}
       
   }
       
   }
   scanf("%d",&a[j]);
   if(flag==0) printf("%d",a[j]);
   else{
        if(a[j]>0)printf("+%d",a[j]);
        if(a[j]<0)printf("%d",a[j]);
   }
  printf("\n");
  }
}
