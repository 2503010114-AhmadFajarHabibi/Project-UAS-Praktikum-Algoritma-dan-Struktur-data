#include <iostream>
#include <string>
#include "Pemesanan.h"
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

void tambahKonser();                  // Tugas: Rangga
void lihatDaftarKonser();
void cariKonser();                    // Tugas: Rangga

void pesanTiket();                    // Tugas: Faiz

void prosesAntreanPembelian();        // Tugas: Rian
void cekKapasitasKursi();             // Tugas: Rian

void lihatRiwayatTransaksi();         // Tugas: Pipit
void urutkanDataKonser();             // Tugas: Pipit

void tampilkanMenuUtama();
void inisialisasiDataDummy();

// ================= RANGGA: Manajemen Jadwal Konser (CRUD) =================

void tambahKonser() {
    if (jumlahKonser >= MAX_KONSER) {
        cout << "[ERROR] Kapasitas maksimum daftar konser telah tercapai!\n";
        return;
    }

    Konser k;
    cout << "\n=== Tambah Jadwal Konser Baru ===\n";
    cout << "Masukkan ID Konser (Angka)  : ";
    cin >> k.id;

    for (int i = 0; i < jumlahKonser; i++) {
        if (daftarKonser[i].id == k.id) {
            cout << "[ERROR] Gagal! ID Konser " << k.id << " sudah terdaftar.\n";
            return;
        }
    }

    cout << "Masukkan Nama Konser        : ";
    cin.ignore();
    getline(cin, k.nama);
    cout << "Masukkan Tanggal Konser     : ";
    getline(cin, k.tanggal);
    cout << "Masukkan Venue/Lokasi       : ";
    getline(cin, k.venue);
    cout << "Kapasitas Tiket VIP         : ";
    cin >> k.kapasitasVIP;
    cout << "Harga Tiket VIP             : ";
    cin >> k.hargaVIP;
    cout << "Kapasitas Tiket Reguler     : ";
    cin >> k.kapasitasReguler;
    cout << "Harga Tiket Reguler         : ";
    cin >> k.hargaReguler;

    k.kursiTerisiVIP = 0;
    k.kursiTerisiReguler = 0;

    daftarKonser[jumlahKonser] = k;
    jumlahKonser++;

    cout << "[SUCCESS] Jadwal konser \"" << k.nama << "\" berhasil ditambahkan!\n";
}

void lihatDaftarKonser() {
    if (jumlahKonser == 0) {
        cout << "\n[INFO] Belum ada jadwal konser yang tersedia.\n";
        return;
    }

    cout << "\n=================================================================================\n";
    cout << "                               DAFTAR JADWAL KONSER                              \n";
    cout << "=================================================================================\n";
    for (int i = 0; i < jumlahKonser; i++) {
        cout << "ID Konser    : " << daftarKonser[i].id << "\n";
        cout << "Nama Konser  : " << daftarKonser[i].nama << "\n";
        cout << "Tanggal      : " << daftarKonser[i].tanggal << "\n";
        cout << "Venue        : " << daftarKonser[i].venue << "\n";
        cout << "Tiket VIP    : Rp " << daftarKonser[i].hargaVIP << " (Tersedia: " << (daftarKonser[i].kapasitasVIP - daftarKonser[i].kursiTerisiVIP) << ")\n";
        cout << "Tiket Reguler: Rp " << daftarKonser[i].hargaReguler << " (Tersedia: " << (daftarKonser[i].kapasitasReguler - daftarKonser[i].kursiTerisiReguler) << ")\n";
        cout << "---------------------------------------------------------------------------------\n";
    }
}

