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


void errortest(){
    printf("\n<<error-->> Perintah tidak tersedia\n");
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


int getidx(){
    return idx;
}


void readFile_ListBarang(int *n, dataBarang source[], char filename[], int lihat){
    FILE *fTemp;
    fTemp = fopen(filename, "r"); // buka file dengan mode read

    int returnVal = fscanf(fTemp, "%s %s", // scan 2 data pertama (baris 1)
                                                source[*n].id_barang,
                                                source[*n].nama_barang);

    // cek apakah scan tadi kolom nimnya merukan EOF dummy atau return hasil fscanf adalah EOF(-1)?
    if (strcmp(source[*n].id_barang, "####") == 0 || returnVal == EOF){
        // jika, ya maka file kosong
        printf("File List Barang Kosong\n");
    } else{
        // jika tidak maka bisa scan kembali selama kolom nim bukan EOF
        while (strcmp(source[*n].nama_barang, "####") != 0){
            *n = *n + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s", // scan 2 data pertama (baris lanjutan)
                                                source[*n].id_barang,
                                                source[*n].nama_barang);
        }
    }

    if(lihat == 1){
        int terpanjang_id = 0;
        for(int i = 0; i <*n; i++) {
            if(strlen(source[i].id_barang) > terpanjang_id){
                terpanjang_id = strlen(source[i].id_barang);
            }
        }
        int terpanjang_nama = 0;
        for(int i = 0; i <*n; i++) {
            if(strlen(source[i].nama_barang) > terpanjang_nama){
                terpanjang_nama = strlen(source[i].nama_barang);
            }
        }
        //tabel
        //header
        //b1
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

        //b2
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

        //b3
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
                for(int j = 0; j < terpanjang_id - strlen(source[i].id_barang); j++){
                    printf(" ");
                }
            } else{
                for(int j = 0; j < 11 - strlen(source[i].id_barang); j++){
                    printf(" ");
                }
            }
            printf("%c", 179);
            printf(" %s ", source[i].nama_barang);
            if(terpanjang_nama > 11){
                for(int j = 0; j < terpanjang_nama - strlen(source[i].nama_barang); j++){
                    printf(" ");
                }
            } else{
                for(int j = 0; j < 11 - strlen(source[i].nama_barang); j++){
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


void readFile_ListPelanggan(int *n, dataPelanggan source[], char filename[], int lihat){
    FILE *fTemp;
    fTemp = fopen(filename, "r"); // buka file dengan mode read

    int returnVal = fscanf(fTemp, "%s %s", // scan 2 data pertama (baris 1)
                                                source[*n].id_pelanggan,
                                                source[*n].nama_pelanggan);

    // cek apakah scan tadi kolom nimnya merukan EOF dummy atau return hasil fscanf adalah EOF(-1)?
    if (strcmp(source[*n].id_pelanggan, "####") == 0 || returnVal == EOF){
        // jika, ya maka file kosong
        printf("File List pelanggan Kosong\n");
    } else{
        // jika tidak maka bisa scan kembali selama kolom nim bukan EOF
        while (strcmp(source[*n].nama_pelanggan, "####") != 0){
            *n = *n + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s", // scan 2 data pertama (baris lanjutan)
                                                source[*n].id_pelanggan,
                                                source[*n].nama_pelanggan);
        }
    }

    if(lihat == 1){
        int terpanjang_id = 0;
        for(int i = 0; i <*n; i++) {
            if(strlen(source[i].id_pelanggan) > terpanjang_id){
                terpanjang_id = strlen(source[i].id_pelanggan);
            }
        }
        int terpanjang_nama = 0;
        for(int i = 0; i <*n; i++) {
            if(strlen(source[i].nama_pelanggan) > terpanjang_nama){
                terpanjang_nama = strlen(source[i].nama_pelanggan);
            }
        }
        //tabel
        //header
        //b1
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

        //b2
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
            if((((terpanjang_id - 14)/2)%2 == 1) || terpanjang_id == 12){
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
            if((((terpanjang_nama - 14)/2)%2 == 1) || terpanjang_nama == 12){
                printf(" ");
            }
        }
        printf("%c\n", 179);

        //b3
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
                for(int j = 0; j < terpanjang_id - strlen(source[i].id_pelanggan); j++){
                    printf(" ");
                }
            } else{
                for(int j = 0; j < 14 - strlen(source[i].id_pelanggan); j++){
                    printf(" ");
                }
            }
            printf("%c", 179);
            printf(" %s ", source[i].nama_pelanggan);
            if(terpanjang_nama > 14){
                for(int j = 0; j < terpanjang_nama - strlen(source[i].nama_pelanggan); j++){
                    printf(" ");
                }
            } else{
                for(int j = 0; j < 14 - strlen(source[i].nama_pelanggan); j++){
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


void writeToFile_ListBarang(int n, dataBarang source[], char filename[]){
    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "w"); // buka file dengan mode write
   
    // tulis data ke file
    for (int i = 0; i < n; i++){
        fprintf(fTemp, "%s %s\n", // tulis 3 kolom lalu beri newline
                                        source[i].id_barang,
                                        source[i].nama_barang);
    }

    // berikan EOF di akhir file
    fprintf(fTemp, "%s %s\n", "####", "####");

    // "tutup file"
    fclose(fTemp);
}


void writeToFile_ListPelanggan(int n, dataPelanggan source[], char filename[]){
    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "w"); // buka file dengan mode write
   
    // tulis data ke file
    for (int i = 0; i < n; i++){
        fprintf(fTemp, "%s %s\n", // tulis 3 kolom lalu beri newline
                                        source[i].id_pelanggan,
                                        source[i].nama_pelanggan);
    }

    // berikan EOF di akhir file
    fprintf(fTemp, "%s %s\n", "####", "####");

    // "tutup file"
    fclose(fTemp);
}


void lihat(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100], int q_lainnya){
    int cek = 0;
    int p = 0;
    int q = 0;
    while (eop(tape) == 0){
        inc(tape);
        if((strcmp(getcw(), "barang") == 0)){
            cek = 1;
            if(eop(tape) == 0){
                inc(tape);

                if(((eop(tape) == 1) && (strcmp(getcw(), "00") > 0) && (q_lainnya == 0)) || ((eop(tape) == 0) && (strcmp(getcw(), "00") > 0) && (q_lainnya == 0)) || ((eop(tape) == 0) && (q_lainnya == 0))){
                    error4();
                    // printf("%d\n", q_lainnya);
                } else {
                    readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1);
                }

            } else if(eop(tape) == 1){
                test();
                readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1);
            }
            
        }
        else if((strcmp(getcw(), "pelanggan") == 0)){
            cek = 1;
            if(eop(tape) == 0){
                inc(tape);
                if(((eop(tape) == 1) && (strcmp(getcw(), "00") > 0) && (q_lainnya == 0)) || ((eop(tape) == 0) && (strcmp(getcw(), "00") > 0)  && (q_lainnya == 0))){
                    error4();
                } else{
                    readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1);
                }
            } else{
                readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1);

            }

        }
        else if((strcmp(getcw(), "tambah") == 0) || (strcmp(getcw(), "TAMBAH") == 0) ||(strcmp(getcw(), "Tambah") == 0)){
            if(eop(tape) == 1){
                error1();
            } else{
                temp_idx = idx;
                lihat(tape, listBarang, listPelanggan, 1);
                idx = temp_idx;
                tambah(tape, listBarang, listPelanggan, 0);
            }
            
        }
        else if((strcmp(getcw(), "ubah") == 0) || (strcmp(getcw(), "UBAH") == 0) ||(strcmp(getcw(), "Ubah") == 0)){
            // test();
            if(eop(tape) == 1){
                error1();
            } else{
                temp_idx = idx;
                lihat(tape, listBarang, listPelanggan, 1);
                idx = temp_idx;
                ubah(tape, listBarang, listPelanggan, 0);
            }
            
        }
        else if((strcmp(getcw(), "hapus") == 0) || (strcmp(getcw(), "HAPUS") == 0) ||(strcmp(getcw(), "Hapus") == 0)){
            if(eop(tape) == 1){
                error1();
            } else{
                temp_idx = idx;
                lihat(tape, listBarang, listPelanggan, 1);
                idx = temp_idx;
                hapus(tape, listBarang, listPelanggan);
            }
        }
        else{
            if(cek == 0){
                error2();
            }
        }

    }
}


