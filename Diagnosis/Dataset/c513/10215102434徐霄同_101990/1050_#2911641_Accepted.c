#include <stdio.h>
#include <string.h>
char s[81];
int l;
int f(char s1[],char s2[])
{
    char ss[81];
    int l1,l2,x1,x2,j,k,p;
    l1=strlen(s1);
    l2=strlen(s2);
    x1=-1;
    x2=-1;
    for(j=0;j<l-l1+1;j++){
        p=0;
        for(k=j;k<j+l1;k++){
            ss[p]=s[k];
            p++;
        }
        ss[l1]='\0';
        if(strcmp(ss,s1)==0){
            x1=j+l1-1;
            break;
        }
    }
    for(j=l-1;j>=l2-1;j--){
        p=l2-1;
        for(k=j;k>j-l2;k--){
            ss[p]=s[k];
            p--;
        }
        ss[l2]='\0';
        if(strcmp(ss,s2)==0){
            x2=j-l2+1;
            break;
        }
    }
    if(x1==-1 || x2==-1 || x2<=x1)
        return 0;
    else
        return x2-x1-1;
}
int main()
{
    char s1[81],s2[81];
    int t,i,x;
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        gets(s1);
        gets(s2);
        gets(s);
        l=strlen(s);
        x=f(s1,s2);
        if(x==0)
            x=f(s2,s1);
        printf("case #%d:\n",i);
        printf("%d\n",x);
    }
    return 0;
}
