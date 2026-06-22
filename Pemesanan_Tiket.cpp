#include "TiketKonser.h"

TiketKonser::TiketKonser() {
    namaPemesan = "";
    kategori = "";
    jumlahTiket = 0;
    hargaTiket = 0;
    totalHarga = 0;
}

void TiketKonser::inputData() {
    cout << "\n=== PEMESANAN TIKET KONSER ===\n";

    cout << "Nama Pemesan : ";
    getline(cin, namaPemesan);

    cout << "\nKategori Tiket\n";
    cout << "1. VIP      (Rp1.000.000)\n";
    cout << "2. Festival (Rp500.000)\n";
    cout << "3. Reguler  (Rp250.000)\n";

    int pilihan;
    cout << "Pilih kategori (1-3): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            kategori = "VIP";
            hargaTiket = 1000000;
            break;
        case 2:
            kategori = "Festival";
            hargaTiket = 500000;
            break;
        case 3:
            kategori = "Reguler";
            hargaTiket = 250000;
            break;
        default:
            kategori = "Reguler";
            hargaTiket = 250000;
    }

    cout << "Jumlah Tiket : ";
    cin >> jumlahTiket;
}

void TiketKonser::hitungTotal() {
    totalHarga = hargaTiket * jumlahTiket;
}

void TiketKonser::tampilData() {
    cout << "\n===== STRUK PEMESANAN =====\n";
    cout << "Nama Pemesan  : " << namaPemesan << endl;
    cout << "Kategori      : " << kategori << endl;
    cout << "Harga Tiket   : Rp" << hargaTiket << endl;
    cout << "Jumlah Tiket  : " << jumlahTiket << endl;
    cout << "Total Bayar   : Rp" << totalHarga << endl;
    cout << "===========================\n";
}
