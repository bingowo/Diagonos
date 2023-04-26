#include<stdio.h>
#include<string.h>
int main()
{
    char abc[]={0123456789abcdef};
    char s[100];
    double a;
    int b;
    while(scanf("%s",s)!=EOF)
    {   int j=0;
        char *p=strstr(s,".");
        if(p!=NULL) 
        {
            sscanf(s,"%lf",&a);
            char aa[17];
            for(int i=0;i<17;i++) aa[i]='0';
            
        
        }    
        else 
        {
            sscanf(s,"%d",&b);
            char bb[9];
            for(int i=0;i<9;i++) bb[i]='0';
            while(b!=0) 
            {
                bb[j]=abc[a%16];
                j++;
                b=b/16;
            }
        }
    }
    return 0;
}