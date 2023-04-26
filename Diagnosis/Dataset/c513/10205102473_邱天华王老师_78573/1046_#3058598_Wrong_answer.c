#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n;
    char s[101];
    char c;
    scanf("%d",&n);
    c=getchar();
    for(int i=0;i<n;i++)
    {
        int num=1;
        char* d=" ";
        char* p;
        gets(s);
        strtok(s,d);
        if(s=="the"||s=="a"||s=="an"||s=="of"||s=="for"||s=="and")num==0;
        while((p = strtok(NULL, d)))    
        {    
            printf("p=%s num=%d\n",p,num);

            if(p!="the"&&p!="a"&&p!="an"&&p!="of"&&p!="for"&&p!="and")num++;
        }
        printf("case #%d: \n",i);
        printf("%d\n",num);
    }
    return 0;  
}