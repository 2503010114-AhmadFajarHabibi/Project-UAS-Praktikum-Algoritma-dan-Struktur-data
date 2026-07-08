#include "antriankursi.h"
#include <sstream>

void prosesAntreanPembelian() {
    if (jumlahAntrean == 0) {
        cout << "\n[INFO] Antrean pembelian kosong. Tidak ada yang perlu diproses.\n";
        return;
    }

    Pemesan p;
    if (!dequeueAntrean(p)) {
        return;
    }

    cout << "\n=== Memproses Antrean Pembelian ===\n";
    cout << "Nama Pemesan : " << p.nama << "\n";
    cout << "Kontak       : " << p.kontak << "\n";
    cout << "Kategori     : " << p.kategoriKursi << "\n";
    cout << "Jumlah Tiket : " << p.jumlahTiket << "\n";

    int idx = -1;
    for (int i = 0; i < jumlahKonser; i++) {
        if (daftarKonser[i].id == p.idKonser) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "[ERROR] Konser dengan ID " << p.idKonser << " sudah tidak ada. Pesanan dibatalkan.\n";
        return;
    }

    bool isVIP = (p.kategoriKursi == "VIP");
    int sisaKursi = isVIP
        ? (daftarKonser[idx].kapasitasVIP - daftarKonser[idx].kursiTerisiVIP)
        : (daftarKonser[idx].kapasitasReguler - daftarKonser[idx].kursiTerisiReguler);

    if (p.jumlahTiket > sisaKursi) {
        cout << "[ERROR] Kursi " << p.kategoriKursi << " tidak cukup saat diproses (sisa: "
             << sisaKursi << "). Pesanan dibatalkan.\n";
        return;
    }

    double hargaSatuan = isVIP ? daftarKonser[idx].hargaVIP : daftarKonser[idx].hargaReguler;
    double totalHarga = hargaSatuan * p.jumlahTiket;

    if (isVIP) {
        daftarKonser[idx].kursiTerisiVIP += p.jumlahTiket;
    } else {
        daftarKonser[idx].kursiTerisiReguler += p.jumlahTiket;
    }

Transaksi t;
    t.idTransaksi = ++counterTransaksi;
    t.namaPemesan = p.nama;
    t.idKonser = p.idKonser;
    t.kategoriKursi = p.kategoriKursi;
    t.jumlahTiket = p.jumlahTiket;
    t.totalHarga = totalHarga;
     
    ostringstream oss;
    oss << "Transaksi ke-" << t.idTransaksi;
    t.waktuTransaksi = oss.str();
    
    pushRiwayat(t);

    cout << "\n[SUCCESS] Transaksi #" << t.idTransaksi << " berhasil diproses!\n";
    cout << "Total Bayar  : Rp " << totalHarga << "\n";
    cout << "Sisa antrean : " << jumlahAntrean << " pesanan lagi.\n";
}

void cekKapasitasKursi() {
    if (jumlahKonser == 0) {
        cout << "\n[INFO] Belum ada jadwal konser.\n";
        return;
    }

    cout << "\n=================================================================================\n";
    cout << "                              KAPASITAS KURSI KONSER                              \n";
    cout << "=================================================================================\n";
    for (int i = 0; i < jumlahKonser; i++) {
        int sisaVIP = daftarKonser[i].kapasitasVIP - daftarKonser[i].kursiTerisiVIP;
        int sisaReguler = daftarKonser[i].kapasitasReguler - daftarKonser[i].kursiTerisiReguler;

        cout << "ID Konser   : " << daftarKonser[i].id << " - " << daftarKonser[i].nama << "\n";
        cout << "  VIP       : " << daftarKonser[i].kursiTerisiVIP << " / " << daftarKonser[i].kapasitasVIP
             << " terisi  (sisa: " << sisaVIP << ")\n";
        cout << "  Reguler   : " << daftarKonser[i].kursiTerisiReguler << " / " << daftarKonser[i].kapasitasReguler
             << " terisi  (sisa: " << sisaReguler << ")\n";

        if (sisaVIP == 0 && sisaReguler == 0) {
            cout << "  Status    : SOLD OUT\n";
        } else if (sisaVIP <= 5 || sisaReguler <= 5) {
            cout << "  Status    : HAMPIR PENUH\n";
        } else {
            cout << "  Status    : TERSEDIA\n";
        }
        cout << "---------------------------------------------------------------------------------\n";
    }

    cout << "\nAntrean pembelian saat ini: " << jumlahAntrean << " orang menunggu diproses.\n";
}
