#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char List[100][301];
char http[100][301];
int cmp(const void *a,const void *b)
{
    char *A = (char*) a;
    char *B = (char*) b;
    return strcmp(A,B);
}
int main()
{
    int num = 0;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%s",List[i]);
    }
    int len = 0;
    for(int i=0;i<num;i++){
        if(List[i][4]==':') strcpy(http[len++],List[i]); 
    }
    qsort(http,len,sizeof(http[0]),cmp);
    for(int i=0;i<len;i++){
    	printf("%s\n",http[i]);
	}
	return 0;
}