#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{int n,length,words_len,words_count;
int l,p,space,j,i;
int start;
scanf("%d",&n);
for(int M=0;M<n;M++)
{printf("case #%d:\n",M);
int t;
char s[2001];
scanf("%d",&t);
getchar();
gets(s);
length=strlen(s);
for(i=0;s[i]==' ';i++);
while(i<length)
{start=i;
words_len=0;words_count=0;
while(words_len+words_count<=t&&i<length)
{for(l=0,p=i;s[p]!=' '&&p<length;l++,p++);
if(words_count+words_len+l<=t)
{words_len+=l;
words_count++;
for(i=p;s[i]==' '&&i<length;i++);
}
else break;
}
space=t-words_len;
j=start;
words_count--;
while(j<i)
{while(s[j]!=' '&&j<length) putchar(s[j++]);
while(s[j]==' '&&j<length) j++;
if(i==length&&words_count) putchar(' ');
else{for(p=0;words_count&&p<space/words_count;p++)
    putchar(' ');
    space-=p;

    }
    words_count--;
}putchar('\n');

}
}
}
