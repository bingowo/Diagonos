#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void*a,const void*b)
{
    char *aa=*(char**)a,*bb=*(char**)b;
    if(strlen(aa)>=strlen(bb)) return -1;
    else if(strlen(aa)<strlen(bb)) return 1;
}

char s[1000001]={0};
int main()
{
    char** sa=(char**)malloc(1000001*sizeof(char*));
    char st[100]={0};
    int arr[127]={0};
    scanf("%s",s);
    int cnt=0;
    for(int i=0,j=0;i<strlen(s);i++)
    {
        if(arr[s[i]]==0)
        {
            st[j]=s[i];
            j++;
            arr[s[i]]=i+1;
        }
        else
        {
            char*p=(char*)malloc(strlen(st)+1);
            strcpy(p,st);
            *(sa+cnt)=p;
            cnt++;
            j=1;
            i=arr[s[i]]-1;
            memset(arr,0,sizeof(arr));
            memset(st,0,sizeof(st));
        }
         if(i+1==strlen(s))
        {
            char*p=(char*)malloc(strlen(st)+1);
            strcpy(p,st);
            *(sa+cnt)=p;
            cnt++;
        }

    }
    if(cnt==0) printf("%s",s);
    else{
    qsort(sa,cnt,sizeof(char*),cmp);
    printf("%s",sa[0]);}
    for(int i=0;i<cnt;i++)
        free(sa[i]);
    free(sa);
    return 0;
}