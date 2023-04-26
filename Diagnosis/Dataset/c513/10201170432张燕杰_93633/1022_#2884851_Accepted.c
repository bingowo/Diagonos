#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{
    char*p1,*p2;
    p1 = *((char**)a);
    p2 = *((char**)b);      //p1,p2存放的是邮箱所存放位置的首地址
    char *at1;              //at1,at2存放@符号地址后一位
    char *at2;
    int i =0;
    while(*(p1+i)!='@')
    {
        i++;
    }
    at1 = p1+i+1;
    i=0;
     while(*(p2+i)!='@')
    {
        i++;
    }
    at2 = p2+i+1;
    if(strcmp(at1,at2)==0)
    {
        return strcmp(p2,p1);
    }
    else
    {
        return strcmp(at1,at2);
    }
}

int main()
{
    char**email;
    int n;      //行数
    scanf("%d",&n);
    if(n==1)
    {
        getchar();
        char word;
        while((word=getchar())!=EOF)
        {
            printf("%c",word);
        }
        return 0;
    }
    email = (char**)malloc(n*sizeof(char*));
    for(int i = 0;i<n;i++)
    {
        char save[100001]={'0'};
        scanf("%s",save);
        int len= strlen(save);
        email[i] = (char *)malloc((len+1)*sizeof(char));
        strcpy(email[i],save);
    }

    qsort(email,n,sizeof(char*),cmp);

    for(int i =0;i<n;i++)
    {
        printf("%s\n",email[i]);
        free(email[i]);
    }
    free(email);
    return 0;
}
