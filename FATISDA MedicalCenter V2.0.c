//FATISDA MEDICAL CENTER v2.0
//Oleh Muhammad Haidar Amru
//run on cmd/terminal plz :)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define DATA_PASIEN "data pasien.txt"
//Fungsi delay
void delay(int milliseconds) {
    Sleep(milliseconds);
}

// Fungsi untuk mencetak teks per karakter (animasi)
void typeAnimation(char *teks, int kecepatan) {
    
    while (*teks != '\0') {
        printf("%c", *teks);
        fflush(stdout);
        delay(kecepatan);
        teks++;
    }
}

//Fungsi clear screen
void clearScreen() {
        system("cls");
}


struct dataPasien {
    int id;
    char nama[50];
    char jk; //(jenis kelamin L/P)
    int umur;
    float suhu;
    float berat;
    float tinggi;

    struct dataPasien *next;
};

struct dataPasien *head = NULL;

void tambahPasien() {
    struct dataPasien *pasienBaru = (struct dataPasien *)malloc(sizeof(struct dataPasien));

    if (pasienBaru == NULL) {
        printf("Memori Penuh!\n");
        return;
    }

    printf("=== Tambah Data Pasien ===\n");
    printf("Masukkan ID Pasien: ");
    scanf ("%d", &pasienBaru->id);
    printf("Masukkan Nama Pasien: ");
    scanf (" %[^\n]", pasienBaru->nama);
    do
    {
        printf("Masukkan Jenis Kelamin (L/P): ");
        scanf(" %c", &pasienBaru->jk);
    } while (pasienBaru->jk != 'L' && pasienBaru->jk != 'P' && pasienBaru->jk != 'l' && pasienBaru->jk != 'p');
    
    printf("Masukkan Umur Pasien (tahun): ");
    scanf ("%d", &pasienBaru->umur);
    printf("Masukkan Suhu Tubuh Pasien (Celsius): ");
    scanf ("%f", &pasienBaru->suhu);    
    printf("Masukkan Berat Badan Pasien (kg): ");
    scanf ("%f", &pasienBaru->berat);
    printf("Masukkan Tinggi Badan Pasien (cm): ");
    scanf ("%f", &pasienBaru->tinggi);
    

    //utk pasien pertama
    pasienBaru->next = NULL;
    
    //utk pasien pertama
    if (head == NULL)
    {
        head = pasienBaru;
    }
    //utk pasien selanjutnya
    else
    {
        //mencari letak pasien terakhir
        struct dataPasien *temp = head;
        while (temp->next != NULL)
        {
        temp = temp->next;
        }
        temp->next = pasienBaru;
    }
    printf("\nData pasien berhasil ditambahkan!\n");
    delay(1000);
}

void muatDataPasien() {
    FILE *fp = fopen(DATA_PASIEN, "r");

    if (fp == NULL){
        return;
    }

    int tmpID;
    char tmpNama[50];
    char tmpJK;
    int tmpUmur;
    float tmpSuhu;
    float tmpBerat;
    float tmpTinggi;   

    while (fscanf(fp, "%d#%[^#]#%c#%d#%f#%f#%f",
        &tmpID, tmpNama, &tmpJK, &tmpUmur, &tmpSuhu, &tmpTinggi, &tmpBerat) != EOF){
            struct dataPasien *dataBaru = (struct dataPasien *)malloc(sizeof(struct dataPasien));

            dataBaru->id = tmpID;
            strcpy(dataBaru->nama, tmpNama);
            dataBaru->jk = tmpJK;
            dataBaru->umur = tmpUmur;
            dataBaru->suhu = tmpSuhu;
            dataBaru->tinggi = tmpTinggi;
            dataBaru->berat = tmpBerat;

            dataBaru->next = NULL;

            if (head == NULL){
            head = dataBaru;
            }
            else{
            struct dataPasien *temp = head;
            while (temp->next != NULL)
            {
            temp = temp->next;
            }
            temp->next = dataBaru;
            }
        }
        fclose(fp);
        printf("Data berhasil dimuat dari data pasien.txt\n");
        delay(1000);
        clearScreen();
    }

