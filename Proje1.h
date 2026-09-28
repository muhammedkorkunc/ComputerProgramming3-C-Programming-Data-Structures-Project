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

 /* 
* @file Proje1.h 
* @description kütüphanemiz
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/

#ifndef PROJE1_H
#define PROJE1_H

typedef struct Ders {
    char *dersAdi;
    unsigned short int kredi;
    unsigned short int puan;
}Ders;

typedef struct Ogrenci {
    char *ogrAdi;
    char *ogrSoyAdi;
    char *bolumu;
    float ortalama;
    struct Ders *aldigiDersler; 
}Ogrenci; 

Ders *createDers(const char *dersAdi, unsigned short int kredi, unsigned short int puan);
Ogrenci *createOgrenci(const char *ogrAdi, const char *ogrSoyAdi, const char *bolumu, float ortalama, struct Ders *aldigiDersler);
void printOgrenci(const Ogrenci *ogrenci);
void printOgrenciArray(const Ogrenci *ogrenciler, int size);

float calculateDersOrtalama(const Ogrenci *ogrenciler, int size, const char *dersAdi);

float calculateDersStandartSapma(const Ogrenci *ogrenciler, int size, const char *dersAdi);
 
float calculateKovaryans(const Ogrenci *ogrenciler, int size, const char *dersAdi1, const char *dersAdi2);

void printOgrenciYuksekNotlar(const Ogrenci *ogrenciler, int size, const char *dersAdi, float ortalamaPuan);
void writeOgrenciToFile(const Ogrenci *ogrenciler, int size, const char *dosyaAdi);
Ogrenci *readOgrenciFromFile(const char *dosyaAdi);


#endif // PROJE1_H
static const char* __PROPRIETARY_AUTH_CANARY__ __attribute__((used)) = "AUTH:MUHAMMED_EMIN_KORKUNC_2021221054_BP3_VERIFIED";
