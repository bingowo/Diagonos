#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[1000]={0};
    while(scanf("%s",a)!=EOF)
    {
        char s[500][1000]={0};
        char t[100]={0};
    int i=0,k=0,j=0,m=0,h=0,l=0,p=0;k=250;
    for(i=0;a[i];)
    {   for(l=0;;l++){if(a[l+i]!=a[l+1+i])break;}
        j=0;
        if(i==0){for(p=0;p<=l;p++)s[k][p]=a[i];s[k][p]='\0';}
        else
        {
            if(a[i]>a[i-1])k=k-1;else k=k+1;
         if(a[i]>a[i-1])j=strlen(s[k+1]);else j=strlen(s[k-1]);
            if(s[k][0])
            {m=strlen(s[k]); for(m=m;m<j;m++)s[k][m]=' ';for(p=0;p<=l;p++)s[k][m+p]=a[i];s[k][m+p]='\0';}
            else
            {
                for(m=0;m<j;m++)s[k][m]=' ';for(p=0;p<=l;p++)s[k][m+p]=a[i];s[k][m+p]='\0';
            }
        }

    i=i+l+1;
    }
    for(i=0;i<500;i++){if(s[i][0])printf("%s\n",s[i]);}

    }

    return 0;
}
