/*
Saya Wildan Hafizh Raffianshar [2202301] mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah 
Algoritma dan Pemrograman II untuk keberkahanNya maka saya tidak
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/

#include "header.h"

int idx;
int temp_idx;
int wlen;
char cw[50];
char temp_cw[50];

void test(){
    printf("test\n");
}


void error1(){
    printf("\n<<error>> Perintah tidak tersedia\n");
}


void error2(){
    printf("\n<<error>> Perintah / tabel tidak tersedia\n");
}


void error3(){
    printf("\n<<error>> Data masukan tidak lengkap\n");
}


void error4(){
    printf("\n<<error>> Data masukan tidak valid\n");
}


int cwlen(char str[]){
    int count = 0;

    while(str[count] != '\0'){
        count++;
    }

    return count;
}


// Prosedur untuk memulai mesin kata
void start(char str[]){
    // inisialisasi index dan panjang kata
    idx = 0;
    wlen = 0;

    // jika karakter dalam index adalah spasi, maka index terus maju
    while (str[idx] == ' '){
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0)){
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }

    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}


// Prosedur untuk mengosongkan kata yang dibaca dalam mesin kata
void reset(){
    // inisialisasi panjang kata dan kata saat ini agar NULL
    wlen = 0;
    cw[wlen] = '\0';
}


// Fungsi untuk memeriksa akhir dari proses
int eop(char str[]){
    // Memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (str[idx] == ';'){
        return 1;
    } else{
        return 0;
    }
}


// Prosedur untuk memajukan kata
void inc(char str[]){
    // inisialisasi ulang panjang kata
    wlen = 0;

    // jika karakter dalam pita adalah spasi, maka index terus maju
    while (str[idx] == ' '){
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0)){
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }

    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}


// Fungsi untuk mendapatkan panjang kata saat ini
int getlen(){
    return wlen;
}


// Fungsi untuk mendapatkan kata saat ini
char *getcw(){
    return cw;
}


//Fungsi untuk mendapatkan index saat ini
int getidx(){
    return idx;
}


//Prosedur membaca data barang pada file dbarang
void readFile_ListBarang(int *n, dataBarang source[], char filename[], int lihat){
    FILE *fTemp;
    fTemp = fopen(filename, "r"); // buka file dengan mode read

    int returnVal = fscanf(fTemp, "%s %s", // scan 2 data pertama (baris 1)
                                                source[*n].id_barang,
                                                source[*n].nama_barang);

    // cek apakah scan tadi kolom id_barang merupakan EOF dummy atau return hasil fscanf adalah EOF(-1)?
    if (strcmp(source[*n].id_barang, "####") == 0 || returnVal == EOF){
        // jika, ya maka file kosong
        printf("File List Barang Kosong\n");
    } else{
        // jika tidak maka bisa scan kembali selama kolom id_barang bukan EOF
        while (strcmp(source[*n].nama_barang, "####") != 0){
            *n = *n + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s", // scan 2 data selanjutnya
                                                source[*n].id_barang,
                                                source[*n].nama_barang);
        }
    }

    //jika nilai lihat = 1, maka data barang ditampilkan
    if(lihat == 1){

        //mencari id_barang terpanjang
        int terpanjang_id = 0;
        for(int i = 0; i <*n; i++) {
            if(cwlen(source[i].id_barang) > terpanjang_id){
                terpanjang_id = cwlen(source[i].id_barang);
            }
        }

        //mencari nama_barang terpanjang
        int terpanjang_nama = 0;
        for(int i = 0; i <*n; i++) {
            if(cwlen(source[i].nama_barang) > terpanjang_nama){
                terpanjang_nama = cwlen(source[i].nama_barang);
            }
        }

        //tabel
        //header
        //baris1
        printf("%c", 218);
        if(terpanjang_id <= 11){
            for(int i = 0; i < 11 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_id + 2 ; i++) {
                printf("%c", 196);
            }
        }
        printf("%c", 194);
        if(terpanjang_nama <= 11){
            for(int i = 0; i < 11 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_nama + 2 ; i++) {
                printf("%c", 196);
            }
        }
        printf("%c\n", 191);

        //baris2
        printf("%c", 179);

        if(terpanjang_id > 11){
            for(int i = 0; i < (terpanjang_id - 11)/2 ; i++) {
                printf(" ");
            }
        }
        printf(" Kode Barang ");
        if(terpanjang_id > 11){
            for(int i = 0; i < (terpanjang_id - 11)/2 ; i++) {
                printf(" ");
            }
            if((((terpanjang_id - 11)/2)%2 == 1) || terpanjang_id == 12){
                printf(" ");
            }
        }
        printf("%c", 179);
        if(terpanjang_nama > 11){
            for(int i = 0; i < (terpanjang_nama - 11)/2 ; i++) {
                printf(" ");
            }
        }
        printf(" Nama Barang ");
        if(terpanjang_nama > 11){
            for(int i = 0; i < (terpanjang_nama - 11)/2 ; i++) {
                printf(" ");
            }
            if((((terpanjang_nama - 11)/2)%2 == 1) || terpanjang_nama == 12){
                printf(" ");
            }
        }
        printf("%c\n", 179);

        //baris3
        printf("%c", 195);
        if(terpanjang_id <= 11){
            for(int i = 0; i < 11 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_id + 2 ; i++) {
                printf("%c", 196);
            }
        }
        printf("%c", 197);
        if(terpanjang_nama <= 11){
            for(int i = 0; i < 11 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_nama + 2 ; i++) {
                printf("%c", 196);
            }
        }
        printf("%c\n", 180);

        //isi
        for(int i = 0; i <*n; i++){
            printf("%c", 179);
            printf(" %s ", source[i].id_barang); 
            if(terpanjang_id > 11){
                for(int j = 0; j < terpanjang_id - cwlen(source[i].id_barang); j++){
                    printf(" ");
                }
            } else{
                for(int j = 0; j < 11 - cwlen(source[i].id_barang); j++){
                    printf(" ");
                }
            }
            printf("%c", 179);
            printf(" %s ", source[i].nama_barang);
            if(terpanjang_nama > 11){
                for(int j = 0; j < terpanjang_nama - cwlen(source[i].nama_barang); j++){
                    printf(" ");
                }
            } else{
                for(int j = 0; j < 11 - cwlen(source[i].nama_barang); j++){
                    printf(" ");
                }
            }
            printf("%c\n", 179);
        }

        //bawah
        printf("%c", 192);
        if(terpanjang_id <= 11){
            for(int i = 0; i < 11 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_id + 2 ; i++) {
                printf("%c", 196);
            }
        }
        printf("%c", 193);
        if(terpanjang_nama <= 11){
            for(int i = 0; i < 11 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_nama + 2 ; i++) {
                printf("%c", 196);
            }
        }
        printf("%c\n", 217);

    }

    // "tutup file"
    fclose(fTemp);
}

//Prosedur membaca data pelanggan pada file dpelanggan
void readFile_ListPelanggan(int *n, dataPelanggan source[], char filename[], int lihat){
    FILE *fTemp;
    fTemp = fopen(filename, "r"); // buka file dengan mode read

    int returnVal = fscanf(fTemp, "%s %s", // scan 2 data pertama (baris 1)
                                                source[*n].id_pelanggan,
                                                source[*n].nama_pelanggan);

    // cek apakah scan tadi kolom id_pelanggan merupakan EOF dummy atau return hasil fscanf adalah EOF(-1)?
    if (strcmp(source[*n].id_pelanggan, "####") == 0 || returnVal == EOF){
        // jika, ya maka file kosong
        printf("File List pelanggan Kosong\n");
    } else{
        // jika tidak maka bisa scan kembali selama kolom id_pelanggan bukan EOF
        while (strcmp(source[*n].nama_pelanggan, "####") != 0){
            *n = *n + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s", // scan 2 data selanjutnya
                                                source[*n].id_pelanggan,
                                                source[*n].nama_pelanggan);
        }
    }

    if(lihat == 1){
        //mencari id_pelanggan terpanjang
        int terpanjang_id = 0;
        for(int i = 0; i <*n; i++) {
            if(cwlen(source[i].id_pelanggan) > terpanjang_id){
                terpanjang_id = cwlen(source[i].id_pelanggan);
            }
        }

        //mencari nama_pelanggan terpanjang
        int terpanjang_nama = 0;
        for(int i = 0; i <*n; i++) {
            if(cwlen(source[i].nama_pelanggan) > terpanjang_nama){
                terpanjang_nama = cwlen(source[i].nama_pelanggan);
            }
        }

        //tabel
        //header
        //baris1
        printf("%c", 218);
        if(terpanjang_id <= 14){
            for(int i = 0; i < 14 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_id + 2 ; i++) {
                printf("%c", 196);
            }
        }
        printf("%c", 194);
        if(terpanjang_nama <= 14){
            for(int i = 0; i < 14 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_nama + 2 ; i++) {
                printf("%c", 196);
            }
        }

        printf("%c\n", 191);

        //baris2
        printf("%c", 179);

        if(terpanjang_id > 14){
            for(int i = 0; i < (terpanjang_id - 14)/2 ; i++) {
                printf(" ");
            }
        }
        printf(" Kode Pelanggan ");
        if(terpanjang_id > 14){
            for(int i = 0; i < (terpanjang_id - 14)/2 ; i++) {
                printf(" ");
            }
            if((((terpanjang_id - 14)/2)%2 == 1) || terpanjang_id == 15){
                printf(" ");
            }
        }
        printf("%c", 179);
        if(terpanjang_nama > 14){
            for(int i = 0; i < (terpanjang_nama - 14)/2 ; i++) {
                printf(" ");
            }
        }
        printf(" Nama Pelanggan ");
        if(terpanjang_nama > 14){
            for(int i = 0; i < (terpanjang_nama - 14)/2 ; i++) {
                printf(" ");
            }
            if((((terpanjang_nama - 14)/2)%2 == 1) || terpanjang_nama == 15){
                printf(" ");
            }
        }
        printf("%c\n", 179);

        //baris3
        printf("%c", 195);
        if(terpanjang_id <= 14){
            for(int i = 0; i < 14 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_id + 2 ; i++) {
                printf("%c", 196);
            }
        }
        printf("%c", 197);
        if(terpanjang_nama <= 14){
            for(int i = 0; i < 14 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_nama + 2 ; i++) {
                printf("%c", 196);
            }
        }
        printf("%c\n", 180);

        //isi
        for(int i = 0; i <*n; i++){
            printf("%c", 179);
            printf(" %s ", source[i].id_pelanggan); 
            if(terpanjang_id > 14){
                for(int j = 0; j < terpanjang_id - cwlen(source[i].id_pelanggan); j++){
                    printf(" ");
                }
            } else{
                for(int j = 0; j < 14 - cwlen(source[i].id_pelanggan); j++){
                    printf(" ");
                }
            }
            printf("%c", 179);
            printf(" %s ", source[i].nama_pelanggan);
            if(terpanjang_nama > 14){
                for(int j = 0; j < terpanjang_nama - cwlen(source[i].nama_pelanggan); j++){
                    printf(" ");
                }
            } else{
                for(int j = 0; j < 14 - cwlen(source[i].nama_pelanggan); j++){
                    printf(" ");
                }
            }
            printf("%c\n", 179);
        }

        //bawah
        printf("%c", 192);
        if(terpanjang_id <= 14){
            for(int i = 0; i < 14 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_id + 2 ; i++) {
                printf("%c", 196);
            }
        }
        printf("%c", 193);
        if(terpanjang_nama <= 14){
            for(int i = 0; i < 14 + 2 ; i++) {
                printf("%c", 196);
            }
        } else{
            for(int i = 0; i < terpanjang_nama + 2 ; i++) {
                printf("%c", 196);
            }
        }
        printf("%c\n", 217);
    }

    // "tutup file"
    fclose(fTemp);
}


//Prosedur menulis data barang ke file dbarang
void writeToFile_ListBarang(int n, dataBarang source[], char filename[]){
    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "w"); // buka file dengan mode write
   
    // tulis data ke file
    for (int i = 0; i < n; i++){
        fprintf(fTemp, "%s %s\n", // tulis 2 kolom lalu beri newline
                                        source[i].id_barang,
                                        source[i].nama_barang);
    }

    // berikan EOF di akhir file
    fprintf(fTemp, "%s %s\n", "####", "####");

    // "tutup file"
    fclose(fTemp);
}


//Prosedur menulis data pelanggan ke file dpelanggan
void writeToFile_ListPelanggan(int n, dataPelanggan source[], char filename[]){
    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "w"); // buka file dengan mode write
   
    // tulis data ke file
    for (int i = 0; i < n; i++){
        fprintf(fTemp, "%s %s\n", // tulis 2 kolom lalu beri newline
                                        source[i].id_pelanggan,
                                        source[i].nama_pelanggan);
    }

    // berikan EOF di akhir file
    fprintf(fTemp, "%s %s\n", "####", "####");

    // "tutup file"
    fclose(fTemp);
}


//Prosedur query lihat
void lihat(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100], int q_lainnya){
    int p = 0;//sebagai index data barang
    int q = 0;//sebagai index data pelanggan
    //cek eop
    if (eop(tape) == 0){
        //jika eop 0 maka lanjut
        inc(tape);//pita maju

        //cek tabel
        if((strcmp(getcw(), "barang") == 0)){
            //jika tabel barang

            //cek eop lagi
            if(eop(tape) == 0){
                //jika eop 0 (terdapat spasi setelah kata "barang")
                inc(tape);//majukan pita

                /*  Cek apakah eop 1 dan terdapat kata-kata dan juga tidak ada query lain
                    atau apakah eop 0 lalu terdapat kata-kata dan juga tidak ada query lain
                */
                if(((eop(tape) == 1) && (strcmp(getcw(), "00") > 0) && (q_lainnya == 0)) || ((eop(tape) == 0) && (strcmp(getcw(), "00") > 0) && (q_lainnya == 0))){
                    //jika iya maka tampilkan error
                    error4();
                } else {
                    //jika tidak maka tampilkan data
                    printf("\nData barang terlihat\n");
                    readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1);
                }

            } else{
                //jika eop tidak nol maka tampilkan data
                printf("\nData barang terlihat\n");
                readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1);
            }
            
        } else if((strcmp(getcw(), "pelanggan") == 0)){
            //jika tabel pelanggan
            
            //cek eop lagi
            if(eop(tape) == 0){
                //jika eop 0 (terdapat spasi setelah kata "pelanggan")
                inc(tape);//majukan pita

                /*  Cek apakah eop 1 dan terdapat kata-kata dan juga tidak ada query lain
                    atau apakah eop 0 lalu terdapat kata-kata dan juga tidak ada query lain
                */
                if(((eop(tape) == 1) && (strcmp(getcw(), "00") > 0) && (q_lainnya == 0)) || ((eop(tape) == 0) && (strcmp(getcw(), "00") > 0)  && (q_lainnya == 0))){
                    //jika iya maka tampilkan error
                    error4();
                } else{
                    //jika tidak maka tampilkan data
                    printf("\nData pelanggan terlihat\n");
                    readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1);
                }
            } else{
                //jika eop tidak nol maka tampilkan data
                printf("\nData pelanggan terlihat\n");
                readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1);

            }

        } else if((strcmp(getcw(), "tambah") == 0) || (strcmp(getcw(), "TAMBAH") == 0) ||(strcmp(getcw(), "Tambah") == 0)){

            //jika perintah tambah
            
            //cek eop
            if(eop(tape) == 1){
                //jika eop 1
                //tampilkan error
                error1();
            } else{
                //jika eop 0
                temp_idx = idx;//tampung index
                //akses kembali prosedur lihat
                lihat(tape, listBarang, listPelanggan, 1);
                idx = temp_idx;//kembalikan nilai index
                //akses prosedur tambah
                tambah(tape, listBarang, listPelanggan, 0);
            }
            
        } else if((strcmp(getcw(), "ubah") == 0) || (strcmp(getcw(), "UBAH") == 0) ||(strcmp(getcw(), "Ubah") == 0)){
            //jika perintah ubah
            
            //cek eop
            if(eop(tape) == 1){
                error1();
            } else{
                temp_idx = idx;//tampung index
                //akses kembali prosedur lihat
                lihat(tape, listBarang, listPelanggan, 1);
                idx = temp_idx;//kembalikan nilai index
                //akses prosedur ubah
                ubah(tape, listBarang, listPelanggan, 0);
            }
            
        } else if((strcmp(getcw(), "hapus") == 0) || (strcmp(getcw(), "HAPUS") == 0) ||(strcmp(getcw(), "Hapus") == 0)){
            //jika perintah hapus
            
            //cek eop
            if(eop(tape) == 1){
                error1();
            } else{
                temp_idx = idx;//tampung index
                //akses kembali prosedur lihat
                lihat(tape, listBarang, listPelanggan, 1);
                idx = temp_idx;//kembalikan nilai index
                //akses prosedur ubah
                hapus(tape, listBarang, listPelanggan);
            }
        } else{
            //jika tabel / perintah lainnya
            //tampilkan error
            error2();
        }

    } else{
        //jika eop tidak nol
        //tampilkan error
        error2();
    }
}


