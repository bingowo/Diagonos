#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int Atoa(char s)
{
    if(s>='A'&&s<='Z')
        return s+32;
    else return s;
}

int main()
{
    char str[100];
    int n,i;
    int Atoa(char s);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    int k,m;
    double num[26];
    for(k=0;k<26;k++)
        scanf("%lf",&num[k]);
    char tmp;
    scanf("%s",&str);
    for(m=0;m<strlen(str)-1;m++){
            for(k=0;k<strlen(str)-1-m;k++){
                if(num[Atoa(str[k])-'a']<=num[Atoa(str[k+1])-'a'])
                {
                    tmp=str[k];
                    str[k]=str[k+1];
                    str[k+1]=tmp;
                }
                if(Atoa(str[k])==Atoa(str[k+1])&&str[k]<str[k+1])
                {
                    tmp=str[k];
                    str[k]=str[k+1];
                    str[k+1]=tmp;
                }
            }
    }
    for(m=0;m<strlen(str)-1;m++){
            for(k=0;k<Atoa(str[k+1]);k++){
                tmp=str[k];
                str[k]=str[k+1];
                str[k+1]=tmp;
                }
            }
        printf("case #%d:\n",i);
        int n=str[0];
        int len=strlen(str);
        str[len]=n;
        for(int x=1;x<len+1;x++)
        {
            str[x-1]=str[x];
        }
        str[len]='\0';
        printf("%s\n",str);
    }
        return 0;
}
