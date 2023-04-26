#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    char *p1,*p2,*domain1,*domain2;
    p1=*((char **)a);
    p2=*((char **)b);
    int i=0;
    while(*(p1+i)!='@') i++;
    domain1=p1+i+1;
    int j=0;
    while(*(p2+j)!='@') j++;
    domain2=p2+j+1;
    if(strcmp(domain1,domain2)==0) return strcmp(p2,p1);
    else return strcmp(domain1,domain2);
}
int main()
{
    char** email;
    int n;
    scanf("%d",&n);
    email=(char**)malloc(n*sizeof(char*)); //动态分配指针数组
    int i,len;
    char s[1000001],*p;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        p=(char *)malloc(len+1);
        strcpy(p,s);
        *(email+1)=p;
        qsort(email,n,sizeof(char *),cmp);
        printf("%s\n",email[i]);
        p=email[i];
        free(p); //释放内存
    }
    free(email);
    return 0;
}
