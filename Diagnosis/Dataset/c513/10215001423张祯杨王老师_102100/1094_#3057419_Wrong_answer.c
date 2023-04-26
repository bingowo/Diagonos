#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  sub(int a[],int b[],int m,int q)
{ for(int i=0;i<q;i++)
  {   if(a[m-1-i]>=b[q-1-i]) a[m-1-i]-=b[q-1-i];
      else {a[m-1-i]-=b[q-1-i]-10; a[m-2-i]--;}
  }
  if(a[m-q-1]==-1)
  {  int w=1;
      while(a[m-q-1-w]==0) {a[m-q-1-w]=9; w++;}
      a[m-q-1-w]--;

  }
  return 0;
}
int main()
{  char s[51][121];
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++) scanf("%s",s[i]);
   int a[51];
   for(int i=0;i<n;i++) a[i]=strlen(s[i]);
   int max=a[0],min=a[0],in_max=0,in_min=0;
   for(int i=1;i<n;i++)
     {  if(a[i]>max) {max=a[i]; in_max=i;}
        if(a[i]<min) {min=a[i]; in_min=i;}
     }
   char MAX[51][121],MIN[51][121];
   int m=0,q=0;
   for(int i=in_max;i<n;i++)
   { if(a[i]==max)  {strcpy(MAX[m],s[i]); m++;}

   }
   for(int i=in_min;i<n;i++)
   { if(a[i]==min)  {strcpy(MIN[q],s[i]); q++;}

   }
   int ma=0,mi=0;
   for(int i=0;i<m+1;i++)
   {
      if(strcmp(MAX[ma],MAX[i])<0) ma=i;
   }
   if(q!=1)
   { for(int i=0;i<q;i++)
       {
          if(strcmp(MIN[mi],MIN[i])>0) mi=i;
       }
   }
   int i_MAX[m+1],i_MIN[n+1];
   for(int i=0;i<max;i++) i_MAX[i]=(int)(MAX[ma][i])-48;
   for(int i=0;i<min;i++) i_MIN[i]=(int)(MIN[mi][i])-48;
   sub(i_MAX,i_MIN,max,min);
   for(int i=0;i<max;i++) printf("%d",i_MAX[i]);
   return 0;
}

