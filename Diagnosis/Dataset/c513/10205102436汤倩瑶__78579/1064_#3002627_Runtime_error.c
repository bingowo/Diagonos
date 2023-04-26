#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double f()
{
    double f1,f2;
    char s[12];
    scanf("%s",s);
    switch(s[0])
    {
     case '+':f1=f();f2=f();
     return f1+f2;
     case '-':f1=f();f2=f();
     return f1-f2;
     case '*':f1=f();f2=f();
     return f1*f2;
     case '/':f1=f();f2=f();
     return f1/f2;
     default:return atof(s[0]);
        
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