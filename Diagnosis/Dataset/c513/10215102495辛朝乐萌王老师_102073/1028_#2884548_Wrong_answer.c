int solve1()
{
    int a[10];
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<10-1;i++)
    {
        for(int j=0;j<10-1-i;j++)
        {
            if(a[j]>a[j+1]){
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    int index = 1;
    int b[10];
    b[0] = a[0];
    for(int i=1;i<10;i++){
        if(a[i] != a[i-1]){
            b[index++] = a[i];
        }
    }
    for(int i=0;i<index;i++){
        printf("%d ",b[i]);
    }
}
int solve2()
{
    int a[10];
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<10-1;i++)
    {
        for(int j=0;j<10-1-i;j++)
        {
            if(a[j]>a[j+1]){
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    int index = 1;
    int b[10];
    b[0] = a[0];
    for(int i=1;i<10;i++){
        if(a[i] != a[i-1]){
            b[index++] = a[i];
        }
    }
    for(int i=0;i<index;i++){
        printf("%d ",b[i]);
    }
}

int main()
{
    char c;
    scanf("%c",&c);
    if(c=='A'){
        solve1;
    }
    else{solve2;}
    return 0;
}
