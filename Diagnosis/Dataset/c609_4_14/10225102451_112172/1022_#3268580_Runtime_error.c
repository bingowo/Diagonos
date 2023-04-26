#include<stdio.h>
#include<string.h>
typedef struct{
char first[1000];
char second[100000];
}EMAIL;
int cmp(const void *p1, const void *p2)
{
    EMAIL *a=(EMAIL*)p1;
    EMAIL *b=(EMAIL*)p2;
    if(strcmp(a->second,b->second)==0)
        return -strcmp(a->first,b->first);
    return
    strcmp(a->second,b->second);
}
int main(void)
{
    long long int n;
    scanf("%lld",&n);
    EMAIL *pointer=(EMAIL*)malloc(sizeof(EMAIL)*(n+2));
    for(int i=0;i<n;i++)
    {
        char buf[100000];
        scanf("%s",buf);
        strcpy((pointer+i)->first,strtok(buf,"@"));
        strcpy((pointer+i)->second,strtok(NULL,"@"));
    }
    qsort(pointer,n,sizeof(EMAIL),cmp);
    for(int j=0;j<n;j++)
    {
        printf("%s@%s\n",(pointer+j)->first,(pointer+j)->second);
    }

    /*char *buf;
    scanf("%s",buf);
    char *temp = strtok(buf,"@");
    while(temp)
    {
        printf("%s\n",temp);
        temp = strtok(NULL,"@");
    }*/

    return 0;
}
