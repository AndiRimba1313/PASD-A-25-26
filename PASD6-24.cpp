#include <iostream>
using namespace std;

class MergeSort {
private:
    int A1[100], A2;

public:
    void InputData() {
        cout << "Masukkan jumlah data : ";
        cin >> A2;

        for (int A3 = 0; A3 < A2; A3++) {
            cout << "Data ke-" << A3 + 1 << " : ";
            cin >> A1[A3];
        }
    }

    void Merge(int A4, int A5, int A6) {
        int A7 = A5 - A4 + 1;
        int A8 = A6 - A5;

        int L[100], R[100];

        for (int A9 = 0; A9 < A7; A9++) {
            L[A9] = A1[A4 + A9];
        }

        for (int A10 = 0; A10 < A8; A10++) {
            R[A10] = A1[A5 + 1 + A10];
        }

        int A11 = 0;
        int A12 = 0;
        int A13 = A4;

        while (A11 < A7 && A12 < A8) {
            if (L[A11] <= R[A12]) {
                A1[A13] = L[A11];
                A11++;
            } else {
                A1[A13] = R[A12];
                A12++;
            }
            A13++;
        }

        while (A11 < A7) {
            A1[A13] = L[A11];
            A11++;
            A13++;
        }

        while (A12 < A8) {
            A1[A13] = R[A12];
            A12++;
            A13++;
        }
    }

    void MergeSortData(int A14, int A15) {
        if (A14 < A15) {
            int A16 = A14 + (A15 - A14) / 2;

            MergeSortData(A14, A16);
            MergeSortData(A16 + 1, A15);

            Merge(A14, A16, A15);
        }
    }

    void TampilData() {
        for (int A17 = 0; A17 < A2; A17++) {
            cout << A1[A17] << " ";
        }
        cout << endl;
    }

    int getSize() {
        return A2;
    }
};

int main() {
    MergeSort A18;

    A18.InputData();

    cout << endl;
    cout << "DATA SEBELUM diurutkan :" << endl;
    A18.TampilData();

    A18.MergeSortData(0, A18.getSize() - 1);

    cout << endl;
    cout << "DATA SETELAH diurutkan Ascending :" << endl;
    A18.TampilData();

    cin.get();
}