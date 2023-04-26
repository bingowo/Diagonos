#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    return 1;
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int num=0;
        scanf("%d",&num);
        char *s[100];
        for(int k=0;k<num;k++)
        {
        	char *p = (char*)malloc(30*sizeof(char));
        	s[k]=(char*)malloc(30*sizeof(char));
            scanf("%s",p);
            strcpy(s[k],p);
            free(p);
        }
        qsort(s,num,sizeof(char*),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<num;j++)
        {
            printf("%s\n",s[j]);
        }
        for(int k=0;k<num;k++)
        {
        	free(s[k]);
    	}
    }
    return 0;
}