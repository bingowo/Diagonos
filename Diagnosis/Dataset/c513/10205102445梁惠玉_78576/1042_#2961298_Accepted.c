#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char com[100];
int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}

void print(char diff[],int len,int l,int r)
{
    if(l==r)
    {
        return;
    }
    for(;l!=r;l++)
    {
        com[len]=diff[l];
        com[len+1]='\0';
        printf("%s\n",com);
        print(diff,len+1,l+1,r);
    }

}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[18];
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(char),cmp);
        //printf("%s\n",s);
        char diff[16];
        char ch=s[0];
        diff[0]=ch;
        int count=1;
        for(int j=1;j<strlen(s);j++)
        {
           if(ch!=s[j])
           {
               ch=s[j];
               diff[count++]=ch;
           }
           else{
            continue;
           }
        }
        diff[count]='\0';
        /*for(int j=0;j<strlen(diff);j++)
        {
            printf("%c ",diff[j]);
        }*/
        print(diff,0,0,strlen(diff));
    }

    return 0;
}
