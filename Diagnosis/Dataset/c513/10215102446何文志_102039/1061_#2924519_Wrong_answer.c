#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyString
{
    char str[20];
    long long num;
}myString;

long long toMinNum(char s[])
{
    int slen = strlen(s);
    char table[20];memset(table,0,20*sizeof(char));
    int base = 0;
    for(int i = 0;i<slen;i++)
    {
        int flag = 0;
        for(int j = i-1;j>=0;j--)
        {
            if(s[i]==s[j]){flag = 1;break;}
        }

        if(flag == 0){table[base] = s[i];base++;}
    }
    if((strlen(table)==1)&&(slen>1)){base = 2;}

    //printf("base = %d, table = %s\n",base,table);
    long long res = 0;
    for(int i = 0;i<slen;i++)
    {
        int tmp = 0;
        if(s[i]==table[0]){tmp = 1;}
        else if(s[i]==table[1]){tmp = 0;}
        else
        {
            for(int j = 2;j<base;j++)
            {
                if(s[i]==table[j]){tmp = j;break;}
            }
        }
        res = res*base+tmp;
    }
    //printf("res = %lld\n",res);
    return res;
}

int cmp(const void *a, const void *b)
{
    myString A = *(myString*)a, B = *(myString*)b;
    if(A.num!=B.num){return A.num-B.num;}
    else{return strcmp(A.str,B.str);}
    return 0;
}

int main()
{
    int N = 0;
    scanf("%d",&N);
    myString s[N];memset(s,0,N*sizeof(myString));
    for(int i = 0;i<N;i++)
    {
        scanf("%s",s[i].str);
        s[i].num = toMinNum(s[i].str);
    }

    qsort(s,N,sizeof(s[0]),cmp);
    for(int i = 0;i<N;i++)
    {
        printf("%s\n",s[i].str);
    }

    return 0;
}
