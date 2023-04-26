#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* str;
}  BIN;

typedef struct
{
    char st[7];
    char c;
}  BASE;

void reverse(char* s)
{
    char tmp; int i,j;
    for (i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}

char* itob(char a)
{
    char* ss=(char*)calloc(9,sizeof(char));
    for (int i=0;i<8;i++)
        ss[i]='0';
    int n=(int)a;
    for (int i=0;n>0;i++)
    {
        ss[i]=n%2+'0';
        n=n>>1;
    }
    reverse(ss);
    return ss;

}

int btoi(char* s)
{
    int n=0;
    for (int i=0;i<strlen(s);i++)
    {
        n=n*2+s[i]-'0';
    }
    return n;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int j,k=0,h=0,l=0;
        printf("case #%d:\n",i);
        char s[120]={0};
        scanf("%s",s);
        int n=strlen(s),m;
        BIN* arr=(BIN*)malloc(n*sizeof(BIN));
        for (j=0;j<n;j++)
            arr[j].str=itob(s[j]);
//        for (j=0;j<n;j++)
//            printf("%s",arr[j].str);
        if (n%3==0)
        {
            m=n*8/6;
            BASE* arr2=(BASE*)calloc(m,sizeof(BASE));
            j=0;
            while (j<n)
            {
                arr2[k].st[h++]=arr[j].str[l++];
                if (h==6)
                {
                    h=0;
                    k++;
                }
                if (l==8)
                {
                    l=0;
                    j++;
                }
            }
            for (j=0;j<m;j++)
            {
                int a=btoi(arr2[j].st);
                if (a<26)
                    arr2[j].c=a+'A';
                if (a>=26 && a<52)
                    arr2[j].c=a-26+'a';
                if (a>=52 && a<62)
                    arr2[j].c=a-52+'0';
                if (a==62)
                    arr2[j].c='+';
                if (a==63)
                    arr2[j].c='-';
            }
            for (j=0;j<m;j++)
                printf("%c",arr2[j].c);
            if (m%4!=0)
            {
                for (j=0;j<((m/4+1)*4-m);j++)
                printf("%c",'=');
            }
            printf("\n");
            free(arr2);
        }
        else
        {
            j=0;
            m=n*8/6+1;
            BASE* arr2=(BASE*)calloc(m,sizeof(BASE));
             while (j<n)
            {
                arr2[k].st[h++]=arr[j].str[l++];
                if (h==6)
                {
                    h=0;
                    k++;
                }
                if (l==8)
                {
                    l=0;
                    j++;
                }
            }
            int x=n*8;
            while (x%6!=0)
            {
                arr2[k].st[h++]='0';
                x++;
            }
            for (j=0;j<m;j++)
            {
                int a=btoi(arr2[j].st);
                if (a<26)
                    arr2[j].c=a+'A';
                if (a>=26 && a<52)
                    arr2[j].c=a-26+'a';
                if (a>=52 && a<62)
                    arr2[j].c=a-52+'0';
                if (a==62)
                    arr2[j].c='+';
                if (a==63)
                    arr2[j].c='-';
            }
            for (j=0;j<m;j++)
                printf("%c",arr2[j].c);
            if (m%4!=0)
            {
                for (j=0;j<((m/4+1)*4-m);j++)
                printf("%c",'=');
            }
            printf("\n");
            free(arr2);


        }
        for (j=0;j<n;j++)
            free(arr[j].str);
        free(arr);

    }

    return 0;
}
