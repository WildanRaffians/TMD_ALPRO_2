<h1>Dibuat untuk memenuhi Tugas Masa Depan Mata (TMD) Kuliah Algortima dan Pemrograman 2</h1>
<br>
Terdapat 2 Folder
<li>Folder Data untuk menampung data yang dapat diolah (dilihat, ditambah, diubah, dihapus)</ul>
<li>Folder Program berisi Program DBMS sederhana untuk mengolah data tersebut</ul>
<br>
<h2>Data</h2>
Terdapat 3 Data/Tabel
<li>Tabel Barang (kode_barang, nama_barang)</li>
<li>Tabel Pelanggan (kode_pelanggan, nama_pelanggan)</li>
<li>Tabel Transaksi (kode_transaksi, kode_pelanggan, kode_barang, waktu_transaksi, tanggal_transaski)</li>
<br>
<h2>Program</h2>
Terdapat 3 File
<li>Header -> Untuk mendeklarasikan struktur, tipe data dan fungsi yang ada</li>
<li>Mesin -> Berisi implementasi fungsi-fungsi yang dideklarasikan di dalam file header</li>
<li>Untuk mengatur alur program DBMS dengan memanggil fungsi-fungsi yang diperlukan dari file mesin</li>
<br>
<h2>Cara Menjalankan</h2>
<li>Download repo</li>
<li>Buka CMD di folder program</li>
<li>Ketik perintah gcc *.c -o a&&a pada CMD</li>
<li>Lakukan pengolahan data</li>
<br>
<h2>Perintah yang diterima</h2>
<li>lihat (nama tabel) ; -> Perintah untuk melihat data (contoh : lihat barang;)</li>
<li>tambah (nama tabel) (data baru) ; -> Perintah untuk menambah data baru (contoh : tambah barang B020 Sarung_Tinju;)</li>
<li>ubah (nama tabel) (kode data) (data baru) ; -> Perintah untuk Mengubah data (contoh : ubah barang B020 Sarung_Tinju_Merah;)</li>
<li>hapus (nama tabel) (kode data) ; -> Perintah untuk menghapus data (contoh : hapus barang B020;) </li>
<br>
Bisa juga melakukan 2 perintah sekaligus
<li>lihat ubah -> melihat data sebelum diubah lalu mengubah data. Lanjutkan query seperti query ubah sebelumnya</li>
<li>lihat tambah -> melihat data sebelum ditambah lalu menambah data. Lanjutkan query seperti query tambah sebelumnya</li>
<li>lihat hapus -> melihat data sebelum dihapus lalu menghapus data. Lanjutkan query seperti query hapus sebelumnya</li>
<li>ubah tambah -> Lanjutkan seperti query ubah/tambah. Jika kode barang tidak ada pada tabel maka akan menjalankan perintah tambah, jika kode barang sudah ada pada tabel maka akan mengubah data</li>
<br>
Bisa melakukan perintah join dengan menyebutkan table mana saja yang akan di join:
<li>lihat barang transaksi; -> Akan menampilkan data transaksi tetapi pada kolom kode barang akan menampilkan nama barang</li>
<li>lihat pelanggan transaski</li>
<li>lihat pelanggan transaski barang</li>
