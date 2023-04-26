#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b);
double char_freq[128];
int main()
{
    double temp;
    int T;
    char s[101]={0};
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
        // if(j==1)
        // {
        //     printf("aaa\n");
        // }
        for(int i=0;i<26;i++)   
        {
            scanf("%f",&temp);
            char_freq['A'+i]=char_freq['a'+i]=temp;
        }
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(char),cmp);
        // printf("aaa\n");
        printf("case #%d:\n%s\n",j,s);
        // printf("bbb\n");

    }
}
int cmp(const void* a,const void* b)
{
    char* pa=(char*)a;
    char* pb=(char*)b;
    if(char_freq[*pa]!=char_freq[*pb])  return char_freq[*pa]>char_freq[*pb]?-1:1;
    return *pa>*pb?-1:1;
}
