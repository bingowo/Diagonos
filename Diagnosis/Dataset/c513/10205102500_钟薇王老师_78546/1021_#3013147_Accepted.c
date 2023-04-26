#include<stdio.h>
#include<stdlib.h>
int table[26];
int cmp(const void*a,const void*b)
{
    char *x=*(char (*)[21])a,*y=*(char (*)[21])b;
    char c1,c2;
    while(*x && *y)
    {
        c1=((*x)>='a')?(*x-32):(*x);
        c2=((*y)>='a')?(*y-32):(*y);
        if( table[c1-'A'] != table[c2-'A'] )return table[c1-'A'] - table[c2-'A'];
        else {x++;y++;}
    }
    if(*x==0)return -1;
    else return 1;
}
int main()
{
    char s[27];
    while(scanf("%s\n",s)!=EOF)
    {
        int i;
        for(i=0;i<26;i++)
            table[s[i]-'A']=i;
        char x[100][21];
        int cnt=0,k=0,flag=0;
        char c;
        do{
            c=getchar();
            if(c!=' ' && c!='\n')
            {
                x[cnt][k++]=c;
                flag=1;
            }
            else if(flag)
            {
                x[cnt][k]='\0';
                cnt++;
                k=0;
                flag=0;
            }
        }while(c!='\n');
        qsort(x,cnt,sizeof(x[0]),cmp);
        for(i=0;i<cnt-1;i++)
            printf("%s ",x[i]);
        printf("%s\n",x[i]);
    }
}
