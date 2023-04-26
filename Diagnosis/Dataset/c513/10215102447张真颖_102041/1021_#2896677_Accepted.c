#include <stdio.h>
#include <stdlib.h>

int p[26];
int cmp(const void* a,const void* b)
{
    char *pa=*(char(*)[21])a,*pb=*(char(*)[21])b;
    char ch1,ch2;
    while(*pa&&*pb)
    {
        ch1=(*pa)>='a'?*pa-32:*pa;
        ch2=(*pb)>='a'?*pb-32:*pb;
        if(p[ch1-'A']!=p[ch2-'A']) return p[ch1-'A']-p[ch2-'A'];
        else pa++,pb++;
    }
    if(*pa==0) return -1;
    else return 1;

}

int main()
{

    char v[27];
    while(scanf("%s",v)!=EOF)
    {
        for(int i=0;i<26;i++)
            p[v[i]-'A']=i;
        getchar();
        char a[100][21];
        int count=0,k=0,status=0;
        char c;
        do
        {
            if((c=getchar())!=' '&&c!='\n') a[count][k++]=c,status=1;
            else if(status)
                a[count][k]='\0',count+=1,status=0,k=0;
        }while(c!='\n');
        qsort(a,count,sizeof(a[0]),cmp);
        for(int i=0;i<count;i++)
            printf("%s%c",a[i],i==(count-1)?'\n':' ');
    }
    return 0;
}
