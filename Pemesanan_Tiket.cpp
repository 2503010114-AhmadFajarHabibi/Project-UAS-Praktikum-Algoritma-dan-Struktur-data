void tampilJudul() {
    cout << "======================================" << endl;
    cout << "      PEMESANAN TIKET KONSER" << endl;
    cout << "======================================" << endl;
}

// Input Nama
void inputNama(string &nama) {
    cout << "Masukkan Nama Pemesan : ";
    getline(cin, nama);
}

// Menampilkan Menu
void tampilMenu() {
    cout << "\nDaftar Kategori Tiket" << endl;
    cout << "1. VIP      : Rp1.000.000" << endl;
    cout << "2. Festival : Rp500.000" << endl;
    cout << "3. Reguler  : Rp250.000" << endl;
}

// Memilih Tiket
void pilihTiket(int &pilihan, int &harga) {
    cout << "\nPilih Kategori Tiket (1-3): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            harga = 1000000;
            break;
        case 2:
            harga = 500000;
            break;
        case 3:
            harga = 250000;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            exit(0);
    }
}

// Input Jumlah Tiket
void inputJumlah(int &jumlah) {
    cout << "Jumlah Tiket : ";
    cin >> jumlah;
}

// Menghitung Total
void hitungTotal(int harga, int jumlah, int &total) {
    total = harga * jumlah;
}

// Cetak Struk
void cetakStruk(string nama, int pilihan, int harga, int jumlah, int total) {
    cout << "\n======================================" << endl;
    cout << "          STRUK PEMESANAN" << endl;
    cout << "======================================" << endl;
    cout << "Nama Pemesan : " << nama << endl;

    cout << "Kategori     : ";
    if (pilihan == 1)
        cout << "VIP" << endl;
    else if (pilihan == 2)
        cout << "Festival" << endl;
    else
        cout << "Reguler" << endl;

    cout << "Harga Tiket  : Rp" << harga << endl;
    cout << "Jumlah Tiket : " << jumlah << endl;
    cout << "Total Bayar  : Rp" << total << endl;
    cout << "======================================" << endl;
    cout << "Terima kasih telah memesan tiket konser!" << endl;
}
