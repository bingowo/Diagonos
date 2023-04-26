#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int cmp(const void *a,const void *b)
{
    char x=*(char *)a,y=*(char *)b;
    return x>y?1:-1;
}

int cmp1(const void *a,const void *b)
{
    char x[4],y[4];
    strcpy(x,(char *)a);strcpy(y,(char *)b);
    return strcmp(x,y);
}
int main()
{
    char f[3][15];int p=-1;char jud[4][3],m=0;
    char ge[2][10],k=0;
    int fab=0,fo=0;
    for(int i=0;i<3;i++){
        scanf("%s",f[i]);
        if(!isalpha(f[i][0]))p=i;
    }
    //推测孩子
    if(p==2){
        for(int i=0;i<2;i++){
            if(strlen(f[i])==2)
                ge[k][0]='A',ge[k][1]='B',ge[k++][2]=0;
            else
                ge[k][0]=f[i][0],ge[k][1]='O',ge[k++][2]=0;
            //printf("%s\n",ge[k-1]);
        }
        if(!(fo&&fab)){
        int len1=strlen(ge[0]),len2=strlen(ge[1]);
        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                char c=0;
                if(ge[0][i]==ge[1][j]){
                    jud[m][c++]=ge[0][i];
                    jud[m][c++]=0;
                    m++;
                }
                else{
                    if(ge[0][i]!='O')jud[m][c++]=ge[0][i];
                    if(ge[1][j]!='O')jud[m][c++]=ge[1][j];
                    jud[m][c++]=0;
                    qsort(jud[m],c-1,sizeof(char),cmp);
                    m++;
                }
            }
        }
        char res[4][3];
        int t=1;
        strcpy(res[0],jud[0]);
        for(int i=1;i<m;i++){
            int flag=1;
            for(int j=0;j<t;j++){
                if(strcmp(res[j],jud[i])==0)flag=0;
            }
            if(flag)strcpy(res[t++],jud[i]);
        }
        qsort(*res,t,sizeof(res[0]),cmp1);
        for(int i=0;i<3;i++){
            if(i!=p)printf("%s ",f[i]);
            else{
                printf("{");
                for(int j=0;j<t-1;j++){
                    printf("%s,",res[j]);
                }
                printf("%s} ",res[t-1]);
            }
        }
    }
    }
    //推测父母
    else{
        for(int i=0;i<2;i++)
            if(strlen(f[i])==2)fab=1;
        if(f[2][0]=='O')fo=1;
        if(fo&&fab){//不可能的情况
            for(int i=0;i<3;i++){
                if(i!=p)printf("%s ",f[i]);
                else printf("impossible ");
            }
        }
        else{
            for(int i=0;i<3;i++){
                if(i!=p){
                    if(strlen(f[i])==2)
                        ge[k][0]='A',ge[k][1]='B',ge[k++][2]=0;
                    else{
                        if(f[i][0]!='O'){
                            ge[k][0]=f[i][0],ge[k][1]='O',ge[k++][2]=0;
                        }
                        else{
                            ge[k][0]='O',ge[k++][1]=0;
                        }
                    }
                    //printf("%s\n",ge[k-1]);
                }
            }
            if(!(fo&&fab)){
                int t=0;
                int len1=strlen(ge[0]),len2=strlen(ge[1]);
                //printf("len1=%d,ge0=%s len2=%d,ge1=%s\n",len1,ge[0],len2,ge[1]);
                if(ge[0][0]=='O'){

                    if(ge[1][0]=='A'){
                        jud[0][0]='A',jud[0][1]=0;
                        jud[1][0]='A',jud[1][1]='B',jud[1][2]=0;
                        t=2;

                    }
                    else if(ge[1][0]=='B'){
                        jud[0][0]='A',jud[0][1]='B',jud[0][2]=0;
                        jud[1][0]='B',jud[1][1]=0;

                        t=2;
                    }
                    else if(ge[1][0]=='O'){
                        jud[0][0]='O',jud[0][1]=0;
                        t=1;
                    }
                }
                else if(len2==2&&ge[0][0]=='O'){
                    jud[0][0]='A',jud[0][1]='B',jud[0][2]=0;
                    t=1;
                }
                else if(len2==2&&ge[0][0]=='A'){
                    jud[0][0]='A',jud[0][1]='B',jud[0][2]=0;
                    jud[1][0]='B',jud[1][1]=0;

                    t=2;
                }
                else if(len2==2&&ge[0][0]=='B'){
                    jud[0][0]='A',jud[0][1]=0;
                    jud[1][0]='A',jud[1][1]='B',jud[1][2]=0;
                    t=2;
                }
                else{
                    jud[0][0]='A',jud[0][1]=0;
                    jud[1][0]='B',jud[1][1]=0;
                    jud[2][0]='O',jud[2][1]=0;
                    t=3;
                }
                for(int i=0;i<3;i++){
                    if(i!=p)printf("%s ",f[i]);
                    else{
                        printf("{");
                        for(int j=0;j<t-1;j++){
                            printf("%s,",jud[j]);
                        }
                        printf("%s} ",jud[t-1]);
                    }
                }
            }
        }
    }
    return 0;
}
