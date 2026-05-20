#include<stdio.h>
#include<iostream>
#include<stdlib.h> //untuk library fungsi malloc
#include<string.h>

using namespace std;

void BUAT_SIMPUL (int X);
void AWAL();
void CETAK();
void INSERTKANAN();

struct Node {
    int INFO;
    //Deklarasi struktur simpul
    struct Node *LINK; 
};

typedef struct Node Simpul;
Simpul *P, *FIRST, *LAST, *Q; //menyiapkan pointer2 yg dpt menunjuk ke simpul
int X;

int main() {
    int A[6] = {181, 182, 183, 104, 105}; //Data yang disimpan kedalam INFO
    int I;
    
    FIRST = NULL; //Inisialisasi Linked List
    I = 0;
    X = A[I];
    
    BUAT_SIMPUL(X);
    AWAL(); //Menyiapkan simpul Awal
    
    for (I = 1; I <= 6; I++) // Menambahkan simpul baru dan insert kanan agar terbentuk Linked List
    {
        X = A[I];
        BUAT_SIMPUL(X);
        INSERTKANAN(); 
    }
    
    cout << "Daftar Nomor Antrian Saat ini: " << endl;
    CETAK();
    
    X = 999;
    BUAT_SIMPUL(X);
    INSERTKANAN(); //Menginsert simpul baru disebelah kanan dgn INFO = 100
    
    cout << endl;
    cout << "Darftar Antrian Setelah Pelanggan Baru: " << endl;
    CETAK();
    
    cout << endl;
    cin.get(); 
}

void BUAT_SIMPUL (int X) //Fungsi membuat sebuah simpul baru
{
    P = (Simpul*) malloc(sizeof(Simpul));
    if(P == NULL) {
        cout << "Pembuatan Simpul Tidak Berhasil" << endl;
        cin.get();
        exit(1);
    }
    else {
        P->INFO = X;
    }
}

void AWAL() //Fungsi membuat simpul awal
{
    FIRST = P;
    LAST = P;
    P->LINK = NULL; 
}

void INSERTKANAN() //Fungsi menginsert simpul disebelah kanan
{
    LAST->LINK = P;
    LAST = P;
    P->LINK = NULL; 
}

void CETAK() //Fungsi mencetak isi seluruh simpul
{
    Q = FIRST;
    while(Q != NULL) {
        X = Q->INFO;
        cout << " " << X;
        Q = Q->LINK;
    }
}
