#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype,h>
int seq[27];

typedef struct
{
    char str[21];
    char upp[21];
    int length;
}DATA;

int cmp(const void*a , const void*b)
{//seq升序
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    int i;
    for(i=0;seq[x->upp[i]] != seq[y->upp[i]] ;i++)
    {
        return seq[x->upp[i]] - seq[y->upp[i]]；
    }
    
}

int main()
{
    char order[27];
    while(scanf("%s",order) != EOF)
    {
        
    	int i,j;
    	for(i=0;i<27;i++)
        {
            seq[order[i] - 'A'] = i;
        }
        	 
    	int k;
    	DATA CASE[101];
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
        printf("%S\n",CASE[n-1].str);
    }
    
    return 0;
}