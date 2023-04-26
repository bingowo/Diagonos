#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char str[16];
    int value;
}pair;

//字符串处理函数
int mini(char*s)
{
    int table2[256],flag = 1,value = 0,count = 1,base = 0;
    //flag用于标记0有没有被赋值
    memset(table2,-1,256*sizeof(int));
    for(int i = 0;i < strlen(s);i++)
    {
        if(flag && table2[s[i]] == -1 && i != 0)
        {
            table2[s[i]] = 0;
            flag = 0;
            base++;
            continue;
        }
        if(table2[s[i]] == -1)
        {
            table2[s[i]] = count++;
            base++;
        }
        else
            continue;
    }
    for(int i = 0;i < strlen(s);i++)
    {
        value = base*value + table2[s[i]];
    }
    return value;
}

int cmp(const void*s1,const void*s2)
{
    pair*st1,*st2;
    st1 = s1,st2 = s2;
    if(st1->value != st2->value)
    {
        return st1->value - st2->value;
    }
    else
        return strcmp(st1->str,st1->str);
}

int main()
{
    int N,i;
    scanf("%d",&N);
    pair*input;
    input = (pair*)malloc(N*sizeof(pair));
    for(i = 0;i < N;i++)
    {
        scanf("%s",input[i].str);
        input[i].value = mini(input[i].str);
    }
    qsort(input,N,sizeof(input[0]),cmp);
    for(i = 0;i < N;i++)
    {
        printf("%s\n",input[i].str);
    }
    return 0;

}