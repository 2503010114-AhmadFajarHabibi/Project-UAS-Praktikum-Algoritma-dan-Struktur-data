#include <iostream>
#include <string>
#include "Pemesanan.h"
#include "antriankursi.h"
#include "pencariankonser.h"
using namespace std;

Konser daftarKonser[MAX_KONSER];
int jumlahKonser = 0;

Pemesan antreanPembelian[MAX_ANTREAN];
int depanAntrean = 0;
int belakangAntrean = -1;
int jumlahAntrean = 0;

Transaksi riwayatTransaksi[MAX_RIWAYAT];
int topRiwayat = -1;

int counterTransaksi = 0;

bool enqueueAntrean(Pemesan p) {
    if (jumlahAntrean >= MAX_ANTREAN) {
        cout << "Antrean penuh!\n";
        return false;
    }
    belakangAntrean = (belakangAntrean + 1) % MAX_ANTREAN;
    antreanPembelian[belakangAntrean] = p;
    jumlahAntrean++;
    return true;
}

bool dequeueAntrean(Pemesan &keluar) {
    if (jumlahAntrean == 0) {
        cout << "Antrean kosong!\n";
        return false;
    }
    keluar = antreanPembelian[depanAntrean];
    depanAntrean = (depanAntrean + 1) % MAX_ANTREAN;
    jumlahAntrean--;
    return true;
}

bool pushRiwayat(Transaksi t) {
    if (topRiwayat >= MAX_RIWAYAT - 1) {
        cout << "Riwayat transaksi penuh!\n";
        return false;
    }
    riwayatTransaksi[++topRiwayat] = t;
    return true;
}

bool popRiwayat(Transaksi &keluar) {
    if (topRiwayat < 0) {
        cout << "Riwayat transaksi kosong!\n";
        return false;
    }
    keluar = riwayatTransaksi[topRiwayat--];
    return true;
}

#include "jadwal_konserp.cpp"           // Tugas: Rangga  -> tambahKonser(), lihatDaftarKonser(), cariKonser()
#include "Pemesanan_Tiket.cpp"          // Tugas: Faiz    -> pesanTiket()
#include "antreankursi.cpp"             // Tugas: Rian    -> prosesAntreanPembelian(), cekKapasitasKursi()
#include "PencarianKonser.cpp"          // Tugas: Raesha  -> cariKonserLanjutan()
#include "riwayatTransaksi_sorting.cpp" // Tugas: Pipit   -> lihatRiwayatTransaksi(), urutkanDataKonser()
void tampilkanMenuUtama();
void inisialisasiDataDummy();


// ================= MENU & MAIN =================

void inisialisasiDataDummy() {
    Konser k1;
    k1.id = 1;
    k1.nama = "Konser Tahun Baru";
    k1.tanggal = "2026-12-31";
    k1.venue = "GBK Senayan";
    k1.kapasitasVIP = 100;
    k1.kapasitasReguler = 500;
    k1.kursiTerisiVIP = 0;
    k1.kursiTerisiReguler = 0;
    k1.hargaVIP = 1500000;
    k1.hargaReguler = 500000;

    daftarKonser[jumlahKonser] = k1;
    jumlahKonser++;
}

void tampilkanMenuUtama() {
    cout << "\n==========================================\n";
    cout << "   SISTEM PEMESANAN TIKET KONSER\n";
    cout << "==========================================\n";
    cout << "1. Lihat Daftar Konser\n";
    cout << "2. Tambah Konser (Admin)\n";
    cout << "3. Cari Konser\n";
    cout << "4. Pesan Tiket\n";
    cout << "5. Proses Antrean Pembelian\n";
    cout << "6. Cek Kapasitas Kursi\n";
    cout << "7. Lihat Riwayat Transaksi\n";
    cout << "8. Urutkan Data Konser\n";
    cout << "9. Pencarian Lanjutan (Venue/Tanggal/Harga)\n";
    cout << "0. Keluar\n";
    cout << "==========================================\n";
    cout << "Pilih menu: ";
}

int main() {
    inisialisasiDataDummy();

    int pilihan;
    do {
        tampilkanMenuUtama();
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(10000, '\n');
            pilihan = -1;
            cout << "Input tidak valid! Masukkan angka menu yang benar.\n";
            continue;
        }

        switch (pilihan) {
            case 1: lihatDaftarKonser(); break;
            case 2: tambahKonser(); break;
            case 3: cariKonser(); break;
            case 4: pesanTiket(); break;
            case 5: prosesAntreanPembelian(); break;
            case 6: cekKapasitasKursi(); break;
            case 7: lihatRiwayatTransaksi(); break;
            case 8: urutkanDataKonser(); break;
            case 9: cariKonserLanjutan(); break;
            case 0: cout << "Terima kasih telah menggunakan sistem ini.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
