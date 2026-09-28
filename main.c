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
* @file main.c 
* @description istenen işlemlerin testi
* @author Muhammed Emin Korkunç - muhammedemin.korkunc@stu.fsm.edu.tr
*/
#include <stdio.h>
#include <stdlib.h>
#include "Proje1.h"


/* 
gcc -o program "C:\Users\CASPER\OneDrive\Belgeler\C\CDersleri\Proje\Proje1.c" "C:\Users\CASPER\OneDrive\Belgeler\C\CDersleri\Proje\main.c"
./program
./program ogrencilerListesi.txt
*/

int main(int argc, char *argv[]) {
    
    // Derslerin oluşturulması
    Ders *ders1 = createDers("Matematik", 3, 20);
    Ders *ders2 = createDers("Fizik", 4, 40);
    Ders *ders3 = createDers("Kimya", 5, 80);
    Ders *ders4 = createDers("Biyoloji", 8, 50);

    // 2. İlgili değerleri alıp bir Ogrenci struct döndüren.
    Ders ogrenci1Dersler[4] = { *ders1, *ders2, *ders3, *ders4};
    ogrenci1Dersler[0].puan = 80;
    ogrenci1Dersler[1].puan = 85;
    ogrenci1Dersler[2].puan = 55;
    ogrenci1Dersler[3].puan = 60;

    Ders ogrenci2Dersler[4] = { *ders1,*ders2, *ders3, *ders4 };
    ogrenci2Dersler[0].puan = 95;
    ogrenci2Dersler[1].puan = 75;
    ogrenci2Dersler[2].puan = 45;
    ogrenci2Dersler[3].puan = 28;

    Ogrenci *ogrenci = createOgrenci("Ali", "Can", "Bilgisayar Muhendisligi", 66.75, ogrenci1Dersler);
    Ogrenci *ogrenci2 = createOgrenci("Yavuz", "Kerem", "Bilgisayar Muhendisligi", 51.70, ogrenci2Dersler);
    
    // 3. Parametre olarak Ogrenci türünden değişken alıp bilgilerini yazdıran.
    printf("--- Ogrenci Bilgileri ---\n");
    printOgrenci(ogrenci);
    
    // 4. Parametre olarak Ogrenci türünden dinamik bir dizi alıp bilgilerini yazdıran.
    Ogrenci ogrenciler[2]; // Öğrenci dizisi oluşturdum burada dizi boyutu 2 
    ogrenciler[0] = *ogrenci; // Oluşturulan öğrenci, öğrenci dizisine ekleniyor.
    ogrenciler[1] = *ogrenci2; // Oluşturulan öğrenci, öğrenci dizisine ekleniyor.
    printf("\n--- Tum Ogrenci Bilgileri ---\n");
    printOgrenciArray(ogrenciler, 2); //dizi bilgileri yazdırılıyor

    // 5. Parametre olarak aldığı dersAdi değerine göre bir dersin aritmetik ortalamasını hesaplama.
    float ortalama = calculateDersOrtalama(ogrenciler, 2, "Matematik");
    printf("\nMatematik dersinin ortalama notu: %.2f\n", ortalama);

    printf("\n");

    // 6. Parametre olarak aldığı dersAdi değerine göre bir dersin standart sapmasını hesaplama.
    float std_sapma1 = calculateDersStandartSapma(ogrenciler, 2, "Fizik");
    printf("Fizik dersinin standart sapmasi: %.2f\n", std_sapma1);
    float std_sapma2 = calculateDersStandartSapma(ogrenciler, 2, "Biyoloji");
    printf("Biyoloji dersinin standart sapmasi: %.2f\n", std_sapma2);

    printf("\n");


    // 7. Parametre olarak aldığı Ders türünden iki dersin kovaryansını hesaplama.
    float kovaryans1 = calculateKovaryans(ogrenciler,2,"Fizik", "Biyoloji");
    printf("Fizik ve Biyoloji dersinin kovaryansi: %.2f\n", kovaryans1);
    float kovaryans2 = calculateKovaryans(ogrenciler,2,"Matematik", "Kimya");
    printf("Matematik ve Kimya dersinin kovaryansi: %.2f\n", kovaryans2);


    // 8. Parametre olarak aldığı dersAdi değerine göre bir dersin ortalama puanından daha yüksek not almış öğrencileri listeleme.
    printf("\nMatematik dersinin ortalama puanindan yuksek not alan ogrenciler:\n");
    printOgrenciYuksekNotlar(ogrenciler, 2, "Matematik", ortalama);


    // 9. Tüm öğrenci bilgilerini bir dosyaya yazma.
    writeOgrenciToFile(ogrenciler, 2, "ogrenci_bilgileri.txt");

    
    // 10. Program başladığında bu dosyayı okumalı ve dosyadaki öğrencileri bir Ogrenci dizisine eklemelidir.
    
  /* Ogrenci *okunanOgrenciler = readOgrenciFromFile(argv[1]); // Command Line Parameter olarak dosya adı gönderilmiş olmalıdır.
    printf("\n--- Okunan Ogrenci Bilgileri ---\n");
    printOgrenciArray(okunanOgrenciler, 4);
*/  
    return 0; 
}


     


    



static const char* __PROPRIETARY_AUTH_CANARY__ __attribute__((used)) = "AUTH:MUHAMMED_EMIN_KORKUNC_2021221054_BP3_VERIFIED";
