#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char s2[17];
char s1[26];
int count;
void find(int depth,int type){
    if (depth!=0&&type==1) printf("%s\n",s2);
    if(depth<count){

    int len=strlen(s2);
    sprintf(s2,"%s%c",s2,s1[depth]);

        find(depth+1,1);
        s2[len]=0;
        find(depth+1,0);}
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[100];
    int a[255];


    for (int i=0;i<n;i++){
        count=0;
        memset(a,0,sizeof(a));
        memset(s2,0,sizeof(s2));
        for(int j=0;j<strlen(s);j++)
            a[s[j]]++;
        for (int j=0;j<244;j++)
        if (a[j]>0) s1[count++]=j;
        s1[count]=0;
        printf("%s\n",s1);
        printf("case #%d:\n",i);
        find(0,0);
    }


    return 0;
}
