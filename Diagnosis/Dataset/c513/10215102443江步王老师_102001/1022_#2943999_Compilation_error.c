#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>


int cmp(const void*_a, const void*_b);

int main()
{
    int n,len;
    int i;
    char s[1000001];
    scanf("%d",&n);
    getchar();
    char **email = (char **)malloc(sizeof(char *)*n);
    
    //输入部分
    for (i=0;i<n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        char *p = (char *)malloc(sizeof(char)*(len+1));
        strcpy(p,s);
        *(email+i)=p;
    }

    qsort(email,n,sizeof(char *),cmp);

    for (i=0;i<n;i++)
    {
        printf("%s\n",email+i);
    }
    return 0;
}


int cmp(const void*_a, const void*_b)
{
    char *a = *((char **)_a);
    char *b = *((char **)_b);
    char *p1,*p2=NULL;
    p1=a;p2=b;
    while (*p1 != '@')
    {
        p1++;
    }
    while (*p2 != '@')
    {
        p2++;
    }
    p1++;p2++;
    if (strcmp(p1,p2))
    {
        return 1;
    }
    else if (strcmp(p1,p2) < 0)
    {
        return -1;
    }
    else 
    {
        p1=a;p2=b;
        while (*p1 != '@')
        {
            p1++;
        }
        *p1='\0';
        while (*p2 != '@')
        {
            p2++;
        }
        *p2='\0';
        if (strcmp(a,b)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}