#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_DOSYA "/var/log/syslog"
#define MAX_SATIR_UZUNLUK 1024

// Bağlı liste düğüm yapısı
typedef struct LogDugum {
    char log[MAX_SATIR_UZUNLUK];
    struct LogDugum *sonraki;
} LogDugum;

// Yeni düğüm oluşturma fonksiyonu
LogDugum* yeniDugum(const char *log) {
    LogDugum *yeni = (LogDugum*)malloc(sizeof(LogDugum));
    if (yeni) {
        strncpy(yeni->log, log, MAX_SATIR_UZUNLUK);
        yeni->log[MAX_SATIR_UZUNLUK - 1] = '\0'; // Guvenlik için son karakteri belirle
        yeni->sonraki = NULL;
    }
    return yeni;
}

// Bağlı listeye düğüm ekleme fonksiyonu
void dugumEkle(LogDugum **bas, const char *log) {
    LogDugum *yeni = yeniDugum(log);
    if (!yeni) return;
    if (*bas == NULL) {
        *bas = yeni;
    } else {
        LogDugum *gecici = *bas;
        while (gecici->sonraki) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
}

// Belirtilen anahtar kelimeye göre logları filtreleme ve yazdırma
void logFiltrele(LogDugum *bas, const char *anahtar) {
    while (bas) {
        if (strstr(bas->log, anahtar)) {
            printf("%s", bas->log);
        }
        bas = bas->sonraki;
    }
}

// Bağlı listeyi serbest bırakma
void listeTemizle(LogDugum *bas) {
    while (bas) {
        LogDugum *gecici = bas;
        bas = bas->sonraki;
        free(gecici);
    }
}

int main() {
    FILE *dosya = fopen(LOG_DOSYA, "r");
    if (!dosya) {
        perror("Dosya acilamadi");
        return EXIT_FAILURE;
    }

    LogDugum *logListe = NULL;
    char tampon[MAX_SATIR_UZUNLUK];

    while (fgets(tampon, sizeof(tampon), dosya)) {
        dugumEkle(&logListe, tampon);
    }

    fclose(dosya);

    char anahtar[100];
    printf("Filtrelemek istediginiz anahtar kelimeyi girin: ");
    scanf("%99s", anahtar);
    
    printf("\nAnahtar kelimeye gore filtrelenen loglar:\n");
    logFiltrele(logListe, anahtar);
    
    listeTemizle(logListe);
    return 0;
}

