#include<stdio.h>
#include<string.h>
typedef struct
{
   int m;//十六进制开始的位置
   int l;//十六进制的长度
} sl;

int main()
{
    unsigned int i=0,j=0,k=0,t=0,n=1,sum=0,m=0,l=0;
    char s[10001]={0},s1[10001]={0};
    sl a[100]={0};
    scanf("%s",s);
    for(i=0;i<strlen(s)-1;i++)//找出所有0x并记录
    {
        if(s[i]==0&&s[i+1]=='x')
        {
            a[j].m=i+2;
            j++;
            if(j!=0) a[j-1].l=a[j].m-a[j-1].m;
         }
    }
    l=j-1;//l为a数组的长度
    if(l==0) printf("-1");
    else
    {
        for(j=0;j<l;j++)
       {
            sum=0;
            n=1;
            memset(s1,0,sizeof(s1[0]));
            for(k=0,t=a[j].m;t<a[j+1].m;t++)
               {s1[k]=s[t];}
            for(k=0;k<strlen(s1);k++)
            {
                if(s1[k]>='0'&&s1[k]<='9')
                    s1[k]=s1[k]-'0';
                else if(s1[k]>='A'&&s1[k]<="F")
                    s1[k]=s1[k]-'A'+10;
                else if(s1[k]>='a'&&s1[k]<='f')
                    s1[k]=s1[k]-'a'+10;
            }
            for(t=strlen(s1)-1;t>=0;t++)
            {
                sum+=n*s1[t];
                n*=16;
            }
           printf("%d ",sum);

       }
    }


}
