#include <iostream>
#include <string>

using namespace std;

// 1. Deklarasi struktur data nilai MK
typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

// 2. Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm {
    NilaiMK Kontainer;
    alamatelm next;
} elemen;

// 3. Deklarasi struktur queue
typedef struct {
    elemen *first;
    elemen *last;
} queue;

// 4. Deklarasi prosedur untuk membuat sebuah queue kosong
void buatQUkosong(queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

// 5. Deklarasi fungsi yang mengembalikan nilai TRUE apabila queue kosong
int isKosong(queue Q) {
    bool hasil = false;
    if (Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}

// 6. Deklarasi fungsi yang menghitung jumlah elemen queue
int jmlElemen(queue Q) {
    int hasil = 0;
    if (Q.first != NULL) {
        elemen *bantu = Q.first;
        while (bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

// 7. Deklarasi prosedur ADD (Enqueue)
void add(string npm, string nama_mhs, double nilai, queue *Q) {
    elemen *info = new elemen;
    info->Kontainer.npm = npm;
    info->Kontainer.nama_mhs = nama_mhs;
    info->Kontainer.nilai = nilai;
    info->next = NULL;

    if ((*Q).first == NULL) {
        (*Q).first = info;
    } else {
        (*Q).last->next = info;
    }
    (*Q).last = info;
    info = NULL;
}

// 8. Deklarasi prosedur DEL (Dequeue)
void del(queue *Q) {
    if ((*Q).first != NULL) {
        elemen *hapus = (*Q).first;
        if (jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last = NULL;
        } else {
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        delete hapus;
    }
}

// 9. Deklarasi prosedur untuk menampilkan queue ke layar
void CetakQueue(queue Q) {
    if (Q.first != NULL) {
        cout << "MENAMPILKAN QUEUE" << endl;
        elemen *bantu = Q.first;
        int i = 1;
        while (bantu != NULL) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Elemen ke : " << i << endl;
            cout << "Nomor Pokok Mahasiswa : " << bantu->Kontainer.npm << endl;
            cout << "Nama Mahasiswa : " << bantu->Kontainer.nama_mhs << endl;
            cout << "Nilai Mahasiswa : " << bantu->Kontainer.nilai << endl;
            bantu = bantu->next;
            i++;
        }
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		
    } else {
        cout << "Queue Kosong" << endl;
    }
}

int main() {
    queue Q;
    buatQUkosong(&Q);

    // Menampilkan keadaan awal
    CetakQueue(Q);
    cout << endl << "~~~~~" << endl;

    // Memasukkan data ke dalam antrian
    add("4523210666", "Budi", 88.75, &Q);
    add("4523210777", "Susi", 78.85, &Q);
    add("4523210888", "Nuri", 98.65, &Q);
    add("4523210999", "Bimo", 68.55, &Q);
    add("4523210555", "Arif", 78.85, &Q);
    add("4523210444", "Rido", 98.65, &Q);
    add("4523210222", "Ella", 68.55, &Q);

    CetakQueue(Q);
    cout << "===========================" << endl;

    // Menghapus elemen pertama
    del(&Q);
    CetakQueue(Q);
    cout << endl;

    // Menghapus elemen kedua
    del(&Q);
    CetakQueue(Q);
    cout << "===========================" << endl;

    return 0;
}