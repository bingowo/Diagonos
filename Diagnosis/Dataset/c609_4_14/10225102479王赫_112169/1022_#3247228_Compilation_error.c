#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct EMAIL
{
   char** name;
   char** area;
}email;
int cmp(const void*_a,const void*_b)
{
    (email*)_a=email* a;
    (email*)_b=email* b;
    if(strcmp(a->name,b->name)==-1) return -1;
    else if(strcmp(a->name,b->name)==1) return 1;
    else{if(strcmp(a->area,b->area)==-1 return -1; else return 1;}
}
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)_
    {
        char* s;
        s=(char*)malloc*1e6;
        scanf("%s\n",s);
        
    }
}
