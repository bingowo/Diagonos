#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char word[20] ;
}words;


int isalpha(char t)
{
    if(t < 'a' || t > 'z')
        return 0 ;
    return 1 ;
}

int cmp(const void* _a , const void* _b)
{
    words *a = (words*)_a , *b = (words*)_b ;
    return(strcmp((*a).word,(*b).word)) ;
}

int main()
{
    int t ;
    scanf("%d",&t) ;
    getchar() ;
    for(int i=0; i<t; i++){
        words words[250] ;
        for(int j=0; j<250;j++){
            for(int k=0; k<20; k++)
                words[j].word[k] = '\0' ;
        }
        char tmp ;
        int count = 0 ,idx = 0 ;
        while(tmp != '\n' || count == 0){
            tmp = getchar() ;
            if(isalpha(tmp))
                words[count].word[idx++] = tmp ;
            else{
                if(idx == 0)
                    continue ;
                else{
                    count++ ;
                    idx = 0 ;
                }
            }
        }
        qsort(words,count,sizeof(words[0]),cmp) ;
        for(int m=0; m<count-1; m++){
            for(int n=m+1; n<count; n++)
                if(strcmp(words[m].word,words[n].word) == 0)
                    words[m].word[0] = '0' ;
        }

        printf("case #%d:\n",i) ;
        for(int m=0; m<count; m++)
            if(words[m].word[0] != '0'){
                printf("%s",words[m].word) ;
                if(m!=count-1)
                    printf(" ") ;
            }
        printf("\n") ;
    }
}