#include <iostream>
using namespace std;

int SearchChar(char A[], int n, char data);

int main()
{
    const int jumlahElemen = 10;
    char huruf[jumlahElemen] =
    {'A','B','C','D','E','F','G','H','I','J'};

    cout << "SEQUENTIAL SEARCH KARAKTER" << endl;
    cout << "==========================" << endl;

    cout << "Isi data :" << endl;

    for(int i=0; i<jumlahElemen; i++)
    {
        cout << huruf[i] << " ";
    }

    cout << endl;

    char cari;

    cout << "Masukkan huruf yang dicari : ";
    cin >> cari;

    int flag = SearchChar(huruf, jumlahElemen, cari);

    if(flag != -1)
    {
        cout << "Data ditemukan pada posisi : "
             << flag << endl;
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }

    cin.get();
    return 0;
}

int SearchChar(char A[], int n, char data)
{
    int flag = -1;

    for(int i=0; i<n; i++)
    {
        if(A[i] == data)
        {
            flag = i;
            break;
        }
    }

    return flag;
}