#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long getFibonacciHugePisano(long n, long m) {
    if (n <= 1)
        return n;

    long beforePrevious  = 0;
    long previous = 1;
    long a = -1;
    long current = -1;

    for (long i = 2; i <= n; i++) {
        current = (beforePrevious + previous) % m; // (a + b) % m = (a%m + b%m) % m

        if (a == 0 && current == 1) {
            long period = (i + 1) - 2;
            long reductionN = n % period;
            return getFibonacciHugePisano(reductionN, m);

        }
        else {
            a = current;
            beforePrevious = previous;
            previous = current;
        }
    }

    return current;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    // n = 2816213588;
    // m = 30524;

    std::cout << getFibonacciHugePisano(n, m) << '\n';

    return 0;
}
