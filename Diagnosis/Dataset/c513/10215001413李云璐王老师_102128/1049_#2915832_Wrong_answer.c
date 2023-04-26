#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


int main()
{
    int n;
    scanf("%d\n",&n);
    for(int h=0;h<n;h++)
    {
        char s[501][20],c;
        int i=0,l=0,count=0;
        while(1)
        {
            c = getchar();
            if(c!=' '&&c!='\n'&&c!=','&&c!='.'&&c!='!'&&c!='?') {s[i][l]=c;l++;}
            else {
                s[i][l] = '\0'; i++;l=0;
                if(c == '\n') break;
            }

        }//输入，共有i个单词
        char b[501][20];
        int k,m;
        for(k=0,m=0;k<i;k++)
        {
            int f;
            for(f=k-1;f>=0;f--)
            if(strcmp(s[k],s[f])==0) break;
            if(f==-1) {strcpy(b[m],s[k]);m++;}
        }
        
        printf("case #%d:\n",h);
        for(int t=0;t<m;t++)
        printf("%s ",b[t]);
        printf("\n");
     }
    return 0;
}