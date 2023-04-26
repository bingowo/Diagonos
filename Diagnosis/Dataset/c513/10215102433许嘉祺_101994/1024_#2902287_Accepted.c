#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    int n,m,g;
    scanf("%d",&t);
    int score[11];
    char s[500][12];
    int num,bianhao;
    int grade[500];
    for (int i=0; i<t; i++)
    {
        memset(grade,0,sizeof(grade));
        scanf("%d%d%d",&n,&m,&g);
        for (int j=0; j<m; j++) scanf("%d",&score[j]);
        for (int j=0; j<n; j++)
        {
            scanf("%s%d",s[j],&num);
            for (int k=0; k<num; k++)
            {
                scanf("%d",&bianhao);
                grade[j]+=score[bianhao-1];
            }
        }
        for (int j=0; j<n-1; j++)
            for (int k=n-1; k>=j+1; k--)
                if(grade[k]>grade[k-1]||(grade[k]==grade[k-1]&&strcmp(s[k],s[k-1])<0))
                {
                    int p=grade[k];
                    grade[k]=grade[k-1];
                    grade[k-1]=p;
                    char s3[12];
                    strcpy(s3,s[k]);
                    strcpy(s[k],s[k-1]);
                    strcpy(s[k-1],s3);
                }
        printf("case #%d:\n",i);
        int count=0;
        for(int j=0;j<n;j++)
            if (grade[j]<g) break;
            else count++;
        printf("%d\n",count);
        for(int j=0;j<count;j++)
            printf("%s %d\n",s[j],grade[j]);


    }
    return 0;
}