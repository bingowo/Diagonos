#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char c;
    int number;
}AAA;

int cmp1(const void* p3,const void* p4)
{
    char* p1=(char* )p3;
    char* p2=(char* )p4;
    if((*(p1))>(*(p2))) return 1;
    else return -1;
}

int cmp2(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    if((*(p1))>(*(p2))) return 1;
    else return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[21];
        scanf("%s",s);
        int len=strlen(s);
        qsort(s,len,sizeof(char),cmp1);
        AAA* p=(AAA* )malloc(20*sizeof(AAA));
        int num=0,geshu=0;
        char al=' ';
        for(int i=0;i<len;i++){
            if(s[i]!=al){
                if(al==' '){
                    (p+num)->c=s[i];
                    al=s[i];
                    geshu++;
                }
                else{
                    (p+num)->number=geshu;
                    num++;
                    geshu=1;
                    (p+num)->c=s[i];
                    al=s[i];
                }
            }
            else geshu++;
            if(i==len-1){
                (p+num)->number=geshu;
                num++;
            }
        }
        int* ans=(int* )malloc(20*sizeof(int));
        int ann=0,angeshu=0;
        for(int j=0;j<num;j++){
            if((p+j)->c=='Z'){
                angeshu=(p+j)->number;
                (p+j)->number=0;
                int anshu=0;
                for(int jj=0;jj<angeshu;jj++){
                    *(ans+ann)=anshu;
                    ann++;
                }
                for(int kk=0;kk<num;kk++){
                    if((p+kk)->c=='E') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='R') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='O') (p+kk)->number=(p+kk)->number-angeshu;
                }
            }
            else if((p+j)->c=='U'){
                angeshu=(p+j)->number;
                (p+j)->number=0;
                int anshu=4;
                for(int jj=0;jj<angeshu;jj++){
                    *(ans+ann)=anshu;
                    ann++;
                }
                for(int kk=0;kk<num;kk++){
                    if((p+kk)->c=='F') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='R') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='O') (p+kk)->number=(p+kk)->number-angeshu;
                }
            }
            else if((p+j)->c=='X'){
                angeshu=(p+j)->number;
                (p+j)->number=0;
                int anshu=6;
                for(int jj=0;jj<angeshu;jj++){
                    *(ans+ann)=anshu;
                    ann++;
                }
                for(int kk=0;kk<num;kk++){
                    if((p+kk)->c=='S') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='I') (p+kk)->number=(p+kk)->number-angeshu;
                }
            }
            else if((p+j)->c=='G'){
                angeshu=(p+j)->number;
                (p+j)->number=0;
                int anshu=8;
                for(int jj=0;jj<angeshu;jj++){
                    *(ans+ann)=anshu;
                    ann++;
                }
                for(int kk=0;kk<num;kk++){
                    if((p+kk)->c=='E') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='I') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='H') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='T') (p+kk)->number=(p+kk)->number-angeshu;
                }
            }
        }
        for(int j=0;j<num;j++){
            if((p+j)->c=='W'){
                angeshu=(p+j)->number;
                (p+j)->number=0;
                int anshu=2;
                for(int jj=0;jj<angeshu;jj++){
                    *(ans+ann)=anshu;
                    ann++;
                }
                for(int kk=0;kk<num;kk++){
                    if((p+kk)->c=='T') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='O') (p+kk)->number=(p+kk)->number-angeshu;
                }
            }
            else if((p+j)->c=='H'){
                angeshu=(p+j)->number;
                (p+j)->number=0;
                int anshu=3;
                for(int jj=0;jj<angeshu;jj++){
                    *(ans+ann)=anshu;
                    ann++;
                }
                for(int kk=0;kk<num;kk++){
                    if((p+kk)->c=='T') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='R') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='E') (p+kk)->number=(p+kk)->number-angeshu*2;
                }
            }
            else if((p+j)->c=='F'){
                angeshu=(p+j)->number;
                (p+j)->number=0;
                int anshu=5;
                for(int jj=0;jj<angeshu;jj++){
                    *(ans+ann)=anshu;
                    ann++;
                }
                for(int kk=0;kk<num;kk++){
                    if((p+kk)->c=='I') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='V') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='E') (p+kk)->number=(p+kk)->number-angeshu;
                }
            }
            else if((p+j)->c=='S'){
                angeshu=(p+j)->number;
                (p+j)->number=0;
                int anshu=7;
                for(int jj=0;jj<angeshu;jj++){
                    *(ans+ann)=anshu;
                    ann++;
                }
                for(int kk=0;kk<num;kk++){
                    if((p+kk)->c=='E') (p+kk)->number=(p+kk)->number-angeshu*2;
                    else if((p+kk)->c=='V') (p+kk)->number=(p+kk)->number-angeshu;
                    else if((p+kk)->c=='N') (p+kk)->number=(p+kk)->number-angeshu;
                }
            }
        }
        for(int j=0;j<num;j++){
            if((p+j)->c=='O'){
                angeshu=(p+j)->number;
                int anshu=1;
                for(int jj=0;jj<angeshu;jj++){
                    *(ans+ann)=anshu;
                    ann++;
                }
            }
            else if((p+j)->c=='I'){
                angeshu=(p+j)->number;
                int anshu=9;
                for(int jj=0;jj<angeshu;jj++){
                    *(ans+ann)=anshu;
                    ann++;
                }
            }
        }
        qsort(ans,ann,sizeof(int),cmp2);
        printf("case #%d:\n",t);
        for(int e=0;e<ann;e++) printf("%d",*(ans+e));
        printf("\n");
        free(p);
        free(ans);
    }
    return 0;
}