//prosedur query tambah
void tambah(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100], int q_ubah){

    int p = 0;      //index data barang
    int q = 0;      //index data pelanggan
    int found = 0;  //indikator pencari id

    //cek eop
    if (eop(tape) == 0){
        //jika eop 0 maka lanjut
        inc(tape);//pita maju
        
        if((strcmp(getcw(), "barang") == 0)){
            //jika tabel barang

            //cek eop lagi
            if(eop(tape) == 1){
                //jika eop 1
                //tampilkan error
                error3();
            } else{
                found = 0;//set found ke 0

                //membaca data untuk mendapat nilai p
                readFile_ListBarang(&p, listBarang, "../data/barang.dat", 0);
                
                inc(tape);//majukan pita

                //cek eop
                if(eop(tape) == 1){
                    //jika eop 1
                    //maka tampilkan error
                    error3();
                } else{
                    //jika eop 0

                    //cari id_barang
                    for(int i = 0; i<p; i++){
                        if(strcmp(getcw(), listBarang[i].id_barang)== 0){
                            found = 1;
                        }
                    }
                    
                    //jika id_barang ditemukan
                    if(found == 1 && q_ubah == 0){
                        //maka berarti id tidak bisa ditambahkan juga q_ubah 0 (tidak memiliki perintah ubah sebelumnya)
                        //tampilkan error
                        printf("<<error>> id barang sudah terdapat pada data barang\n");
                    } else if(found == 1 && q_ubah == 1){
                        //jika found 1 dan q_ubah 1
                        idx = temp_idx;//kembalikan nilai index
                        //pindah ke prosedur ubah
                        ubah(tape, listBarang, listPelanggan, 0);
                    } else{
                        //jika found 0
                        strcpy(listBarang[p].id_barang, getcw()); //masukan kata saat ini (nama_barang) ke dalam data
                        temp_idx = idx;                           //tampung index saat ini
                        inc(tape);                                //majukan pita

                        /*
                            cek apakah eop nol
                            atau eop 1 dan tidak ada kata-kata lain setelahnya
                        */
                        if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") < 0))){
                            //jika iya
                            //cek eop
                            if((eop(tape) == 0)){
                                //jika eop nol
                                inc(tape);//majukan pita

                                //cek apakah eop 1 dan tidak ada kata-kata lain 
                                if((eop(tape) == 1 && (strcmp(getcw(), "00") < 0))){
                                    //jika iya
                                    //tambahkan data

                                    idx = temp_idx;//kembalikan index
                                    inc(tape);

                                    strcpy(listBarang[p].nama_barang, getcw());
                                    p++;

                                    writeToFile_ListBarang(p, listBarang, "../data/barang.dat");

                                    printf("\nData Barang telah bertambah\n\n");

                                    p=0;
                                    readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1); 
                                } else{
                                    //jika tidak
                                    //tampilkan error
                                    error4();
                                }
                            } else{
                                //jika eop tidak nol
                                //tampilkan error
                                error3();
                            }
                        } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
                            //jika eop 1 dan terdapat kata-kata
                            //maka tambahkan data

                            strcpy(listBarang[p].nama_barang, getcw());
                            p++;

                            writeToFile_ListBarang(p, listBarang, "../data/barang.dat");

                            printf("\nData Barang telah bertambah\n\n");

                            p=0;
                            readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1); 
                        }
                    }
                }
            }
        } else if((strcmp(getcw(), "pelanggan") == 0)){
            //jika tabel pelanggan

            //cek eop lagi
            if(eop(tape) == 1){
                //jika eop 1
                //tampilkan error
                error1();
            } else{
                found = 0;//set found ke 0

                //membaca data untuk mendapat nilai q
                readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 0);
                
                inc(tape);//majukan pita

                //cek eop
                if(eop(tape) == 1){
                    //jika eop 1
                    //maka tampilkan error
                    error3();
                } else{
                    //jika eop 0

                    //cari id_pelanggan
                    for(int i = 0; i<q; i++){
                        if(strcmp(getcw(), listPelanggan[i].id_pelanggan)== 0){
                            found = 1;
                        }
                    }

                    //jika id_pelanggan ditemukan
                    if(found == 1 && q_ubah == 0){
                        //maka berarti id tidak bisa ditambahkan juga q_ubah 0 (tidak memiliki perintah ubah sebelumnya)
                        //tampilkan error
                        printf("<<error>> id pelanggan sudah terdapat pada data pelanggan\n");
                    } else if(found == 1 && q_ubah == 1){
                        //jika found 1 dan q_ubah 1
                        idx = temp_idx;//kembalikan nilai index
                        //pindah ke prosedur ubah
                        ubah(tape, listBarang, listPelanggan, 0);
                    } else{
                        //jika found 0
                        strcpy(listPelanggan[q].id_pelanggan, getcw());
                        temp_idx = idx;
                        inc(tape);

                        /*
                            cek apakah eop nol
                            atau eop 1 dan tidak ada kata-kata lain setelahnya
                        */
                        if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") < 0))){
                            //jika iya
                            //cek eop
                            if((eop(tape) == 0)){
                                //jika eop nol
                                inc(tape);//majukan pita

                                //cek apakah eop 1 dan tidak ada kata-kata lain 
                                if((eop(tape) == 1 && (strcmp(getcw(), "00") < 0))){
                                    //jika iya
                                    //tambahkan data

                                    idx = temp_idx;//kembalikan index
                                    inc(tape);
                                    strcpy(listPelanggan[q].nama_pelanggan, getcw());
                                    q++;

                                    writeToFile_ListPelanggan(q, listPelanggan, "../data/pelanggan.dat");

                                    printf("\nData Pelanggan telah bertambah\n\n");
                                    
                                    q=0;
                                    readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1); 
                                } else{
                                    //jika tidak
                                    //tampilkan error
                                    error4();
                                }
                            } else{
                                //jika eop tidak nol
                                //tampilkan error
                                error3();
                            }
                        } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
                            //jika eop 1 dan terdapat kata-kata
                            //maka tambahkan data
                            strcpy(listPelanggan[q].nama_pelanggan, getcw());
                            q++;

                            writeToFile_ListPelanggan(q, listPelanggan, "../data/pelanggan.dat");

                            printf("\nData Pelanggan telah bertambah\n\n");
                            
                            q=0;
                            readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1);  
                        }
                    } 
                }
            }
        } else if((strcmp(getcw(), "ubah") == 0) || (strcmp(getcw(), "UBAH") == 0) ||(strcmp(getcw(), "Ubah") == 0)){
            //jika perintah ubah
            temp_idx = idx;//tampung index
            //panggil kembali prosedur tambah dengan q_ubah = 1
            tambah(tape, listBarang, listPelanggan, 1);
        } else if((strcmp(getcw(), "lihat") == 0) || (strcmp(getcw(), "LIHAT") == 0) ||(strcmp(getcw(), "Lihat") == 0)){
            //jika perintah lihat
            //panggil kembali prosedur tambah
            tambah(tape, listBarang, listPelanggan, 0);
        } else if((strcmp(getcw(), "hapus") == 0) || (strcmp(getcw(), "HAPUS") == 0) ||(strcmp(getcw(), "Hapus") == 0)){
            //jika perintah hapus
            //tampilkan error
            printf("\n<<error>> Perintah tidak diijinkan\n");
        } else{
            //jika perintah lain
            //tampilkan error
            error2();
        }
    } else{
        //jika eop tidak nol
        //tampilkan error
        error1();
    }
}


