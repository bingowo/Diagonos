#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* s)
{
    int i,j,l;
    char c;
    l=strlen(s);
    for(i=0,j=l-1;i<j;i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}

int main()
{
    int N,R,zR,i,zN;
    scanf("%d %d",&N,&R);
    zR=(-1)*R;
    zN=(-1)*N;
    char s[1000];
    int shang,yu;
    if(N==0)
    {
        printf("0");
        return 0;
    }
    if(zR<10)  //判断转化进制没有字母
    {
        if(N<0)
        {
            shang=zN;
            yu=0;
            for(i=0;shang>0;i++)
            {
                if(i%2==0||i==0)  //余数是负的
                {
                    yu=zR-shang%zR;
                    s[i]=yu;
                    shang=shang/zR+1;
                }
                else
                {
                    yu=shang%zR;
                    s[i]=yu;
                    shang=shang/zR;
                }
            }
            s[i]='\0';
            reverse(s);
        }
        else
        {
            shang=N;
            for(i=0;shang>0;i++)
            {
                yu=shang%zR;
                s[i]=yu+'0';
                if(i%2!=0&&i!=0)
                    shang=(shang+yu)/zR;
                else
                    shang=(shang-yu)/zR;
            }
            s[i]='\0';
            reverse(s);
        }
    }
    else
    {
        if(N<0)
        {
            int zN;
            zN=(-1)*N;
            shang=zN;
            yu=0;
            for(i=0;shang>0;i++)
            {
                yu=shang%zR;
                if(yu<10)
                    s[i]=yu+'0';
                else
                    s[i]=yu+55;
                shang=shang/zR;
                if(i%2==0||i==0)
                    shang=shang+yu;
            }
            s[i]='\0';
            reverse(s);
        }
        else
        {
            shang=N;
            for(i=0;shang>0;i++)
            {
                yu=shang%zR;
                if(yu<10)
                    s[i]=yu+'0';
                else
                    s[i]=yu+55;
                shang=shang/zR;
                if(i%2!=0&&i!=0)
                    shang=shang+yu;
            }
            s[i]='\0';
                        reverse(s);
        }
    }
    for(i=0;s[i];i++)
        printf("%c",s[i]);
}
