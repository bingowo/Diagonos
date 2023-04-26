#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{

    int n;
    scanf("%d",&n);
    char s[101];
    char criteria[101];
    int error=0;
    int count[101];
    scanf("%s",s);
    int len=0;
    int** array;
    array=(int**)malloc(sizeof(int*)*n);
    memset(count,0,sizeof(count));
    for (int i=0;i<strlen(s);i++){
        while(s[i]==s[i+1]) {i++;count[len]++;}
        count[len]++;
        criteria[len++]=s[i];

    }
    array[0]=(int*)malloc(len*sizeof(int));
    for (int i=0;i<len;i++) array[0][i]=count[i];
    criteria[len]=0;
    char st[101];
    for (int i=1;i<n;i++){
        scanf("%s",s);
        int lent=0;
        array[i]=(int*)malloc(len*sizeof(int));
        if (error!=1)
        for (int j=0;j<strlen(s);j++){

            array[i][lent]=1;
            while(s[j]==s[j+1]){j++;count[lent]++;array[i][lent]++;}
            count[lent]++;
            st[lent++]=s[j];
            if (lent>len) {lent--;error=1;break;}

        }
        st[lent]=0;
        if (strcmp(criteria,st)!=0) error=1;

    }
    if (error==1) printf("-1\n");
    else {
        int step=0;
        for (int i=0;i<len;i++){
            int t=count[i]/n;
            if (count[i]-t*n<t*n+t-count[i])
                for (int j=0;j<n;j++)
                 step=step+abs(array[j][i]-t);
            else
                for (int j=0;j<n;j++)
                step=step+abs(array[j][i]-t-1);
        }
        printf("%d\n",step);
    }
    for (int i=0;i<len;i++) free(array[i]);
    free(array);
    return 0;
}
