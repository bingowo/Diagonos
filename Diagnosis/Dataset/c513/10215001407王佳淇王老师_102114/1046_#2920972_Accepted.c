#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
void hanshu(int p)
{
    char str[1100];
    char t[100][100];
    char k[6][4]={"the","a","an","of","for","and"};
    gets(str);
        int i=0,j=0,r=0,count=0,l;
        while(str[i])
        {
            j=0;
            while(str[i]!=' ' && str[i]){t[r][j]=tolower(str[i]);j++;i++;}
            t[r][j]='\0';
            if(str[i]==' ')r++,i++;
        }
        count=r+1;
        for(i=0;i<r+1;i++)
        {
            for(l=0;l<6;l++)if(strcmp(t[i],k[l])==0)count--;
        }
        printf("case #%d:\n",p);
        printf("%d\n",count);
}
int main()
{
    int N,p;
    scanf("%d",&N);
    getchar();
    for(p=0;p<N;p++)hanshu(p);
}