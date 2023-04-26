#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

char str[105][105],st[30],strs[10005];
char* ps[105];
int n;
int cmp[128];

char ChUpr(char c){
    if(c>='a'&&c<='z')
        return c+'A'-'a';
    return c;
}

int Cmp(const char** pa, const char** pb){
    const char *sa=*pa,*sb=*pb;
    static int i;
    for(i=0;sa[i]!='\0'&&sb[i]!='\0';i++)
        if(cmp[(int)ChUpr(sa[i])]!=cmp[(int)ChUpr(sb[i])])
            return cmp[(int)ChUpr(sa[i])]-cmp[(int)ChUpr(sb[i])];
    return sa[i]=='\0'?-1:1;
}

void MakeCmp(char* s){
    for(int i=0;i<26;i++)
        cmp[(int)s[i]]=i;
}

int main(){
    memset(cmp,-1,sizeof(cmp));
    while(1){
        n=0;
        if(scanf("%s",st)==EOF) break;
        MakeCmp(st);
        gets(strs);
        memset(strs,0,sizeof(strs));
        gets(strs);
        for(char* p=strs;
                sscanf(p,"%s",str+n)!=EOF;
                p+=strlen(str[n])+1,n++)
            ps[n]=str[n];

        qsort(ps,n,sizeof(ps[0]),Cmp);

        for(int i=0;i<n;i++)
            printf("%s ",ps[i]);
        printf("\n");
    }

    return 0;
}
