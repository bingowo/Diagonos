#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int finddigit(char* a)
{
    int i=0,weight=1,res=0,flag=0;
    for(i=strlen(a)-1;i>=0;i--)
    {
        if(a[i]>='0' && a[i]<='9') 
        {
            flag=1;
            res+=weight*(a[i]-'0');
            weight*=10;
        }
    }
    if(flag==0) return -1;
    else return res;
}

int strnumcmp(const void* a, const void* b)
{
    char* p1=(char*)a;char* p2=(char*)b;
    if(finddigit(p1)==finddigit(p2)) return strcmp(p1,p2);
    else return finddigit(p1)-finddigit(p2);
}

int main()
{
    char str[110][40]={{'\0'}};
    int num=0;
    while (scanf("%s",str[num])!=EOF) num++;
    qsort(str,num,sizeof(str[0]),strnumcmp);
    
    int i;
    for(i=0;i<num-1;i++) i==num ? printf("%s\n",str[i]) : printf("%s ",str[i]);

    return 0;
}