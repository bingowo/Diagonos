#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{

    int n;
    scanf("%d",&n);
    char s[101];
    scanf("%s",s);
    char criteria[101];
    int lenc=0;
    int error=0;
    int max[101],min[101];
    memset(max,0,sizeof(max));
    memset(min,0,sizeof(min));
    for (int i=0;i<strlen(s);i++){
        int count=1;
        while (s[i]==s[i+1]){
            i++;
            count++;
        }
        max[lenc]=count;
        min[lenc]=count;
        criteria[lenc++]=s[i];

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
            if (count>max[len]) max[len]=count;
            if (count<min[len]) min[len]=count;
            temp[len++]=s[j];

        }
        temp[len]=0;
        if (strcmp(temp,criteria)!=0) error=1;
    }
    if (error==1) printf("-1\n");
    else {
        int step=0;
        for(int i=0;i<lenc;i++)
            {step=step+max[i]-min[i];}
        printf("%d",step);
    }
}

