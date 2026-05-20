#include <iostream>
using namespace std;

int main() {
    int tahun = 2026; 

    if (tahun % 400 == 0) {
        cout << "Tahun " << tahun << " adalah Tahun Kabisat";
    } 
    else if (tahun % 100 == 0) {
        cout << "Tahun " << tahun << " bukan Tahun Kabisat";
    } 
    else if (tahun % 4 == 0) {
        cout << "Tahun " << tahun << " adalah Tahun Kabisat";
    } 
    else {
        cout << "Tahun " << tahun << " bukan Tahun Kabisat";
    }

    cin.get();
}
