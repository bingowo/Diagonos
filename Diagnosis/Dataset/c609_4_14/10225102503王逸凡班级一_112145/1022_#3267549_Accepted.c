#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b){//指针的指针
    char*p1,*p2,*domain1,*domain2;
    int i=0;
    p1=*((char**)a);//a，b都是指针的指针所以要char**
    p2=*((char**)b);//他们间接访问的值还是一个指针
    while(*(p1+i)!='@'){
        i++;
    }
    domain1=p1+i+1;//主机域名的地址
    i=0;
    while(*(p2+i)!='@'){
        i++;
    }
    domain2=p2+i+1;
    if(strcmp(domain1,domain2)==0){
        return strcmp(p2,p1);
    }else{
        return strcmp(domain1,domain2);//关注升序，降序
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
        scanf("%s",s);//读入一个邮件地址
        int len;//长度
        len = strlen(s);
        p=(char*)malloc(len+1);//动态分配邮件地址储存空间
        strcpy(p,s);//字符串复制，s表示的字符串复制到开辟完空间的p里面
        *(email+i)=p;//*(email+i)间接访问数组元素，且每个元素是一个指针。
    }
    qsort(email,n,sizeof(char*),cmp);//快速排序函数
    for(int i=0;i<n;i++){
        printf("%s\n",email[i]);
    }
    for(int i=0;i<n;i++){
        p=email[i];//释放每个指针对应的邮件地址的空间
        free(p);
    }
    free(email);//释放数组的空间


    return 0;
}
