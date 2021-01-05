int help_me;//为什么！！！！！！！！不能缺少全局变量？？？？？
int main () {
    int a;
    int b;
    int c;
    a = 1;
    b = 4;
    c = 28;
    int t;
    if (c + a != b) {
        b=-b;t=c%b;
        //t = c % -b;
        printf("%d\n",t);
    }
    if (b - c == a) {
        t = c%b+b;
        printf("%d\n",t);
    }
    return 0;
}
