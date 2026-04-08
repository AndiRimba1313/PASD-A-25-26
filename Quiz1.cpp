#include <iostream>
#include <string>
using namespace std;

int main();  {
//DEKLARASI STRUKTUR
struct MATAKULIAH   {
       string nama;
	   char sks;
	   int nHuruf;
       float nAngka;   };
//Pendefinisian Struktur
MATAKULIAH Data_AR;
//Pengaksesan anggota struktur
Data_AR.nama = "Hell Mode";
Data_AR.sks = Kishimoto;
Data_AR.nHuruf = 2020;
Data_AR.nAngka = 250.000;
cout << endl;
cout << endl;
cout << "Judul Buku = " << Data_AR.nama << endl;
cout << "Pengarang = " << Data_AR.sks << endl;
cout << "Tahun Terbit =" << Data_AR.nHuruf << endl;
cout << "Harga = " << Data_AR.nAngka << endl;
cin.get();    
}