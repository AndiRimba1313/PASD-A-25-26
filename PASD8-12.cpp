#include <iostream>
using namespace std;

int Search01(int A[], int n, int elemen);

int main()
{
    int jumlahElemen;

    cout << "Masukkan jumlah elemen : ";
    cin >> jumlahElemen;

    int data[100];

    for(int i=0; i<jumlahElemen; i++)
    {
        cout << "Data ke-" << i+1 << " : ";
        cin >> data[i];
    }

    cout << endl;
    cout << "Isi data :" << endl;

    for(int i=0; i<jumlahElemen; i++)
    {
        cout << data[i] << " ";
    }

    cout << endl;

    int cari;

    cout << "Masukkan data yang dicari : ";
    cin >> cari;

    int flag = Search01(data, jumlahElemen, cari);

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

int Search01(int A[], int n, int elemen)
{
    int flag = -1;

    for(int i=0; i<n; i++)
    {
        if(elemen == A[i])
        {
            flag = i;
            break;
        }
    }

    return flag;
}