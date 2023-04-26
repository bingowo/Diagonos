#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process(char *s)
{
    int cc[58]={0};
    int i,j=0; char ch;
    for(i=0;(ch=s[i])!='\0';i++)
        if(cc[ch - 'A']==0) cc[ch-'A']=1;
    for(i=0;i<58;i++)
        if(cc[i]==1) s[j++]=i+'A';
    s[j]='\0';
}
void comb(char* s,char* char_comb)
{
    if(*s)
    {
        char char_comb_left[17];
        sprintf(char_comb_left,"%s%c",char_comb,s[0]);
        printf("%s\n",char_comb_left);
        comb(s+1,char_comb_left);
        comb(s+1,char_comb);
    }
}

void solve()
{
    char s[17]="";
    scanf("%s",s);
    process(s);
    char char_comb[17]="";
    comb(s,char_comb);
}
int main()
{
   int T;
   scanf("%d",&T);
   for(int cas=0;cas<T;cas++)
   {
       printf("case #%d:\n",cas);
       solve();
   }
    return 0;
}