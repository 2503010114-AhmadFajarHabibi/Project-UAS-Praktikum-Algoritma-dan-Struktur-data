#include "Pemesanan.h"

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
        case 1: // Bubble Sort - ID Ascending
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
            
        case 2: // Selection Sort - ID Descending
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
            
        case 3: // Insertion Sort - Nama A-Z
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
            
        case 4: // Bubble Sort - Nama Z-A
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
            
        case 5: // Selection Sort - Harga VIP Termurah
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
            
        case 6: // Bubble Sort - Harga VIP Termahal
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
