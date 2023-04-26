#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmp1(const void* p3,const void* p4)
{
    char* p1=(char* )p3;
    char* p2=(char* )p4;
    if((*p1)>(*p2)) return 1;
    else return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    char s0[17],s1[17];
    for(int t=0;t<T;t++){
        scanf("%s",s0);
        int len0=strlen(s0),len1=1;
        qsort(s0,len0,sizeof(char),cmp1);
        char c=s0[0];
        s1[0]=c;
        s1[1]=0;
        for(int i=1;i<len0;i++){
            if(s0[i]!=c){
                s1[len1]=s0[i];
                len1++;
            }
            c=s0[i];
        }
        s1[len1]=0;
        printf("case #%d:\n",t);
        int* p=(int *)malloc(len1*sizeof(int));
        int num=0;
        *(p+num)=0;
        num++;
        while(*(p)<len1){
            for(int x=0;x<num;x++) printf("%c",s1[*(p+x)]);
            printf("\n");
            if(*(p+num-1)<len1-1) {
                *(p+num)=(*(p+num-1))+1;
                num++;
            }
            else if(*(p)==len1-1) break;
            else{
                (*(p+num-2))+=1;
                num--;
            }
        }
        free(p);
    }
    return 0;
}
