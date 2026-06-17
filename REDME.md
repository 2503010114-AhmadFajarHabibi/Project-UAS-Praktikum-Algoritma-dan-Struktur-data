# 🎫 Sistem Pemesanan Tiket Konser

Proyek UAS Praktikum Algoritma dan Struktur Data — Project Based Learning (PjBL)
Studi Kasus #7: **Sistem Pemesanan Tiket Konser**

## 📋 Deskripsi

Aplikasi berbasis C++ yang membantu penyelenggara konser mengelola jadwal konser, pemesanan tiket, antrean pembelian, riwayat transaksi, dan kapasitas kursi penonton.

## 👥 Anggota Kelompok

| Nama | NIM | Peran |
|---|---|---|
| Habibi | `[isi NIM]` | Lead Developer / Ketua |
| Rangga | `[isi NIM]` | Anggota |
| Faiz | `[isi NIM]` | Anggota |
| Rian | `[isi NIM]` | Anggota |
| Pipit | `[isi NIM]` | Anggota |

> Catatan: ganti `[isi NIM]` dengan NIM masing-masing sebelum dikumpulkan.

## ✨ Fitur Aplikasi

1. Manajemen jadwal konser (tambah, ubah, hapus, lihat konser)
2. Pencarian konser (berdasarkan nama/tanggal)
3. Pemesanan tiket
4. Antrean pembelian tiket
5. Manajemen kapasitas & status kursi
6. Riwayat transaksi pembelian
7. Pengurutan data konser/tiket

## 🗂️ Struktur Data & Algoritma yang Digunakan

| Fitur | Struktur Data / Algoritma | Alasan Pemilihan |
|---|---|---|
| Manajemen jadwal konser | Array / Vector | Mudah ditambah, dihapus, dan ditelusuri |
| Pencarian konser | Linear Search / Hash Map | Pencarian cepat berdasarkan ID atau nama |
| Pemesanan tiket | Struct + Array/Vector | Menyimpan relasi data konser, kursi, dan pemesan |
| Antrean pembelian | Queue (FIFO) | Pembeli dilayani sesuai urutan datang |
| Manajemen kapasitas kursi | 2D Array / Map | Mengecek ketersediaan kursi per kategori dengan cepat |
| Riwayat transaksi | Stack (LIFO) | Transaksi terbaru mudah ditampilkan paling atas |
| Pengurutan data | Sorting (Quick Sort / Merge Sort) | Efisien mengurutkan data konser/tiket dalam jumlah besar |

## 🛠️ Pembagian Tugas

| Anggota | Tugas / Fitur yang Dikembangkan |
|---|---|
| **Habibi (Ketua)** | Koordinasi tim, integrasi seluruh modul ke program utama, mengelola repository GitHub, review & merge Pull Request |
| **Rangga** | Manajemen jadwal konser (CRUD) & pencarian konser |
| **Faiz** | Pemesanan tiket |
| **Rian** | Antrean pembelian (Queue) & manajemen kapasitas kursi |
| **Pipit** | Riwayat transaksi & pengurutan data (sorting) |

## 💻 Tech Stack

- Bahasa: **C++**
- Compiler: g++ / MinGW / Visual Studio (sesuaikan dengan yang dipakai tim)

## 🚀 Cara Menjalankan

```bash
git clone <link-repository-ini>
cd <nama-folder-project>
g++ main.cpp -o tiket_konser
./tiket_konser
```

## 🌿 Alur Kerja GitHub (Wajib Diikuti)

1. **Jangan push langsung ke branch `main`.**
2. Setiap anggota bekerja di branch masing-masing, contoh:
   ```bash
   git checkout -b fitur-pemesanan-tiket
   ```
3. Setelah fitur selesai, push branch dan buat **Pull Request** ke `main`.
4. Ketua (Habibi) melakukan review sebelum **merge**.
5. Setiap anggota wajib memiliki minimal 1 commit dan 1 Pull Request yang dapat dibuktikan.

### Penamaan Branch yang Disarankan

| Anggota | Nama Branch |
|---|---|
| Rangga | `fitur-jadwal-konser` |
| Faiz | `fitur-pemesanan-tiket` |
| Rian | `fitur-antrean-kursi` |
| Pipit | `fitur-riwayat-sorting` |

## 📄 Lisensi

Proyek ini dibuat untuk keperluan akademik (UAS Praktikum Algoritma dan Struktur Data).
