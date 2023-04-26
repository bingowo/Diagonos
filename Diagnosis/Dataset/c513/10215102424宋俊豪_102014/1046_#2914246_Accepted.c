#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
char s[105],b[105];char t[6][5]={"the","a","an","of","for","and"};
void slo(char s[])
{
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
            s[i]=s[i]+32;
    }
}
int cmp(char s[])
{
    for(int i=0;i<6;i++)
    {
        if(strcmp(s,t[i])==0)
            return 0;
    }
    return 1;
}
int main()
{
    int n,cnt,id;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {   cnt=0;id=0;
        gets(s);
        slo(s);
        int j=0;
        while(j<=strlen(s))
        {
            if(s[j]==' '||s[j]=='\0')
            {
                b[id]='\0';
                cnt+=cmp(b);
                id=0;
            }
            else{
            b[id++]=s[j];
            }
            j++;
        }
        printf("case #%d:\n",i);
        printf("%d\n",cnt);
    }
    return 0;
}
