#include<stdio.h>

void swap(int *a, int *b);
int main()
{
    int n=0,m=0;
    int a,b,c;
    int i,j,k;
    int score[11];
    int win[11];
    int lose[11];
    int index[11];
    for (i=1;i<11;i++){
        score[i]=0;
    }
    for (i=1;i<11;i++){
        win[i]=0;
    }
    for (i=1;i<11;i++){
        lose[i]=0;
    }
    for (i=1;i<11;i++){
        index[i]=i;
    }
    scanf("%d %d",&n,&m);
    while (1){
        if (n==0 && m==0){
            break;
        }
        for (i=0;i<m;i++){//输入部分
            scanf("%d %d %d",&a,&b,&c);
            if (c==1){
                win[a]++;
                score[a]+=3;
                lose[b]++;
                score[b]--;
            }
            else if (c==-1){
                win[b]++;
                score[b]+=3;
                lose[a]++;
                score[a]--;
            }
            else{
                score[a]++;
                score[b]++;
            }
        }
        for (i=1;i<11;i++){//排序部分
                k=i;
                for (j=i+1;j<11;j++){
                    if (score[index[j]]>score[index[k]]){
                        k=j;
                    }
                    else if (score[index[j]]==score[index[k]] && win[index[j]]>win[index[k]]){
                        k=j;
                    }
                    else if (score[index[j]]==score[index[k]] && win[index[j]]==win[index[k]] && lose[index[j]]<lose[index[k]]){
                        k=j;
                    }
                    else if (score[index[j]]==score[index[k]] && win[index[j]]==win[index[k]] && lose[index[j]]==lose[index[k]] && index[j]<index[k]){
                        k=j;
                    }
                }
                if (k != i){
                    swap(&index[i],&index[k]);
                }
                
        }
        for (i=1;i<=n;i++){
            printf("%d ",index[i]);
        }
        putchar('\n');
        scanf("%d %d",&n,&m);
    }
    return 0;

    
}

void swap(int *a, int *b)
    {
        int t;
        t=*a;
        *a=*b;
        *b=t;
    }