#include <stdio.h>
#include <stdlib.h>
int p[26];
char up(char x)
{
    if (x<='z'&&x>='a')
        return x+'A'-'a';
    return x;
}
int cmp(const void *p1,const void *p2)
{
    char *a=(char*)p1;char *b=(char*)p2;
    while((*a)!='\0'&&(*b)!='\0')
    {
        if(p[up(*a)-'A']<p[up(*b)-'A'])
            return -1;
        if(p[up(*a)-'A']>p[up(*b)-'A'])
            return 1;
        a++;b++;
    }
    if((*a)=='\0')
        return -1;
    if((*b)=='\0')
        return 1;
    return 0;
}
int main()
{
    char alpha[27];
    while(scanf("%s",alpha)!=EOF){
        for(int i=0;i<26;i++){
            p[alpha[i]-'A']=i;
        }
        char c;
        getchar();
        char a[100][21];
        int count=0,k=0;
        do{
            c=getchar();
            if((c>='a'&&c<='z')||(c<='Z'&&c>='A')){
                a[count][k]=c;
                k++;
            }
            else if(c==' '){
                a[count][k]='\0';
                count++;
                k=0;
            }
        }while(c!='\n');
        count++;
        qsort(a,count,sizeof(a[0]),cmp);
        for(int i=0;i<count;i++){
            printf("%s ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
