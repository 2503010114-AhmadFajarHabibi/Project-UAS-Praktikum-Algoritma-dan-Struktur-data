#include <iostream>
#include <string>
using namespace std;

struct Konser{
    string nama;
    string artis;
    string kota;
    string tanggal;
    int harga;
};

Konser data[10]={
    {"Java Jazz","Tulus","Jakarta","10 Juli 2026",350000},
    {"Soundfest","Sheila On 7","Bekasi","20 Juli 2026",450000},
    {"Synchronize Fest","Dewa 19","Jakarta","5 Agustus 2026",500000},
    {"Pestapora","Hindia","Jakarta","15 September 2026",400000},
    {"Prambanan Jazz","Raisa","Yogyakarta","12 Oktober 2026",550000},
    {"Music Fest","Nadin Amizah","Bandung","25 Juli 2026",300000},
    {"Rock Festival","NOAH","Surabaya","30 Juli 2026",450000},
    {"Summer Concert","Mahalini","Bandung","18 Agustus 2026",350000},
    {"City Music","Bernadya","Tasikmalaya","2 September 2026",250000},
    {"Mega Concert","Juicy Luicy","Bogor","8 Oktober 2026",375000}
};

void tampilSemua(){
    cout<<"==============================\n";
    cout<<"      DAFTAR KONSER\n";
    cout<<"==============================\n";

    for(int i=0;i<10;i++){
        cout<<"\nData ke-"<<i+1<<endl;
        cout<<"Nama Konser : "<<data[i].nama<<endl;
        cout<<"Artis       : "<<data[i].artis<<endl;
        cout<<"Kota        : "<<data[i].kota<<endl;
        cout<<"Tanggal     : "<<data[i].tanggal<<endl;
        cout<<"Harga       : Rp"<<data[i].harga<<endl;
    }
}

void cariKota(){
    string kota;
    bool ketemu=false;

    cout<<"\nMasukkan Kota : ";
    cin.ignore();
    getline(cin,kota);

    cout<<"\nHASIL PENCARIAN\n";

    for(int i=0;i<10;i++){
        if(data[i].kota==kota){
            ketemu=true;
            cout<<"\nNama Konser : "<<data[i].nama<<endl;
            cout<<"Artis       : "<<data[i].artis<<endl;
            cout<<"Tanggal     : "<<data[i].tanggal<<endl;
            cout<<"Harga       : Rp"<<data[i].harga<<endl;
        }
    }

    if(!ketemu){
        cout<<"Konser tidak ditemukan.\n";
    }
}

void cariArtis(){
    string artis;
    bool ketemu=false;

    cout<<"\nMasukkan Nama Artis : ";
    cin.ignore();
    getline(cin,artis);

    cout<<"\nHASIL PENCARIAN\n";

    for(int i=0;i<10;i++){
        if(data[i].artis==artis){
            ketemu=true;
            cout<<"\nNama Konser : "<<data[i].nama<<endl;
            cout<<"Kota        : "<<data[i].kota<<endl;
            cout<<"Tanggal     : "<<data[i].tanggal<<endl;
            cout<<"Harga       : Rp"<<data[i].harga<<endl;
        }
    }

    if(!ketemu){
        cout<<"Artis tidak ditemukan.\n";
    }
}

void hargaMurah(){
    int batas;

    cout<<"\nMasukkan Harga Maksimal : Rp";
    cin>>batas;

    bool ketemu=false;

    for(int i=0;i<10;i++){
        if(data[i].harga<=batas){
            ketemu=true;
            cout<<"\nNama Konser : "<<data[i].nama<<endl;
            cout<<"Artis       : "<<data[i].artis<<endl;
            cout<<"Kota        : "<<data[i].kota<<endl;
            cout<<"Harga       : Rp"<<data[i].harga<<endl;
        }
    }

    if(!ketemu){
        cout<<"Tidak ada konser sesuai harga.\n";
    }
}

int main(){

    int pilih;

    do{

        cout<<"\n=====================================\n";
        cout<<"     APLIKASI PENCARIAN KONSER\n";
        cout<<"=====================================\n";
        cout<<"1. Tampilkan Semua Konser\n";
        cout<<"2. Cari Berdasarkan Kota\n";
        cout<<"3. Cari Berdasarkan Artis\n";
        cout<<"4. Cari Berdasarkan Harga\n";
        cout<<"5. Keluar\n";
        cout<<"=====================================\n";
        cout<<"Pilihan : ";
        cin>>pilih;

        switch(pilih){

        case 1:
            tampilSemua();
            break;

        case 2:
            cariKota();
            break;

        case 3:
            cariArtis();
            break;

        case 4:
            hargaMurah();
            break;

        case 5:
            cout<<"\nTerima kasih telah menggunakan aplikasi.\n";
            break;

        default:
            cout<<"\nPilihan tidak tersedia.\n";
        }

    }while(pilih!=5);

    return 0;
}