//prosedur query ubah
void ubah(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100], int q_tambah){
    int p = 0, q = 0;   //p sebagai index data barang, q sebagai index data pelanggan
    int take = 0;       //penampung index yang akan diubah
    int found = 0;      //indikator ditemukannya id
    //cek eop
    if (eop(tape) == 0){
        //jika eop nol
        inc(tape);//majukan pita

        if((strcmp(getcw(), "barang") == 0)){
            //jika tabel barang

            //cek eop lagi
            if(eop(tape) == 1){
                //jika eop 1
                //tampilkan error
                error3();
            } else{
                take = 0;  //set take ke 0
                found = 0; //set found ke 0

                //membaca data untuk mendapat nilai p
                readFile_ListBarang(&p, listBarang, "../data/barang.dat", 0);
                
                inc(tape);//majukan pita
                
                //cek eop
                if(eop(tape) == 1){
                    //jika eop 1
                    //maka tampilkan error
                    error3();
                } else{
                    //jika eop 0

                    //cari id_barang
                    for(int i = 0; i<p; i++){
                        if(strcmp(getcw(), listBarang[i].id_barang)== 0){
                            take = i;
                            found = 1;
                            i = p;
                        }
                    }

                    if(found == 0 && q_tambah == 0){
                        //jika id tidak ditemukan dan q_tambah 0
                        //tampilkan error
                        printf("<<error>> id barang tidak ditemukan\n");
                    } else if(found == 0 && q_tambah == 1){
                        //jika tidak ditemukan tapi q_tambah 1
                        idx = temp_idx;//kembalikan index
                        //panggil prosedur tambah
                        tambah(tape, listBarang, listPelanggan, 0);
                    } else{
                        //jika id ditemukan

                        temp_idx = idx;//tampung index
                        inc(tape);//majukan pita

                        /*
                            cek apakah eop nol
                            atau eop 1 dan tidak ada kata-kata lain setelahnya
                        */
                        if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") < 0))){
                           //jika iya
                            //cek eop
                             if((eop(tape) == 0)){
                                //jika eop nol
                                inc(tape);//majukan pita

                                //cek apakah eop 1 dan tidak ada kata-kata lain
                                if((eop(tape) == 1 && (strcmp(getcw(), "00") < 0))){
                                    //jika iya
                                    //ubah data

                                    idx = temp_idx;//kembalikan index
                                    inc(tape);
                                    strcpy(listBarang[take].nama_barang, getcw());

                                    writeToFile_ListBarang(p, listBarang, "../data/barang.dat");
                                    printf("\ndata telah berubah\n\n");
                                    
                                    p=0;
                                    readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1);
                                }
                                else{
                                    //jika tidak
                                    //tampilkan error
                                    error4();
                                }
                            } else{
                                //jika eop tidak nol
                                //tampilkan error
                                error3();
                            }
                        } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
                            //jika eop 1 dan terdapat kata-kata
                            //maka ubah data
                            strcpy(listBarang[take].nama_barang, getcw());

                            writeToFile_ListBarang(p, listBarang, "../data/barang.dat");
                            printf("\ndata telah berubah\n\n");
                            
                            p=0;
                            readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1);
                        }
                        
                        
                    } 
                }
                
                
            }
            
        }
        else if((strcmp(getcw(), "pelanggan") == 0)){
            //jika tabel pelanggan

            //cek eop lagi
            if(eop(tape) == 1){
                //jika eop 1
                //tampilkan error
                error3();
            } else{
                take = 0;
                found = 0;//set found ke 0

                //membaca data untuk mendapat nilai p
                readFile_ListPelanggan(&p, listPelanggan, "../data/pelanggan.dat", 0);
                
                inc(tape);//majukan pita

                //cek eop
                if(eop(tape) == 1){
                    //jika eop 1
                    //maka tampilkan error
                    error3();
                } else{
                    //jika eop 0

                    //cari id_pelanggan
                    for(int i = 0; i<p; i++){
                        if(strcmp(getcw(), listPelanggan[i].id_pelanggan)== 0){
                            take = i;
                            found = 1;
                            i = p;
                        }
                    }

                    if(found == 0 && q_tambah == 0){
                        //jika id tidak ditemukan dan q_tambah 0
                        //tampilkan error
                        printf("<<error>> id pelanggan tidak ditemukan\n");
                    } else if(found == 0 && q_tambah == 1){
                        //jika id tidak ditemukan tapi q_tambah 1
                        idx = temp_idx;//kembalikan index
                        //panggil prosedur tambah
                        tambah(tape, listBarang, listPelanggan, 0);
                    } else{
                        //jika id ditemukan

                        temp_idx = idx;//tampung index
                        inc(tape);//majukan pita
                        /*
                            cek apakah eop nol
                            atau eop 1 dan tidak ada kata-kata lain setelahnya
                        */
                        if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") < 0))){
                            //jika iya
                            //cek eop
                            if((eop(tape) == 0)){
                                //jika eop nol
                                inc(tape);//majukan pita

                                //cek apakah eop 1 dan tidak ada kata-kata lain 
                                if((eop(tape) == 1 && (strcmp(getcw(), "00") < 0))){
                                    //jika iya
                                    //ubah data
                                    
                                    idx = temp_idx;//kembalikan index
                                    inc(tape);//majukan pita
                                    strcpy(listPelanggan[take].nama_pelanggan, getcw());

                                    writeToFile_ListPelanggan(p, listPelanggan, "../data/pelanggan.dat");
                                    printf("data berhasil diubah\n\n");

                                    q=0;
                                    readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1);
                                } else{
                                    //jika tidak
                                    //tampilkan error
                                    error4();
                                }
                            } else{
                                //jika eop tidak nol
                                //tampilkan error
                                error3();
                            }
                        } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
                            //jika eop 1 dan terdapat kata-kata (tidak kosong)
                            //ubah data
                            strcpy(listPelanggan[take].nama_pelanggan, getcw());

                            writeToFile_ListPelanggan(p, listPelanggan, "../data/pelanggan.dat");
                            printf("data berhasil diubah\n\n");

                            q=0;
                            readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1);
                        }
                    }
                }
            }
        }
        else if((strcmp(getcw(), "lihat") == 0) || (strcmp(getcw(), "LIHAT") == 0) ||(strcmp(getcw(), "Lihat") == 0)){
            //jika perintah lihat
            //panggil kembali prosedur ubah
            ubah(tape, listBarang, listPelanggan, 0);
        } else if((strcmp(getcw(), "tambah") == 0) || (strcmp(getcw(), "TAMBAH") == 0) ||(strcmp(getcw(), "Tambah") == 0)){
            //jika perintah tambah
            temp_idx = idx;//tampung index
            //panggil prosedur ubah dengan q_tambah 1
            ubah(tape, listBarang, listPelanggan, 1);
        } else if((strcmp(getcw(), "hapus") == 0) || (strcmp(getcw(), "HAPUS") == 0) ||(strcmp(getcw(), "Hapus") == 0)){
            //jika perintah hapus
            //tampilkan error
            printf("\n<<error>> Perintah tidak diijinkan\n");
        } else{
            //jika perintah lain
            //tampilkan error
            error2();
        }
    } else{
        //jika eop tidak nol
        //tampilkan error
        error1();
    }
}


