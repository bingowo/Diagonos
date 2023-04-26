#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b){
    char *p1,*p2;
    p1=*((char**)a);
    p2=*((char**)b);//cmp第一步永远是先强制转换转，再取值

    int i=0;
    while(*(p1+i)!='@') i++;
    char *ch1=p1+i+1;
    i=0;//循环变量第二次使用前清零
    while(*(p2+i)!='@') i++;
    char *ch2=p2+i+1;
    if(strcmp(ch1,ch2)!=0) return strcmp(ch1,ch2);
    else return strcmp(p2,p1);
}
int main(){
    int n;
    char** email;
    scanf("%d\n",&n);
    email=(char**)malloc(n*sizeof(char*));//现在email就是一个伟大的指针,他开始存放指针，其实指针的sizeof都为4
    //double-star advanced pointer email指向这块地址的开头,这块地址里可以存放n个地址，相当于是二维数组
    char s[1000001], *p;//s的大小根据题目里定的
    int i;
    for(i=0;i<n;i++){
        scanf("%s",s);
        p=(char*)malloc(strlen(s)+1);//p是真实存放字符串的
        strcpy(p,s);//p不能直接接受，要把s复制到p里
        *(email+i)=p;//每一个p，被email对准一下
    }
    qsort(email,n,sizeof(char*),cmp);
    for(i=0;i<n;i++){
        printf("%s\n",*(email+i));
    }
    for(i=0;i<n;i++){
        p=email[i];
        free(p);
    }
    free(email);
    return 0;
}
//字典序就是用strcmp处理一下
//指针的自加自减运算很重要
//这里的email作用相当于目录，p和email单独申请空间，单独释放，之间的联系是通过*(email+i)=p;来建立的，类似链表