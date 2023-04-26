#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char s[27]={0};

typedef struct
{
    char str[21];
} LINE;

int mgetline(char s[],int lim)
{
    int c,i;
    i=0;
    while ((c=getchar())!=EOF && c!='\n' && i<lim-1 && c!='@')
        s[i++]=c;
    if (c==EOF && i==0)
        return -1;
    s[i]='\0';
    return i;
}


int find(char a)
{
    int n;
    for (n=0;n<26;n++)
        if (s[n]==a)
            break;
    return n;
}

int cmp(const void* a,const void* b)
{
    LINE* pa=(LINE*)a; LINE* pb=(LINE*)b;
    int i;
    for (i=0;i<strlen(pa->str) && i<strlen(pb->str);i++)
    {
        if (find(toupper(pa->str[i]))<find(toupper(pb->str[i]))) return -1;
        if (find(toupper(pa->str[i]))>find(toupper(pb->str[i]))) return 1;
    }
    if (strlen(pa->str)<strlen(pb->str)) return -1;
    if (strlen(pb->str)<strlen(pa->str)) return 1;

}



int main()
{
    int T=0,N;
    char s1[3000]={0};
    int i=0,j=0,k=0;
    while (scanf("%s",s)!=EOF)
    {
        getchar();
        N=mgetline(s1,3000);
        for (i=0;s1[i]!='\0';i++)
            if (s1[i]==' ')
                T++;
        T++;
        LINE* arr=(LINE*)malloc(T*sizeof(LINE));
        i=0;
        while (s1[j]!='\0')
        {
            arr[i].str[k++]=s1[j++];
            if (s1[j]==' ')
            {
                arr[i].str[k]='\0';
                i++; j++;
                k=0;
            }
        }
        arr[i].str[k]='\0';
        j=0; k=0;
        qsort(arr,T,sizeof(LINE),cmp);
        for (i=0;i<T;i++)
            printf("%s%c",arr[i].str,i==T-1?'\n':' ');
        printf("\n");
        free(arr);
        T=0;
    }
    return 0;
}
