#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char *x=(char *)a;
    char *y=(char *)b;
    return strcmp(x,y);
}
void comb(char*s,char* char_comb)
{
    if(*s)
    {
        char left[17]={0};
        sprintf(left,"%s%c",char_comb,s[0]);
        printf("%s\n",left);
        comb(s+1,left);
        comb(s+1,char_comb);
    }
}
int main()
{
    int t;
    char s[20];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int a[256]={0};
        char h[20];
        int k=0,j=0;
        scanf("%s",s);
        int len= strlen(s);
        qsort(s, len,sizeof(s[0]),cmp);
        for(j=k=0;j<len;j++)
        {
            if(a[s[j]]==0)
            {
                a[s[j]]=1;
                h[k++]=s[j];
            }
        }
        h[k]='\0';
        printf("case #%d:\n",i);
        char x[20]="";
        comb(h,x);
    }
    return 0;
}