void simpanDataPasien(){
    FILE *fp = fopen(DATA_PASIEN, "w");
    if (fp == NULL) {
        printf("Gagal membuat file :(\n");
        return;
    }
    struct dataPasien *current = head;

    while (current != NULL){
        fprintf(fp, "%d#%s#%c#%d#%.1f#%.1f#%.1f\n", current->id, current->nama, current->jk, current->umur,
                current->suhu, current->tinggi, current->berat);
        current = current->next;
    }
    fclose (fp);
}

void cekDataPasien() {
    if (head == NULL) {
        printf("\nBelum ada data pasien!\n");
        delay(2000);
        return;
    }

    struct dataPasien *current = head;
    int count = 0;

    printf("=== Lihat Semua Data Pasien ===\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("| %-3s | | %-15s | | %-4s | | %-4s | | %-6s  | | %-6s | | %-6s |\n",
            "ID", "Nama", "JK", "Umur", "Suhu", "Tinggi", "Berat");
    while (current != NULL) {
        printf("| %-3d | | %-15s | | %-4c | | %-4d | | %-6.1fC | | %-6.1f | | %-6.1f |\n",
                current->id, current->nama, current->jk, current->umur,
                current->suhu, current->tinggi, current->berat);
        
        //pindah ke pasien berikutnya
        current = current->next;
        count++;

}
    //itung jml total pasien
    printf("-------------------------------------------------------------------------------\n");
    typeAnimation("Total pasien terdaftar: ", 50);
    printf("%d\n", count);
    delay(2000);
}

void cariRekursif(struct dataPasien *current, int idCari) {
    if(current == NULL){
        printf("Pasien dengan id %d tidak ditemukan!", idCari);
        return;
    }
    if (current->id == idCari){
        printf("Pasien ditemukan!\n");
        printf("-------------------------------------------------------------------------------\n");
        printf("| %-3s | | %-15s | | %-4s | | %-4s | | %-6s  | | %-6s | | %-6s |\n",
            "ID", "Nama", "JK", "Umur", "Suhu", "Tinggi", "Berat");

        printf("| %-3d | | %-15s | | %-4c | | %-4d | | %-6.1fC | | %-6.1f | | %-6.1f |\n",
                current->id, current->nama, current->jk, current->umur,
                current->suhu, current->tinggi, current->berat);

        return;
    }
    cariRekursif(current->next, idCari);
}

void cariPasienByID() {
    if (head == NULL){
        printf("\nBelum ada data pasien!\n");
        delay(1000);
        return;
    }

    int cariID;

    struct dataPasien *current = head;

    printf("Masukkan ID pasien yang ingin dicari : ");
    scanf("%d", &cariID);
    clearScreen();
    cariRekursif(head, cariID);

}

void cekKondisi() {
    if (head == NULL){
        printf("\nBelum ada data pasien!\n");
        delay(1000);
        return;
    }

    int cariID;
    struct dataPasien *current = head;

    printf("Masukkan ID pasien yang ingin dicek : ");
    scanf("%d", &cariID);
    clearScreen();
    while (current != NULL){
    if (current->id == cariID){
            printf("=== Kondisi Pasien Saat Ini ===\n");
            printf ("\nNama : %s\n", current->nama);
            printf ("Suhu %s : %.1fC\n", current->nama, current->suhu);
            
            if (current->suhu < 36.0)
                printf("Keterangan kondisi %s : Suhu rendah, mengalami hipotermia ringan\n", current->nama);
            else if (current->suhu <= 37.5)
                printf("Keterangan kondisi %s : Suhu normal jaga kesehatan!\n", current->nama);
            else if (current->suhu <= 38.5)
                printf("Keterangan kondisi %s : Demam ringan, minum paracetamol!\n", current->nama);
            else if (current->suhu <= 40.0)
                printf("Keterangan kondisi %s : Demam tinggi, konsultasikan ke dokter segera!\n", current->nama);
            else
                printf("Keterangan kondisi : Suhu terlalu tinggi, %s butuh penanganan segera!\n", current->nama);
            
                return;
        }
        current = current->next;
    }
    printf("Pasien dengan id %d tidak ditemukan!", cariID);
    return;
}

