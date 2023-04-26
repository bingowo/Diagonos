#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
char s[101];
double f()
{
    scanf("%s",s);
    switch(s[0])
    {
        case '+':return f()+f();
        case '-':return f()-f();
        case '*':return f()*f();
        case '/':return f()/f();
        default:return atof(s);
    }
}
int main()
{
   int i,n,k,j;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       printf("case #%d:\n%.6f\n",i,f());
   }

}
