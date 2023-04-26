#include <stdio.h>
#include <stdlib.h>


double trans()
{
   char s[11];
   double f1,f2;
   scanf("%s",s);
   switch(s[0])
   {
       case'+':f1=trans();f2=trans();return f1+f2;
       case'-':f1=trans();f2=trans();return f1-f2;
       case'*':f1=trans();f2=trans();return f1*f2;
       case'/':f1=trans();f2=trans();return f1/f2;
       default:return atof(s); //将char转换成对应的浮点数

   }
}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {

        printf("case #%d\n:",i);
         printf("%.6lf\n",trans());
    }



    return 0;
}
