#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
char tab[27];
int cmp(const void*a,const void*b)
{
    char* pa=(char*)a,*pb=(char*)b;
    while(*(pa++)==*(pb++));
    pa--;pb--;
    return strchr(tab,*pa>='a'?*pa-32:*pa)>strchr(tab,*pb>='a'?*pb-32:*pb)?1:-1;
}
int main() {
    while(scanf("%s\n",tab)!=-1)
    {
        char s[100][21],c;
        int i=0,j=0;
        while((c=getchar())!='\n')if(c==' '){s[i][j]=0;i++;j=0;}else s[i][j++]=c;
        s[i++][j]=0;
        qsort(s,i,sizeof(s[0]),cmp);
        for(j=0;j<i;j++)printf("%s%c",s[j],j==i-1?'\n':' ');
    }
    return 0;
}
