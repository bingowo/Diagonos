#include <stdio.h>
#include <stdlib.h>
int judge(char s[150])
{
    int i=0,k=0;
    char t[150]={0};
    for(i=0;s[i];i++)
    {
        switch(s[i])
        {
            case '(':if(k<=0 || t[k-1]=='['){t[k]=s[i];k++;}else return -1; break;
            case '[':if(k<=0 || t[k-1]=='{'){t[k]=s[i];k++;}else return -1; break;
            case '{':if(k<=0 || t[k-1]=='('){t[k]=s[i];k++;}else return -1; break;
            case ')':if(k>0 && t[k-1]=='('){k--;t[k]=0;}else return -1; break;
            case ']':if(k>0 && t[k-1]=='['){k--;t[k]=0;}else return -1; break;
            case '}':if(k>0 && t[k-1]=='{'){k--;t[k]=0;}else return -1; break;
        }
    }
    return 1;

}
void jisuan()
{
    char s[150]={0};
    int d=0,l=0;
    scanf("%s",s);
    l=strlen(s);
    if(s%2!=0){printf("No\n");return;}
    d=judge(s);
    if(d>0)printf("Yes\n");
    else printf("No\n");
    return ;
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan();
}
