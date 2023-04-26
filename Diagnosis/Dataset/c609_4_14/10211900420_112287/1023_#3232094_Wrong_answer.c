#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* month[21]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu"};
int cmp(const void* a,const void* b)
{
    int i,j=0,k=0;
    char *date1=*(char**)a,*date2=*(char**)b,month1[10]={0},month2[10]={0},year1[5]={0},year2[5]={0};
    for(i=0;i<strlen(date1);i++)
    {
        if(date1[i]==' ') break;
    }
    for(i=i+1;i<strlen(date1);i++)
    {
        if(date1[i]!=' ')
        {
            month1[j]=date1[i];
            j++;
        }
        if(date1[i]==' ')
        {
            month1[j]='\0';
            break;
        }
    }
    for(i=i+1;i<strlen(date1);i++)
    {
        year1[k]=date1[i];
        k++;
    }
    year1[k]='\0';
    for(i=0;i<strlen(date2);i++)
    {
        if(date2[i]==' ') break;
    }
    j=0;k=0;
    for(i=i+1;i<strlen(date2);i++)
    {
        if(date2[i]!=' ')
        {
            month2[j]=date2[i];
            j++;
        }
        if(date2[i]==' ')
            break;
    }
    for(i=i+1;i<strlen(date2);i++)
    {
        year2[k]=date2[i];
        k++;
    }

    if(strcmp(year1,year2)!=0) return strcmp(year1,year2);
    for(i=0;i<20;i++)
    {
        if(month1==month[i])
            break;
    }
    for(j=0;j<20;j++)
    {
        if(month2==month[j])
            break;
    }
    if(i!=j) return i-j;
    return strcmp(date1,date2);
}
int main()
{
    int N,T,i;
    char **a;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d\n",&N);
        a=(char**)malloc(sizeof(char*)*N);
        for(int j=0;j<N;j++)
        {
            a[j]=(char*)malloc(sizeof(char)*40);
            gets(a[j]);
        }
        qsort(a,N,sizeof(a[0]),cmp);
        for(int j=0;j<N;j++)
            printf("%s\n",a[j]);
    }
    return 0;
}