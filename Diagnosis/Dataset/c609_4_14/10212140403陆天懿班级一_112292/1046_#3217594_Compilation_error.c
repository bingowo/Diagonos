#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int n,m=-1,r;
char s[105],st[105],lst;
int* a[105],mid[105];

int Cmp(int* pa, int* pb){return *pa-*pb;}

int main(){
    scanf("%d",&n);
    for(int i=0;i<101;i++)
        a[i]=calloc(n, sizeof(int));
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]!=lst){
            m++;
            st[m]=s[i];
            a[m][0]=1;
            lst=s[i];
        }
        else{
            a[m][0]++;
        }
    }
    m++;
    for(int i=1,k;i<n;i++){
        scanf("%s",s);
        lst=0;
        k=-1
        for(int j=0;s[j]!='\0';j++){
            if(s[j]!=lst){
                k++;
                if(st[k]!=s[j]){
                    printf("-1\n");
                    return 0;
                }
                a[k][i]=1;
                lst=s[j];
            }
            else{
                a[k][i]++;
            }
        }
        if(k+1!=m){
            printf("-1\n");
            return 0;
        }
    }
    for(int i=0;i<m;i++){
        qsort(a[i],n,sizeof(a[i][0]),Cmp);
        mid[i]=a[i][n/2];
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            r+=labs(mid[j]-a[j][i]);
    printf("%d",r);
    for(int i=0;i<101;i++)
        free(a[i]);

    return 0;
}
