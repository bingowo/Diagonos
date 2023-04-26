#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct mail
{
    char username[25000];
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
    int m=0;
    do{
        if(a1.username[m+place1]!=b1.username[m+place2]&&a1.username[m+place1]!='\0'&&b1.username[m+place2]!='\0')return (a1.username[m+place1]>b1.username[m+place2]?1:-1);
        if((m+place1)>=strlen(a1.username)&&m+place2<strlen(b1.username))return -1;
        if((m+place1)<strlen(a1.username)&&m+place2>=strlen(b1.username))return 1;
        m++;
    }while(m+place1<=strlen(a1.username)&&m+place2<=strlen(b1.username));
    int i=0;
    do{
        if(a1.username[i]!=b1.username[i])return (a1.username[i]>b1.username[i]?-1:1);
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
