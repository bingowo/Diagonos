#include <stdio.h>
#include <stdlib.h>
#define N 2200
int p[26];
int compare(const void*a,const void*b)
{
      char *s1=(char*)a;
      char *s2=(char*)b;
       char ch1,ch2;
       while(*s1&&*s2)
       {
           ch1=(*s1)>='a'?*s1-32:*s1;
           ch2=(*s2)>='a'?*s2-32:*s2;
           if(p[ch1-'A']!=p[ch2-'A'])
            return p[ch1-'A']-p[ch2-'A'];
           else {s1++;s2++;}
       }
       if(*s1==0)return -1;
       else return 1;
}

int main()
{
    int i,j,k,num,length;
    char s[27];
    while(scanf("%s\n",s)!=EOF)
    {
        for(i=0;i<26;i++)p[s[i]-'A']=i;
        char t[N],str[101][21];
        gets(t);
        num=0;length=0;
        for(j=0;t[j]!='\0';j++)
           {
               str[num][length]=t[j];
               if(t[j+1]==' ')
                {
                    str[num][length+1]='\0';
                    j++;num++;
                    length=0;
                }
                else length++;
            }
        num++;
        qsort(str,num,sizeof(str[0]),compare);
        for(k=0;k<num;k++)printf("%s%c",str[k],k==num-1?'\n':' ');
    }
    return 0;
}
