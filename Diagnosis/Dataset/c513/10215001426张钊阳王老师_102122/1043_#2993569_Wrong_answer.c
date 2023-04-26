#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int max=0;
        char s1[101];
        scanf("%s",s1);
        char s[102];
        memset(s,'\0',102);
        int l=strlen(s1);
        for(int z=0;z<l;z++)
        {
            int sum=0;
            int k,p;
            for(k=0,p=0;k<=z;k++,p++)
            {
                s[p]=s1[k];
            }
            s[p]=s1[z];
            p++;
            for(;k<l;k++,p++)
            {
                s[p]=s1[k];
            }
            minus(s,l+1);
            int l2=strlen(s);
            sum=l+1-l2;
            if(sum>max) max=sum;
        }
        printf("case #%d:\n",z);
        printf("%d",max);
        printf("\n");
    }
    return 0;
}

void minus(char *s1,int l)
{
    char s[102];
    memset(s,'\0',102);
    if(s1[0]=='\0') return;
    int flag=0;
    int i;
    for(i=0;i<l-1;i++)
    {
        while(s1[i]==s1[i+1])
        {
            s1[i]='0';
            i++;
            flag++;
            s1[i]='0';
        }
    }
    if(flag!=0)
    {
         for(int z=0,p=0;z<l;)
        {
            if(s1[z]!='0') {s[p]=s1[z];z++;p++;}
            else z++;
        }
    }
    else strcpy(s,s1);
    if(flag!=0)
       {
            memset(s1,'\0',101);
            strcpy(s1,s);
       }
    if(flag==0) return ;
    else if(flag!=0) minus(s1,l-flag-1);
}



