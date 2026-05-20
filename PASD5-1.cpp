#include <iostream>
using namespace std;

//Deklarasi struktur data nilai MK
typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

//Deklarasi struktur elemen
typedef struct elm *alamatelmn;
typedef struct elm {
    NilaiMK Kontainer;
    alamatelmn next;
} elemen;

//Deklarasi struktur queue
typedef struct {
    elemen *first;
    elemen *last;
} queue;

//Fungsi membuat queue kosong
void buatQkosong(queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

//Fungsi cek queue kosong
int isKosong(queue Q) {
    bool hasil = false;

    if(Q.first == NULL) {
        hasil = true;
    }

    return hasil;
}

//Fungsi menghitung jumlah elemen
int jmlElemen(queue Q) {
    int hasil = 0;

    if(Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;

        while(bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }

    return hasil;
}

//Fungsi menambah data ke queue
void add(string npm, string nama_mhs, double nilai, queue *Q) {

    elemen *info;
    info = new elemen;

    info->Kontainer.npm = npm;
    info->Kontainer.nama_mhs = nama_mhs;
    info->Kontainer.nilai = nilai;
    info->next = NULL;

    if((*Q).first == NULL) {
        (*Q).first = info;
    }
    else {
        (*Q).last->next = info;
    }

    (*Q).last = info;
    info = NULL;
}

//Fungsi menghapus data queue
void del(queue *Q) {

    if((*Q).first != NULL) {

        elemen *hapus = (*Q).first;

        if(jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else {
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }

        delete hapus;
    }
}

//Fungsi menampilkan queue
void cetakQueue(queue Q) {

    if(Q.first != NULL) {

        cout << "ISI QUEUE :" << endl;

        elemen *bantu = Q.first;
        int i = 1;

        while(bantu != NULL) {

            cout << "==========================" << endl;
            cout << "Elemen Ke : " << i << endl;
            cout << "NPM       : " << bantu->Kontainer.npm << endl;
            cout << "Nama      : " << bantu->Kontainer.nama_mhs << endl;
            cout << "Nilai     : " << bantu->Kontainer.nilai << endl;

            bantu = bantu->next;
            i = i + 1;
        }

        cout << "==========================" << endl;
    }
    else {
        cout << "Queue Kosong" << endl;
    }
}

int main() {

    queue Q;
    buatQkosong(&Q);

    int n;
    string npm, nama;
    double nilai;

    cout << "Jumlah Data : ";
    cin >> n;
    cin.get();

    for(int i = 1; i <= n; i++) {

        cout << endl;
        cout << "Data Ke-" << i << endl;

        cout << "Input NPM : ";
        getline(cin, npm);

        cout << "Input Nama Mahasiswa : ";
        getline(cin, nama);

        cout << "Input Nilai : ";
        cin >> nilai;
        cin.get();

        add(npm, nama, nilai, &Q);
    }

    cout << endl;
    cout << "HASIL QUEUE" << endl;
    cetakQueue(Q);

    cout << endl;
    cout << "Setelah Hapus 1 Data" << endl;

    del(&Q);

    cetakQueue(Q);

    return 0;
}