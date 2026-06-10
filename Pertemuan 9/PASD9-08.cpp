#include <iostream>
using namespace std;

struct Node {
    char info;
    Node *left;
    Node *right;
};

Node *root = NULL;

Node* buatNode(char data) {
    Node *baru = new Node;
    baru->info = data;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

void insertLevelOrder(char data[], int n) {
    Node *Q[100];
    int depan = 0, belakang = 0;

    Q[belakang++] = root;

    int i = 0;

    while(i < n) {
        Node *current = Q[depan++];

        if(i < n) {
            current->left = buatNode(data[i]);
            Q[belakang++] = current->left;
            i++;
        }

        if(i < n) {
            current->right = buatNode(data[i]);
            Q[belakang++] = current->right;
            i++;
        }
    }
}

void levelOrder() {
    if(root == NULL)
        return;

    Node *Q[100];
    int depan = 0, belakang = 0;

    Q[belakang++] = root;

    while(depan < belakang) {
        Node *current = Q[depan++];

        cout << current->info << " ";

        if(current->left != NULL)
            Q[belakang++] = current->left;

        if(current->right != NULL)
            Q[belakang++] = current->right;
    }
}

int main() {

    char akar;
    int n;

    cout << "Input Root : ";
    cin >> akar;

    root = buatNode(akar);

    cout << "Jumlah Daun : ";
    cin >> n;

    char daun[100];

    for(int i = 0; i < n; i++) {
        cout << "Daun ke-" << i + 1 << " : ";
        cin >> daun[i];
    }

    insertLevelOrder(daun, n);

    cout << endl;
    cout << "Hasil Binary Tree (Level Order) : ";
    levelOrder();

    cout << endl;

    return 0;
}