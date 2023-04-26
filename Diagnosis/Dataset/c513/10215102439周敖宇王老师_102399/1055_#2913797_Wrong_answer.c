#include<stdio.h>
#include<string.h>
int main()
{
    char s[100010];
    int num[130];
    int i=0,j,len,k=1,maxl=0,p=0,l=0;
    for(i=0;i<=129;i++)  num[i]=-1;
    i=0;
    scanf("%s",s);
    while(s[i]!='\0')
    {
        //printf("s[i]=%c\n",s[i]);
        //printf("%d\n",num[s[i]-'A']);
        if(num[s[i]]==-1)
        {
            num[s[i]]=i;
            l++;
        }
        else
        {
            if(l>maxl)
            {
                maxl=l;
                p=i-l;
                l=l-num[s[i]];
                num[s[i]]=i;
            }
        }
        i++;
    }
    if(l>maxl)
    {
        maxl=l;
        p=i-l;
    }
    //printf("maxl=%d,p=%d\n",maxl,p);
    for(i=p;i<=p+l-1;i++)
    {
        printf("%c",s[i]);
    }
    return 0;
}