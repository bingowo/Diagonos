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
    char *p;
    char **email;
    scanf("%d\n",&n);
    email = (char **)malloc(sizeof(char *)*n);
    
    //输入部分
    for (i=0;i<n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        p = (char *)malloc(sizeof(char)*(len+1));
        strcpy(p,s);
        *(email+i)=p;
    }

    qsort(email,n,sizeof(char *),cmp);

    for (i=0;i<n;i++)
    {
        printf("%s\n",email[i]);
    }

    for (i=0;i<n;i++)
    {
        p=email[i];
        free(p);
    }
    free(email);


    return 0;
}


int cmp(const void*_a, const void*_b)
{
    char *a = *((char **)_a);
    char *b = *((char **)_b);
    char *p1=NULL,*p2=NULL,*d1=NULL,*d2=NULL;
    int i=0;
    p1=a;p2=b;
    while (*(p1+i) != '@')
    {
        i++;
    }
    d1=p1+i+1;
    i=0;
    while (*(p2+i) != '@')
    {
        i++;
    }
    d2=p2+i+1;
    if (strcmp(d1,d2)==0)
    {
        return strcmp(p1,p2);
    }
    else
    {
        return strcmp(d1,d2);
    }
}