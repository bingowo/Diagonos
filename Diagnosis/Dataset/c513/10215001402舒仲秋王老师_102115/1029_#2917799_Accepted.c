#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*int cmp(const void* a,const void* b)
{
    char d1,d2;
    int t=-1;
    d1=*((char*)a),d2=*((char*)b);
    if(d1>='A'&&d1<='Z'&&d2>='A'&&d2<='Z')
        t=d1-d2;
    return t;
}*/

int main()
{
    int N,i;
    scanf("%d\n",&N);
    for(i=0;i<N;i++)
    {
        char str[500];
        gets(str);
        int l,j,q;
        l=strlen(str);
        for(j=0;j<l;j++)
        {
            if(str[j]==' '||str[j]<'A'||str[j]>'Z') continue;
            for(q=j;q<l;q++)
            {
                if(str[q]==' '||str[q]<'A'||str[q]>'Z') continue;
                char c=str[j];
                if(str[q]<str[j])
                {
                    str[j]=str[q];
                    str[q]=c;
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%s\n",str);
    }
    return 0;
}
