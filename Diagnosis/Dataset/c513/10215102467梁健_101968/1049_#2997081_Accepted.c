#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main()
{
    int T;scanf("%d",&T);
    char c;c=getchar();
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        char s[550];gets(s);
        char dj[100][20],j[100][20];//d:dis,j:judge;
        int k=0,cnt=0;
        for(int i=0;i<=strlen(s);i++){
            if(isalpha(s[i]))
                dj[k][cnt++]=s[i];
            else{
                if(isalpha(s[i-1])){
                    dj[k][cnt]=0;
                    k++;
                    cnt=0;
                }
            }
        }
        cnt=0;
        int sq=0;
        strcpy(j[sq],dj[0]);
        sq++;
        for(int i=1;i<k;i++){
            for(int m=0;m<sq;m++){
                if(strcmp(j[m],dj[i])!=0)cnt++;
            }
            if(cnt==sq){
                strcpy(j[sq],dj[i]);
                sq++;
            }
            cnt=0;
        }
        qsort(*j,sq,sizeof(j[0]),strcmp);
        for(int i=0;i<sq;i++){
            printf("%s ",j[i]);
        }
        printf("\n");
    }
    return 0;
}
