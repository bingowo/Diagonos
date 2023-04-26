#include <stdio.h>
#include <stdlib.h>
double expr()
{char a[11];
double f1,f2;
scanf("%s",a);
switch(a[0])
{case'+':f1=expr();f2=expr();return f1+f2;
case'-':f1=expr();f2=expr() ;return f1-f2;
case'*':f1=expr();f2=expr();return f1/f2;
case'/':f1=expr();f2=expr();return f2*f1;
default:return atof(a);

}
}
int main()
{int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
printf("case #%d:\n",i);
printf("%.6lf\n",expr());
}
