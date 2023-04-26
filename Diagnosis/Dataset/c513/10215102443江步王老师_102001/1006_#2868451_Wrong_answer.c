#include<stdio.h>

long long int trans(char *str);
int main()
{
    char str[100];
    int T;
    int i;
    scanf("%d",&T);
    long long int *res=(long long int*)malloc(sizeof(long long int)*T);
    for (i=0;i<T;i++){
        scanf("%s",str);
        res[i]=trans(str);
    }
    for(i=0;i<T;i++){
        printf("case #%d\n:",i);
        printf("%lld\n",res[i]);
    }
    return 0;
}

long long int trans(char *str)
{
    char *p=str;
    long long int res=0;
    while(*p!='\0'){
        if (*p=='-'){
            res=res*3-1;
        }
        else if(*p=='0'){
            res=res*3;
        }
        else{
            res=res*3+1;
        }
    p++;
    }
    return res;
}