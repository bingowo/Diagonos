#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
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

        }
        char a[501][20];
        int k,e;
        for(k=1,e=0;k<i;k++)
        {
            int m;
            for(m=k-1;m>=0;m--)
            if(strcmp(s[k],s[m])==0) break;
            if(m=-1)
            {
                strcpy(a[e],s[k]);
                e++;
            }
         }
         qsort(a,e,sizeof(char*),strcmp);
         printf("case #%d:\n",h);
         for(int r=0;r<e;r++)
         printf("%s ",a[r]);
        
    }
    return 0;
}