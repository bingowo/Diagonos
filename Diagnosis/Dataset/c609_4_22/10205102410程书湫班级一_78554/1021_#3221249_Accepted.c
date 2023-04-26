#include <stdio.h>
#include <stdlib.h>
int T[100];
int cmp(const void* a,const void* b)
{
    char *s1,*s2;
    s1=(char*)a;
    s2=(char*)b;
    char c1,c2;
    while(*s1&&*s2)
    {
        c1=(*s1)>='a'?*s1-32:*s1;
        c2=(*s2)>='a'?*s2-32:*s2;
        if(T[c1]!=T[c2]) return T[c1]-T[c2];
        else{
            s1++;
            s2++;
        }
    }
        if(*s1==0) return -1;
        else return 1;
}
int main()
{
    char a[27];
    while(scanf("%s\n",a)!=EOF)
    {
        for(int i=0;i<26;i++) T[a[i]]=i;
        char c,s[100][21];
        int n=0,k=0,flag=0;
    do
    {
        c=getchar();
        if(c!=' '&&c!='\n')
        {
            s[n][k++]=c;
            flag=1;
        }
        else if(flag)
        {
            s[n][k]='\0';
            n++;
            k=0;flag=0;
        }
    }while(c!='\n');
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++)
    printf("%s%c",s[i],i<n-1?' ':'\n');
    }
    return 0;
}
