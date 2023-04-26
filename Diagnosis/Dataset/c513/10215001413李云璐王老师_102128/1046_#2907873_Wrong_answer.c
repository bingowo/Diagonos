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
        char s[110][30],c;
        int i=0,l=0,count=0;
        while((c=getchar())!='\n')
        {  
            if(c!=' ')
            {s[i][l]=c;l++;}
            else {i++;l=0;}
            
        }
            int k;
            for(int g=0;g<i;g++)
           { for(k=g-1;k>=0;k--)
            if(strcmp(s[g],s[k])==0) break;
            if(k=-1&&s[g]!="the"&&s[g]!="a"&&s[g]!="an"&&s[g]!="of"&&s[g]!="for"&&s[g]!="and") count++;
           }
        
        printf("case #%d:\n",h);
        printf("%d\n",count);
    }
    return 0;
}