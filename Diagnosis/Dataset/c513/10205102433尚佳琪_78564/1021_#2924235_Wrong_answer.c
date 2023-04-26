#include <stdio.h>
#include <stdlib.h>
int p[128]={0};
int cmp(const void *a,const void *b)
{
    char *s1,*s2;char ch1,ch2;
    s1=(char *)a;s2=(char *)b;
    while(*s1&&*s2)
    {
        ch1=(*s1)>='a'?*s1-32:*s1;    //转换为大写字母
        ch2=(*s2)>='a'?*s2-32:*s2;     //转换为大写字母
        if(p[ch1-'A']!=p[ch2-'A'])     //按字母顺序表比较字母
                return p[ch1-'A']-p[ch2-'A'];
        else {s1++;s2++;}
    }
    if(*s1==0) return -1;
    else return 1;
}
int main()
{
    char s[27];
    while(scanf("%s\n",s)!=EOF)
    {
        for(int i=0;i<26;i++)
        {
            p[s[i]]=i;
            p[s[i]+'a'-'A']=i;
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
        char a[100][21];
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
        for(int i=0;i<count;i++)
            printf("%s ",a[i]);
        printf("\n");
        for(int i=0;i<26;i++)
        {
            p[i]=0;
        }
    }
    return 0;
}
