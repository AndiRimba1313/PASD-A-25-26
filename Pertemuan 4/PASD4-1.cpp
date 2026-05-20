#include <iostream>
using namespace std;

struct NilaiMK {
    string npm;
    string nama_mhs;
    double nilai;
};

struct queue {
    int first;
    int last;
    NilaiMK Dat[10];
};

void buatKosong(queue *Q) {
    (*Q).first = -1;
    (*Q).last = -1;
}

bool isKosong(queue Q) {
    return (Q.first == -1);
}

bool isPenuh(queue Q) {
    return (Q.last == 9);
}

void ADD(string npm, string nama_mhs, double nilai, queue *Q) {
    if (isKosong(*Q)) {
        (*Q).first = 0;
        (*Q).last = 0;
    } else if (!isPenuh(*Q)) {
        (*Q).last = (*Q).last + 1;
    } else {
        cout << "QUEUE PENUH" << endl;
        return;
    }

    (*Q).Dat[(*Q).last].npm = npm;
    (*Q).Dat[(*Q).last].nama_mhs = nama_mhs;
    (*Q).Dat[(*Q).last].nilai = nilai;
}

void DEL(queue *Q) {
    if ((*Q).last == 0) {
        (*Q).first = -1;
        (*Q).last = -1;
    } else {
        for (int i = (*Q).first + 1; i <= (*Q).last; i++) {
            (*Q).Dat[i-1] = (*Q).Dat[i];
        }
        (*Q).last = (*Q).last - 1;
    }
}

void CetakQueue(queue Q) {
    if (isKosong(Q)) {
        cout << "Queue Kosong" << endl;
    } else {
        cout << "=== ISI QUEUE ===" << endl;
        for (int i = Q.first; i <= Q.last; i++) {
            cout << "NPM   : " << Q.Dat[i].npm << endl;
            cout << "Nama  : " << Q.Dat[i].nama_mhs << endl;
            cout << "Nilai : " << Q.Dat[i].nilai << endl;
            cout << "---------------------" << endl;
        }
    }
}

int main() {
    queue Q;
    buatKosong(&Q);

    int n;
    string npm, nama;
    double nilai;

    cout << "Jumlah data: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i+1 << endl;

        cout << "NPM   : ";
        cin >> npm;

        cout << "Nama  : ";
        cin >> nama;

        cout << "Nilai : ";
        cin >> nilai;

        ADD(npm, nama, nilai, &Q);
    }

    cout << endl;
    CetakQueue(Q);

    cout << "\nHapus 1 data...\n";
    DEL(&Q);

    cout << endl;
    CetakQueue(Q);

    cin.get();
}