/* ==============================================================================
 * BILGISAYAR PROGRAMLAMA 3 (BP3) - C PROGRAMMING & DATA STRUCTURES PROJECT
 * ==============================================================================
 * Author      : Muhammed Emin Korkunç (Student ID: 2021221054)
 * Institution : Fatih Sultan Mehmet Vakıf Üniversitesi - Bilgisayar Mühendisliği
 * GitHub      : https://github.com/muhammedkorkunc
 * LinkedIn    : https://www.linkedin.com/in/muhammed-emin-korkun%C3%A7-100ba2215
 * Email       : muhammedemin.korkunc@gmail.com
 * License     : Proprietary - All Rights Reserved (c) 2026
 * ==============================================================================
 * NOTICE: Unauthorized copying, reverse engineering or distribution of this
 * software and algorithms is strictly prohibited under copyright law.
 * ==============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Proje1.h"
#define MAX_OGRENCI_SAYISI 4

/* 
* @file Proje1.c 
* @description 1. İlgili değerleri alıp bir Ders struct döndüren. 
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/

Ders *createDers(const char *dersAdi, unsigned short int kredi, unsigned short int puan) {
    Ders *newDers = (Ders *)malloc(sizeof(Ders));

    if (newDers == NULL) {
        printf("Bellek tahsisi yapilamadi.\n");
        exit(EXIT_FAILURE);
    }

    newDers->dersAdi = (char *)malloc(strlen(dersAdi) + 1);
    if (newDers->dersAdi == NULL) {
        printf("Bellek tahsisi yapilamadi.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newDers->dersAdi, dersAdi);

    newDers->kredi = kredi;
    newDers->puan = puan;
    
    return newDers;
}

/* 
* @file Proje1.c 
* @description 2. İlgili değerleri alıp bir Ogrenci struct döndüren.
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/
Ogrenci *createOgrenci(const char *ogrAdi, const char *ogrSoyAdi, const char *bolumu, float ortalama, Ders *aldigiDersler) {
    Ogrenci *newOgrenci = (Ogrenci *)malloc(sizeof(Ogrenci));

    if (newOgrenci == NULL) {
        printf("Bellek tahsisi yapilamadi.\n");
        exit(EXIT_FAILURE);
    }

    newOgrenci->ogrAdi = (char *)malloc(strlen(ogrAdi) + 1);
    if (newOgrenci->ogrAdi == NULL) {
        printf("Bellek tahsisi yapilamadi.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newOgrenci->ogrAdi, ogrAdi);

    newOgrenci->ogrSoyAdi = (char *)malloc(strlen(ogrSoyAdi) + 1);
    if (newOgrenci->ogrSoyAdi == NULL) {
        printf("Bellek tahsisi yapilamadi.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newOgrenci->ogrSoyAdi, ogrSoyAdi);

    newOgrenci->bolumu = (char *)malloc(strlen(bolumu) + 1);
    if (newOgrenci->bolumu == NULL) {
        printf("Bellek tahsisi yapilamadi.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newOgrenci->bolumu, bolumu);

    newOgrenci->ortalama = ortalama;
    newOgrenci->aldigiDersler = aldigiDersler;

    return newOgrenci;
}

/* 
* @file Proje1.c 
* @description 3. Parametre olarak Ogrenci türünden değişken alıp bilgilerini yazdıran.
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/
void printOgrenci(const Ogrenci *ogrenci) {


    printf("Ogrenci Adi: %s %s\n", ogrenci->ogrAdi, ogrenci->ogrSoyAdi);
    printf("Bolum: %s\n", ogrenci->bolumu);
    printf("Ortalama: %.2f\n", ogrenci->ortalama);

    printf("Aldigi Dersler:\n");
    for (int i = 0; i < 4; ++i) {
        printf("Ders %d: %s, Kredi: %d, Puan: %d\n", i + 1, ogrenci->aldigiDersler[i].dersAdi, ogrenci->aldigiDersler[i].kredi, ogrenci->aldigiDersler[i].puan);
    }
}

/* 
* @file Proje1.c 
* @description 4. Parametre olarak Ogrenci türünden dinamik bir dizi alıp bilgilerini 
yazdıran.
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/
void printOgrenciArray(const Ogrenci *ogrenciler, int size) {   

    for (int i = 0; i < size; ++i) {
        printf("Ogrenci %d:\n", i + 1);
        printf("Adi: %s %s\n", ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi);
        printf("Bolum: %s\n", ogrenciler[i].bolumu);
        printf("Ortalama: %.2f\n", ogrenciler[i].ortalama);
        
        printf("Aldigi Dersler:\n");
        for (int j = 0; j < 4; ++j) {
            printf("Ders %d: %s, Kredi: %d, Puan: %d\n", j + 1, ogrenciler[i].aldigiDersler[j].dersAdi, ogrenciler[i].aldigiDersler[j].kredi, ogrenciler[i].aldigiDersler[j].puan);
        }
        printf("\n");
    }
}

/* 
* @file Proje1.c 
* @description 5. Parametre olarak aldığı dersAdi değerine göre bir dersin aritmetik
ortalamasını hesaplayan.
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/
float calculateDersOrtalama(const Ogrenci *ogrenciler, int size, const char *dersAdi) {


    int toplamNot = 0;
    int dersSayisi = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 4; ++j) { // Öğrencinin aldığı derslerin sayısı 4 olsun
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi) == 0) {
                toplamNot += ogrenciler[i].aldigiDersler[j].puan;
                dersSayisi++;
            }
        }
    }

    if (dersSayisi == 0) {
        printf("Belirtilen dersi alan ogrenci bulunamadi.\n");
        return 0.0;
    }

    float ortalama = (float)toplamNot / dersSayisi;
    return ortalama;
}


/* 
* @file Proje1.c 
* @description 6. Parametre olarak aldığı dersAdi değerine göre bir dersin standart 
sapmasını hesaplayan.
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/

float calculateDersStandartSapma(const Ogrenci *ogrenciler, int size, const char *dersAdi) {
    int dersNotlari[100]; 
    int notIndex = 0;

    // Belirtilen dersin notlarını bulma
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 4; ++j) { 
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi) == 0) {
                dersNotlari[notIndex++] = ogrenciler[i].aldigiDersler[j].puan;
            }
        }
    }

    // Eğer belirtilen dersi alan öğrenci yoksa
    if (notIndex == 0) {
        printf("Belirtilen dersi alan ogrenci bulunamadi.\n");
        return 0.0;
    }

    // Standart sapma hesaplama
    float ortalama = 0;
    for (int i = 0; i < notIndex; ++i) {
        ortalama += dersNotlari[i];
    }
    ortalama /= notIndex;

    float toplamKareFark = 0;
    for (int i = 0; i < notIndex; ++i) {
        toplamKareFark += pow(dersNotlari[i] - ortalama, 2);
    }

    float standartSapma = sqrt(toplamKareFark / notIndex);
    return standartSapma;
}
 
 /* 
* @file Proje1.c 
* @description 7. Parametre olarak aldığı Ders türünden iki dersin kovaryansını hesaplayan.
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/
float calculateKovaryans(const Ogrenci *ogrenciler, int size, const char *dersAdi1, const char *dersAdi2) {
    int ders1Notlari[size];
    int ders2Notlari[size];
    int notIndex = 0;

    // Belirtilen derslerin notlarını bulma
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi1) == 0) {
                ders1Notlari[notIndex] = ogrenciler[i].aldigiDersler[j].puan;
            }
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi2) == 0) {
                ders2Notlari[notIndex] = ogrenciler[i].aldigiDersler[j].puan;
                notIndex++;
            }
        }
    }

    // Eğer belirtilen dersleri alan öğrenci yoksa
    if (notIndex == 0) {
        printf("Belirtilen dersleri alan ogrenci bulunamadi.\n");
        return 0.0;
    }

    // Ortalamaları bulma
    float ders1Ortalama = 0, ders2Ortalama = 0;
    for (int i = 0; i < notIndex; ++i) {
        ders1Ortalama += ders1Notlari[i];
        ders2Ortalama += ders2Notlari[i];
    }
    ders1Ortalama /= notIndex;
    ders2Ortalama /= notIndex;

    // Kovaryansı hesaplama
    float kovaryans = 0;
    for (int i = 0; i < notIndex; ++i) {
        kovaryans += (ders1Notlari[i] - ders1Ortalama) * (ders2Notlari[i] - ders2Ortalama);
    }
    kovaryans /= (notIndex - 1); // Bölme işlemi (n-1) ile yapılır

    return kovaryans;
}

 /* 
* @file Proje1.c 
* @description 8. Parametre olarak aldığı dersAdi değerine göre bir dersin ortalama 
puanından daha yüksek not almış öğrencileri listeleyen.
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/
void printOgrenciYuksekNotlar(const Ogrenci *ogrenciler, int size, const char *dersAdi, float ortalamaPuan) {
    printf("%s dersinin ortalama puani olan %.2f'den yuksek not alan ogrenciler:\n", dersAdi, ortalamaPuan);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 4; ++j) { 
            if (strcmp(ogrenciler[i].aldigiDersler[j].dersAdi, dersAdi) == 0 &&
                ogrenciler[i].aldigiDersler[j].puan > ortalamaPuan) {
                printf("Ogrenci %d: %s %s, Puan: %d\n", i + 1, ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi, ogrenciler[i].aldigiDersler[j].puan);
                break; // Aynı dersi bir öğrencinin birden fazla kez alması durumunda tekrar etmemek için.
            }
        }
    }
}

 /* 
* @file Proje1.c 
* @description 9. Tüm öğrenci bilgilerini bir dosyaya yazan.
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/
void writeOgrenciToFile(const Ogrenci *ogrenciler, int size, const char *dosyaAdi) {

    FILE *dosya = fopen(dosyaAdi, "w");
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; ++i) {
        fprintf(dosya, "Ogrenci %d:\n", i + 1);
        fprintf(dosya, "Adi: %s %s\n", ogrenciler[i].ogrAdi, ogrenciler[i].ogrSoyAdi);
        fprintf(dosya, "Bolum: %s\n", ogrenciler[i].bolumu);
        fprintf(dosya, "Ortalama: %.2f\n", ogrenciler[i].ortalama);

        fprintf(dosya, "Aldigi Dersler:\n");
        for (int j = 0; j < 4; ++j) {
            fprintf(dosya, "Ders %d: %s, Kredi: %d, Puan: %d\n", j + 1, ogrenciler[i].aldigiDersler[j].dersAdi, ogrenciler[i].aldigiDersler[j].kredi, ogrenciler[i].aldigiDersler[j].puan);
        }
        fprintf(dosya, "\n");
    }

    fclose(dosya);
}

/* 
* @file Proje1.c 
* @description 10. Program başladığında bu dosyayı okumalı ve dosyadaki öğrencileri bir 
Ogrenci dizisine eklemelidir. Dosya adı Command Line Parameter olarak 
gönderilmelidir. Yani programda dosya adı ve konumunu main’de verilen 
argümanlardan okumalısınız.
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/
Ogrenci *readOgrenciFromFile(const char *dosyaAdi) {
    FILE *dosya = fopen(dosyaAdi, "r");
    
    if (dosya == NULL) {
        printf("Dosya acilamadi.\n");
        exit(EXIT_FAILURE);
    }

    Ogrenci *ogrenciDizisi = (Ogrenci *)malloc(MAX_OGRENCI_SAYISI * sizeof(Ogrenci));
    if (ogrenciDizisi == NULL) {
        printf("Bellek tahsisi yapilamadi.\n");
        exit(EXIT_FAILURE);
    }

    int ogrenciIndex = 0;
    char satir[1000];

    while (fgets(satir, sizeof(satir), dosya) != NULL) {
        if (strstr(satir, "Ogrenci") != NULL) {
            // Yeni bir öğrenci 
            sscanf(satir, "Ogrenci %*d:", &ogrenciIndex);
            fgets(ogrenciDizisi[ogrenciIndex - 1].ogrAdi, sizeof(ogrenciDizisi[ogrenciIndex - 1].ogrAdi), dosya);
            fgets(ogrenciDizisi[ogrenciIndex - 1].bolumu, sizeof(ogrenciDizisi[ogrenciIndex - 1].bolumu), dosya);
            fscanf(dosya, "Ortalama: %f", &ogrenciDizisi[ogrenciIndex - 1].ortalama);

            for (int i = 0; i < 4; ++i) {
                fscanf(dosya, "Ders %d: %s, Kredi: %*d, Puan: %d",
                       &i, ogrenciDizisi[ogrenciIndex - 1].aldigiDersler[i].dersAdi,
                       &ogrenciDizisi[ogrenciIndex - 1].aldigiDersler[i].puan);
            }
        }
    }

    fclose(dosya);
    return ogrenciDizisi;
}

 
    


static const char* __PROPRIETARY_AUTH_CANARY__ __attribute__((used)) = "AUTH:MUHAMMED_EMIN_KORKUNC_2021221054_BP3_VERIFIED";
