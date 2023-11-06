#define MAX_N 1000

long int fib[MAX_N];

long int fibonacci(int n) {
    if (n == 1 || n == 2) { 
        return 1;
    } else if (fib[n] != 0) {
        return fib[n];
    } else { 
        fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return fib[n];
    }
}