#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[18];
} WORD;

int cmp(const void* a,const void* b)
{
    WORD* pa=(WORD*)a; WORD* pb=(WORD*)b;
    return (strlen(pa->s)>strlen(pb->s))?-1:1;
}

char* subst(char* s,int start,int end)
{
    char* s1=(char*)malloc((end-start+1)*sizeof(char));
    int i,j;
    for (i=start,j=0;i<=end && i<strlen(s);i++,j++)
        s1[j]=s[i];
    s1[j]=0;
    return s1;
}

int main()
{
    int n=0,L=0;
    scanf("%d",&n);
    WORD* lib=(WORD*)malloc(n*sizeof(WORD));
    for (int i=0;i<n;i++)
        scanf("%s",lib[i].s);
    char s[5050]={0};
    scanf("%s",s);
    qsort(lib,n,sizeof(WORD),cmp);
    L=strlen(lib[0].s);
    int i,start=0;
    while(start<strlen(s))
    {
        for (i=L-1;i>=0;i--)
        {
            char* a=subst(s,start,start+i);
            int flag=0;
            for (int j=0;j<n;j++)
                if (strcmp(a,lib[j].s)==0)
                {
                    printf("%s%c",a,(start+i==strlen(s)-1)?'\n':' ');
                    free(a);
                    flag=1;
                    break;
                }
            if (flag==1) break;
            if (i==0)
            {
                printf("%s%c",a,(start+i==strlen(s)-1)?'\n':' ');
                free(a);
                break;
            }
            free(a);
        }
        start+=(i+1);
    }

    free(lib);
    return 0;
}
