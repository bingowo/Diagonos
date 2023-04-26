#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char s1[6][4]={"the","and","a","an","of","for"};

typedef struct
{
    char* str;
} WORD;


int mgetline(char s[],int lim)
{
    int c,i;
    i=0;
    while ((c=getchar())!=EOF && c!='\n' && i<lim-1 && c!='@')
        s[i++]=c;
    if (c==EOF && i==0)
        return -1;
    s[i]='\0';
    return i;
}


int main()
{
    int T;
    scanf("%d",&T);
    char s[120]={0};
    getchar();
    int m;
    for (int i=0;i<T;i++)
    {

        printf("case #%d:\n",i);
        m=mgetline(s,550);
        int j,n=0,k,h,cn=strlen(s);
        for(j=0;j<cn;j++)
        {

            if (s[j]==' ' || s[j]==',' || s[j]=='.'|| s[j]=='!' || s[j]=='?')
            {
                if (j<cn-1)
                {
                    if (s[j+1]==' ' || s[j+1]==',' || s[j+1]=='.'|| s[j+1]=='!' || s[j+1]=='?')
                    {
                        j++;
                    }
                }
                if (j==cn-1)
                    if (s[j-1]==' ' || s[j-1]==',' || s[j-1]=='.'|| s[j-1]=='!' || s[j-1]=='?')
                        if (s[j-2]==' ' || s[j-2]==',' || s[j-2]=='.'|| s[j-2]=='!' || s[j-2]=='?')
                        break;
                n++;
            }
        }
        if (isalpha(s[strlen(s)-1]))
            n++;
        WORD* arr=(WORD*)malloc(n*sizeof(WORD));
        int cnt=0;
        if (n!=0)
            cnt=550/n;
        if (n==0 && strlen(s)!=0)
        {
            printf("%s\n",s);
            continue;
        }
        for(j=0;j<n;j++)
            arr[j].str=(char*)malloc(cnt*sizeof(char));
        for(j=0,k=0,h=0;k<n && j<strlen(s);j++)
        {
            arr[k].str[h++]=s[j];
            if (s[j]==' ' || s[j]==',' || s[j]=='.'|| s[j]=='!' || s[j]=='?')
            {
                if (j<strlen(s)-1)
                {
                    if (s[j+1]==' ' || s[j+1]==',' || s[j+1]=='.'|| s[j+1]=='!' || s[j+1]=='?')
                    j++;
                }
                arr[k].str[h-1]='\0';
                k++;
                h=0;

            }
        }
        int nn=0,flag=0,ii;
        for (j=0;j<n;j++)
        {
            flag=0;
            for (ii=0;ii<6;ii++)
            {
                if (strcmp(arr[j].str,s1[ii])==0 || strlen(arr[j].str)==0)
                {
                    flag=1;
                }
            }
            if (flag==0)
                nn++;

        }
        printf("%d\n",nn);
        for (j=0;j<n;j++)
            free(arr[j].str);
        free(arr);


    }

    return 0;
}
