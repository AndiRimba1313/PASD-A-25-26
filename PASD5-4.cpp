#include <iostream>
using namespace std;

struct Node
{
    char A1;
    Node *A2;
};

Node *A3 = NULL;
Node *A4 = NULL;

void TambahBelakang(char A5)
{
    Node *A6 = new Node;
    A6->A1 = A5;
    A6->A2 = NULL;

    if (A3 == NULL)
    {
        A3 = A6;
        A4 = A6;
    }
    else
    {
        A4->A2 = A6;
        A4 = A6;
    }
}

void TambahSetelahA(char A5)
{
    Node *A6 = new Node;
    A6->A1 = A5;

    Node *A7 = A3;

    while (A7 != NULL && A7->A1 != 'A')
    {
        A7 = A7->A2;
    }

    if (A7 != NULL)
    {
        A6->A2 = A7->A2;
        A7->A2 = A6;

        if (A7 == A4)
        {
            A4 = A6;
        }
    }
}

void TambahSetelahB(char A5)
{
    Node *A6 = new Node;
    A6->A1 = A5;

    Node *A7 = A3;

    while (A7 != NULL && A7->A1 != 'B')
    {
        A7 = A7->A2;
    }

    if (A7 != NULL)
    {
        A6->A2 = A7->A2;
        A7->A2 = A6;

        if (A7 == A4)
        {
            A4 = A6;
        }
    }
}

void HapusDepan()
{
    if (A3 != NULL)
    {
        Node *A8 = A3;
        A3 = A3->A2;
        delete A8;

        if (A3 == NULL)
        {
            A4 = NULL;
        }
    }
}

void Tampil()
{
    Node *A7 = A3;

    while (A7 != NULL)
    {
        cout << A7->A1 << " ";
        A7 = A7->A2;
    }

    cout << endl;
}

int main()
{
    TambahBelakang('A');
    TambahBelakang('B');
    TambahBelakang('C');

    cout << "Queue Awal : ";
    Tampil();

    TambahSetelahA('D');
    cout << "a. D setelah A : ";
    Tampil();

    HapusDepan();
    HapusDepan();
    HapusDepan();

    cout << "b. A, B, C hilang : ";
    Tampil();

    TambahBelakang('F');
    cout << "F paling akhir : ";
    Tampil();

    TambahBelakang('A');
    TambahBelakang('B');
    TambahBelakang('C');

    TambahSetelahB('E');
    cout << "d. E setelah B : ";
    Tampil();

    return 0;
}