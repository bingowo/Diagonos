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
        
    	int i,j;
    	for(i=0;i<27;i++)
        {
            seq[order[i] - 'A'] = i;
        }
        	 
    	int k;
    	DATA CASE[102];
        char inp[2000];
        gets(inp);
    	for(j=0;scanf("%s",CASE[j].str) != EOF;j++)
    	{
        	CASE[j].length = strlen(CASE[j].str);
            for(k=0 ; k<strlen(CASE[j].str) ; k++)
            {
                CASE[j].upp[k] = CASE[j].str[k];
            }
    	}
    	int n = j;
    	qsort(CASE , n , sizeof(DATA) , cmp);
    	int r;
        for(r=0;r<n-1;r++)
            printf("%s ",CASE[r].str);
        printf("%s\n",CASE[n-1].str);
    }
    
    return 0;
}