#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b);

int *standard;

int main()
{
    char word[100][21],c;//因为是字符串，所以虽然字符串最多有二十个元素，但是由于结尾的\0，要设置为[21]
    int i,j,status=0;
    extern *standard;
    standard=(int*)malloc(26*sizeof(int));
    while((c=getchar())!=EOF)//c=getchar()记得加括号
    {
        for(i=0;i<26;i++)
        {
            standard[c-'A']=i;
            c=getchar();
        }
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
        word[i][j]='\0';
        qsort(word,i+1,sizeof(word[0]),cmp);//注意word[0]啊！！！
        for(j=0;j<=i;j++)
        {
            printf("%s ",word[j]);
        }
        printf("\n");//换行符是双引号哦
        memset(word,0,2000);
    }
    return 0;
}

int cmp(const void* a,const void* b)
{
    char *p,*q,c1,c2;
    int i;
    extern int *standard;
    p=*(char(*)[20])a;//e.g.a指向第一行数据，b指向第二行数据，*a（就是p）表示第一行整行，*p是第一行第一个元素的值
    q=*(char(*)[20])b;
    //printf("%s %s\n",p,q);
    for(i=0;;i++)
    {
        if(*(p+i)>90)
            c1=*(p+i)-32;
        else
            c1=*(p+i);
        if(*(q+i)>90)
            c2=*(q+i)-32;
        else
            c2=*(q+i);
        //printf("%c %c %d\n",*(p+i),*(q+i),i);
        if(*(p+i)!=*(q+i))
            return *(standard+(int)(c1-'A'))-*(standard+(int)(c2-'A'));
 
    }
}
