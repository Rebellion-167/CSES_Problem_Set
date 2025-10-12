#include <iostream>

int main() {
    long long n, i, total_combo, attack_knight;
    std::cin >> n;
    for(i=1;i<=n;i++) {
        total_combo = ((i * i) * ((i * i) - 1)) / 2;
        attack_knight = 4 * (i - 1) * (i - 2);
        std::cout << total_combo - attack_knight << std::endl;
    }
    return 0;
}