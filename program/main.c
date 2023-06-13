/*
Saya Wildan Hafizh Raffianshar [2202301] mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah 
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"//deklarasi header file

int main(){
    
    //deklarasi variabel
    char masukan[10][500]; //wadah masukan user
    char tape[500];        //pita string
    int panjang_full = 0;  //panjang seluruh masukan, panjang pita
    int baris = 0;         //jumlah baris masukan
    int tutup = 0;         //indikator penutup
    int akhiran = 0;       //index sebagai indikator karakter terakhir pada masukan
    int index_tape = 0;    //index tape

    //deklarasi bungkusan
    dataBarang listBarang[100];        //penampung data barang
    dataPelanggan listPelanggan[100];  //penampung data pelanggan
    dataTransaksi listTransaksi[100];  //penampung data transaksi

    //tampilan awal
    printf("\nSelamat Datang di DBMS UMKM Pakaian Raffians\n");
    printf("Versi : 0.9 (beta)\n");

    //proses/system berlangsung selama 'tutup' bernilai nol
    while( tutup == 0){

        //me 'reset' isi tape
        for(int i=0; i<panjang_full; i++){
            tape[i] = '\0';
        }

        baris = 0;          //baris diset nol setiap berulang
        panjang_full = 0;   //panjang tape diset nol setiap berulang
        akhiran = 0;        //index sebagai indikator karakter terakhir pada masukan diset nol setiap berulang
        index_tape = 0;     //index tape diset nol setiap berulang

        //meminta masukan user
        printf("\n");
        printf("dbms Raffians> ");   
        scanf(" %499[^\n]s", &masukan[baris]);

        akhiran = cwlen(masukan[baris])-1;//menampung index terakhir pada masukan
        
        //memasukkan 'masukan' ke 'tape'
        for(int j = 0; j < akhiran+1; j++){
            tape[index_tape] = masukan[baris][j];
            index_tape++;
        }
        panjang_full+=(akhiran+1);//panjang tape bertambah (+1 untuk spasi)

        //mengecek apakah karakter terakhir merupakan ';' (eop) dan baris tidak lebih dari 10
        //jika tidak maka akan terjadi looping
        while(masukan[baris][akhiran] != ';' && baris < 10){
            
            tape[index_tape] = ' '; //memasukkan spasi ke dalam tape (baris baru berarti menambah spasi)
            index_tape++;           //index tape bergeser

            baris++;//baris baru
            
            if(baris == 10){
                //jika baris bernilai 10
                //tampilkan error
                printf("\n\n<<<system error>>>\n"); 
                tutup = 1;          //proses/system berakhir
            }
            else{
                //jika baris belum bernilai 10
                //meminta masukan user
                printf("\n");
                printf("        ---> ");
                scanf(" %499[^\n]s", &masukan[baris]);

                akhiran = cwlen(masukan[baris])-1;  //menampung index terakhir pada masukan
                panjang_full+=(akhiran+1)+1;        //panjang tape bertambah
                
                //memasukkan 'masukan' ke 'tape'
                for(int j = 0; j < akhiran+1; j++){
                    tape[index_tape] = masukan[baris][j];
                    index_tape++;
                }
            }
            
        }

        //jika system belum berakhir (nilai 'tutup' masih bernilai nol)
        if(tutup == 0){
            // memulai mesin kata dan membaca pita
            start(tape);
            
            //jika masukan perintah 'lihat'
            if((strcmp(getcw(), "lihat") == 0) || (strcmp(getcw(), "LIHAT") == 0) ||(strcmp(getcw(), "Lihat") == 0)){
                //jalankan prosedur lihat
                lihat(tape, listBarang, listPelanggan, listTransaksi, 0);
            }
            //jika masukan perintah 'tambah'
            else if((strcmp(getcw(), "tambah") == 0) || (strcmp(getcw(), "TAMBAH") == 0) ||(strcmp(getcw(), "Tambah") == 0)){
                //jika masukan perintah 'tambah'                
                tambah(tape, listBarang, listPelanggan, listTransaksi, 0, 0);
            }
            //jika masukan perintah 'ubah'
            else if((strcmp(getcw(), "ubah") == 0) || (strcmp(getcw(), "UBAH") == 0) ||(strcmp(getcw(), "Ubah") == 0)){
                //jika masukan perintah 'ubah'                
                ubah(tape, listBarang, listPelanggan, listTransaksi, 0, 0);
            }
            //jika masukan perintah 'hapus'
            else if((strcmp(getcw(), "hapus") == 0) || (strcmp(getcw(), "HAPUS") == 0) ||(strcmp(getcw(), "Hapus") == 0)){
                //jika masukan perintah 'hapus'
               hapus(tape, listBarang, listPelanggan, listTransaksi, 0);
            }
            //jika perintah awal adalah "exit"
            else if((strcmp(getcw(), "exit") == 0) || (strcmp(getcw(), "EXIT") == 0) || (strcmp(getcw(), "Exit") == 0)){
                //system akan tertutup / keluar (exit)
                tutup = 1;
                printf("\nsystem ('exit')\n");
                printf("\nJangan lupa bahagia teman-teman!\n");
            }
            //jika perintah awal adalah "semangat"
            else if((strcmp(getcw(), "semangat") == 0) || (strcmp(getcw(), "Semangat") == 0) || (strcmp(getcw(), "SEMANGAT") == 0) || (strcmp(getcw(), "semangat!") == 0)){
                //system akan tertutup / keluar (exit)
                tutup = 1;
                printf("\nsystem ('exit')\n");
                printf("\nJangan lupa bahagia teman-teman!\n");
            }
            //jika masukan lain
            else{
                //tampilkan error
                error1();
            }
        }
    }
    
    return 0;
}