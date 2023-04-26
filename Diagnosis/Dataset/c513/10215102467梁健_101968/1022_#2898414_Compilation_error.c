#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
int cmp(const void *a,const void *b);
int main()
{
    scanf("%d",&n);
    char a[n][1200000/n+];
    for(int i=0;i<n;i++)scanf("%s",a[i]);
    qsort(a,n,1200000/n,cmp);
    for(int i=0;i<n;i++)printf("%s\n",a[i]);
    return 0;
}
int cmp(const void *a,const void *b)
{
    char a1[1200000/n];
    char b1[1200000/n];
    strcpy(a1,(char*)a);
    strcpy(b1,(char*)b);
    int place1=0,place2=0;
    for(int i=0;i<strlen(a1);i++){
        if(a1[i+1]=='@'){
            place1=i+1;
            break;
        }
    }
    for(int i=0;i<strlen(b1);i++){
        if(b1[i+1]=='@'){
            place2=i+1;
            break;
        }
    }
    int m=0;
    do{
        if(a1[m+place1]!=b1[m+place2])return (a1[m+place1]>b1[m+place2]?1:-1);
        if((m+place1)>=strlen(a1)&&m+place2<strlen(b1))return -1;
        if((m+place1)<strlen(a1)&&m+place2>=strlen(b1))return 1;
        m++;
    }while(m+place1<=strlen(a1)&&m+place2<=strlen(b1));
    int i=0;
    do{
        if(a1[i]!=b1[i])return (a1[i]>b1[i]?-1:1);
        i++;
    }while(1);
}
