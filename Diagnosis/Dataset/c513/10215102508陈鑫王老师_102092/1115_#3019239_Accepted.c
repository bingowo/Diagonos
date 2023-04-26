#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*a,const void*b)
{

    return *(char*)a-*(char*)b;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=0;k<t;k++)
    {
        char minc,c,s[22];
        s[0]='0';
        scanf("%s",s+1);
        int index,i,j,len=strlen(s);
        for(i=len-1;s[i]<=s[i-1];i--);
        c=s[i-1];
        minc=s[i];
        index=i;
        for(j=len-1;j>=i;j--)
        {
            if(s[j]<minc&&s[j]>s[i-1])
            {
                minc=s[j];
                index=j;
            }
        }
        s[i-1]=minc;
        s[index]=c;
        qsort(s+i,len-i,sizeof(s[0]),cmp);
        printf("case #%d:\n",k);
        if(s[0]!='0')
            printf("%s\n",s);
        else
            printf("%s\n",s+1);


    }
    return 0;
}
