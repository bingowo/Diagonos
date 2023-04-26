#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char s[],char model[])
{
    char t[101] = {};
    for (int i=0,k=0;s[i];i++) if (s[i]!=s[i+1]) t[k++] = s[i];
    if (strcmp(t,model)==0) return 0;
    else return 1;
}

int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}

main()
{
    int n; scanf("%d",&n);
    char s[100001] = {};
    scanf("%s",s);
    char model[101] = {};
    for (int i=0,k=0;s[i];i++) if (s[i]!=s[i+1]) model[k++] = s[i];
    /*for (int i=1;i<n;i++) if (check(a[i],model)) {printf("-1\n"); return 0;}*/
    int *num[101] = {};
    for (int i=0;i<n;i++)
    {
        int *z = (int*)malloc(n*sizeof(int));
        num[i] = z;
    }
    int index = 0;
    for (int j=0;j<strlen(model);j++)
    {
        int cal = 0;
        for (;s[index]&&s[index]==model[j];index++) cal++;
        num[j][0] = cal;
    }
    for (int i=1;i<n;i++)
    {
        scanf("%s",s);
        if (check(s,model)) {printf("-1\n"); system("pause"); return 0;}
        index = 0;
        for (int j=0;j<strlen(model);j++)
        {
            int cal = 0;
            for (;s[index]&&s[index]==model[j];index++) cal++;
            num[j][i] = cal;
        }
    }
    for (int i=0;i<strlen(model);i++) qsort(num[i],n,sizeof(num[i][0]),cmp);
    int cnt = 0;
    for (int i=0;i<strlen(model);i++)
    {
        int base = num[i][n/2];
        for (int j=0;j<n;j++) cnt += abs(num[i][j]-base);
    }
    /*for (int i=0;i<strlen(model);i++)
        for (int j=0;j<n;j++) printf("%d ",num[i][j]);*/
    printf("%d\n",cnt);
    system("pause");
    return 0;
}