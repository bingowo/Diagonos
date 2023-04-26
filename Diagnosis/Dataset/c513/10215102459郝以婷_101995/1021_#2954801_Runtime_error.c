#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b);

int *standard;

int main()
{
    char word[100][20],c;
    int i,j,status=0;
    extern *standard;
    standard=(int*)malloc(26*sizeof(int));
    for(i=0;i<26;i++)
    {
        c=getchar();
        standard[c-'A']=i;
    }
    c=getchar();
    c=getchar();
    i=0;j=0;
    while(c!='\n')
    {
        if(c!=' ')
        {
            word[i][j]=c;
            j++;
            status=1;
        }
        else if(status)
        {
            word[i][j]='\0';
            i++;
            j=0;
            status=0;//避免有多个空格时重复操作
        }
        c=getchar();

    }

    qsort(word,i+1,sizeof(char),cmp);

    for(j=0;j<=i;j++)
    {
        printf("%s ",word[j]);
    }
    return 0;
}

int cmp(const void* a,const void* b)
{
    char *p,*q;
    int i;
    extern int *standard;
    p=*(char(*)[20])a;//e.g.a指向第一行数据，b指向第二行数据，*a（就是p）表示第一行整行，*p是第一行第一个元素的值
    q=*(char(*)[20])b;
    //printf("%s %s\n",q,p);
    for(i=0;;i++)
    {
        if(*(p+i)>90)
            *(p+i)=*(p+i)-32;
        if(*(q+i)>90)
            *(q+i)=*(q+i)-32;
        //printf("%c %c\n",*(q+i),*(p+i));
        if(*(p+i)!=*(q+i))
            return *(standard+(int)(*(p+i)-'A'))-*(standard+(int)(*(q+i)-'A'));
    }
}
