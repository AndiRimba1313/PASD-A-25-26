#include <iostream>
using namespace std;

//pendeklarasian tipe data baru struct mahasiswa
class Mahasiswa{
            public:
            char kodeBarang[9];
			char namaBarang[30];
			float harga;
		  };
int main(){
        //Buat variabel mhs bertipe data mahasiswa
		Mahasiswa mhs;
		cout << "Kode Barang    = "; cin >> mhs.kodeBarang;
		cout << "Nama Barang           = "; cin >> mhs.namaBarang;
		cout << "Harga   = "; cin >> mhs.harga;
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout << "                Data Barang" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout << "Kode Barang    = " << mhs.kodeBarang << endl;
		cout << "Nama Barang           = " << mhs.namaBarang<< endl;
		cout << "Harga = " << mhs.harga <<endl;
		cin.get();
}