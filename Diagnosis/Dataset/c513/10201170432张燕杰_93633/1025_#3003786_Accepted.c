#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dic[91];

typedef struct String{
    char s[100];
    int num;
}String;

int cmp(const void* a,const void* b)
{
    String* p1 = (String*)a;
    String*p2 = (String*)b;
    if(p1->num>p2->num)
    {
        return -1;
    }
    else if(p1->num<p2->num)
    {
        return 1;
    }
    else{
        int flag = 0;
        while(p1->s[flag]==p2->s[flag])
        {
            flag++;
        }
        return p1->s[flag]-p2->s[flag];
    }
}

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i = 0;i<T;i++)
    {
        int n;                      //n为数据个数
        scanf("%d\n",&n);

        String* str = (String*)malloc(sizeof(String)*n);

        for(int z = 0;z<91;z++)
        {
            dic[z] = 0;
        }

        for(int x = 0;x<n;x++)
        {
            for(int y=0;y<100;y++)
            {
                (str+x)->s[y] = '\0';
            }

            (str+x)->num = 0;
            scanf("%s",&(str+x)->s);
            for(int z = 0;z<strlen((str+x)->s);z++)
            {
                if(dic[(str+x)->s[z]]==0)
                {
                    ((str+x)->num) = ((str+x)->num)+1;
                    dic[(str+x)->s[z]]=1;
                }
                else{continue;}
            }
            for(int z = 0;z<91;z++)
            {
                dic[z] = 0;
            }
        }

        qsort(str,n,sizeof(String),cmp);
        printf("case #%d:\n",i);
        for(int j = 0;j<n;j++)
        {
            printf("%s\n",(str+j)->s);
        }
    }
    return 0;
}