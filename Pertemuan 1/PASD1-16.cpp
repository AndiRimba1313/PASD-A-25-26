#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    string nim[n], nama[n];
    float quiz[n], uts[n], uas[n], na[n];
    string index[n];

    // Input data
    for(int i = 0; i < n; i++) {
        cout << endl;
        cout << "Pengisian Data Mahasiswa ke-" << i+1 << endl;
        cout << "NIM        : "; cin >> nim[i];
        cout << "Nama       : "; cin >> nama[i];
        cout << "Nilai Quiz : "; cin >> quiz[i];
        cout << "Nilai UTS  : "; cin >> uts[i];
        cout << "Nilai UAS  : "; cin >> uas[i];

        // Hitung NA
        na[i] = (quiz[i] + uts[i] + uas[i]) / 3;

        // Tentukan index
        if(na[i] >= 0 && na[i] <= 44.99)
            index[i] = "E";
        else if(na[i] <= 55.99)
            index[i] = "D";
        else if(na[i] <= 59.99)
            index[i] = "C";
        else if(na[i] <= 63.99)
            index[i] = "C+";
        else if(na[i] <= 67.99)
            index[i] = "B-";
        else if(na[i] <= 71.99)
            index[i] = "B";
        else if(na[i] <= 75.99)
            index[i] = "B+";
        else if(na[i] <= 79.99)
            index[i] = "A-";
        else
            index[i] = "A";
    }

    // Output
    cout << endl;
    cout << "Data yang telah dimasukkan adalah:" << endl;
    cout << "====================================================================" << endl;
    cout << "| NIM   | NAMA   | QUIZ | UTS | UAS |   NA   | INDEX |" << endl;
    cout << "====================================================================" << endl;

    for(int i = 0; i < n; i++) {
        cout << "| " << setw(5) << nim[i]
             << " | " << setw(6) << nama[i]
             << " | " << setw(4) << quiz[i]
             << " | " << setw(3) << uts[i]
             << " | " << setw(3) << uas[i]
             << " | " << setw(6) << fixed << setprecision(2) << na[i]
             << " | " << setw(5) << index[i] << " |" << endl;
    }

    cout << "====================================================================" << endl;

    cin.get();
}