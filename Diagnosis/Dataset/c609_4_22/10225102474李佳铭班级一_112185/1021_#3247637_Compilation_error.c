#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    char* A = *(char(*)[21])a;
    char* B = *(char(*)[21])b;
    while(*A != '\0' && *B != '\n')
    {
        if((*A) >= 'a')
            *A = *A - 32;
        if((*B) >= 'a')
            *B = *B - 32;
        char s1 = *A;
        char s2 = *B;
        if(a[s1 - 'A'] != a[s2 - 'A'])
            return a[s1 - 'A'] - a[s2 - 'A'];
        else
        {
            A++;B++;
        }
    }
    if(*A == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }

}


int main()
{
    char aph[27];
    int a[26];
    while(scanf("%s",aph) != EOF)
    {
        for(int i = 0; i < 26;i++)
        {
            a[aph[i] - 'A'] = i;
        }
        getchar();
    }

    char s[1000][21];
    int k = 0,count = 0;
    char c;
    int status = 0;
    do
    {
        c = getchar();
        if(c != ' ' && c !=  '\n')
        {
            s[count][k] = c;
            k++;
            status = 1;
        }
        else if(status)
        {
            s[count][k] = '\0';
            k = 0;
            status = 0;
        }
    }while(c != '\n');
    qsort(s,count,sizeof(s[0]),cmp);
    for(int i = 0;i < count;i++)
    {
        printf("%s ",s[i]);
    }



    return 0;
}