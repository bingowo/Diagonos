#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void*b)
{
    char *p1,*p2,*domain1,*domain2;
    int i=0;
    p1 = *((char **)a);//可以理解为 一个一维数组的指针 a的类型 所以p1就是一行字符串
    p2 = *((char **)b);
    while(*(p1+i)!='@')i++;
    domain1 = p1+i+1;//domain1是个地址 没毛病，字符串可以用开始地址表示
    i=0;
    while(*(p2+i)!='@') i++;
    domain2 = p2+i+1;

    if(strcmp(domain1,domain2)==0) return strcmp(p2,p1);
    else return strcmp(domain1,domain2);
}
int main()
{
    int n;
    char **email;
    scanf("%d\n",&n);
    email = (char **)malloc(n*sizeof(char*));//email是一个二维数组

    char s[20000],*p;
    int i,len;
    for(i =0;i<n;i++){
        scanf("%s",email[i]);
    }
    qsort(email,n,sizeof(char*),cmp);
    for(i =0;i<n;i++) printf("%s\n",email[i]);
    free(email);
    return 0;
}