#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    double a;
    int b;
    scanf("%s",s);
    char *p=strstr(s,".");
    if(p!=NULL) 
    {
        sscanf(s,"%lf",&a);
    }    
    else 
    {
        sscanf(s,"%d",&b);

    }    
}