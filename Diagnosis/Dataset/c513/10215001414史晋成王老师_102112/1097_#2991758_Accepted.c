#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct data
{ char c;
  int row;
  int col;
    };
int main()
{ int i,j,n,m,temp,t,l,min,loc;
struct data d[200];
   char s[1000],a[150][150];
   while(scanf("%s",s)!=EOF)
   {   memset(a,' ',sizeof(a));
       l=strlen(s);
     temp=0; loc=0; min=0;
       for(i=0;i<l;i++)
       { d[i].c=s[i];
          d[i].col=i;
       }
       for(i=0;i<l-1;i++)
       { if(s[i+1]<s[i])
           temp--;
         else if(s[i+1]>s[i])
           temp++;
           
           if(temp<min) {min=temp; loc=i+1;}
       }
       d[loc].row=0;
       for(i=loc;i>0;i--)
       { if(d[i-1].c>d[i].c)
           d[i-1].row=d[i].row+1;
         else if(d[i-1].c<d[i].c)
           d[i-1].row=d[i].row-1;
           else
           d[i-1].row=d[i].row;
       }
       for(i=loc;i<l;i++)
       { if(d[i+1].c>d[i].c)
           d[i+1].row=d[i].row+1;
         else if(d[i+1].c<d[i].c)
           d[i+1].row=d[i].row-1;
           else
           d[i+1].row=d[i].row;
        }
      for(i=0;i<l;i++)
      a[d[i].col][d[i].row]=d[i].c;
      
      int h=0;
      for(i=0;i<l;i++)
      {
          if(d[i].row>h)
          h=d[i].row;
      }
      
      for(i=h;i>=0;i--)
      {
          for(j=0;j<l;j++)
          printf("%c",a[j][i]);
          printf("\n");    
      }
   }
   return 0;
    
}