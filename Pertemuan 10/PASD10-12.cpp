#include <iostream>
#include <cmath>
using namespace std;

// ── Struct Node ──────────────────────────────────────────────
struct Node {
    struct Node *Left;   // [FIX] tambah *Right (sebelumnya hanya *Left & *Link)
    struct Node *Right;  // [FIX] ganti *Link → *Right agar konsisten dengan Binary Tree
    char INFO;
};

typedef struct Node Simpul; // bersifat global

Simpul *Root, *P, *Q_ptr, *LastCurrent, *Current, *LastKiri; // [FIX] tambah LastKiri
const int kiri = 0, kanan = 1;
int i, n, Flag, FlagHabis, Level;
char X, A[52] = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z"; // [FIX] 26 huruf + 25 koma + 1 '\0' = 52

// ── Inisialisasi ─────────────────────────────────────────────
void Inisialisasi() {
    Root = NULL;
}

// ── Buat Simpul ──────────────────────────────────────────────
void BuatSimpul(char item) {
    P = (Simpul*) malloc(sizeof(Simpul));
    if (P != NULL) {
        P->INFO  = item;
        P->Left  = NULL;
        P->Right = NULL; // [FIX] ganti P->Link → P->Right
    } else {
        cout << "Memory Penuh" << endl;
        exit(1);
    }
}

// ── Buat Simpul Akar ─────────────────────────────────────────
// [FIX] nama fungsi diubah dari BuatAkar() → BuatSimpulAkar()
//       agar cocok dengan pemanggilan di TambahSimpul() & main()
void BuatSimpulAkar() {
    if (Root == NULL) {
        Root        = P;
        LastCurrent = Root;
        LastKiri    = Root; // [FIX] inisialisasi LastKiri
        Flag        = kiri;
        Level       = 0;
        n           = 1;
        FlagHabis   = 1;
    } else {
        cout << "Pohon Sudah Ada" << endl;
        exit(1);
    }
}

// ── Tambah Simpul ────────────────────────────────────────────
// [FIX] nama fungsi diubah dari Insert(n, X) → TambahSimpul()
//       agar konsisten — logika n sudah dikelola global
void TambahSimpul() {
    if (Root != NULL) {
        n = n + 1;
        if (FlagHabis == 1) {
            FlagHabis = 0;
            Current   = P;
            LastCurrent->Left = P;
            Flag  = kanan;
            Level = Level + 1;
        } else {
            if (Flag == kiri) {
                Flag = kanan;
                LastCurrent->Left  = P;
                Current->Left = P; // [FIX] ganti Current->Link → Current->Left
                Current = P;
            } else {
                LastCurrent->Right = P;
                Current->Right = P; // [FIX] ganti Current->Link → Current->Right (konsisten)
                Flag = kiri;
                if (n == (pow(2, Level + 1) - 1)) {
                    FlagHabis   = 1;
                    LastCurrent = LastKiri->Left;  // [FIX] ganti LastCurrent→Left(typo) → LastKiri->Left
                    LastKiri    = LastKiri->Left;
                }
            }
        }
    }
}

// ── Baca Urut Nomor (Level Order / BFS) ──────────────────────
void BacaUrutNomor() {
    int i, j;
    Simpul *Q[128], *Current; // [FIX] ukuran array Q disesuaikan (sebelumnya 129, cukup 128)
    i = 1; j = 1;
    Q[i] = Root;
    while (Q[i] != NULL) {
        Current = Q[i];
        cout << Current->INFO << endl;
        if (Current->Left != NULL) {
            j++;
            Q[j] = Current->Left;
        }
        if (Current->Right != NULL) { // [FIX] ganti Q[i] → Q[j] agar tidak menimpa slot yang sedang dibaca
            j++;
            Q[j] = Current->Right;
        }
        i++;
        Q[i] = (i <= j) ? Q[i] : NULL; // [FIX] cegah baca memori tak valid
    }
}

// ── Main ─────────────────────────────────────────────────────
int main() {
    int i, n;
    char X;
    char INFOx[20] = "PANCASILA"; // 9 karakter

    Inisialisasi();

    // Buat simpul akar dari karakter pertama
    X = INFOx[0]; // [FIX] indeks 0 (bukan 1) karena array C dimulai dari 0
    BuatSimpul(X);
    BuatSimpulAkar(); // [FIX] nama diperbaiki dari BuatAkar()

    // Masukkan sisa karakter ke pohon
    for (i = 1; i <= 8; i++) { // [FIX] i mulai dari 1 (indeks ke-2 s/d ke-9)
        X = INFOx[i];
        BuatSimpul(X);
        TambahSimpul(); // [FIX] nama & signature diperbaiki dari Insert(n, X)
    }

    BacaUrutNomor();
    cin.get();
}