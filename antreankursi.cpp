#include "SeatQueue.h"

// Constructor
SeatQueue::SeatQueue(int kapasitas) {
    totalKursi = kapasitas;
    kursiTersedia = kapasitas;
}

// Menambah pembeli ke antrean
void SeatQueue::tambahAntrean(string nama) {
    antreanPembeli.push(nama);
    cout << nama << " masuk ke antrean pembelian." << endl;
}

// Melayani pembeli pertama
void SeatQueue::layaniPembeli() {
    if (antreanPembeli.empty()) {
        cout << "Antrean kosong!" << endl;
        return;
    }

    cout << antreanPembeli.front()
         << " sedang dilayani." << endl;

    antreanPembeli.pop();
}

// Menampilkan antrean
void SeatQueue::tampilAntrean() {
    if (antreanPembeli.empty()) {
        cout << "Antrean kosong!" << endl;
        return;
    }

    queue<string> temp = antreanPembeli;

    cout << "\nDaftar Antrean:" << endl;

    while (!temp.empty()) {
        cout << "- " << temp.front() << endl;
        temp.pop();
    }
}

// Pemesanan kursi
bool SeatQueue::pesanKursi(int jumlah) {
    if (jumlah <= kursiTersedia) {
        kursiTersedia -= jumlah;

        cout << jumlah
             << " kursi berhasil dipesan." << endl;

        return true;
    }

    cout << "Kursi tidak mencukupi!" << endl;
    return false;
}

// Menampilkan kapasitas kursi
void SeatQueue::tampilKapasitas() {
    cout << "\nTotal Kursi     : "
         << totalKursi << endl;

    cout << "Kursi Tersedia : "
         << kursiTersedia << endl;

    cout << "Kursi Terisi   : "
         << totalKursi - kursiTersedia << endl;
}

// Getter
int SeatQueue::getKursiTersedia() {
    return kursiTersedia;
}
