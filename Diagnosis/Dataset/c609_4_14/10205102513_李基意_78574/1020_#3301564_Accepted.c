#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {char str[31]; int n;}S;
int cmp(const void *a, const void *b)
{
    S *p1=(S*)a, *p2=(S*)b;
    if(p1->n==p2->n) return strcmp(p1->str,p2->str);
    return p1->n-p2->n;
}
int main(void)
{
    char all[3005];
    S s[100]={0};
    gets(all);
    int cnt=0, number=0, i=0, j=0, check=0;
    while(all[j]!='\0')
    {
        if(all[j]==' ')
        {
            s[cnt].str[i]='\0';
            if(check==1)s[cnt].n=number;
            else {s[cnt].n=-1;}
            cnt++;
            number=0;
            i=0;
            check=0;
        }
        else
            s[cnt].str[i++]=all[j];
            if(all[j]>='0'&&all[j]<='9'){
                number=number*10+(all[j]-'0');
                check=1;}
        j++;
    }
    s[cnt].str[i]='\0';
    if(check==1)s[cnt].n=number;
    else {s[cnt].n=-1;}
    cnt++;
    qsort(s, cnt, sizeof(s[0]), cmp);
    for(i=0;i<cnt-1;++i)
        printf("%s ",s[i].str);
    printf("%s\n",s[i].str);
    return 0;
}