#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int cmp(const void *a,const void *b)
{
    char a1=*(char*)a,b1=*(char *)b;
    return a1>b1?-1:1;
}
int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        char s[21];scanf("%s",s);
        char c[21];strcpy(c,s);
        char deal[21];
        qsort(c,strlen(c),sizeof(char),cmp);
        if(strcmp(s,c)!=0){
            for(int i=strlen(s)-1;i>0;i--){
                int flag=0;
                for(int j=i-1;j>0;j--){
                    if(s[i]>s[j]){
                        flag=1;
                        char g=s[i];
                        s[i]=s[j];
                        s[j]=g;
                        for(int d=j+1;d<strlen(s);d++)
                            deal[d-j-1]=s[d];
                        deal[strlen(s)-j-1]=0;
                        qsort(deal,strlen(s)-j-1,sizeof(char),strcmp);
                        for(int pr=0;pr<j+1;pr++){
                            printf("%c",s[pr]);
                        }
                        printf("%s\n",deal);
                        break;
                    }
                }
                if(flag)break;
            }
        }
        else{
            qsort(s,strlen(s),sizeof(char),strcmp);
            printf("%c",s[0]);printf("0");
            for(int i=0;i<strlen(s);i++)
                printf("%c",s[i]);
            printf("\n");
        }
    }
    return 0;
}
