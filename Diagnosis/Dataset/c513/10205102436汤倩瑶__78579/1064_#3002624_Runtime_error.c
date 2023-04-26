#include<stdio.h>
#include<stdlib.h>
double f()
{
    double f1,f2;
    char c;
    scanf("%c",&c);
    switch(c)
    {
     case '+':f1=f();f2=f();
     return f1+f2;
     case '-':f1=f();f2=f();
     return f1-f2;
     case '*':f1=f();f2=f();
     return f1*f2;
     case '/':f1=f();f2=f();
     return f1/f2;
     default:return atof(c);
        
    }
    
    
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n%.6f\n",i,f());
        
        
    }
    
    
}