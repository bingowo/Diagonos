#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int M=0;
        scanf("%d",&M);
        char s[2000][36]={0},ch;
        int j=0;
        do
        {
            scanf("%s",s[j]);
            j++;
        }while((ch=getchar())!='\n');
        printf("case #%d:\n",i);
        int n=0,l=0;//判断每行放几个单词，l为计算每行单词配上间隔为一个空格的总长度
        for(int i=0;i<j;i++)
        {
            int t=0;
            if(n) t=1;
            if(l+strlen(s[i])+t<=M) l+=strlen(s[i])+t,n++;//第一个单词不带空格，从第二个开始带一个
            else
            {
                int t=M-l+(n-1);//纯空格的个数
                if(t%(n-1)==0)//如果能均分的话
                {
                    for(int m=i-n;m<i;m++)
                    {
                        printf("%s",s[m]);
                        if(m+1!=i)
                        {
                            for(int i=0;i<t/(n-1);i++)
                                printf(" ");
                        }
                        else printf("\n");
                    }
                }
                else//不能均分
                {
                    for(int m=i-n,j=0;m<i;m++,j++)//j代表用的空格数
                    {
                        printf("%s",s[m]);
                        if(m+1!=i)
                        {
                            for(int i=0;i<t/(n-1-j);i++)
                                printf(" ");
                            t-=t/(n-1-j);
                        }
                        else printf("\n");
                    }
                }
                n=1,l=strlen(s[i]);//记录下来新的个数与长度
            }
            if(i==j-1)
            {
                for(int m=i-n+1;m<j;m++)
                {
                    printf("%s",s[m]);
                    if(m+1!=j) printf(" ");
                    else printf("\n");
                }
            }
        }
    }
    return 0;
}
