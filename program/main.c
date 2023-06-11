#include "header.h"


int main(){
    // deklarasi variabel jumlah perintah dan pita
    int i, n;
    
    char tape[500];
    int tutup = 0;

    dataBarang listBarang[100];
    dataPelanggan listPelanggan[100];
    dataTransaksi listTransaksi[100];

    
    printf("\nSelamat Datang di DBMS UMKM Wildan\n");
    printf("Versi : 0.1 (alpha)\n");

    
    while( tutup == 0){
        int p = 0;
        int q = 0;
        int r = 0;

        printf("\n");
        printf("dbms Wildan> ");
        scanf(" %499[^\n]s", &tape); // ada spasi sebelum simbol %
        // printf("        ---> ");
        printf("\n");

        if(strcmp(tape, "bang udah bang;") == 0){
            tutup = 1;
            printf("system ('exit')\n");
        }
        // readFile_ListBarang(&p, listBarang, "../data/barang.dat");
        // readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat");
        // readFile_ListTransaksi(&r, listTransaksi, "../data/transaksi.dat");

        if(tutup == 0){
            // memulai mesin kata dan membaca pita
            start(tape);
            // printf("%s\n", getcw());
            if(eop(tape) == 1){
                error1();
            }
            else if((strcmp(getcw(), "lihat") == 0) || (strcmp(getcw(), "LIHAT") == 0) ||(strcmp(getcw(), "Lihat") == 0)){
                lihat(tape, listBarang, listPelanggan, 0);
            }

            else if((strcmp(getcw(), "tambah") == 0) || (strcmp(getcw(), "TAMBAH") == 0) ||(strcmp(getcw(), "Tambah") == 0)){
                tambah(tape, listBarang, listPelanggan, 0);
            }

            else if((strcmp(getcw(), "ubah") == 0) || (strcmp(getcw(), "UBAH") == 0) ||(strcmp(getcw(), "Ubah") == 0)){
                ubah(tape, listBarang, listPelanggan, 0);
            }

            else if((strcmp(getcw(), "hapus") == 0) || (strcmp(getcw(), "HAPUS") == 0) ||(strcmp(getcw(), "Hapus") == 0)){
               hapus(tape, listBarang, listPelanggan);
            }

            else{
                error1();
            }
        }
    }
    
    return 0;
}
