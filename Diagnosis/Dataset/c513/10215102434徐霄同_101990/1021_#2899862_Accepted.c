#include <stdio.h>
#include <stdlib.h>
int p[26];
char zm[27];
int cmp(const void *a,const void *b)
{
    char *s1,*s2;
    char c1,c2;
    s1=*(char(*)[21])a;
    s2=*(char(*)[21])b;
    while(*s1 && *s2){
        c1=(*s1)>='a'?*s1-32:*s1;
        c2=(*s2)>='a'?*s2-32:*s2;
        if(p[c1-'A']!=p[c2-'A'])
            return p[c1-'A']-p[c2-'A'];
        else{
            s1++;
            s2++;
        }
    }
    if(*s1==0)
        return -1;
    else
        return 1;
}
int main()
{
    char a[100][21];
    int i,s,t,k;
    char c;
    while(scanf("%s",zm)!=EOF){
        for(i=0;i<26;i++)
            p[zm[i]-'A']=i;
        getchar();
        s=0;
        k=0;
        t=0;
        do{
            c=getchar();
            if(c!=' ' && c!='\n'){
                a[s][k++]=c;
                t=1;
            }
            else if(t){
                a[s][k]='\0';
                s++;
                k=0;
                t=0;
            }
        }while(c!='\n');
        qsort(a,s,sizeof(a[0]),cmp);
        for(i=0;i<s;i++){
            printf("%s",a[i]);
            if(i==s-1)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
