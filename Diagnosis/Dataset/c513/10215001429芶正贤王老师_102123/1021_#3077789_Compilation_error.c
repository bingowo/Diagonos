#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int p[30];
int cmp(const void*a,const void*b)
{
    char *s1,*s2;
    char ch1,ch2;
    s1 = (char*)a;
    s2 = (char*)b;
    while(*s1 && *s2)
    {
        ch1 = (*s1)>='a'?*s1-32:*s1;
        ch2 = (*s2)>='a'?*s1-32:*s1;
        if(p[ch1-'A'] != p[ch2-'A'])//升序
            return (p[ch1-'A'] - p[ch2-'A']);
        else
        {
            s1++;
            s2++;
        }
        
    }
    
    if(*s1 == 0)
        return -1;
    else
        return 1;
    
}


int main()
{
    char std[30];
    for(int i=0;i<26;i++)
    {
        scanf("%c",&std[i]);
        p[std[i]-'A'] = i;
    }
    char str[2200];
    getchar();
    gets(str);
    char let[105][25];
    int cnt=0,i=0,j;
    whlie(1)
    {
        j=0;
        while(str[i]!=' ' && str[i])
        {
            let[cnt][j] = str[i];
            j++;
            i++;
        }
        let[cnt][j] = '\0';
        cnt++;
        if(str[i]!='\0')
            break;
        else
            i++;
    }
    qsort(let,cnt,sizeof(let[0]),cmp);
    for(int k=0;k<cnt-1;k++)
        printf("%s ",let[k]);
    printf("%s\n",let[cnt-1]);
    return 0;
    
    
}