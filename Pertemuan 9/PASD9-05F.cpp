#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node *left;
    Node *right;
};

Node *root = NULL;

Node* buatNode(string data) {
    Node *baru = new Node;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

Node* insert(Node *root, string data) {
    if(root == NULL)
        return buatNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void inorder(Node *root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {

    int pilih;

    do {

        cout << endl;
        cout << "===== MENU =====" << endl;
        cout << "1. Input String" << endl;
        cout << "2. Input Float" << endl;
        cout << "3. Cetak" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilih;

        if(pilih == 1) {

            string data;

            cout << "Masukkan String : ";
            cin >> data;

            root = insert(root, data);
        }
        else if(pilih == 2) {

            float angka;
            string data;

            cout << "Masukkan Float : ";
            cin >> angka;

            data = to_string(angka);

            root = insert(root, data);
        }
        else if(pilih == 3) {

            cout << "Isi Tree : ";
            inorder(root);
            cout << endl;
        }

    } while(pilih != 4);

    return 0;
}