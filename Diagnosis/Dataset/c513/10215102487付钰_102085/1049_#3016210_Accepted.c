#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char word[20];
    int changdu;
}danci;

int cmp(const void *a,const void *b)
{
    danci *p1=(danci*)a;
    danci *p2=(danci*)b;
    return strcmp(p1->word,p2->word);
}
int main()
{
    int t,k,k1,k2;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        char s[500]={0};
        danci a[200];
        for(k1=0;k1<200;k1++){
            for(k2=0;k2<20;k2++){
                a[k1].word[k2]=0;
            }
        }
        gets(s);
        int len=strlen(s);
        int x=0,y=0,j;
        for(j=0;j<len;j++){
            if(s[j]==' '||s[j]==','||s[j]=='.'||s[j]=='!'||s[j]=='?'){
               if(s[j-1]!=' '&&s[j-1]!=','&&s[j-1]!='.'&&s[j-1]!='!'&&s[j-1]!='?'){
                a[y].changdu=x;
                y++;}
                x=0;
                continue;
            }
            else{
                a[y].word[x]=s[j];
                x++;
            }
        }

        qsort(a,y,sizeof(a[0]),cmp);

       /*for(j=0;j<y;j++){
            for(k=0;k<a[j].changdu;k++)
            printf("%c",a[j].word[k]);
            printf(" ");
        }
        printf("\n");
*/

        char b[y];
        for(k=0;k<a[0].changdu;k++)
            printf("%c",a[0].word[k]);
        printf(" ");

        strcpy(b,a[0].word);
        //b[a[0].changdu]='\0';
        //printf("\n%s\n",b);
        for(j=1;j<y;j++){
            if(strcmp(b,a[j].word)==0){
                //printf("chong\n");
                continue;
            }
            else{
                strcpy(b,a[j].word);
                for(k=0;k<a[j].changdu;k++)
                printf("%c",a[j].word[k]);
                printf(" ");
            }

        }
        printf("\n");
    }
}
