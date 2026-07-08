#include "pencariankonser.h"

void cariKonserLanjutan() {
    if (jumlahKonser == 0) {
        cout << "\n[INFO] Belum ada jadwal konser untuk dicari.\n";
        return;
    }

    cout << "\n=== Pencarian Konser Lanjutan ===\n";
    cout << "1. Cari berdasarkan Venue/Lokasi\n";
    cout << "2. Cari berdasarkan Tanggal\n";
    cout << "3. Cari berdasarkan Rentang Harga VIP\n";
    cout << "Pilih metode pencarian: ";

    int pilihan;
    cin >> pilihan;

    bool ditemukan = false;

    if (pilihan == 1) {
        string keyword;
        cout << "Masukkan venue/lokasi yang dicari: ";
        cin.ignore();
        getline(cin, keyword);

        for (int i = 0; i < jumlahKonser; i++) {
            if (daftarKonser[i].venue.find(keyword) != string::npos) {
                if (!ditemukan) cout << "\n--- Hasil Pencarian ---\n";
                cout << "ID: " << daftarKonser[i].id
                     << " | Nama: " << daftarKonser[i].nama
                     << " | Venue: " << daftarKonser[i].venue
                     << " | Tgl: " << daftarKonser[i].tanggal << "\n";
                ditemukan = true;
            }
        }
    } else if (pilihan == 2) {
        string tanggal;
        cout << "Masukkan tanggal yang dicari (contoh: 2026-12-31): ";
        cin.ignore();
        getline(cin, tanggal);

        for (int i = 0; i < jumlahKonser; i++) {
            if (daftarKonser[i].tanggal.find(tanggal) != string::npos) {
                if (!ditemukan) cout << "\n--- Hasil Pencarian ---\n";
                cout << "ID: " << daftarKonser[i].id
                     << " | Nama: " << daftarKonser[i].nama
                     << " | Tgl: " << daftarKonser[i].tanggal
                     << " | Venue: " << daftarKonser[i].venue << "\n";
                ditemukan = true;
            }
        }
    } else if (pilihan == 3) {
        double hargaMin, hargaMax;
        cout << "Masukkan harga VIP minimum: ";
        cin >> hargaMin;
        cout << "Masukkan harga VIP maksimum: ";
        cin >> hargaMax;

        for (int i = 0; i < jumlahKonser; i++) {
            if (daftarKonser[i].hargaVIP >= hargaMin && daftarKonser[i].hargaVIP <= hargaMax) {
                if (!ditemukan) cout << "\n--- Hasil Pencarian ---\n";
                cout << "ID: " << daftarKonser[i].id
                     << " | Nama: " << daftarKonser[i].nama
                     << " | Harga VIP: Rp " << daftarKonser[i].hargaVIP << "\n";
                ditemukan = true;
            }
        }
    } else {
        cout << "[ERROR] Pilihan tidak valid.\n";
        return;
    }

    if (!ditemukan) {
        cout << "[INFO] Tidak ada konser yang cocok dengan kriteria pencarian.\n";
    }
}
