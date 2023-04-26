#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b){
    char*p1,*p2,*domain1,*domain2;
    int i=0;
    p1=*((char**)a);
    p2=*((char**)b);
    while(*(p1+i)!='@'){
        i++;
    }
    domain1=p1+i+1;
    i=0;
    while(*(p2+i)!='@'){
        i++;
    }
    domain2=p2+i+1;
    if(strcmp(domain1,domain2)==0){
        return strcmp(p2,p1);
    }else{
        return strcmp(domain1,domain2);
    }
}

int main()
{
    char **email;//定义指针数组
    int n;//排序个数
    scanf("%d",&n);
    email=(char **)malloc(n*sizeof(char*));//动态分配指针数组空间
    char s[1000001],*p;
    for(int i=0;i<n;i++){
        scanf("%s",s);
        int len;
        len = strlen(s);
        p=(char*)malloc(len+1);//动态分配邮件地址储存空间
        strcpy(p,s);//字符串复制
        *(email+i)=p;//*(email+i)间接访问数组元素，且每个元素是一个指针。
    }
    qsort(email,n,sizeof(char*),cmp);
    for(int i=0;i<n;i++){
        printf("%s\n",email[i]);
    }
    for(int i=0;i<n;i++){
        p=email[i];
        free(p);
    }
    free(email);


    return 0;
}
