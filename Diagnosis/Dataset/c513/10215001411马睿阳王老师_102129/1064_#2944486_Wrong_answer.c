#include<stdio.h>

double expr()
{char a[10];
 scanf("%s",a);
 switch(a[0])
 {case '+':return expr()+expr();break;
  case '-':return expr()+expr();break;
  case '*':return expr()+expr();break;
  case '/':return expr()+expr();break;
  default:return atof(a);break;

 }
}

int main()
{int T,i;
 double v;
 scanf("%d",&T);
 for(i=0;i<T;i++)
 {v=expr();
  printf("case #%d:\n",i);
  printf("%.6lf",v);
 }
return 0;
}
