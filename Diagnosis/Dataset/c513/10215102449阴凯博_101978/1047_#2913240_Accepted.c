#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int count;
    char CH;
} CHR;

int cmp(const void* a,const void* b)
{
    char* pa=(char*)a; char* pb=(char*)b;
    return (*pa>*pb)?1:-1;
}


int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for (int j=0;j<T;j++)
    {
        char s[600]={0}; int i,n=0;
        printf("case #%d:\n",j);
        gets(s);
        CHR* arr=(CHR*)calloc(strlen(s),sizeof(CHR));
        for (i=1;i<strlen(s);i++)
        {
            if (s[i]!=s[i-1])
            {
                arr[n].CH=s[i-1];
                arr[n++].count++;

            }
            if (s[i]==s[i-1])
            {
                if (arr[n].count==255)
                {
                arr[n].CH=s[i-1];
                arr[++n].CH=s[i];
                arr[n].count++;
                }
                else
                    arr[n].count++;
            }


        }
        arr[n].CH=s[strlen(s)-1];
        arr[n].count++;
        for (i=0;i<strlen(s) && arr[i].count!=0;i++)
        {
            printf("%d%c",arr[i].count,arr[i].CH);
        }
        printf("\n");
        free(arr);
    }


    return 0;
}
