#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){
    int a1=*(int*)a,b1=*(int*)b;
    if (a1>b1) return 1;
    else return -1;
}
int main()
{

    int n;
    scanf("%d",&n);
    char s[101];
    scanf("%s",s);
    char criteria[101];
    int lenc=0;
    int error=0;

    for (int i=0;i<strlen(s);i++){
        int count=1;
        while (s[i]==s[i+1]){
            i++;
            count++;
        }
        criteria[lenc++]=s[i];
    }

    int* con[101];
    for (int i=0;i<lenc;i++)
    {
        con[i]=(int*)malloc(sizeof(int)*n);

    }
    int k=0;
    for (int i=0;i<strlen(s);i++){
        int count=1;
        while (s[i]==s[i+1]){
            i++;
            count++;
        }
        con[k++][0]=count;
    }
    criteria[lenc]=0;

    for (int i=1;i<n;i++){
        scanf("%s",s);
        char temp[101];
        int len=0;
        if (error==0)
        for (int j=0;j<strlen(s);j++){
            int count=1;
            while (s[j]==s[j+1]){
                j++;
                count++;
            }
            con[len][i]=count;
            temp[len++]=s[j];

        }
        temp[len]=0;
        if (strcmp(temp,criteria)!=0) error=1;
    }
    if (error==1) printf("-1\n");
    else {
        int step=0;
        for (int i=0;i<lenc;i++)
            qsort(con[i],n,sizeof(con[i][0]),cmp);
        if (n%2==0){

            for (int i=0;i<lenc;i++){
                int t=(con[i][n/2-1]+con[i][n/2])/2;
                for (int j=0;j<n;j++)
                    step=step+abs(t-con[i][j]);
            }
        }
        else{
            for(int i=0;i<lenc;i++){
                int t=con[i][n/2];
                for (int j=0;j<n;j++)
                    step=step+abs(t-con[i][j]);
            }
        }
        printf("%d",step);
    }
    for (int i=0;i<lenc;i++)free(con[i]);
}
