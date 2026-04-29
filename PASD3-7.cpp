#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* top = NULL;
Node* tempTop = NULL;

// PUSH
void push(Node* &top, string x) {
    Node* baru = new Node;
    baru->data = x;
    baru->next = top;
    top = baru;
}

// POP
string pop(Node* &top) {
    Node* hapus = top;
    string x = hapus->data;
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

    // Data awal
    push(top, "Iphone");
    push(top, "Windows");
    push(top, "Mac");
    push(top, "Symbian");
    push(top, "Maemo");

    // a. Iphone 5 di atas Iphone
    while (top->data != "Iphone") {
        push(tempTop, pop(top));
    }
    push(top, "Iphone 5");
    while (tempTop != NULL) {
        push(top, pop(tempTop));
    }
    tampil(top);

    // b. Windows Phone di atas Windows
    while (top->data != "Windows") {
        push(tempTop, pop(top));
    }
    push(top, "Windows Phone");
    while (tempTop != NULL) {
        push(top, pop(tempTop));
    }
    tampil(top);

    // c. SnowLeopard setelah Mac
    while (top->data != "Mac") {
        push(tempTop, pop(top));
    }
    push(top, "SnowLeopard");
    while (tempTop != NULL) {
        push(top, pop(tempTop));
    }
    tampil(top);

    // d. Symbian Belle setelah Symbian
    while (top->data != "Symbian") {
        push(tempTop, pop(top));
    }
    push(top, "Symbian Belle");
    while (tempTop != NULL) {
        push(top, pop(tempTop));
    }
    tampil(top);

    // e. Maemo 4 paling bawah
    while (top != NULL) {
        push(tempTop, pop(top));
    }
    push(top, "Maemo 4");
    while (tempTop != NULL) {
        push(top, pop(tempTop));
    }
    tampil(top);

    cin.get();
}
