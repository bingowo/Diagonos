#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

double expr()
{char a[10];
 scanf("%s",a);
 double f1,f2;
 switch(a[0])
 {case '+':{f1=expr();f2=expr();return f1+f2;}
  case '-':{f1=expr();f2=expr();return f1-f2;}
  case '*':{f1=expr();f2=expr();return f1*f2;}
  case '/':{f1=expr();f2=expr();return f1/f2;}
  default:return atof(a);
}
}

int main()
{int T,i;
 scanf("%d",&T);
 for(i=0;i<T;i++)
 {
  printf("case #%d:\n",i);
  printf("%lf\n",expr());
 }
return 0;
}
