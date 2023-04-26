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
        for(int k=0;k<i;k++)
        printf("%s ",s[k]);
       
        
    }
    return 0;
}