#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int order;
    double freq;
    int cas;
} LETTER;


int cmp(const void* a,const void* b)
{
    LETTER* pa=(LETTER*)a; LETTER* pb=(LETTER*)b;
    if (pa->freq>pb->freq) return -1;
    if (pa->freq<pb->freq) return 1;
    if (pa->freq==pb->freq) return (pa->cas>pb->cas)?1:-1;
}

int main()
{
    int T,j,n;
    scanf("%d",&T);
    double arr1[26];
    char s[120]={0};
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        for (j=0;j<26;j++)
            scanf("%lf",&arr1[j]);
        scanf("%s",s);
        n=strlen(s);
        LETTER* arr2=(LETTER*)malloc(n*sizeof(LETTER));
        for (j=0;j<n;j++)
        {
            arr2[j].order=j;
            if (s[j]>='A' && s[j]<='Z')
            {
                arr2[j].freq=arr1[s[j]-'A'];
                arr2[j].cas=1;
            }
            if (s[j]>='a' && s[j]<='z')
            {
                arr2[j].freq=arr1[s[j]-'a'];
                arr2[j].cas=0;
            }

        }
        qsort(arr2,n,sizeof(LETTER),cmp);
        char s1[120]={0};
        for (j=0;j<n;j++)
            s1[j]=s[arr2[j].order];
        printf("%s\n",s1);
        free(arr2);
    }
    return 0;
}
