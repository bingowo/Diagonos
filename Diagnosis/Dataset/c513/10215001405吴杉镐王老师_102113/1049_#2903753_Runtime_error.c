#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char res[501]={'\0'};

int cmp(const void* a,const void* b)
{
    char *p1=*(char**)a;
    char *p2=*(char**)b;
    return strcmp(*p1,*p2);
}

int main()
{
	int T;
	scanf("%d",&T);
	char c;
	gets(res);
	int i;
	for(i=0;i<T;i++)
	{
		printf("case #%d:\n",i);
		gets(res);
		int len =strlen(res);
		int cnt=0;
		int idx=0;
		int num=0;
		char ans[50][50];
		for(int i=0;i<len;i++)
        {
            if(res[i]!=',' && res[i]!='.' && res[i]!='!' && res[i]!='?')
            {
                cnt++;
            }
            else
            {
                for(int j=0;j<cnt;j++)
                {
                    ans[idx][j]=res[i-cnt+1+j];
                }
                cnt=0;
                num++;
            }
            qsort(ans,num,sizeof(ans[0][0]),cmp);
        }
        printf("%s",res[0]);
        for(int k=1;k<num;k++)
        {
            if(strcmp(ans[k],ans[k-1]))
            {
                printf(" %s",ans[k]);
            }
        }
	}
	return 0;
}
