#include <stdio.h>
#include <stdlib.h>
#define N 2200
int p[26];
int compare(const void*a,const void*b)
{
      char *s1=(char*)a;
      char *s2=(char*)b;//将a，b转换为指针
       char ch1,ch2;
       while(*s1&&*s2)
       {
           ch1=(*s1)>='a'?*s1-32:*s1;
           ch2=(*s2)>='a'?*s2-32:*s2;
           if(p[ch1-'A']!=p[ch2-'A'])
            return p[ch1-'A']-p[ch2-'A'];
           else {s1++;s2++;}
       }
       if(*s1==0)return 0;
       else return 1;
}

int main()
{
    int i,j,k,num,length,l;
    char s[27];
    while(scanf("%s",s)!=EOF)
    {
        for(i=0;i<26;i++)p[s[i]-'A']=i;
        char t[N],str[101][21];
        for(i=0;i<101;i++)
        	for(int j=0;j<21;j++)
        		str[i][j]='\0';//要么清零
        gets(t);
        num=0;
        length=0;
        for(j=0;t[j]!='\0';j++)
           {
               str[num][length]=t[j];
               if(t[j+1]==' '||'\0')
                {
                    str[num][length+1]='\0';
                    j++;num++;
                    length=0;
                }//要么这里分空格和结束符两种情况讨论，如果是结束符，就要break
                else length++;
            }
            num++;
        qsort(str,num,sizeof(str[0]),compare);
        for(k=0;k<num;k++)printf("%s%c",str[k],k==num-1?'\n':' ');
    }
    return 0;
}
