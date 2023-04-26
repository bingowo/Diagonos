#include<stdio.h>
#include<string.h>
#define N 1000
int t=0;//t为消除字母的个数

//消除函数
void de(char a[N],int c)
{
    int i=0,j=0,k=0;
    char b[N]={0};
    for(i=0;i<c;i++)
    {
        if(a[i]!=a[i+1]) break;
        else
        {
           j=i+1;
           while(a[j]==a[i]&&j<c)  j++;
           j--;//从i到j是重复的
           for(k=i;k<=j;k++)
           a[k]=0;
           for(k=j+1;k<c;k++,i++)
           a[i]=a[j+1];
           t+=j-i+1;
        }

    }
}

int max(int a,int b)
{
    if(a>=b) return a;
    else return b;
}

int main()
{
    int i=0,j=0,k=0,T;
    char s[N];
    scanf("%d",&T);
    for(k=0;k<T;k++)
    {
        int c=0,p=0,d1=0,d2=0,h1=0,h2=0,h3=0,l=0;//c为字符串s的长度，p为插入字符串的位置
        char a[N]={0},b[N]={0},e[N]={0};
        scanf("%s",a);
        c=strlen(a);

        //p在0到c中间
            for(p=1;p<=c;p++)
            {
                  strncpy(b,a,p);
                  b[p]='A';
                  for(i=p+1,j=p;i<=c;i++,j++)
                    b[i]=a[j];
                  de(b,c+1);
                  h1=t;
                  t=0;
                  memset(b,0,c+1);

                  strncpy(b,a,p);
                  b[p]='B';
                  for(i=p+1,j=p;i<=c;i++,j++)
                    b[i]=a[j];
                  de(b,c+1);
                  h2=t;
                  t=0;
                  memset(b,0,c+1);

                  strncpy(b,a,p);
                  b[p]='C';
                  for(i=p+1,j=p;i<=c;i++,j++)
                    b[i]=a[j];
                  de(b,c+1);
                  h3=t;

            }
        //(p==0)
            for(i=0;i<c;i++)
                e[i]=a[i];
            for(i=1;i<=c;i++)
                a[i]=a[i-1];
            de(a,c+1);
            d1=t;//d为被消除掉的字符总数
        //(p==c)

            a[c]=e[c-1];
            de(a,c+1);
            d2=t;

        //比较5个值的大小
        l=max(h1,h2);
        l=max(l,h3);
        l=max(l,d1);
        l=max(l,d2);

        //输出
        printf("case #%d:\n",k);
        printf("%d\n",l);
    }
return 0;
}
