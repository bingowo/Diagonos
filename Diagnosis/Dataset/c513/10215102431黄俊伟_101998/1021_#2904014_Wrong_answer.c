#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int table[26];
int cmp(const void* p1,const void* p2);
int main()
{
    char input[100][21];
    int num=0,count=0,status=0;
    char alpha[27];
    char c;
    scanf("%s",alpha);
    getchar();
    for(int i=0;i<26;i++)
        table[alpha[i]-65]=i;
    do
    {
        c=getchar( );
        if(c!=' ' && c!='\n')
        {
            input[num][count++]=c;
            status=1;
        }
        else if(status)
            {
                input[num][count]='\0';
                num++;
                count=0;
                status=0;
            }
    }while(c!='\n'&&c!=EOF);
    qsort(input,num,sizeof(input[0]),cmp);
    for(int i=0;i<num;i++)
    {
        i<num-1?printf("%s ",input[i]):printf("%s",input[i]);
    }
    return 0;
}
int cmp(const void* p1,const void* p2)
{
    char *str1,*str2;
    str1 = *((char(*)[21])p1);
    str2 = *((char(*)[21])p2);
    char c1,c2;
    while(*str1&&*str2)
    {
        c1=(*str1)>='a'?*str1-32:*str1;
        c2=(*str2)>='a'?*str2-32:*str2;
        if(table[c1-'A']!=table[c2-'A'])
                return table[c1-'A']-table[c2-'A'];
        else {str1++;str2++;}
    }
    if(*str1==0) return -1;
    else return 1;

}