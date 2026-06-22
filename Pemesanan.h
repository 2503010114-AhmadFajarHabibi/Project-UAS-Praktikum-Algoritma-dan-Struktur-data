
#ifndef TIKETKONSER_H
#define TIKETKONSER_H

#include <iostream>
#include <string>

using namespace std;

class TiketKonser {
private:
    string namaPemesan;
    string kategori;
    int jumlahTiket;
    int hargaTiket;
    int totalHarga;

public:
    TiketKonser();

    void inputData();
    void hitungTotal();
    void tampilData();
};

#endif
