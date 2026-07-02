#include <iostream>
#include <string>

using namespace std;

int main() {
    string nama;
    int pilihan, jumlah;
    int harga = 0;
    int total;

    cout << "======================================" << endl;
    cout << "      PEMESANAN TIKET KONSER" << endl;
    cout << "======================================" << endl;

    cout << "Masukkan Nama Pemesan : ";
    getline(cin, nama);

    cout << "\nDaftar Kategori Tiket" << endl;
    cout << "1. VIP      : Rp1.000.000" << endl;
    cout << "2. Festival : Rp500.000" << endl;
    cout << "3. Reguler  : Rp250.000" << endl;

    cout << "\nPilih Kategori Tiket (1-3): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            harga = 1000000;
            break;
        case 2:
            harga = 500000;
            break;
        case 3:
            harga = 250000;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    cout << "Jumlah Tiket : ";
    cin >> jumlah;

    total = harga * jumlah;

    cout << "\n======================================" << endl;
    cout << "          STRUK PEMESANAN" << endl;
    cout << "======================================" << endl;
    cout << "Nama Pemesan : " << nama << endl;

    cout << "Kategori     : ";
    if (pilihan == 1)
        cout << "VIP" << endl;
    else if (pilihan == 2)
        cout << "Festival" << endl;
    else
        cout << "Reguler" << endl;

    cout << "Harga Tiket  : Rp" << harga << endl;
    cout << "Jumlah Tiket : " << jumlah << endl;
    cout << "Total Bayar  : Rp" << total << endl;
    cout << "======================================" << endl;
    cout << "Terima kasih telah memesan tiket konser!" << endl;

    return 0;
}