void cekBBI() {

    float bbi = 0;

    if (head == NULL){
        printf("\nBelum ada data pasien!\n");
        delay(1000);
        return;
    }

    int cariID;
    struct dataPasien *current = head;

    printf("Masukkan ID pasien yang ingin dicek : ");
    scanf("%d", &cariID);
    clearScreen();
    while (current != NULL){
    if (current->id == cariID){
        if (current->jk == 'l' || current->jk == 'L'){
        bbi = (current->tinggi - 100) * 0.9;
            }
        else if (current->jk == 'p' || current->jk == 'P'){
        bbi = (current->tinggi - 100) * 0.85;
            }
        else {
                printf("Error: Jenis kelamin pasien tidak valid!\n");
                return;
            }
        printf ("=== BBI Pasien === \n");
        printf("Nama   : %s\n", current->nama);
        printf("Tinggi : %.1f cm\n", current->tinggi);
        printf("Berat  : %.1f kg\n", current->berat);
        printf("BBI    : %.1f kg\n", bbi);

        if (current->berat > bbi + 5){
            printf("Berat badan %s di atas ideal.\n", current->nama);
            }
        else if (current->berat < bbi - 5){
            printf("Berat badan %s di bawah ideal.\n",  current->nama);
            }
        else {
            printf ("Berat badan %s sudah ideal.",  current->nama);
            }
        return;
        }
        current = current->next; 
    }
    printf("Pasien dengan id %d tidak ditemukan!", cariID);
    return;
}

void statistikUmur() {
    if (head == NULL) {
        printf("\nBelum ada data pasien!\n");
        return;
    }

    int kumpulanUmur[100]; 
    int jumlahData = 0;
    float totalUmur = 0;

    struct dataPasien *current = head;

    while (current != NULL && jumlahData < 100) {
        kumpulanUmur[jumlahData] = current->umur;
        current = current->next;
        jumlahData++;
    }

    printf("=== Statistik Umur Pasien (Dari Array) ===\n");
    printf("Data Umur: ");
    for (int i = 0; i < jumlahData; i++) {
        printf("%d ", kumpulanUmur[i]);
        totalUmur += kumpulanUmur[i];
    }

    printf("\nRata-rata Umur: %.2f tahun\n", totalUmur / jumlahData);
}
    
void rekapKondisi (){
    if (head == NULL) {
        printf("\nBelum ada data pasien!\n");
        return;
    }

    int suhu[3] = {0, 0, 0};

    struct dataPasien *current = head;

    while (current != NULL){
        if (current->suhu <= 37.5){
            suhu[0]++;
        
        }
        else if (current->suhu <= 39.0){
            suhu[1]++;
        }
        else {
            suhu[2]++;
        }
        current = current->next;
    }
    printf("=== Rekap Kondisi Pasien ===\n");
    printf("\n1. Kondisi Normal/Aman  : %d pasien\n", suhu[0]);
    printf("2. Kondisi Demam        : %d pasien\n", suhu[1]);
    printf("3. Kondisi DARURAT      : %d pasien\n", suhu[2]);
}


