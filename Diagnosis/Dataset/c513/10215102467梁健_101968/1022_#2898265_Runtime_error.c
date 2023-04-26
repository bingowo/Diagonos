#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct mail
{
    char username[7500];
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
    char un1[7500],un2[7500];
    for(int i=0;i<place1;i++)un1[i]=a1.username[i];
    for(int i=0;i<place2;i++)un2[i]=b1.username[i];
    char net1[7500];
    char net2[7500];
    for(int i=place1;i<strlen(a1.username);i++)net1[i-place1]=a1.username[i];
    for(int i=place2;i<strlen(b1.username);i++)net2[i-place2]=b1.username[i];
    int m=0;
    do{
        if(net1[m]!=net2[m]&&net1[m]!='\0'&&net2[m]!='\0')return (net1[m]>net2[m]?1:-1);
        if(m==strlen(net1)&&m!=strlen(net2))return -1;
        if(m!=strlen(net1)&&m==strlen(net2))return 1;
        m++;
    }while(m<strlen(net1)+1&&m<strlen(net2)+1);
    int i=0;
    do{
        if(un1[i]!=un2[i])return (un1[i]>un2[i]?-1:1);
        i++;
    }while(1);
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
