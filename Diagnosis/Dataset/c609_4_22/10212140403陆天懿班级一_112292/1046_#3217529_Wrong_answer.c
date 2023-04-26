#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int n,m=-1,r;
char s[105],st[105],lst;
int* a[100005],sum[105];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        a[i]=calloc(105, sizeof(int));
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        if(s[i]!=lst){
            m++;
            st[m]=s[i];
            a[0][m]=1;
            lst=s[i];
        }
        else{
            a[0][m]++;
        }
    }
    m++;
    for(int i=1;i<n;i++){
        scanf("%s",s);
        lst=0;
        for(int j=0,k=-1;s[j]!='\0';j++){
            if(s[j]!=lst){
                k++;
                if(st[k]!=s[j]){
                    printf("-1\n");
                    return 0;
                }
                a[i][k]=1;
                lst=s[j];
            }
            else{
                a[i][k]++;
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            sum[j]+=a[i][j];
    for(int i=0;i<m;i++)
        sum[i]=(double)sum[i]/n+0.5;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            r+=labs(sum[j]-a[i][j]);
    printf("%d",r);
    for(int i=0;i<n;i++)
        free(a[i]);

    return 0;
}
