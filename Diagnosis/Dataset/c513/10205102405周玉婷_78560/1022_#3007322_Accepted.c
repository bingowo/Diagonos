#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char *pc;//用户名
    char *ww;//主机域名
} mail;

int cmp(const void *pa, const void *pb)
{
    mail a=*(mail *)pa;
    mail b=*(mail *)pb;
    if(strcmp(a.ww, b.ww)==0)
    {
        return -strcmp(a.pc, b.pc);
    }
    else return strcmp(a.ww, b.ww);
}

int main()
{
        int n;
        scanf("%d",&n);
        mail* s = (mail *)malloc(sizeof(mail)*n);
        char temp[1000005];
        for(int i=0; i<n; i++)
        {
           scanf("%s",temp);
           int j=0;
           for( j=0; temp[j]!='@'; j++);
           s[i].pc=(char *)malloc(sizeof(char)*(j+10));
           memmove(s[i].pc, temp,j);
           s[i].pc[j] = 0;
           int len = strlen(temp) - strlen(s[i].pc) -1;
           s[i].ww=(char *)malloc(sizeof(char)*(len+10));
           memmove(s[i].ww, temp+j+1, len);
           s[i].ww[len] = 0;
        }
        qsort(s, n, sizeof(mail), cmp);
        for(int i=0; i<n; i++)
        {
            printf("%s@%s\n",s[i].pc,s[i].ww);
        }
}