void tambah(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100], int q_ubah){

    int p = 0;
    int q = 0;
    int cek = 0;
    int cek2 = 0;
        if (eop(tape) == 0){
            inc(tape);
            
            if((strcmp(getcw(), "barang") == 0)){
                cek2 = 1;
                if(eop(tape) == 1){
                    error3();
                } else{
                    cek = 0;
                    readFile_ListBarang(&p, listBarang, "../data/barang.dat", 0);
                    
                    inc(tape);
                    if(eop(tape) == 1){
                        error3();
                    } else{
                        for(int i = 0; i<p; i++){
                            if(strcmp(getcw(), listBarang[i].id_barang)== 0){
                                cek = 1;
                            }
                        }
                        
                        if(cek == 1 && q_ubah == 0){
                            printf("<<error>> id barang sudah terdapat pada data barang\n");
                        } 
                        else if(cek == 1 && q_ubah == 1){
                            idx = temp_idx;
                            ubah(tape, listBarang, listPelanggan, 0);
                        }

                        else{
                            strcpy(listBarang[p].id_barang, getcw());
                            temp_idx = idx;
                            inc(tape);

                            if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") <= 0))){
                                if((eop(tape) == 0)){
                                    inc(tape);
                                    if((eop(tape) == 1 && (strcmp(getcw(), "00") <= 0))){
                                        idx = temp_idx;
                                        inc(tape);
                                        strcpy(listBarang[p].nama_barang, getcw());
                                        p++;

                                        writeToFile_ListBarang(p, listBarang, "../data/barang.dat");

                                        printf("\nData Barang telah bertambah\n\n");

                                        p=0;
                                        readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1); 
                                    }
                                    else{
                                        error4();
                                    }
                                } else{
                                    error3();
                                }
                            } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
                                // printf("%s %d-%d\n", getcw(), eop(tape), strcmp(getcw(), "00"));

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
                
            }
            else if((strcmp(getcw(), "pelanggan") == 0)){
                if(eop(tape) == 1){
                    error1();
                } else{
                    cek2 = 1;
                    cek = 0;
                    readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 0);
                    
                    inc(tape);
                    if(eop(tape) == 1){
                        error3();
                    } else{
                        for(int i = 0; i<q; i++){
                            if(strcmp(getcw(), listPelanggan[i].id_pelanggan)== 0){
                                cek = 1;
                            }
                        }

                        if(cek == 1 && q_ubah == 0){
                                printf("<<error>> id pelanggan sudah terdapat pada data pelanggan\n");
                        } 
                        else if(cek == 1 && q_ubah == 1){
                            idx = temp_idx;
                            ubah(tape, listBarang, listPelanggan, 0);
                        } else{

                            strcpy(listPelanggan[q].id_pelanggan, getcw());
                            temp_idx = idx;
                            inc(tape);
                            if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") <= 0))){
                                if((eop(tape) == 0)){
                                    inc(tape);
                                    if((eop(tape) == 1 && (strcmp(getcw(), "00") <= 0))){
                                        idx = temp_idx;
                                        inc(tape);
                                        strcpy(listPelanggan[q].nama_pelanggan, getcw());
                                        q++;

                                        writeToFile_ListPelanggan(q, listPelanggan, "../data/pelanggan.dat");

                                        printf("\nData Pelanggan telah bertambah\n\n");
                                        
                                        q=0;
                                        readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1); 
                                    }
                                    else{
                                        error4();
                                    }
                                } else{
                                    error3();
                                }
                            } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
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
                
                
            }
            else if((strcmp(getcw(), "ubah") == 0) || (strcmp(getcw(), "UBAH") == 0) ||(strcmp(getcw(), "Ubah") == 0)){
                temp_idx = idx;
                tambah(tape, listBarang, listPelanggan, 1);
            }
            else if((strcmp(getcw(), "lihat") == 0) || (strcmp(getcw(), "LIHAT") == 0) ||(strcmp(getcw(), "Lihat") == 0)){
                tambah(tape, listBarang, listPelanggan, 0);
            }
            else if((strcmp(getcw(), "hapus") == 0) || (strcmp(getcw(), "HAPUS") == 0) ||(strcmp(getcw(), "Hapus") == 0)){
                printf("\n<<error>> Perintah tidak diijinkan\n");
            }
            else{
                if(cek2 == 0){
                    error2();
                }
            }

        }else{
            error1();
        }
}


void ubah(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100], int q_tambah){
    int p = 0, q = 0;
    int cek = 0;
    int found = 0;
    if (eop(tape) == 0){
        inc(tape);
        if((strcmp(getcw(), "barang") == 0)){
            if(eop(tape) == 1){
                error3();
            } else{
                cek = 0;
                found = 0;
                readFile_ListBarang(&p, listBarang, "../data/barang.dat", 0);
                
                inc(tape);
                if(eop(tape) == 1){
                    error3();
                } else{
                    for(int i = 0; i<p; i++){
                        if(strcmp(getcw(), listBarang[i].id_barang)== 0){
                            cek = i;
                            found = 1;
                            i = p;
                        }
                    }

                    if(found == 0 && q_tambah == 0){
                        printf("<<error>> id barang tidak ditemukan\n");
                    } else if(found == 0 && q_tambah == 1){
                        idx = temp_idx;
                        tambah(tape, listBarang, listPelanggan, 0);
                    } 
                    else{
                        temp_idx = idx;
                        inc(tape);

                        if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") <= 0))){
                            if((eop(tape) == 0)){
                                inc(tape);
                                if((eop(tape) == 1 && (strcmp(getcw(), "00") <= 0))){
                                    idx = temp_idx;
                                    inc(tape);
                                    strcpy(listBarang[cek].nama_barang, getcw());

                                    writeToFile_ListBarang(p, listBarang, "../data/barang.dat");
                                    printf("\ndata telah berubah\n\n");
                                    
                                    p=0;
                                    readFile_ListBarang(&p, listBarang, "../data/barang.dat", 1);
                                }
                                else{
                                    error4();
                                }
                            } else{
                                error3();
                            }
                        } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
                            strcpy(listBarang[cek].nama_barang, getcw());

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
            if(eop(tape) == 1){
                error3();
            } else{
                cek = 0;
                found = 0;
                readFile_ListPelanggan(&p, listPelanggan, "../data/pelanggan.dat", 0);
                
                inc(tape);
                if(eop(tape) == 1){
                    error3();
                } else{
                    
                    for(int i = 0; i<p; i++){
                        if(strcmp(getcw(), listPelanggan[i].id_pelanggan)== 0){
                            cek = i;
                            found = 1;
                            i = p;
                        }
                    }

                    if(found == 0 && q_tambah == 0){
                        printf("<<error>> id pelanggan tidak ditemukan\n");
                    } else if(found == 0 && q_tambah == 1){
                        idx = temp_idx;
                        tambah(tape, listBarang, listPelanggan, 0);
                    } else{
                        temp_idx = idx;
                        inc(tape);

                        if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") <= 0))){
                            if((eop(tape) == 0)){
                                inc(tape);
                                if((eop(tape) == 1 && (strcmp(getcw(), "00") <= 0))){
                                    idx = temp_idx;
                                    inc(tape);
                                    strcpy(listPelanggan[cek].nama_pelanggan, getcw());

                                    writeToFile_ListPelanggan(p, listPelanggan, "../data/pelanggan.dat");
                                    printf("data berhasil diubah\n\n");

                                    q=0;
                                    readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 1);
                                }
                                else{
                                    error4();
                                }
                            } else{
                                error3();
                            }
                        } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
                            strcpy(listPelanggan[cek].nama_pelanggan, getcw());

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
            ubah(tape, listBarang, listPelanggan, 0);
        }
        else if((strcmp(getcw(), "tambah") == 0) || (strcmp(getcw(), "TAMBAH") == 0) ||(strcmp(getcw(), "Tambah") == 0)){
            temp_idx = idx;
            ubah(tape, listBarang, listPelanggan, 1);
        }
        else if((strcmp(getcw(), "hapus") == 0) || (strcmp(getcw(), "HAPUS") == 0) ||(strcmp(getcw(), "Hapus") == 0)){
            printf("\n<<error>> Perintah tidak diijinkan\n");
        } else{
            error2();
        }
    } else{
        error1();
    }
}


void hapus(char tape[500], dataBarang listBarang[100], dataPelanggan listPelanggan[100]){
    int p = 0, q = 0;
    int cek = 0;
    int found = 0;
    if (eop(tape) == 0){
        inc(tape);
        if((strcmp(getcw(), "barang") == 0)){
            if(eop(tape) == 1){
                error3();
            } else{
                cek = 0;
                found = 0;
                readFile_ListBarang(&p, listBarang, "../data/barang.dat", 0);
                
                inc(tape);
                
                    for(int i = 0; i<p; i++){
                        if(strcmp(getcw(), listBarang[i].id_barang)== 0){
                            cek = i;
                            found = 1;
                            i = p;
                        }
                    }

                    if(found == 0){
                        printf("<<error>> id barang tidak ditemukan\n");
                    } else{
                        if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") <= 0))){
                            if((eop(tape) == 0)){
                                inc(tape);
                                if((eop(tape) == 1 && (strcmp(getcw(), "00") <= 0))){
                                    strcpy(listBarang[cek].id_barang, "\0");
                                    strcpy(listBarang[cek].nama_barang, "\0");

                                    for(int i = cek; i<p; i++){
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
                                    error4();
                                }
                            } else{
                                    test();
                                error3();
                            }
                        } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
                            strcpy(listBarang[cek].id_barang, "\0");
                            strcpy(listBarang[cek].nama_barang, "\0");

                            for(int i = cek; i<p; i++){
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
        }

        else if((strcmp(getcw(), "pelanggan") == 0)){
            if(eop(tape) == 1){
                error3();
            } else{

                cek = 0;
                found = 0;
                readFile_ListPelanggan(&q, listPelanggan, "../data/pelanggan.dat", 0);
                
                inc(tape);
                
                for(int i = 0; i<q; i++){
                    if(strcmp(getcw(), listPelanggan[i].id_pelanggan)== 0){
                        cek = i;
                        found = 1;
                        i = q;
                    }
                }

                if(found == 0){
                    printf("<<error>> id pelanggan tidak ditemukan\n");
                } else{
                    if((eop(tape) == 0) || ((eop(tape) == 1) && (strcmp(getcw(), "00") <= 0))){
                        if((eop(tape) == 0)){
                            inc(tape);
                            if((eop(tape) == 1 && (strcmp(getcw(), "00") <= 0))){
                                strcpy(listPelanggan[cek].id_pelanggan, "\0");
                                strcpy(listPelanggan[cek].nama_pelanggan, "\0");
                                    
                                for(int i = cek; i<q; i++){
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
                                error4();
                            }
                        } else{
                            error3();
                        }
                    } else if((eop(tape) == 1) && (strcmp(getcw(), "00") > 0)){
                        strcpy(listPelanggan[cek].id_pelanggan, "\0");
                        strcpy(listPelanggan[cek].nama_pelanggan, "\0");
                            
                        for(int i = cek; i<q; i++){
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
        }
        else if((strcmp(getcw(), "lihat") == 0) || (strcmp(getcw(), "LIHAT") == 0) ||(strcmp(getcw(), "Lihat") == 0)){
               hapus(tape, listBarang, listPelanggan);
        }
        else{
            error2();
        }
    } else{
        error1();
    }
}


// int cekMonoQuery(char tape[500]){
//     int perintah = 0;
//     start(tape);
//     if((strcmp(getcw(), "00") > 0) && (eop(tape) == 0)){
//         perintah++;
//         inc(tape);
//         if((strcmp(getcw(), "00") > 0) && (eop(tape) == 0)){
//             perintah++;
//             inc(tape);
//             if((strcmp(getcw(), "00") > 0) && (eop(tape) == 0)){
//                 perintah++;
//                 inc(tape);             
//                 if((strcmp(getcw(), "00") > 0) && (eop(tape) == 1)){
//                     perintah++;
//                     inc(tape);
//                 } else{
//                     inc(tape);
//                     if((strcmp(getcw(), "00") <= 0) && (eop(tape) == 1)){
//                         perintah++;
//                         inc(tape);
//                     }
//                 }               
//             }
//         }
//     }
//     return perintah;
// }


// int cekDuoQuery(char tape[500]){
//     int perintah = 0;
//     start(tape);
//     if((strcmp(getcw(), "00") > 0) && (eop(tape) == 0)){
//         perintah++;
//         inc(tape);
//         if((strcmp(getcw(), "00") > 0) && (eop(tape) == 0)){
//             perintah++;
//             inc(tape);
//             if((strcmp(getcw(), "00") > 0) && (eop(tape) == 0)){
//                 perintah++;
//                 inc(tape);
//                 if((strcmp(getcw(), "00") > 0) && (eop(tape) == 0)){
//                     perintah++;
//                     inc(tape);
//                     if((strcmp(getcw(), "00") > 0) && (eop(tape) == 1)){
//                         perintah++;
//                         inc(tape);
//                     } else{
//                         inc(tape);
//                         if((strcmp(getcw(), "00") <= 0) && (eop(tape) == 1)){
//                             perintah++;
//                             inc(tape);
//                         }
//                     } 
//                 }
//             }
//         }
//     }
//     return perintah;
// }