#include <stdio.h>
#include <stdlib.h>
int p[128]={0};
int cmp(const void *a,const void *b)
{
    char* s1;
    char* s2;
    a=(char *)a;
    b=(char *)b;
    s1=a;s2=b;
    int i=0;
    while(*(s1+i)!='\0'&&*(s2+i)!='\0')
    {
        if(p[s1[i]]!=p[s2[i]])
            return p[s1[i]]-p[s2[i]];
        else i++;
    }
    if(*(s1+i)=='\0')
        return -1;
    else
        return 1;
}
int main()
{
    char s[27];
    while(scanf("%s\n",s)!=EOF)
    {
        for(int i=0;i<26;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                p[s[i]]=i;
                p[s[i]-'a'+'A']=i;
            }
            else{
                p[s[i]]=i;
                p[s[i]+'a'-'A']=i;
            }
        }
        /*char a[100][100],c;
        int cnt=0,k=0;
        c=getchar();
        while(1)
        {
            c=getchar();
            if(c=='\n')
                break;
            else if((c<='z'&&c>='a')||(c<='Z'&&c>='A'))
            {
                a[cnt][k++]=c;
            }
            else if(c==' ')
            {
                cnt++;
                k=0;
            }
        }

        cnt++;*/
        char a[105][21];
        int count=0,k=0,status=0;
        char c;
        do
        {
            c=getchar( );
            if(c!=' '&&c!='\n') {a[count][k++]=c;status=1;}
            else if(status)
                {a[count][k]='\0';count=count+1;k=0;status=0;}
        }while(c!='\n');//每个字符单独处理
         qsort(a,count,sizeof(a[0]),cmp);
       // qsort(a,cnt,sizeof(a[0]),cmp);
      //  for(int j=0;j<cnt;j++)
        for(int i=0;i<count-1;i++)
            printf("%s ",a[i]);
        printf("%s\n",a[count-1]);
        for(int i=0;i<26;i++)
        {
            p[i]=0;
        }
    }
    return 0;
}
