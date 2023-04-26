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
int cmp0(const void *a,const void *b)
{
    char a1=*(char*)a,b1=*(char *)b;
    if(a1=='0')return 1;
    if(b1=='0')return -1;
    return a1>b1?1:-1;
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
        if(strcmp(s,c)!=0){//不需要补0
            char d1[21];int cnt1=0,flag1=-1;
            char d2[21];int cnt2=0,flag2=-1;
            strcpy(d2,s);
            for(int i=strlen(s)-1;i>0;i--){
                for(int j=i-1;j>0;j--){
                    if(s[i]>s[j]){
                        flag1=1;
                        char g=s[i];
                        s[i]=s[j];
                        s[j]=g;
                        for(int d=j+1;d<strlen(s);d++)
                            deal[d-j-1]=s[d];
                        deal[strlen(s)-j-1]=0;
                        qsort(deal,strlen(s)-j-1,sizeof(char),strcmp);
                        for(int pr=0;pr<j+1;pr++){
                            d1[cnt1++]=s[pr];
                        }
                        for(int q=0;q<strlen(deal);q++){
                            d1[cnt1++]=deal[q];
                        }
                        d1[cnt1]=0;
                        break;
                    }
                }
                if(flag1)break;
            }
            for(int i=strlen(d2)-1;i>0;i--){

                if(d2[i]>d2[i-1]){
                    char g=d2[i];
                    d2[i]=d2[i-1];
                    d2[i-1]=g;
                    flag2=1;
                    char ord[21];
                    int t;
                    for(t=0;t+i<strlen(d2);t++){
                        ord[t]=d2[i+t];
                    }
                    ord[strlen(d2)-t]=0;
                    qsort(ord,strlen(d2)-t,sizeof(char),strcmp);
                    //printf("ord=%s\n",ord);
                    for(t=i;t<strlen(d2);t++){
                        d2[t]=ord[t-i];
                    }
                    //printf("d2=%s\n",d2);
                    break;
                }
            }
            if(flag1==1&&flag2==1){
                int judge=strcmp(d1,d2);
                //printf("d1=%s,d2=%s\n",d1,d2);
                //printf("judge=%d\n",judge);
                if(judge>0)printf("%s\n",d2);
                else printf("%s\n",d1);
            }
            else if(flag1==-1){
                printf("%s\n",d2);
            }
            else printf("%s\n",d1);
        }
        else{//需要补0
            qsort(s,strlen(s),sizeof(char),cmp0);
            printf("%c",s[0]);printf("0");
            for(int i=1;i<strlen(s);i++)
                printf("%c",s[i]);
            printf("\n");

        }
    }
    return 0;
}
