#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int o;
    int tms;
} TIMES;

char* shorten (char* s1)
{
    char* s2=(char*)calloc(120,sizeof(char));
    int k,x=0;
    if (strlen(s1)==0)
        return NULL;
    else
    {
        for (k=0;k<strlen(s1);k++)
        {
            if (k>0 && k<strlen(s1)-1)
                if (s1[k]!=s1[k-1] && s1[k]!=s1[k+1])
                    s2[x++]=s1[k];
            if (k==0)
                if (s1[k]!=s1[k+1])
                    s2[x++]=s1[k];
            if (k==strlen(s1)-1)
                if (s1[k]!=s1[k-1])
                    s2[x++]=s1[k];
        }
        s2[x]='\0';
        return s2;
    }
}

int remove1(char* s1)
{
    int j,cnt=1,result=0;

    for (j=1;j<strlen(s1);j++)
    {
        if (s1[j]==s1[j-1])
        {
            cnt++;
            if (s1[j+1]!=s1[j] && j<strlen(s1)-1)
                result+=cnt;
            if (j==strlen(s1)-1)
            {
                result+=cnt;
            }

        }
        else
            cnt=1;

    }
    return result;
}

int insertt(char* s,int i)
{
    int n=strlen(s);
    int j=i+1,cnt=1,result=0;
    char s1[120]; strcpy(s1,s);
    char a=s[n-1];
    for (j,i;j<strlen(s);j++,i++)
    {
        s1[j]=s[i];
    }
    s1[j++]=a;
    s1[j]='\0';
    result+=remove1(s1);
    char* s2=shorten(s1);
    while (s2!=NULL && remove1(s2)!=0)
    {
        result+=remove1(s2);
        s2=shorten(s2);
    }
    return result;

}

int cmp(const void* a,const void* b)
{
    TIMES* pa=(TIMES*)a;  TIMES* pb=(TIMES*)b;
    return (pa->tms>pb->tms)?-1:1;
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for (int i=0;i<T;i++)
    {
        int j,k=0,cnt=1;
        printf("case #%d:\n",i);
        char c; char s[120]={0};
        scanf("%s",s);
        for (j=1;j<strlen(s);j++)
            if (s[j]!=s[j-1])
                cnt++;
        if (cnt==0)
        {
            int n=insertt(s,0);
            printf("%d\n",n);
        }
        else
        {
            TIMES* arr=(TIMES*)malloc(cnt*sizeof(TIMES));
            for (j=1;j<strlen(s);j++)
                if (s[j]!=s[j-1])
                {
                    if (j==1)
                    {
                        arr[k++].o=j-1;
                        arr[k++].o=j;
                    }
                    else
                        arr[k++].o=j;
                }
            for (j=0;j<cnt;j++)
            {
                arr[j].tms=insertt(s,arr[j].o);
            }

            qsort(arr,cnt,sizeof(TIMES),cmp);
            printf("%d\n",arr[0].tms);
            free(arr);
        }




    }
    return 0;
}
