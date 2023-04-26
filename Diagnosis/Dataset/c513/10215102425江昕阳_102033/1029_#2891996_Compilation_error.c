#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{char n=*(char*)a;
char m=*(char*)b;
if(n>m)return 1;
else return -1;
}

int main()
{
    char s[100],c,s1[100];
    int T,j=0,k=0,q;
    scanf("%d",&T);
    getchar();
    for (int i=0; i<T; i++)
    {c='\0';
        j=0;
        k=0;
        while(c!='\n')
        {scanf("%c",&c);
            if(c<='Z'&&c>='A')
            {
                s[j]='*';
                s1[k]=c;
                k++;
            }
            else
            {
                s[j]=c;
            };

            j++;
        };
        s[j]='\0';
        qsort(s1,k,sizeof(char),cmp);
        q=0;
        for(k=0;k<j-1;k++){
            if(s[k]=='*'){s[k]=s1[q];q++;};
        };
        printf("case #%d:\n%",i);
printf("%s\n",s)
    }

    return 0;
}
