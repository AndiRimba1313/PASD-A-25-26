#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* top = NULL;
Node* tempTop = NULL;

// PUSH
void push(Node* &top, char x) {
    Node* baru = new Node;
    baru->data = x;
    baru->next = top;
    top = baru;
}

// POP
char pop(Node* &top) {
    if (top == NULL) return '-';
    Node* hapus = top;
    char x = hapus->data;
    top = top->next;
    delete hapus;
    return x;
}

// TAMPIL
void tampil(Node* top) {
    Node* bantu = top;
    while (bantu != NULL) {
        cout << bantu->data << endl;
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {

    // Awal: A B C
    push(top, 'A');
    push(top, 'B');
    push(top, 'C');

    // a. D setelah A
    while (top->data != 'A') {
        push(tempTop, pop(top));
    }
    push(top, 'D');
    while (tempTop != NULL) {
        push(top, pop(tempTop));
    }
    tampil(top);

    // b. E setelah B
    while (top->data != 'B') {
        push(tempTop, pop(top));
    }
    push(top, 'E');
    while (tempTop != NULL) {
        push(top, pop(tempTop));
    }
    tampil(top);

    // c. F paling bawah (hapus semua)
    while (top != NULL) pop(top);
    push(top, 'F');
    tampil(top);

    // d. F paling bawah tanpa hapus
    push(top, 'A');
    push(top, 'B');
    push(top, 'C');

    while (top != NULL) {
        push(tempTop, pop(top));
    }
    push(top, 'F');
    while (tempTop != NULL) {
        push(top, pop(tempTop));
    }
    tampil(top);

    cin.get();
}