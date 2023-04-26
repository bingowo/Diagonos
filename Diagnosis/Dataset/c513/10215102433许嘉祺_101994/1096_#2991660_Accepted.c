#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int send[110];
        int receive[110];
        memset(send,0,sizeof(send));
        memset(receive,0,sizeof(receive));
        for (int j=0;j<n;j++){
            int a,b;
            scanf("%d%d",&a,&b);
            if (send[a]==0)
            send[a]=b;
            else if (send[a]!=b)send[a]=-1;

            receive[b]++;

        }
        int find=0;
        for (int j=0;j<110;j++)
            if (send[j]==-1||receive[j]!=0&&send[j]!=0) find=1;
        if (find==1) printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
    return 0;
}
