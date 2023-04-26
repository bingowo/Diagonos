#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000100];
    int num[130];
    int i=0,j,len,k=1,maxl=0,p=0,l=0,maxp=0;
    for(i=0;i<=129;i++)  num[i]=-1;
    i=0;
    scanf("%s",s);
    while(s[i]!='\0')
    {
        //printf("s[i]=%c\n",s[i]);
        //printf("%d\n",num[s[i]]);
        if(num[s[i]]==-1)
        {
            num[s[i]]=i;
            l++;
        }
        else
        {
            //printf("l=%d ",l);
            p=i-l;
            if(l>maxl)
            {
                maxl=l;
                maxp=p;
            }
            l=l-num[s[i]]+p;
            for(j=p;j<=num[s[i]];j++)  num[s[j]]=-1;
            num[s[i]]=i; 
            //printf("maxl=%d,p=%d\n",maxl,p);
        }
        i++;
    }
    if(l>maxl)
    {
        maxl=l;
        p=i-l;
    }
    //printf("maxl=%d,p=%d\n",maxl,p);
    for(i=maxp;i<=maxp+maxl-1;i++)
    {
        printf("%c",s[i]);
    }
    return 0;
}