#ifndef SEATQUEUE_H
#define SEATQUEUE_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class SeatQueue {
private:
    queue<string> antreanPembeli;
    int totalKursi;
    int kursiTersedia;

public:
    // Constructor
    SeatQueue(int kapasitas);

    // Queue Pembelian
    void tambahAntrean(string nama);
    void layaniPembeli();
    void tampilAntrean();

    // Manajemen Kursi
    bool pesanKursi(int jumlah);
    void tampilKapasitas();

    // Getter
    int getKursiTersedia();
};

#endif
