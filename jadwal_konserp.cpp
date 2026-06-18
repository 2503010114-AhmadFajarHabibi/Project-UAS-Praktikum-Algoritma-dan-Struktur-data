#include <iostream>
#include <string>

using namespace std;

struct Konser {
    string id;
    string nama;
    string tanggal;
    string lokasi;
    double hargaTiket;
};

class ManajemenKonser {
private:
    Konser daftarKonser[100];
    int jumlahKonser = 0;

    int cariIndeksBerdasarkanId(const string& id) {
        for (int i = 0; i < jumlahKonser; ++i) {
            if (daftarKonser[i].id == id) {
                return i;
            }
        }
        return -1;
    }

public:
    void tambahKonser(const Konser& k) {
        if (jumlahKonser >= 100) {
            cout << "[ERROR] Kapasitas penuh!\n";
            return;
        }
        if (cariIndeksBerdasarkanId(k.id) != -1) {
            cout << "[ERROR] ID " << k.id << " sudah ada!\n";
            return;
        }
        daftarKonser[jumlahKonser] = k;
        jumlahKonser++;
        cout << "[SUCCESS] Berhasil ditambahkan.\n";
    }

    void tampilkanSemuaKonser() const {
        if (jumlahKonser == 0) {
            cout << "TIDAK ADA JADWAL KONSER TERSEDIA\n";
            return;
        }
        
        for (int i = 0; i < jumlahKonser; ++i) {
            cout << "ID: " << daftarKonser[i].id 
                 << " | Nama: " << daftarKonser[i].nama 
                 << " | Tgl: " << daftarKonser[i].tanggal 
                 << " | Lokasi: " << daftarKonser[i].lokasi 
                 << " | Harga: Rp " << daftarKonser[i].hargaTiket << "\n";
        }
    }

    void ubahKonser(const string& id) {
        int indeks = cariIndeksBerdasarkanId(id);
        if (indeks == -1) {
            cout << "[ERROR] Tidak ditemukan!\n";
            return;
        }

        cout << "Nama Baru   : "; cin.ignore(); getline(cin, daftarKonser[indeks].nama);
        cout << "Tanggal Baru: "; getline(cin, daftarKonser[indeks].tanggal);
        cout << "Lokasi Baru : "; getline(cin, daftarKonser[indeks].lokasi);
        cout << "Harga Baru  : "; cin >> daftarKonser[indeks].hargaTiket;

        cout << "[SUCCESS] Berhasil diperbarui.\n";
    }

    void hapusKonser(const string& id) {
        int indeks = cariIndeksBerdasarkanId(id);
        if (indeks == -1) {
            cout << "[ERROR] Tidak ditemukan!\n";
            return;
        }

        for (int i = indeks; i < jumlahKonser - 1; ++i) {
            daftarKonser[i] = daftarKonser[i + 1];
        }
        jumlahKonser--;
        cout << "[SUCCESS] Berhasil dihapus.\n";
    }

    void cariKonserBerdasarkanNama(const string& keyword) const {
        bool ditemukan = false;
        for (int i = 0; i < jumlahKonser; ++i) {
            if (daftarKonser[i].nama == keyword) {
                cout << "ID: " << daftarKonser[i].id 
                     << " | Nama: " << daftarKonser[i].nama 
                     << " | Tgl: " << daftarKonser[i].tanggal 
                     << " | Harga: Rp " << daftarKonser[i].hargaTiket << "\n";
                ditemukan = true;
            }
        }
        if (!ditemukan) {
            cout << "Tidak ditemukan.\n";
        }
    }
};
