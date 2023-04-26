#include<stdio.h>
#include<stdlib.h>
int cmp1 (const void*a,const void*b)
{
        return *(int*)a-*(int*)b;

}

int cmp2 (const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    char seq;
    scanf("%c\n",&seq);
    int line[101];
    int i=0;
   while (scanf("%d", &line[i]) != EOF)
{
    i++;
}

    if (seq=='A')//升序
        qsort(line,i,sizeof(line[0]),cmp1);
    if(seq=='D')//降序
        qsort(line,i,sizeof(line[0]),cmp2);


    printf("%d",line[0]);
	for(int j = 0; j < i-1; j++) {
		if(line[j]!=line[j+1]){            
			printf(" %d",line[j+1]);
		}
	}


    return 0;
}