#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    char *p1,*p2,*domain1,*domain2;
    int i=0;
    p1=*((char**)a); p2=*((char**)b);
    while(*(p1+i)!='@') i++; //查找@的位置
    domain1=p1+i+1;//domain1 指向第二个邮件地址的主机域名；
    i=0;
    while(*(p2+i)!='@') i++;
    domain2=p2+i+1;//domain2指向第二个邮件地址的主机域名；
    if(strcmp(domain1,domain2)==0) return strcmp(p2,p1);
    else return strcmp(domain1,domain2);

}

int main() {
    char **email; int n;
    scanf("%d",&n);
    email=(char**) malloc(n*sizeof(char*));

    char s[1000001],*p;
    for(int i=0;i<n;i++){
        scanf("%s",s);
        int len= strlen(s);
        p=(char*) malloc(len+1);//动态分配邮件地址存储空间
        strcpy(p,s);
        *(email+i)=p;
    }

    qsort(email,n,sizeof(char*),cmp);
    for(int i=0;i<n;i++) printf("%s\n",email[i]);
    
    //内存空间释放
    for(int i=0;i<n;i++){
        p=email[i]; free(p);
    }
    return 0;
}
