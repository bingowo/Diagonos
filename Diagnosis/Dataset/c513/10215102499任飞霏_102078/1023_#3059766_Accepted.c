#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct str{
    char s[31];
    int number;
};

int num(char *s)
{
    int sum=0,flag=0;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='0' && s[i]<='9'){
            sum = sum*10 + s[i]-'0';
            flag = 1;
        }
    }
    if(flag==0)return -1;
    else return sum;
}

int cmp(const void *a,const void *b)
{
    struct str x,y;
    x = *((struct str *)a);
    y = *((struct str *)b);
    if(x.number != y.number){
        return x.number - y.number;
    }
    else
        return strcmp(x.s,y.s);
}

int main()
{
    int count=0;
    struct str a[100];
    while(scanf("%s",a[count].s)!= EOF){
        count++;
    }
    for(int i=0;i<count;i++){
        a[i].number = num(a[i].s);
    }
    qsort(a,count,sizeof(a[0]),cmp);
    for(int i=0;i<count;i++){
        printf("%s ",a[i].s);
    }
    return 0;
}
