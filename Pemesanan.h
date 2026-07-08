#ifndef TIKETKONSER_H
#define TIKETKONSER_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_KONSER  = 50;
const int MAX_ANTREAN = 100;
const int MAX_RIWAYAT = 100;

struct Konser {
    int id;
    string nama;
    string tanggal;
    string venue;
    int kapasitasVIP;
    int kapasitasReguler;
    int kursiTerisiVIP;
    int kursiTerisiReguler;
    double hargaVIP;
    double hargaReguler;
};

struct Pemesan {
    string nama;
    string kontak;
    int idKonser;
    string kategoriKursi;
    int jumlahTiket;
};

struct Transaksi {
    int idTransaksi;
    string namaPemesan;
    int idKonser;
    string kategoriKursi;
    int jumlahTiket;
    double totalHarga;
    string waktuTransaksi;
};

extern Konser daftarKonser[MAX_KONSER];
extern int jumlahKonser;

extern Pemesan antreanPembelian[MAX_ANTREAN];
extern int depanAntrean;
extern int belakangAntrean;
extern int jumlahAntrean;

extern Transaksi riwayatTransaksi[MAX_RIWAYAT];
extern int topRiwayat;

extern int counterTransaksi;

bool enqueueAntrean(Pemesan p);
bool dequeueAntrean(Pemesan &keluar);
bool pushRiwayat(Transaksi t);
bool popRiwayat(Transaksi &keluar);

void lihatDaftarKonser();
void pesanTiket();

#endif
