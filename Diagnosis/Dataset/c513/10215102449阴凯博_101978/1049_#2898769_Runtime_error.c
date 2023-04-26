#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char* str;
} WORD;

int cmp(const void* a,const void* b)
{
    WORD* pa=(WORD*)a; WORD* pb=(WORD*)b;
    return (strcmp(pa->str,pb->str)<0)?-1:1;
}

int main()
{
    int T;
    scanf("%d",&T);
    char s[550]={0};
    getchar();
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        gets(s);
        int j,n=0,k,h;
        for(j=0;j<strlen(s);j++)
            if (s[j]==' ' || s[j]==',' || s[j]=='.'|| s[j]=='!' || s[j]=='?')
            {
                if (s[j+1]==' ' || s[j+1]==',' || s[j+1]=='.'|| s[j+1]=='!' || s[j+1]=='?')
                    j++;
                n++;
            }

        WORD* arr=(WORD*)malloc(n*sizeof(WORD));
        int cnt=550/n;
        for(j=0;j<n;j++)
            arr[j].str=(char*)malloc(cnt*sizeof(char));
        for(j=0,k=0,h=0;j<strlen(s);j++)
        {
            arr[k].str[h++]=s[j];
            if (s[j]==' ' || s[j]==',' || s[j]=='.'|| s[j]=='!' || s[j]=='?')
            {
                if (s[j+1]==' ' || s[j+1]==',' || s[j+1]=='.'|| s[j+1]=='!' || s[j+1]=='?')
                    j++;
                arr[k].str[h-1]='\0';
                k++;
                h=0;
            }

        }
        qsort(arr,n,sizeof(WORD),cmp);
        for (j=0;j<n-1;j++)
        {
            if (strcmp(arr[j].str,arr[j+1].str)!=0)
            {
                printf("%s ",arr[j].str);
            }
            
        }
        
        printf("%s\n",arr[n-1]);
        for (j=0;j<n;j++)
            free(arr[j].str);
        free(arr);


    }
    return 0;
}
