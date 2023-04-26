#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct mail
{
    char username[1500];
}MAIL;
int cmp(const void *a,const void *b)
{
    MAIL a1=*(MAIL*)a;
    MAIL b1=*(MAIL*)b;
    int place1=0,place2=0;
    for(int i=0;i<strlen(a1.username);i++){
        if(a1.username[i+1]=='@'){
            place1=i+1;
            break;
        }
    }
    for(int i=0;i<strlen(b1.username);i++){
        if(b1.username[i+1]=='@'){
            place2=i+1;
            break;
        }
    }
    char un1[1010],un2[1010];
    for(int i=0;i<place1;i++)un1[i]=a1.username[i];
    for(int i=0;i<place2;i++)un2[i]=b1.username[i];
    char net1[200];
    char net2[200];
    for(int i=place1;i<strlen(a1.username);i++)net1[i-place1]=a1.username[i];
    for(int i=place2;i<strlen(b1.username);i++)net2[i-place2]=b1.username[i];
    if(net1[0]!=net2[0])return (net1[0]>net2[0]?1:-1);
    else{
        int i=0;
        do{

            if(un1[i]!=un2[i])return (un1[i]>un2[i]?-1:1);
            i++;
        }while(1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    MAIL *a=NULL;
    a=(MAIL*)malloc(sizeof(MAIL)*n);
    for(int i=0;i<n;i++)scanf("%s",a[i].username);
    qsort(a,n,sizeof(MAIL),cmp);
    for(int i=0;i<n;i++)printf("%s\n",a[i].username);
    return 0;
}
