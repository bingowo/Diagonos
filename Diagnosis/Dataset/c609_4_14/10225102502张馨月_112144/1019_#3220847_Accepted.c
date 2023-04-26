#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int digit(int a)
{
    int n=1,ws=0;
    while(a!=0)
    {
        a=a/10;
        ws++;
    }
    return ws;
}

int cmp1 (const void*a,const void*b)
{
    int pa=*(int*)a;
    int pb=*(int*)b;
    if(digit(pa)!=digit(pb))
        return digit(pb)-digit(pa);
    else
        return pa-pb;
}

int main()
{

    int *line;
    line=(int*)malloc(sizeof(int)*1000001);
    //int line[1000001];
    int i=0;
    while (scanf("%d", &line[i]) != EOF)
    {
        i++;
    }
    qsort(line,i,sizeof(line[0]),cmp1);
    printf("%d",line[0]);
	for(int j = 1; j < i; j++) {
			printf(" %d",line[j]);
	}

    return 0;
}