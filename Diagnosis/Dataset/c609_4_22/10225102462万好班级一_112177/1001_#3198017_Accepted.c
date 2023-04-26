#include <stdio.h>

int main() {

    int a,b,count;
    scanf("%d",&count);
    char sex[36] = {'0','1','2','3','4',
                    '5','6','7','8','9',
                    'A','B','C','D','E',
                    'F','G','H','I','J',
                    'K','L','M','N','O',
                    'P','Q','R','S','T',
                    'U','V','W','X','Y','Z'};

    int arr[100];

    for (int l = 0; l < count; ++l) {
        scanf("%d %d",&a,&b);
        if(a<0){
            a = -a;
            printf("-");
        }
        int i = 0;int m;
        while(a){
            int yu;yu = a%b;arr[i++] = yu;a = a/b;
        }
        for(i = i -1;i>=0;i--){
            m = arr[i];
            printf("%c",sex[m]);
    }printf("\n");
    }
}
