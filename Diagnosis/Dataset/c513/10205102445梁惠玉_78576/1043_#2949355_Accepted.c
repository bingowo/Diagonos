#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strdel(char* s,int i,int j)//从串s位置i开始，删除j个字符
{
    int m=strlen(s);
    if(i+j>=m)
    {
        s[i]='\0';

    }
    else{
        for(int k=0;k<=m-i-j;k++)
        {
            s[i+k]=s[i+j+k];
        }
    }
    return;
}

void strins(char* s,int i,char ch)//把字符加在串s的位置i
{
    int m=strlen(s);
    for(int k=m;k>=i;k--)
    {
        s[k+1]=s[k];
        //printf("%d\n",k);
    }
    s[i]=ch;
    return;
}

int delrep(char* s)
{
    int len=strlen(s);
    int num=0;
    int eranum=0;
    for(int k=0;k<len-1;)
    {
        int sublen=1;
        for(int j=k+1;j<len;j++)
        {
            if(s[j]==s[k])
            {
                sublen++;
            }
            else{
                break;
            }
        }
        if(sublen>1)
        {
            strdel(s,k,sublen);
            num+=sublen;
            eranum++;
            len=strlen(s);
        }
        else{
            k++;
        }
    }
    if(eranum==0)
    {
        return 0;
    }
    return num+delrep(s);

}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[105];
        scanf("%s",s);
        int result=0;
        for(int j=0;j<strlen(s);j++)
        {
            char s1[105];
            strcpy(s1,s);
            strins(s1,j,'A');
            int temp=delrep(s1);
            if(temp>result)
            {
                result=temp;
            }
        }
        for(int j=0;j<strlen(s);j++)
        {
            char s1[105];
            strcpy(s1,s);
            strins(s1,j,'B');
            int temp=delrep(s1);
            if(temp>result)
            {
                result=temp;
            }
        }
        for(int j=0;j<strlen(s);j++)
        {
            char s1[105];
            strcpy(s1,s);
            strins(s1,j,'C');
            int temp=delrep(s1);
            if(temp>result)
            {
                result=temp;
            }
        }
        printf("%d\n",result);

    }

}

/*int main()
{
    char s[11];
    scanf("%s",s);
    printf("%s ",s);
    strins(s,1,'A');
    printf("%s ",s);
    strdel(s,2,2);
    printf("%s\n",s);
    return 0;
}
*/
