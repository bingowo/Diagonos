
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <ctype.h>
double expr()
{ char s[10];
  double f1,f2;
  scanf("%s",s);
  switch (s[0])
  { case '+':{f1=expr();f2=expr();return f1+f2;}
    case '-':{f1=expr();f2=expr();return f1-f2;}
    case '*':{f1=expr();f2=expr();return f1*f2;}
    case '/':{f1=expr();f2=expr();return f1/f2;}
    default : return atof(s);
      
  }
  
    
}

int main ()
{ int i,j,n,m,s,T; double f;
scanf("%d",&T);
for(i=0;i<T;i++)
{ f=expr();
printf("case #%d:\n",i);
printf("%.6lf\n",f);
}

 return 0; }

