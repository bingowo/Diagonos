#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int  strnumcmp(const void *a1,const void *b1);
    int num=0;
    int i=0;
    char ch;
    char s[100][30];
    do{
        scanf("%s",s[i]);
        ch=getchar();
        i++;
    }while(ch==' ');
    num=i;
    i=0;
    qsort(s,num,30,strnumcmp);
    for(i=0;i<num;i++)
    {
        if(i!=num-1) printf("%s ",s[i]);
        else printf("%s",s[i]);
    }
    return 0;
}


int  strnumcmp(const void *a1,const void *b1)
{
    char* a=(char*)a1;
    char* b=(char*)b1;
    int l1=strlen(a),l2=strlen(b);
    int flag1=0,flag2=0;
    int point1,point2;
    int flag=0;
    int numlen1=0,numlen2=0;
    while(1)
    {
        for(int i=0;i<l1;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            {
                flag1++;
                if(flag1==1)
                {point1=i;}
                numlen1++;
            }
        if(b[i]>='0'&&b[i]<='9') {flag2++;if(flag2==1) {point2=i;} numlen2++; }
    }
    if(flag1==0&&flag2==0) return strcmp(a,b);
    else if(flag1!=0&&flag2==0) return 1;
    else if(flag1==0&&flag2!=0) return -1;
    else if(flag1!=0&&flag2!=0)
    {
        if(numlen1>numlen2) return 1;
        if(numlen1<numlen2) return -1;
        else
        {
            int j=0;
            while(j<=numlen1)
            {
                if(a[point1]!=b[point2]) return b[point2]-a[point1];
                else j++;
            }
            return strcmp(a,b);
        }
    }

    }
}