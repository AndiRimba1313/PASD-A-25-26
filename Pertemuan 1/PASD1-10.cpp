#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// struct
struct pelanggan_toko {
    string nama;
    string alamat;
    string kelamin;
    string telp;
    int umur;
};

int main() {
    int jumlah = 5;
    pelanggan_toko data[5];

    cout << endl;
    cout << "INPUT DATA PELANGGAN" << endl;

    // Input Data
    for(int i = 0; i < jumlah; i++) {
        cout << endl;
        cout << "Data ke-" << i+1 << endl;

        cout << "Nama Pelanggan Toko      : "; cin >> data[i].nama;
        cout << "Alamat Pelanggan Toko    : "; cin >> data[i].alamat;
        cout << "Umur Pelanggan Toko      : "; cin >> data[i].umur;
        cout << "Jenis Kelamin [L/P]      : "; cin >> data[i].kelamin;
        cout << "No telp Pelanggan        : "; cin >> data[i].telp;
    }

    // Output Data
    cout << endl;
    cout << "============================================" << endl;
    cout << "           Data Pelanggan Toko              " << endl;
    cout << "============================================" << endl;
    cout << "Nama     Alamat     Umur     Kelamin     Telp" << endl;
    cout << "============================================" << endl;

    for(int i = 0; i < jumlah; i++) {
        cout << setw(10) << data[i].nama
             << setw(10) << data[i].alamat
             << setw(10) << data[i].umur
             << setw(10) << data[i].kelamin
             << setw(10) << data[i].telp;
        cout << endl;
    }

    cout << "============================================" << endl;
    cin.get();
}