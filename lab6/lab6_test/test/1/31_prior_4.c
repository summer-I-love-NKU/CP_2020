int help_me;//为什么！！！！！！！！不能缺少全局变量？？？？？
int main () {
    int a;
    int b;
    int c;
    int d;
    a = 3;
    b = 8;
    c = -4;
    d = 15;
    int t;
    if (d % (b - a) != 0 && a > 0 || d % 3 == 0 && c > 0) {
        t = d + c - -b;
        printf("%d",t);
    }
    return 0;
}
