#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char p[26];
int trans(char t){
if(t>96&&t<123)t=t-32;
int j=0;
for(;j<26;j++)
    if(t==p[j])break;
return j;
}
int cmp(const void* a,const void* b){
for(int i=0;(((char*)a)[i])!=0&&(((char*)b)[i])!=0;i++)
{
    if(trans(((char*)a)[i])>trans(((char*)b)[i]))
    return 1;
    else if(trans(((char*)a)[i])<trans(((char*)b)[i]))
    return -1;
    else continue;
}
}
int main(){
    while(scanf("%s",p)!=EOF){
        char in[100][21];
        int n=0;
        while(1){
       if(scanf("%s",in[n])==' ')n++;
       if(scanf("%s",in[n])==EOF)break;}
        qsort(in,n,sizeof(in[0]),cmp);
        for(int i=0;i<n;i++)
        printf("%s ",in[i]);
        printf("\n");

    }

return 0;
}