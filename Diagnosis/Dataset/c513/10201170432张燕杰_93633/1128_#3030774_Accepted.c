#include<stdio.h>
#include<string.h>

int cmp(const void *p1,const void*p2)
{
    char*s1 = *(char**)p1;
    char*s2 = *(char**)p2;
    return strcmp(s1,s2);
}

int main()
{
    int n;
    scanf("%d",&n);

    char**p = (char**)malloc(sizeof(char*)*n);
    char**p_wash = (char**)malloc(sizeof(char*)*n);
    for(int i = 0;i<n;i++)
    {
        *(p+i) = (char*)malloc(sizeof(char)*300);
        scanf("%s",*(p+i));
    }
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        if(*(*(p+i)+4)=='s')
        {
            continue;
        }
        else{
            *(p_wash+count) = (char*)malloc(sizeof(char)*300);
            strcpy(*(p_wash+count),*(p+i));
            count++;
        }
    }

    qsort(p_wash,count,sizeof(char*),cmp);


    for(int i =0;i<count;i++)
    {
        printf("%s\n",*(p_wash+i));
    }

    return 0;
}