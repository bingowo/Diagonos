#include<stdio.h>
#include<math.h>
int main()
{double a;
 int n;
 while(1)
   {scanf("%d",&n);
    if(n==0) break;
    else
       {a=n*log10(n);//n*n=10^nlog10(n);
        a=a-(int)a;//得到小数部分，强转不会四舍五入
        printf("%d\n",(int)pow(10,a));//最后算10^(小数部分）

        }
   }
 return 0;


}
