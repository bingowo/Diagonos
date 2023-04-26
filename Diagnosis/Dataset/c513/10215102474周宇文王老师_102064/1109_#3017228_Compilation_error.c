#include <stdio.h>
#include <stdlib.h>
int main(){
int i,a,first=0,flag=0;
//引入flag判断是否为首项，first记录首项非零是第几项
 for (i=8;i>=0;i--)
 {
     scanf("%d",&a);
     if (a&&!flag) {flag=1,first=i;}//如果非0，flag为0，说明该项是首项
     if (first==0 && i==0) printf(“%d”,a);//如果是仅有常数项输出
     if (first!=0 &&a!=0)
     {
         if (a<0) printf("-");
         if (a>0 && i!=first) printf("+");
         if ((int)fabs(a)!=1||i==0) printf ("%d",(int)fabs(a));
         if (i>0) printf("x");
         if (i>1) printf("^%d",i);}}
          printf("\n");
    }
}
return 0;
}