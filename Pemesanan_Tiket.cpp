#include "Pemesanan.h"

// Tugas: Faiz - Pemesanan Tiket
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
