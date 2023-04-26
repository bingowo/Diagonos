#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int seq[27];

typedef struct
{
    char str[22];
    char upp[22];
    int length;
}DATA;

int cmp(const void*a , const void*b)
{//seq升序
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    int i;
    for(i=0;seq[x->upp[i]-'A'] != seq[y->upp[i]-'A'] ;i++)
    {
        return seq[x->upp[i]-'A'] - seq[y->upp[i]-'A'];
    }
    
}

int main()
{
    char order[28];
    while(scanf("%s",order) != EOF)
    {
        
    	
        printf("1");
    }
    
    return 0;
}