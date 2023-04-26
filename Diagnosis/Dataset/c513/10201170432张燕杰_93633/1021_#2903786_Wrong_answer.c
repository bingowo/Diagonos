#include<stdio.h>
#include<stdlib.h>
int p[26];
int cmp(const void *a,const void*b)
{
    char *p1,*p2;
    p1 = *(char(*)[21])a;
    p2 = *(char(*)[21])b;
    int L = 0;
    do
    {
        char s1,s2;
        s1 = *(p1+L);
        s2 = *(p2+L);
        if(s1 =='\0')
        {
            return 1;
        }
        else if(s2=='\0')
        {
            return -1;
        }
        else{
            if(s1>90)
            {
                s1 = s1-32;
            }
            else if(s2>90)
            {
                s2 = s2-32;
            }
            if(s1==s2)
            {
                L++;continue;
            }
            else
            {return p[s1]-p[s2];}
        }
    }while(1);
}

int main()
{
    char alpha[27];
    while(scanf("%s",alpha)!=EOF)
    {
        for(int i =0;i<26;i++)
        {
            p[alpha[i]-'A'] = i;
        }
        getchar();

        char c[100][21];
        int count =0;
        do
        {
            scanf("%s",c[count]);
            count++;
        }while(getchar()!='\n');

        qsort(c,count,sizeof(c[0]),cmp);
        for(int i =0;i<count;i++)
        {printf("%s ",c[i]);}
        printf("\n");
    }
    return 0;
}