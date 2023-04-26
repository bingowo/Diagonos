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
        if((s1 =='\0')&&(s2 !='\0'))
        {
            return 1;
        }
        else if((s1 !='\0')&&(s2 =='\0'))
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
            else{;}

            if(s1==s2)
            {
                L++;continue;
            }
            else
            {return p[s1]-p[s2];}
        }
    }while(1);
}

/*int cmp(const void *a,const void *b)
{
    char *s1,*s2;char ch1,ch2;
    s1=*(char (*)[21])a;s2=*(char (*)[21])b;
    while(*s1&&*s2)
    {
        ch1=(*s1)>='a'?*s1-32:*s1;    //转换为大写字母
        ch2=(*s2)>='a'?*s2-32:*s2;     //转换为大写字母
        if(p[ch1-'A']!=p[ch2-'A'])     //按字母顺序表比较字母
                return p[ch1-'A']-p[ch2-'A'];
        else {s1++;s2++;}
    }
    if(*s1==0) return -1;
    else return 1;
}*/


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