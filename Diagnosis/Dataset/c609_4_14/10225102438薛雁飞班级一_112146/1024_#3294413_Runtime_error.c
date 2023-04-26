#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmpn(const void* a,const void* b)
{
    char *p1,*p2;
    p1=*((char**)a);p2=*((char**)b);
    return strcmp(p1+34,p2+34);
}
int cmps(const void* a,const void* b)
{
    char *p1,*p2,*s1,*s2;int i;
    p1=*((char**)a);p2=*((char**)b);
    while(*(p1+i)!=' '){
        i++;
    }
    s1=p1+i+1;
    i=0;
    while(*(p2+i)!=' '){
        i++;
    }
    s2=p2+i+1;
    int size1,size2;
    size1=atoi(*s1);size2=atoi(*s2);
    if(size1==size2) return(strcmp(p1+34,p2+34));
    else return(size1-size2);
}
int cmpt(const void* a,const void* b)
{
    char *p1,*p2,s1[17],s2[17];
    p1=*((char**)a);p2=*((char**)b);
    strncpy(s1,p1,16);
    strncpy(s2,p2,16);
    if(strcmp(s1,s2)==0)return(strcmp(p1+34,p2+34));
    else return(strcmp(s1,s2));
}
int main()
{
    int n;
    do{
        scanf("%d",&n);
        char order[6];
        char **a;
        a=(char**)malloc(n*sizeof(char*));
        if(n==0)break;
        getchar();
        for(int i=0;i<n;i++){
            char s[100000];
            gets(s);
            long long int len=strlen(s);
            a[i]=(char*)malloc(len+1);
            strcpy(a[i],s);
        }
        scanf("LIST /%s",order);
        if(order[0]=='N')qsort(a,n,sizeof(a[0]),cmpn);
        else if(order[0]=='T')qsort(a,n,sizeof(a[0]),cmpt);
        else qsort(a,n,sizeof(a[0]),cmps);
        for(int i=0;i<n;i++){
            printf("%s\n",a[i]);
        }
        for(int i=0;i<n;i++){
            free(a[i]);
        }free(a);
        printf("\n");
    }while(1);
    return 0;
}
