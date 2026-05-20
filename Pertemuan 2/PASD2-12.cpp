#include <iostream>
using namespace std;

#define MAX 10

string nama[MAX];
int umur[MAX];
int top = -1;

// PUSH
void push(string n, int u) {
    if(top == MAX - 1) {
        cout << "Stack Penuh" << endl;
    } else {
        top++;
        nama[top] = n;
        umur[top] = u;
    }
}

// POP
void pop() {
    if(top == -1) {
        cout << "Stack Kosong" << endl;
    } else {
        top--;
    }
}

// DISPLAY DETAIL
void displayDetail() {
    for(int i = 0; i <= top; i++) {
        cout << "Nama & Umur : " << nama[i] << " - " << umur[i] << endl;
    }
}

// DISPLAY SATU BARIS
void displayBaris() {
    cout << "Nama : ";
    for(int i = 0; i <= top; i++) {
        cout << nama[i] << " --" << umur[i] << " ";
    }
    cout << endl;
}

int main() {

    // PUSH DATA
    push("Fanny", 10);
    push("Tiara", 63);
    push("Ilham", 28);
    push("Cinthya", 66);
    push("Candra", 22);

    // SEBELUM HAPUS
    cout << "Data Sebelum Penghapusan" << endl;
    displayDetail();

    cout << "====================================" << endl;
    displayBaris();
    cout << "====================================" << endl;

    // HAPUS SAMPAI TIARA TERHAPUS
    while(top != -1 && nama[top] != "Tiara") {
        pop();
    }
    pop(); // hapus Tiara

    // SETELAH HAPUS
    cout << endl;
    cout << "Data Setelah Penghapusan" << endl;

    for(int i = 0; i <= top; i++) {
        cout << nama[i] << " --" << umur[i] << " ";
    }

    cin.get();
}
