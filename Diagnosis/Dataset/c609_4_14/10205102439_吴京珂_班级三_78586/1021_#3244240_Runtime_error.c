#include <stdio.h>
#include <stdlib.h>
int p[26];


int main()
{

    char s[27];
    while(scanf("%s\n",s)!=EOF)
    {
        for(int i=0; i<26; i++)
        {
            p[s[i]-'A']=i;
        }
    }

    char str[2005];
    char a[100][21];
    gets(str);
    int count=0;
    int i=0,j;
    while(1)
    {
        j=0;
        while(str[i]!=' '&&str[i]) a[count][j++]=str[i++];
        a[count][j]='\0';//结束符
        count++;
        if(!str[i]) break;
        else i++;
    }

    //qsort(a,count,sizeof(a[0]),cmp);

    for(i=0; i<count-1; i++)
        printf("%s ",a[i]);
    printf("%s\n",a[i]);

    return 0;
}