void cariKonser() {
    if (jumlahKonser == 0) {
        cout << "\n[INFO] Belum ada jadwal konser untuk dicari.\n";
        return;
    }

    string keyword;
    cout << "\n=== Pencarian Konser (Linear Search) ===\n";
    cout << "Masukkan nama konser yang dicari: ";
    cin.ignore();
    getline(cin, keyword);

    bool ditemukan = false;
    for (int i = 0; i < jumlahKonser; i++) {
        if (daftarKonser[i].nama.find(keyword) != string::npos) {
            if (!ditemukan) {
                cout << "\n--- Hasil Pencarian ---\n";
            }
            cout << "ID: " << daftarKonser[i].id
                 << " | Nama: " << daftarKonser[i].nama
                 << " | Tgl: " << daftarKonser[i].tanggal
                 << " | Venue: " << daftarKonser[i].venue << "\n";
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "[INFO] Konser dengan nama \"" << keyword << "\" tidak ditemukan.\n";
    }
}

// ================= FAIZ & RIAN: masih menyusul (langkah 2 & 3) =================

void pesanTiket() {
    if (jumlahKonser == 0) {
        cout << "\n[INFO] Belum ada jadwal konser yang bisa dipesan.\n";
        return;
    }

    lihatDaftarKonser();

    int idKonser;
    cout << "\n=== Pesan Tiket ===\n";
    cout << "Masukkan ID Konser yang ingin dipesan: ";
    cin >> idKonser;

    int idx = -1;
    for (int i = 0; i < jumlahKonser; i++) {
        if (daftarKonser[i].id == idKonser) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "[ERROR] Konser dengan ID " << idKonser << " tidak ditemukan.\n";
        return;
    }

    Pemesan p;
    p.idKonser = idKonser;

    cout << "Masukkan Nama Pemesan       : ";
    cin.ignore();
    getline(cin, p.nama);
    cout << "Masukkan Nomor Kontak       : ";
    getline(cin, p.kontak);

    cout << "Pilih Kategori Kursi (1=VIP, 2=Reguler): ";
    int kategori;
    cin >> kategori;

    if (kategori == 1) {
        p.kategoriKursi = "VIP";
    } else if (kategori == 2) {
        p.kategoriKursi = "Reguler";
    } else {
        cout << "[ERROR] Kategori tidak valid.\n";
        return;
    }

    cout << "Masukkan Jumlah Tiket       : ";
    cin >> p.jumlahTiket;

    if (p.jumlahTiket <= 0) {
        cout << "[ERROR] Jumlah tiket harus lebih dari 0.\n";
        return;
    }

    int sisaKursi = (kategori == 1)
        ? (daftarKonser[idx].kapasitasVIP - daftarKonser[idx].kursiTerisiVIP)
        : (daftarKonser[idx].kapasitasReguler - daftarKonser[idx].kursiTerisiReguler);

    if (p.jumlahTiket > sisaKursi) {
        cout << "[ERROR] Kursi tidak cukup! Sisa kursi " << p.kategoriKursi << ": " << sisaKursi << "\n";
        return;
    }

    if (enqueueAntrean(p)) {
        cout << "[SUCCESS] Pesanan atas nama \"" << p.nama << "\" berhasil masuk antrean pembelian.\n";
        cout << "Silakan pilih menu 5 (Proses Antrean Pembelian) untuk memproses pesanan ini.\n";
    }
}

void prosesAntreanPembelian() {
    cout << "[TODO - Rian]\n";
}

void cekKapasitasKursi() {
    cout << "[TODO - Rian]\n";
}

// ================= PIPIT: Riwayat Transaksi & Sorting =================

void lihatRiwayatTransaksi() {
    if (topRiwayat < 0) {
        cout << "\n=== RIWAYAT TRANSAKSI ===\n";
        cout << "Belum ada transaksi.\n";
        return;
    }

    cout << "\n=== RIWAYAT TRANSAKSI ===\n";
    cout << "========================================\n";
    for (int i = topRiwayat; i >= 0; i--) {
        cout << "ID Transaksi: " << riwayatTransaksi[i].idTransaksi << endl;
        cout << "Nama Pemesan : " << riwayatTransaksi[i].namaPemesan << endl;
        cout << "ID Konser    : " << riwayatTransaksi[i].idKonser << endl;
        cout << "Kategori     : " << riwayatTransaksi[i].kategoriKursi << endl;
        cout << "Jumlah Tiket : " << riwayatTransaksi[i].jumlahTiket << endl;
        cout << "Total Harga  : Rp " << riwayatTransaksi[i].totalHarga << endl;
        cout << "Waktu        : " << riwayatTransaksi[i].waktuTransaksi << endl;
        cout << "----------------------------------------\n";
    }
    cout << "Total Transaksi: " << (topRiwayat + 1) << endl;
}

void urutkanDataKonser() {
    if (jumlahKonser == 0) {
        cout << "Tidak ada data konser untuk diurutkan.\n";
        return;
    }

    cout << "\n=== PENGURUTAN DATA KONSER ===\n";
    cout << "1. Urutkan berdasarkan ID (Ascending)\n";
    cout << "2. Urutkan berdasarkan ID (Descending)\n";
    cout << "3. Urutkan berdasarkan Nama (A-Z)\n";
    cout << "4. Urutkan berdasarkan Nama (Z-A)\n";
    cout << "5. Urutkan berdasarkan Harga VIP (Termurah-Termahal)\n";
    cout << "6. Urutkan berdasarkan Harga VIP (Termahal-Termurah)\n";
    cout << "Pilih metode sorting: ";

    int pilihanSort;
    cin >> pilihanSort;

    Konser temp;

    switch (pilihanSort) {
        case 1:
            for (int i = 0; i < jumlahKonser - 1; i++) {
                for (int j = 0; j < jumlahKonser - i - 1; j++) {
                    if (daftarKonser[j].id > daftarKonser[j + 1].id) {
                        temp = daftarKonser[j];
                        daftarKonser[j] = daftarKonser[j + 1];
                        daftarKonser[j + 1] = temp;
                    }
                }
            }
            cout << "Data berhasil diurutkan berdasarkan ID (Ascending)!\n";
            break;

        case 2:
            for (int i = 0; i < jumlahKonser - 1; i++) {
                int maxIdx = i;
                for (int j = i + 1; j < jumlahKonser; j++) {
                    if (daftarKonser[j].id > daftarKonser[maxIdx].id) {
                        maxIdx = j;
                    }
                }
                if (maxIdx != i) {
                    temp = daftarKonser[i];
                    daftarKonser[i] = daftarKonser[maxIdx];
                    daftarKonser[maxIdx] = temp;
                }
            }
            cout << "Data berhasil diurutkan berdasarkan ID (Descending)!\n";
            break;

        case 3:
            for (int i = 1; i < jumlahKonser; i++) {
                Konser key = daftarKonser[i];
                int j = i - 1;
                while (j >= 0 && daftarKonser[j].nama > key.nama) {
                    daftarKonser[j + 1] = daftarKonser[j];
                    j--;
                }
                daftarKonser[j + 1] = key;
            }
            cout << "Data berhasil diurutkan berdasarkan Nama (A-Z)!\n";
            break;

        case 4:
            for (int i = 0; i < jumlahKonser - 1; i++) {
                for (int j = 0; j < jumlahKonser - i - 1; j++) {
                    if (daftarKonser[j].nama < daftarKonser[j + 1].nama) {
                        temp = daftarKonser[j];
                        daftarKonser[j] = daftarKonser[j + 1];
                        daftarKonser[j + 1] = temp;
                    }
                }
            }
            cout << "Data berhasil diurutkan berdasarkan Nama (Z-A)!\n";
            break;

        case 5:
            for (int i = 0; i < jumlahKonser - 1; i++) {
                int minIdx = i;
                for (int j = i + 1; j < jumlahKonser; j++) {
                    if (daftarKonser[j].hargaVIP < daftarKonser[minIdx].hargaVIP) {
                        minIdx = j;
                    }
                }
                if (minIdx != i) {
                    temp = daftarKonser[i];
                    daftarKonser[i] = daftarKonser[minIdx];
                    daftarKonser[minIdx] = temp;
                }
            }
            cout << "Data berhasil diurutkan berdasarkan Harga VIP (Termurah-Termahal)!\n";
            break;

        case 6:
            for (int i = 0; i < jumlahKonser - 1; i++) {
                for (int j = 0; j < jumlahKonser - i - 1; j++) {
                    if (daftarKonser[j].hargaVIP < daftarKonser[j + 1].hargaVIP) {
                        temp = daftarKonser[j];
                        daftarKonser[j] = daftarKonser[j + 1];
                        daftarKonser[j + 1] = temp;
                    }
                }
            }
            cout << "Data berhasil diurutkan berdasarkan Harga VIP (Termahal-Termurah)!\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            return;
    }

    cout << "\nHasil Pengurutan:\n";
    lihatDaftarKonser();
}

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
    cout << "0. Keluar\n";
    cout << "==========================================\n";
    cout << "Pilih menu: ";
}

int main() {
    inisialisasiDataDummy();

    int pilihan;
    do {
        tampilkanMenuUtama();
        cin >> pilihan;

        switch (pilihan) {
            case 1: lihatDaftarKonser(); break;
            case 2: tambahKonser(); break;
            case 3: cariKonser(); break;
            case 4: pesanTiket(); break;
            case 5: prosesAntreanPembelian(); break;
            case 6: cekKapasitasKursi(); break;
            case 7: lihatRiwayatTransaksi(); break;
            case 8: urutkanDataKonser(); break;
            case 0: cout << "Terima kasih telah menggunakan sistem ini.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
