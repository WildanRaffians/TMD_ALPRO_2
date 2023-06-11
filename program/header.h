/*
Saya Wildan Hafizh Raffianshar [2202301] mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah 
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include <stdio.h>
#include <string.h>

typedef struct{//bungkusan untuk data list barang
    char id_barang[100];
    char nama_barang[100];
} dataBarang;

typedef struct{//bungkusan untuk data list merk
    char id_pelanggan[100];
    char nama_pelanggan[100];
} dataPelanggan;

typedef struct{//bungkusan untuk data list barang
    char id_transaksi[100];
    char id_pelanggan[100];
    char id_barang[100];
    char waktu_transaksi[100];
    char tanggal_transaksi[100];
} dataTransaksi;


void error1();
void error2();
void errortest();


// deklarasi variabel global
extern int idx;     // index dari karakter terakhir pada kata
extern int temp_idx;     // index dari karakter terakhir pada kata
extern int wlen;    // panjang kata (word length)
extern char cw[50]; // kata saat ini (current word)
extern char temp_cw[50]; // kata saat ini (current word)


// bagian untuk memulai, mereset, dan mengakhiri mesin kata
void start(char str[]);
void reset();
int eop(char str[]);


// bagian memajukan mesin kata
void inc(char str[]);


// bagian mendapatkan variabel global/atribut mesin kata
int getlen();
char *getcw();
int getidx();

int cwlen(char str[]);

void readFile_ListBarang(int *n, dataBarang source[], char filename[], int lihat);
void readFile_ListPelanggan(int *n, dataPelanggan source[], char filename[], int lihat);

void writeToFile_ListBarang(int n, dataBarang source[], char filename[]);
void writeToFile_ListPelanggan(int n, dataPelanggan source[], char filename[]);

void lihat(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100], int q_lainnya);
void tambah(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100], int q_ubah);
void ubah(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100], int q_tambah);
void hapus(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100]);