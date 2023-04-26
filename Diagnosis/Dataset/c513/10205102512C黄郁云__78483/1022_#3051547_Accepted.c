/* 在邮件地址中查找‘@’,分割出用户名和主机域名两个子串；
    调用qsort排序：
    排序规则：先按照主机域名进行字典序升序排序，如果主机域名相同，则按照用户名进行字典序降序排序。*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ** email;
int cmp(const void *a,const void *b){
    char* p1,* p2,* domain1,* domain2;
    p1 = *((char**) a);
    p2 = *((char**)b);
    int i = 0;//确定@位置
    while(*(p1+i) != '@') i++;
    domain1 = p1+i+1;
    i = 0;
    while(*(p2+i) != '@' ) i++;
    domain2= p2+i+1;
    if(strcmp(domain1,domain2) == 0){
        return strcmp(p2,p1);
    }
    return strcmp(domain1,domain2);
}

int main(){
    int n = 0;// n<10^6
    scanf("%d",&n);
    email = (char**)malloc(n*sizeof(char *));

//    printf("%d\n",sizeof(char *));
//    printf("%d\n",sizeof(char));
//    printf("%d\n",sizeof(char **));
char s[1000001],*p;
    for(int i = 0; i < n;i++){
        scanf("%s",s);
         int len = strlen(s);
         p = (char *)malloc(len+1);
         //printf("%d",len);
         strcpy(p,s);//strcpy
         *(email+i) = p;
    }
    qsort(email,n,sizeof(char *),cmp);
    for(int i = 0; i < n;i++){
        printf("%s\n",email[i]);
    }
}