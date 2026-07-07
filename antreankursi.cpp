void tambahAntrean(string nama, int jumlahTiket, string jenisTiket) {
        string id = "P" + to_string(nomorAntrean++);
        Pemesan baru;
        baru.nama = nama;
        baru.idPemesanan = id;
        baru.jumlahTiket = jumlahTiket;
        baru.jenisTiket = jenisTiket;
        antrean.push(baru);
        
        cout << "\n✓ Pemesan ditambahkan ke antrean!" << endl;
        cout << "  ID: " << id << " | Nama: " << nama << endl;
        cout << "  Tiket: " << jumlahTiket << " " << jenisTiket << endl;
        cout << "  Posisi antrean: " << antrean.size() << endl;
    }
    
    // Memproses antrean (FIFO)
    void prosesAntrean(ManajemenKursi &kursi) {
        if (antrean.empty()) {
            cout << "\n❌ Antrean kosong!" << endl;
            return;
        }
        
        Pemesan depan = antrean.front();
        cout << "\n=== MEMPROSES ANTREAN ===" << endl;
        cout << "Memproses: " << depan.nama << " (ID: " << depan.idPemesanan << ")" << endl;
        
        if (kursi.pesanKursi(depan.jumlahTiket, depan.jenisTiket)) {
            cout << "✅ Pemesanan berhasil! (" << depan.jumlahTiket 
                 << " tiket " << depan.jenisTiket << ")" << endl;
            antrean.pop();
        } else {
            cout << "❌ Pemesanan gagal! Kursi " << depan.jenisTiket 
                 << " tidak mencukupi." << endl;
            antrean.pop();
        }
    }
    
    // Menampilkan semua antrean
    void tampilkanAntrean() {
        if (antrean.empty()) {
            cout << "\n📋 Antrean kosong." << endl;
            return;
        }
        
        cout << "\n=== DAFTAR ANTREAN (" << antrean.size() << " pemesan) ===" << endl;
        queue<Pemesan> temp = antrean;
        int posisi = 1;
        while (!temp.empty()) {
            Pemesan p = temp.front();
            cout << posisi++ << ". " << p.nama << " (ID: " << p.idPemesanan << ")" << endl;
            cout << "   " << p.jumlahTiket << " tiket " << p.jenisTiket << endl;
            temp.pop();
        }
    }
    
    // Proses semua antrean sekaligus
    void prosesSemuaAntrean(ManajemenKursi &kursi) {
        if (antrean.empty()) {
            cout << "\n❌ Antrean kosong!" << endl;
            return;
        }
        
        cout << "\n=== MEMPROSES SEMUA ANTREAN ===" << endl;
        int berhasil = 0, gagal = 0;
        int total = antrean.size();
        
        while (!antrean.empty()) {
            Pemesan depan = antrean.front();
            cout << "Memproses: " << depan.nama << " (ID: " << depan.idPemesanan << ") ... ";
            
            if (kursi.pesanKursi(depan.jumlahTiket, depan.jenisTiket)) {
                cout << "✅ Berhasil" << endl;
                berhasil++;
            } else {
                cout << "❌ Gagal (kursi tidak cukup)" << endl;
                gagal++;
            }
            antrean.pop();
        }
        
        cout << "\n📊 RINGKASAN:" << endl;
        cout << "   Total: " << total << " pemesan" << endl;
        cout << "   Berhasil: " << berhasil << endl;
        cout << "   Gagal: " << gagal << endl;
    }
    
    bool isEmpty() {
        return antrean.empty();
    }
    
    int getJumlahAntrean() {
        return antrean.size();
    }
};

// ========== BAGIAN MANAJEMEN KAPASITAS KURSI ==========

class ManajemenKursi {
private:
    int totalKapasitas;
    int kursiTerisi;
    vector<int> kursiVIP;
    vector<int> kursiRegular;
    vector<int> kursiEconomy;
    int kapasitasVIP;
    int kapasitasRegular;
    int kapasitasEconomy;
    
public:
    // Constructor
    ManajemenKursi(int total, int vip, int regular, int economy) {
        totalKapasitas = total;
        kursiTerisi = 0;
        kapasitasVIP = vip;
        kapasitasRegular = regular;
        kapasitasEconomy = economy;
        
        kursiVIP.assign(vip, 0);
        kursiRegular.assign(regular, 0);
        kursiEconomy.assign(economy, 0);
    }
    
    // Cek ketersediaan kursi
    bool cekKetersediaan(int jumlah, string jenis) {
        int tersedia = 0;
        if (jenis == "VIP") {
            for (int i = 0; i < kapasitasVIP; i++) {
                if (kursiVIP[i] == 0) tersedia++;
            }
        } else if (jenis == "Regular") {
            for (int i = 0; i < kapasitasRegular; i++) {
                if (kursiRegular[i] == 0) tersedia++;
            }
        } else if (jenis == "Economy") {
            for (int i = 0; i < kapasitasEconomy; i++) {
                if (kursiEconomy[i] == 0) tersedia++;
            }
        }
        return tersedia >= jumlah;
    }
    
    // Pesan kursi
    bool pesanKursi(int jumlah, string jenis) {
        if (!cekKetersediaan(jumlah, jenis)) {
            return false;
        }
        
        int dipesan = 0;
        if (jenis == "VIP") {
            for (int i = 0; i < kapasitasVIP && dipesan < jumlah; i++) {
                if (kursiVIP[i] == 0) {
                    kursiVIP[i] = 1;
                    dipesan++;
                }
            }
        } else if (jenis == "Regular") {
            for (int i = 0; i < kapasitasRegular && dipesan < jumlah; i++) {
                if (kursiRegular[i] == 0) {
                    kursiRegular[i] = 1;
                    dipesan++;
                }
            }
        } else if (jenis == "Economy") {
            for (int i = 0; i < kapasitasEconomy && dipesan < jumlah; i++) {
                if (kursiEconomy[i] == 0) {
                    kursiEconomy[i] = 1;
                    dipesan++;
                }
            }
        }
        
        kursiTerisi += dipesan;
        return true;
    }
    
    // Tampilkan status kursi
    void tampilkanStatusKursi() {
        cout << "\n=== STATUS KAPASITAS KURSI ===" << endl;
        cout << "Total: " << totalKapasitas << " kursi" << endl;
        cout << "Terisi: " << kursiTerisi << " kursi" << endl;
        cout << "Tersedia: " << (totalKapasitas - kursiTerisi) << " kursi" << endl;
        
        // Hitung per kategori
        int vipTersedia = 0, regTersedia = 0, ecoTersedia = 0;
        for (int i = 0; i < kapasitasVIP; i++) {
            if (kursiVIP[i] == 0) vipTersedia++;
        }
        for (int i = 0; i < kapasitasRegular; i++) {
            if (kursiRegular[i] == 0) regTersedia++;
        }
        for (int i = 0; i < kapasitasEconomy; i++) {
            if (kursiEconomy[i] == 0) ecoTersedia++;
        }
        
        cout << "\nDetail per Kategori:" << endl;
        cout << "  VIP     : " << kapasitasVIP << " kursi (" << vipTersedia << " tersedia)" << endl;
        cout << "  Regular : " << kapasitasRegular << " kursi (" << regTersedia << " tersedia)" << endl;
        cout << "  Economy : " << kapasitasEconomy << " kursi (" << ecoTersedia << " tersedia)" << endl;
    }
};
