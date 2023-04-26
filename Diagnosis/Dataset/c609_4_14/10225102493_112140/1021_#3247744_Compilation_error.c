#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char a[27];
#define N=100;


int cmp(void*c,void*d)
{
    char a1[21];
    a1=(char*)void*c;
    char a2[21];
    a2=(char*)void*d;
    int i=0;
    while(s[])
    for(i=0;i<26;i++)
    {
        
    }
    
}




int main()
{
    for()
    {
        
    }
    scanf("%s",a);
    char*b[N];
    char c;
    int i=1;
    b[0]=(char*)malloc(sizeof(char)*21);
    while((c=getchar())!='\n')
    {
       
        char s[21];
        s[0]=c;
        int j=1;
        while((c=getchar())!=' '&&c!='\n')
        {
            s[j]=c;
            j++;
        }
        s[j]='\0';
        strcpy(b[i-1],s);
         if(c==' ') 
        {
           b[i]=(char*)malloc(sizeof(char)*21);
           i++;
        }
        if (c=='\n') break;
    }
    qsort (*b,i,sizeof(b[0]),cmp);
    return 0;
}
