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
    email = (char **)malloc(n*sizeof(char*));//email是一个动态二维数组 不是很好理解 用动态二维数组的时候要记住他的每一个元素都指向一个字符串 所以要给他再开辟一个空间让他去指向

    char s[1000001],*p;
    int i,len;
    for(i =0;i<n;i++){
        scanf("%s",s);
        len = strlen(s);
        p=(char *)malloc(len+1);
        strcpy(p,s);
        email[i]=p;//动态二维数组 email[i]指向p 所以p里面才是存放的地方，而不是email 这是动态二维数组的核心
    }
    qsort(email,n,sizeof(char*),cmp);

    for(i =0;i<n;i++) printf("%s\n",email[i]);
    for(i=0;i<n;i++){
        p = email[i];
        free(p);
    }
    free(email);
    return 0;
}