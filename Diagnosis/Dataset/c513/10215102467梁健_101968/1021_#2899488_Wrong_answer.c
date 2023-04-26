#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ord[27];
char ORD[128];
int cmp(const void *a,const void *b)
{
    char a1[21],b1[21];
    strcpy(a1,(char*)a);
    strcpy(b1,(char*)b);
    for(int i=0;i<strlen(a1);i++)if(a1[i]>91)a1[i]=a1[i]-32;
    for(int i=0;i<strlen(b1);i++)if(b1[i]>91)b1[i]=b1[i]-32;
    int i=0;
    do{
        if(ORD[a1[i]]!=ORD[b1[i]])return (ORD[a1[i]]>ORD[b1[i]]?-1:1);
        if(i+1==strlen(a1)&&i+1!=strlen(b1))return -1;
        if(i+1!=strlen(a1)&&i+1==strlen(b1))return 1;
        i++;
    }while(i<21);
}
int main()
{
    char c=0;
    char list[101][21];
    do{
        scanf("%s",ord);
        ORD['Q']=27;
        for(int i=0;i<strlen(ord);i++)ORD[ord[i]]=26-i;
        int ele=0;
        do{
            scanf("%s",list[ele++]);
        }while(c=getchar()==' '&&c!='\n');
        qsort(list,ele,sizeof(list[0]),cmp);
        for(int i=0;i<ele-1;i++){
            printf("%s ",list[i]);
        }
        printf("%s\n",list[ele-1]);
    }while(c=getchar()!=EOF);
    return 0;
}