int main (){
    typeAnimation("Loading data pasien...", 5);
    delay(1000);
    clearScreen();
    muatDataPasien();
    int pilMenu; 
    char pilUlang;

    // --- FATISDA ---
    typeAnimation("                      ______    _  _____ ___ ____  ____    _    \n", 5);
    typeAnimation("                     |  ____|  / \\|_   _|_ _/ ___||  _ \\  / \\   \n", 5);
    typeAnimation("                     | |__    / _ \\ | |  | |\\___ \\| | | |/ _ \\  \n", 5);
    typeAnimation("                     |  __|  / ___ \\| |  | | ___) | |_| / ___ \\ \n", 5);
    typeAnimation("                     | |    / /   \\ \\ |  | ||____/|____/_/   \\_\\\n", 5);
    typeAnimation("                     |_|   /_/     \\_\\_| |___|                  \n", 5);
    typeAnimation("\n", 5);

    // --- MEDICAL ---
    typeAnimation("  __  __ _____ ____ ___ ____    _    _         ____ _____ _   _ _____ _____ ____        \n", 5);
    typeAnimation(" |  \\/  | ____|  _ \\_ _/ ___|  / \\  | |       / ___| ____| \\ | |_   _| ____|  _ \\       \n", 5);
    typeAnimation(" | |\\/| |  _| | | | | | |     / _ \\ | |      | |   |  _| |  \\| | | | |  _| | |_) |      \n", 5);
    typeAnimation(" | |  | | |___| |_| | | |___ / ___ \\| |___   | |___| |___| |\\  | | | | |___|  _ <       \n", 5);
    typeAnimation(" |_|  |_|_____|____/___\\____/_/   \\_\\_____|   \\____|_____|_| \\_| |_| |_____|_| \\_\\      \n", 5);
    typeAnimation("\n", 5);

    typeAnimation("                            BY Muhammad Haidar Amru                       \n", 20);
    typeAnimation("                          Informatika A, NIM L0125025                     \n", 20);
    typeAnimation("                         Version 2.0.  -  December 2025                   \n", 20);
    printf("\n");

    typeAnimation("Press Enter to continue...", 50);  
    getchar(); 
    clearScreen();

    

    do
    {
        do {
        printf ("============================\n");
        printf ("     SILAHKAN PILIH MENU    \n");
        printf ("============================\n");
        printf("\n1. Tambah Data Pasien");
        printf("\n2. Lihat Semua Data Pasien");
        printf("\n3. Cari Data Pasien Berdasarkan ID");
        printf("\n4. Cek Kondisi Pasien");
        printf("\n5. Hitung Berat Badan Ideal");
        printf("\n6. Statistik Umur");
        printf("\n7. Rekap Kondisi Pasien");
        printf("\n8. Keluar Program\n");

        printf("\n----------------------------");
        printf("\nPilih menu (1-8) : ");
        int pilihan = scanf("%d", &pilMenu);

        if (pilihan != 1) { 
            while(getchar() != '\n');
            pilMenu = 0; 
        }

        if (pilMenu < 1 || pilMenu > 8){
            printf ("\nPilihan tidak VALID, silahkan coba lagi\n");
            delay (1000);
            clearScreen();
            }
        
        } while (pilMenu < 1 || pilMenu > 8);

        switch (pilMenu) {
    case 1:
        clearScreen();
        tambahPasien();
        printf("\nKembali ke menu utama? (y/n) : ");
        scanf(" %c", &pilUlang);
        clearScreen();
        
        break;
    case 2 :
        clearScreen();
        cekDataPasien();
        printf("\nKembali ke menu utama? (y/n) : ");  
        scanf(" %c", &pilUlang);
        clearScreen();
        break;
    case 3 : 
        clearScreen();
        cariPasienByID();
        printf("\nKembali ke menu utama? (y/n) : ");  
        scanf(" %c", &pilUlang);
        clearScreen();
        break;
    case 4 : 
        clearScreen();
        cekKondisi();
        printf("\nKembali ke menu utama? (y/n) : ");  
        scanf(" %c", &pilUlang);
        clearScreen();
        break;
    case 5 :
        clearScreen();
        cekBBI();
        printf("\nKembali ke menu utama? (y/n) : ");  
        scanf(" %c", &pilUlang);
        clearScreen();
        break;
    case 6 : 
        clearScreen();
        statistikUmur();
        printf("\nKembali ke menu utama? (y/n) : ");  
        scanf(" %c", &pilUlang);
        clearScreen();
        break;
    case 7 : 
        clearScreen();
        rekapKondisi();
        printf("\nKembali ke menu utama? (y/n) : ");  
        scanf(" %c", &pilUlang);
        clearScreen();
        break;
    case 8 : 
        clearScreen();
        simpanDataPasien();
        typeAnimation("Data Pasien berhasil disimpan!\n", 10);
        typeAnimation ("\nTerima kasih telah menggunakan layanan FATISDA Medical Center v2.0!\n", 10);
        delay(1000);
        return 0;
    default:
        break;
        
    }
        } while (pilUlang == 'y' || pilUlang == 'Y');
    
    return 0;
    }
