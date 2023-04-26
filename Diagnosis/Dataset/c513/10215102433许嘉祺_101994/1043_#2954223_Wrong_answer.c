#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int erase(char*s){
    char s1[105];
    int find=0;
    int len=0;
    if (strlen(s)==1) return 0;
    for (int i=0;i<strlen(s);i++){
        if (i==0) {if (s[i]==s[i+1]) find=1;else s1[len++]=s[i];}
        else if(i==strlen(s)-1) {if (s[i]==s[i-1]) find=1;else s1[len++]=s[i];}
        else if(s[i]==s[i-1]||s[i]==s[i+1]) find=1;
        else s1[len++]=s[i];}
    s1[len]=0;
    strcpy(s,s1);
    return find;

}
int matter(char*s,int pos){
    int len=1;
    while (pos-len>=0&&pos+len<=strlen(s)-1) if (s[pos-len]!=s[pos+len]) break;else len++;
    return len;
}

int main()
{
    int t;
    scanf("%d",&t);
    char s[105];
    for (int i=0;i<t;i++){
        scanf("%s",s);
        int find=1;
        int count=strlen(s);
        while (find==1)
            find=erase(s);
        count=count-strlen(s);
        int nummax=1;
        int num=1;
        for (int j=1;j<strlen(s)-1&&strlen(s)>=3;j++)
        {
                num=matter(s,j);
                if (num>nummax) nummax=num;
        }
        printf("case #%d:\n",i);
        if (strlen(s)!=0)
        printf("%d\n",nummax*2+count);
        else printf("%d\n",count+1);
    }

    return 0;
}