void hapus(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100]){
    int p = 0, q = 0;   //p sebagai index data barang, q sebagai index data pelanggan
    int take = 0;       //penampung index yang akan dihapus
    int found = 0;      //indikator ditemukannya id
    //cek eop
    if (eop(tape) == 0){
        //jika eop nol
        inc(tape);//majukan pita

        if((strcmp(getcw(), "barang") == 0)){
            //jika tabel barang

            //cek eop
            if(eop(tape) == 1){
                //jika eop 1
                //tampilkan error
                error3();
            } else{
                take = 0;   //set take ke 0
                found = 0;  //set found ke 0
                
                //membaca data untuk mendapat nilai p
                readFile_ListBarang(&p, listBarang, "../data/barang.dat", 0);
                
                inc(tape);//majukan pita
                
                //cari id_barang
                for(int i = 0; i<p; i++){
                    if(strcmp(getcw(), listBarang[i].id_barang)== 0){
                        take = i;
                        found = 1;
                        i = p;
                    }
                }

                if(found == 0){
                    //jika id tidak ditemukan
                    //tampilkan error
                    printf("<<error>> id barang tidak ditemukan\n");
                } else{
                    //jika id ditemukan
                    /*
                        cek apakah eop nol
                        atau eop 1 dan tidak ada kata-kata lain setelahnya
                    */
                    if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") < 0))){
                        //jika iya
                        //cek eop
                        if((eop(tape) == 0)){
                            //jika eop nol
                            inc(tape);//majukan pita

                            //cek apakah eop 1 dan tidak ada kata-kata lain 
                            if((eop(tape) == 1 && (strcmp(getcw(), "00") < 0))){

                                //jika iya
                                //hapus data

                                strcpy(listBarang[take].id_barang, "\0");
                                strcpy(listBarang[take].nama_barang, "\0");

                                for(int i = take; i<p; i++){
                                    strcpy(listBarang[i].id_barang, listBarang[i+1].id_barang);
                                    strcpy(listBarang[i].nama_barang, listBarang[i+1].nama_barang);
                                }
                                
                                p-=1;
                                strcpy(listBarang[p].id_barang, "\0");
                                strcpy(listBarang[p].nama_barang, "\0");

                                writeToFile_ListBarang(p, listBarang, "../data/barang.dat");
                                printf("\nData berhasil dihapus\n\n");

                                p=0;
                                readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1);

                            }
                            else{
                                //jika tidak
                                //tampilkan error
                                error4();
                            }
                        } else{
                            //jika eop tidak nol
                            //tampilkan error
                            error3();
                        }
                    } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
                        //jika eop 1 juga terdapat kata tidak kosong
                        //hapus kata
                        strcpy(listBarang[take].id_barang, "\0");
                        strcpy(listBarang[take].nama_barang, "\0");

                        for(int i = take; i<p; i++){
                            strcpy(listBarang[i].id_barang, listBarang[i+1].id_barang);
                            strcpy(listBarang[i].nama_barang, listBarang[i+1].nama_barang);
                        }
                        
                        p-=1;
                        strcpy(listBarang[p].id_barang, "\0");
                        strcpy(listBarang[p].nama_barang, "\0");

                        writeToFile_ListBarang(p, listBarang, "../data/barang.dat");
                        printf("\nData berhasil dihapus\n\n");

                        p=0;
                        readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1);
                    }
                }
            }
        } else if((strcmp(getcw(), "pelanggan") == 0)){
            //jika tabel pelanggan

            //cek eop
            if(eop(tape) == 1){
                //jika eop 1
                //tampilkan error
                error3();
            } else{

                take = 0;   //set take ke 0
                found = 0;  //set found ke 0
                  
                //membaca data untuk mendapat nilai p
                readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 0);
                
                inc(tape);//majukan pita
                
                //cari id_barang
                for(int i = 0; i<q; i++){
                    if(strcmp(getcw(), listPelanggan[i].id_pelanggan)== 0){
                        take = i;
                        found = 1;
                        i = q;
                    }
                }

                if(found == 0){
                    //jika id tidak ditemukan
                    //tampilkan error
                    printf("<<error>> id pelanggan tidak ditemukan\n");
                } else{
                    //jika id ditemukan
                    /*
                        cek apakah eop nol
                        atau eop 1 dan tidak ada kata-kata lain setelahnya
                    */
                    if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") < 0))){
                        //jika iya
                        //cek eop
                        if((eop(tape) == 0)){
                            //jika eop nol
                            inc(tape);//majukan pita

                            //cek apakah eop 1 dan tidak ada kata-kata lain 
                            if((eop(tape) == 1 && (strcmp(getcw(), "00") < 0))){
                                //jika iya
                                //hapus data
                                strcpy(listPelanggan[take].id_pelanggan, "\0");
                                strcpy(listPelanggan[take].nama_pelanggan, "\0");
                                    
                                for(int i = take; i<q; i++){
                                    strcpy(listPelanggan[i].id_pelanggan, listPelanggan[i+1].id_pelanggan);
                                    strcpy(listPelanggan[i].nama_pelanggan, listPelanggan[i+1].nama_pelanggan);
                                }
                                
                                q-=1;
                                strcpy(listPelanggan[q].id_pelanggan, "\0");
                                strcpy(listPelanggan[q].nama_pelanggan, "\0");

                                writeToFile_ListPelanggan(q, listPelanggan, "../data/pelanggan.dat");
                                printf("\nData berhasil dihapus\n\n");

                                q=0;
                                readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1);
                            }
                            else{
                                //jika tidak
                                //tampilkan error
                                error4();
                            }
                        } else{
                            //jika eop tidak nol
                            //tampilkan error
                            error3();
                        }
                    } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
                        //jika eop 1 juga terdapat kata tidak kosong
                        //hapus kata
                        strcpy(listPelanggan[take].id_pelanggan, "\0");
                        strcpy(listPelanggan[take].nama_pelanggan, "\0");
                            
                        for(int i = take; i<q; i++){
                            strcpy(listPelanggan[i].id_pelanggan, listPelanggan[i+1].id_pelanggan);
                            strcpy(listPelanggan[i].nama_pelanggan, listPelanggan[i+1].nama_pelanggan);
                        }
                        
                        q-=1;
                        strcpy(listPelanggan[q].id_pelanggan, "\0");
                        strcpy(listPelanggan[q].nama_pelanggan, "\0");

                        writeToFile_ListPelanggan(q, listPelanggan, "../data/pelanggan.dat");
                        printf("\nData berhasil dihapus\n\n");

                        q=0;
                        readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1);
                    }
                }
            }
        } else if((strcmp(getcw(), "lihat") == 0) || (strcmp(getcw(), "LIHAT") == 0) ||(strcmp(getcw(), "Lihat") == 0)){
               //jika perintah lihat
               //panggil kembali prosedur hapus
               hapus(tape, listBarang, listPelanggan);
        } else{
            //jika perintah lain
            //tampilkan error
            error2();
        }
    } else{
        //jika eop tidak nol
        //tampilkan error
        error1();
    }
}