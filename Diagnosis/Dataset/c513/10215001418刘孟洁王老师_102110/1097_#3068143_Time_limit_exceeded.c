#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct
{
    char ch;int po;
}point;

int main()
{
    int i,j,k,max;
    char s[1007];
    while(scanf("%s",s)!=EOF)
    {
        char **ss;
        point *wave;
        int len=strlen(s);
        wave=(point*)malloc(len*sizeof(point));
        for(i=0;i<len;i++) wave[i].ch=s[i];
        ss=(char**)malloc(107*sizeof(char*));
        for(i=0;i<107;i++) ss[i]=(char*)malloc(len*sizeof(char));
        for(i=0;i<len;i++)
        {
            for(j=0;j<len;j++)
            {
                ss[i][j]=' ';
            }
            ss[i][len]='\0';
        }//初始化为空格

    ss[0][0]=s[0];
    wave[0].po=0;
    for(i=0;i<len-1;i++)
    {
        if(s[i+1]>s[i])
        {
            ss[wave[i].po+1][i+1]=s[i+1];
            wave[i+1].po=wave[i].po+1;
        }
        else if(s[i+1]<s[i])
        {
            if(wave[i].po>0)
            {
                ss[wave[i].po-1][i+1]=s[i+1];
                wave[i+1].po=wave[i].po-1;
            }
            else if(wave[i].po==0)
            {
                for(k=105;k>=0;k--) strcpy(ss[k+1],ss[k]);
                for(k=0;k<len;k++) ss[0][k]=' ';
                ss[0][i+1]=s[i+1];
                wave[i+1].po=0;
                for(k=0;k<=i;k++) wave[k].po++;
            }
        }
        else
        {
            ss[wave[i].po][i+1]=s[i+1];
            wave[i+1].po=wave[i].po;
        }
    }
    max=wave[0].po;
    for(i=0;i<len;i++)
        if(max<wave[i].po) max=wave[i].po;
    for(i=0;i<=max;i++)
    {
        for(j=len-1;ss[i][j]=' ';j--);
        ss[i][j+1]='\0';
    }
    for(j=max;j>=0;j--)
        printf("%s\n",ss[j]);
  }
  return 0;
}
