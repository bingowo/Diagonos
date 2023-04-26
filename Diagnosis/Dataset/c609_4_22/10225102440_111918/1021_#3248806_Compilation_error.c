#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(void* a,void* b){
    char* m=(char*)a,*n=(char*)b;
    int i=0,j;
    while(i<strlen(m)&&i<strlen(n)){
        if(m[i]==n[i]) continue;
        else{
            for(j=0;j<26;j++){
                if(m[i]==)
            }
        }
    }
}
int main()
{
    int j,k,i=0;
    char a[100][30],x[100][20][30],c;
    while(scanf("%s",&a[i])!=EOF) {
        j=0;
        while((c=getchar())!=-1){
            if(c!=" ") {
                x[i][j][k]=c;
                k++;
            }
            else j++,k=0;
        }
        i++;
    }
    for(j=0;j<i;j++) {
        qsort(x[i],sizeof(x[i])/sizeof(x[i][0]),sizeof(x[i][0]),cmp);

    }
    return 0;
}