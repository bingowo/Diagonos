#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short table[128]={0};

int randomcmp(const void *a,const void *b)
{
    short lena=0,lenb=0,i=0;
    lena=strlen(*(char**)a);
    lenb=strlen(*(char**)b);
    for(i=0;i<lena&&i<lenb;i++)
        if(table[toupper(*(*(char**)a+i))]!=table[toupper(*(*(char**)b+i))]) return table[toupper(*(*(char**)a+i))]-table[toupper(*(*(char**)b+i))];
    return lena-lenb;
}

int main()
{
    char *sequence;
    char in[3000];
    sequence=(char*)malloc(100*sizeof(char));
    while(fgets(sequence,100,stdin)!=NULL)
        {
            short i=0,n=0;
            char **string;
            string=(char**)malloc(101*sizeof(char*));
            for(i=0;i<26;i++)
                table[sequence[i]]=i+1;
            fgets(in,3000,stdin);
            short len=strlen(in),cut=0;
            for(i=0;len>0;i++)
            {
                *(string+i)=(char*)malloc(100*sizeof(char));
                sscanf(in+cut,"%s",*(string+i));
                len-=strlen(*(string+i))+1;
                cut+=strlen(*(string+i))+1;
            }
            n=i;
            qsort(string,n,sizeof(char*),randomcmp);
            for(i=0;i<n;i++)
                printf("%s ",*(string+i));
            printf("\n");
        }
    return 0;
}
