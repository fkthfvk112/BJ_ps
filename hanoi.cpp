#include <iostream>
using namespace std;

void move(int n, int from, int to, int aux) {
    if(n == 1) {
        cout << "Move disk 1 from peg " << from << " to peg " << to << endl;
        return;
    }
    move(n-1, from, aux, to);
    cout << "Movasde disk " << n << " from peg " << from << " to peg " << to << endl;
    move(n-1, aux, to, from);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    move(n, 1, 3, 2);
    return 0;
}
