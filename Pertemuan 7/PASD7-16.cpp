#include <iostream>
#include <string.h>
using namespace std;

struct Data
{
    int A1[10];
    int A2[10];
};

Data A3;

int A4;

void tukar(int A5, int A6)
{
    int A7;

    A7 = A3.A1[A6];
    A3.A1[A6] = A3.A1[A5];
    A3.A1[A5] = A7;
}

void Input()
{
    cout<<"Masukkan jumlah data = ";
    cin>>A4;

    cout<<"--------------------------------"<<endl;

    for(int A5=0; A5<A4; A5++)
    {
        cout<<"Masukkan data ke-"<<(A5+1)<<" = ";
        cin>>A3.A1[A5];

        A3.A2[A5] = A3.A1[A5];
    }

    cout<<endl;
}

void Tampil()
{
    for(int A5=0; A5<A4; A5++)
    {
        cout<<A3.A1[A5]<<" ";
    }

    cout<<endl;
}

void bubble_sort()
{
    int A5, A6;
    int A7;
    int flag;

    A5 = 0;a
    flag = 1;

    while(A5 <= A4 - 2 && flag == 1)
    {
        A6 = 0;
        flag = 0;

        while(A6 <= A4 - 2 - A5)
        {
            if(A3.A1[A6] > A3.A1[A6 + 1])
            {
                flag = 1;

                tukar(A6, A6 + 1);
            }

            A6++;
        }

        Tampil();

        A5++;
    }

    cout<<endl;
}

int main()
{
    cout<<"*--------------------------------*"<<endl;
    cout<<"* Selamat datang di aplikasi *"<<endl;
    cout<<"* Bubble Sort *"<<endl;
    cout<<"*--------------------------------*"<<endl;

    Input();

    cout<<"Proses Bubble Sort........"<<endl;
    cout<<"--------------------------------"<<endl;

    Tampil();

    bubble_sort();

    cout<<"--------------------------------"<<endl;
    cout<<" TERIMA KASIH "<<endl;
    cout<<"--------------------------------"<<endl;

    cin.get();
}