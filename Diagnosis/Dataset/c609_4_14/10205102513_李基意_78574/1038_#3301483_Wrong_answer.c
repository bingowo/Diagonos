#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void* a,const void* b)
{
    return(strcmp((char*)a,(char*)b));
}
void solve()
{
    char text[511];char word[511][100];
    gets(text);
    int i=0,j=0,k=0;int flag=0;
    for (i=0;i<=strlen(text);i++)
    {
        if (text[i]>='a'&&text[i]<='z')
        {
            word[k][j]=text[i];
            j++;
            flag=1;
        }
        else {
            if(flag==1)
            {
                k=k+1;j=0; 
                flag=0;
            }
        }
    }
    qsort(word,k,sizeof(word[0]),cmp);
    printf("%s ",word[0]);
    i=1;
    for(i=1;i<k;i++){
        if(strcmp(word[i],word[i-1])!=0)
            printf("%s ",word[i]); 
    }
    printf("\n");
    i=0;j=0;k=0;
    memset(text,0,sizeof(text));
    memset(word,0,sizeof(word));
}

int main()
{
    int i,t;
    scanf("%d",&t);getchar();
    for (i=0;i<t;i++) {printf("case #%d:\n",i); solve(); }
    return 0;
}