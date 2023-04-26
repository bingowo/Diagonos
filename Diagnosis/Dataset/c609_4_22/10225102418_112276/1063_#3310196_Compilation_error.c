
int main() {
    int T;
    scanf("%d", &T); // 读入问题数
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n); // 读入楼梯数
        printf("case #%d: %d\n", i, f[n]); // 输出问题编号和答案
    }
    return 0;
}