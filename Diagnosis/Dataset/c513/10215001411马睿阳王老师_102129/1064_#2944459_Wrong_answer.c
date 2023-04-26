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
{printf("%lf",expr());
 return 0;
}
