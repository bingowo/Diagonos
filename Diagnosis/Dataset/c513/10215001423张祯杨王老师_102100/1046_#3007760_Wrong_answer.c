#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s[16]= {"the","a","an","of","for","and","THE","AN","OF","FOR","AND","An","The","OF","For","A"};

int main()
{
    int con(char* a);
    int m;
    scanf("%d",&m);
    int i;
    for(int z=0; z<m; z++)
    {
        int count=0;
        char s[100];
        do
        {
            scanf("%s",s);
            if(con(s)==1) ;
            else count++;
        }
        while(getchar()!='\n');

        printf("case #%d:\n",z);

        printf("%d",count);

        printf("\n");

        count=0;
    }
    return 0;
}

int con(char* a)
{
    int i=0;
    for(i=0; i<16; i++)
    {
        if(strcmp(a,s[i])==0) return 1;
    }
    return 0;
}
