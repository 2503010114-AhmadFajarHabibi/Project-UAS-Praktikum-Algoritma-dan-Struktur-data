void tambahKonser() {
    if (jumlahKonser >= MAX_KONSER) {
        cout << "[ERROR] Kapasitas maksimum daftar konser telah tercapai!\n";
        return;
    }

    Konser k;
    cout << "\n=== Tambah Jadwal Konser Baru ===\n";
    cout << "Masukkan ID Konser (Angka)  : ";
    cin >> k.id;

    // Validasi apakah ID sudah digunakan
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

    // Set awal kursi terisi menjadi 0
    k.kursiTerisiVIP = 0;
    k.kursiTerisiReguler = 0;

    // Masukkan ke array global
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
        // Melakukan pencarian substring sederhana (case-sensitive)
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
