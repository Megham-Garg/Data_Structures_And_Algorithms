#include <iostream>
using namespace std;

int main() {
    int t; cin >> t; getchar(); char c;
    while (t--) {
        int count[256] = {0};
        while (((c = getchar()) != '\n') && (c != EOF)) if (count[c]++ == 0) putc(c, stdout);
        printf("\n");
    }
	return 0;
}
