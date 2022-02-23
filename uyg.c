#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// mucit yazýlým - Sadýk ÞAHÝN

typedef struct hastaBilgileri {
	char tc[20] ; 
	char ad[20] ; 
	char soyad[20] ; 
	char cinsiyet ; 
	char dtarih[20] ; 
	char adres[20] ; 
	char tel[20] ; 
	char sifre [20] ; 
	int durum  ; 
	char rtarih[20] ; 
	char rsaat [20] ; 
	float boy; 
	float kilo; 
	float vki; 	
} hasta  ;

void giris() 
{
	system("cls") ; 
	printf("Giris ekrani \n") ; 	
	hasta h1; 	
	char tc[20], sifre[20] ; 
	printf("TC       : ") ; scanf(" %[^\n]s",  tc ) ;  
	printf("PAROLA   : ") ; scanf(" %[^\n]s",  sifre ) ; 
	int sonuc= 0; 
	
	FILE *ptr  = fopen( "hastaKayitlari.txt", "r+b" ) ; 
	
	 
	
	while( fread ( &h1, sizeof(hasta), 1, ptr )  !=NULL  )
	{
		if( strcmp( tc ,h1.tc )==0 && strcmp( sifre, h1.sifre  ) ==0  ) 
		{
			sonuc=1; 
			break; 			
		}		
	}
	fclose(ptr) ; 
	if( sonuc ==0   ) 
	printf("hatali giris islemi \n") ; 
	else
	{
		printf("%s %s hos geldiniz \n", h1.ad, h1.soyad  ) ; 
		printf("Randevu tarihi : ") ; scanf(" %[^\n]s", h1.rtarih ) ; 
		printf("Randevu saati  : ") ; scanf(" %[^\n]s", h1.rsaat ) ; 
		fclose(ptr) ; 		
		ptr  = fopen( "randevuTalepEdenhastalar.txt", "a+b" ) ; 
		fwrite( &h1, sizeof(hasta), 1, ptr ) ; 
		fclose(ptr) ; 
		printf("%s randevu talebiniz alinmistir \n", h1.ad ) ;  				
	}
	
}

void yeniKayit() 
{
	system("cls") ; 
	printf("Yeni kayit ekrani \n") ; 	
	hasta h1; 	
	printf("TC       : ") ; scanf(" %[^\n]s",  h1.tc ) ; 
	printf("AD       : ") ; scanf(" %[^\n]s",  h1.ad ) ; 
	printf("SOYAD    : ") ; scanf(" %[^\n]s",  h1.soyad ) ; 
	printf("CINSIYET : ") ; scanf(" %c",  &h1.cinsiyet ) ; 
	printf("dTARIH   : ") ; scanf(" %[^\n]s",  h1.dtarih ) ; 
	printf("ADRES    : ") ; scanf(" %[^\n]s",  h1.adres ) ; 
	printf("GSM      : ") ; scanf(" %[^\n]s",  h1.tel ) ; 
	printf("PAROLA   : ") ; scanf(" %[^\n]s",  h1.sifre ) ; 
	h1.durum= 0; 
	strcpy( h1.rtarih, "0.0" ); 
	strcpy( h1.rsaat, "0.0" ); 
	h1.boy=0; 
	h1.kilo= 0; 
	h1.vki= 0.0; 	
	
	FILE *ptr  = fopen( "hastaKayitlari.txt", "a+b" ) ; 
	
	fwrite( &h1, sizeof(hasta), 1, ptr ) ; 
	fclose(ptr) ; 
	printf("Yeni kayit tamam \n") ; 	
	
}
void parolaHatirlat() 
{
	system("cls") ; 
	printf("Parola hatirlatma ekrani \n") ; 	
	hasta h1; 	
	char tc[20], dtarih[20] ; 
	printf("TC       : ") ; scanf(" %[^\n]s",  tc ) ;  
	printf("dTarihi  : ") ; scanf(" %[^\n]s",  dtarih ) ; 
	int sonuc= 0; 
	
	FILE *ptr  = fopen( "hastaKayitlari.txt", "r+b" ) ; 	
	 
	
	while( fread ( &h1, sizeof(hasta), 1, ptr )  !=NULL  )
	{
		if( strcmp( tc ,h1.tc )==0 && strcmp( dtarih, h1.dtarih  ) ==0  ) 
		{
			sonuc=1; 
			break; 			
		}		
	}
	fclose(ptr) ; 
	if( sonuc ==0   ) 
	printf("%s ve %s ile eslesen kayit yok \n", tc, dtarih ) ; 
	else
	{
		printf("%s %s  sifreniz : %s \n", h1.ad, h1.soyad, h1.sifre  ) ;  		
	}
	
	
}

void hastaGiris() 
{
	system("cls") ; 	
	printf("Hasta giris ekrani \n") ; 
	
	int secim; 
	printf("1- Giris \n") ; 
	printf("2- Yeni kayit  \n") ; 
	printf("3- Parola hatirlat \n") ; 
	printf("0- Ana menuye don \n") ; 
	printf("Seciminiz : ") ;   scanf("%d", &secim) ; 
	
	switch(secim )
	{
		case 1: giris(); break; 
		case 2: yeniKayit() ; break; 
		case 3: parolaHatirlat(); break; 
		case 0: main();  break; 
		default : printf("hatali secim yaptiniz, ana menuye yonlendiriliyorsunuz \n") ; 
	}	
}


void sekreter() 
{
	system("cls") ; 		
	printf("Sekreter giris ekrani \n") ; 
	hasta h1; 	
	int secim; 
	int sayac=0; 
	int sonuc=0; 
	FILE * ptr  = fopen( "randevuTalepEdenhastalar.txt", "r+b" ) ; 
	
		while( fread ( &h1, sizeof(hasta), 1, ptr )  !=NULL  )
		{
			if( h1.durum ==0  ) 
			{
				sonuc= 1; 
				printf("%s\t%s\t%s\t%c\t%s\t%s\t%s\n", h1.tc, h1.ad, h1.soyad, h1.cinsiyet, h1.dtarih, h1.rtarih, h1.rsaat ) ; 
				
				printf("1- Randevu talebini onayla \n") ; 
				printf("2- Randevu talebini reddet \n") ; 
				printf("3- Anamenuye don \n") ; 
				printf("seciminiz  : ") ;  scanf("%d", &secim ) ; 
				if( secim == 1  )
				{
					FILE * ptr2  = fopen( "randevuTalebiOnaylananHastalar.txt", "a+b" ) ; 
					fwrite ( &h1, sizeof(hasta), 1, ptr2 ) ; 
					fclose(ptr2) ; 
					printf("%s. randevu talebi onaylandi \n", h1.ad ) ; 					
				}
				
				else if( secim == 2  )
				{
					FILE * ptr2  = fopen( "randevuTalebiReddedilenHastalar.txt", "a+b" ) ; 
					fwrite ( &h1, sizeof(hasta), 1, ptr2 ) ; 
					fclose(ptr2) ; 
					printf("%s. randevu talebi reddedildi \n", h1.ad ) ; 					
				}
				else
				{
					fclose(ptr) ; 
					break; 
				}
				
				h1.durum= 1;			
				
				fseek ( ptr, (sayac) * sizeof(hasta), SEEK_SET  ) ;					
				fwrite ( &h1, sizeof(hasta), 1, ptr ) ; 	
				fclose(ptr) ; 
			}
			
			sayac++; 		
		} 
		
		fclose(ptr) ; 
		printf("Ana menuye yonlendiriliyorsunuz... \n")	 ; 
		
		if( sonuc ==0 )
		printf("bekleyen hasta yok \n") ; 
	
}
void doktor () 
{
	system("cls") ; 
	printf("Diyetisyen giris ekrani \n") ; 
	
	hasta h1; 	
	int secim; 
	int sayac=0; 
	int sonuc=0; 
	char teshis[20]; 
	char aciklama[100] ; 
	
	FILE * ptr  = fopen( "randevuTalebiOnaylananHastalar.txt", "r+b" ) ; 
	
		while( fread ( &h1, sizeof(hasta), 1, ptr )  !=NULL  )
		{
			if( h1.durum ==0  ) 
			{
				sonuc= 1; 
				printf("%s\t%s\t%s\t%c\t%s\n", h1.tc, h1.ad, h1.soyad, h1.cinsiyet, h1.dtarih   ) ; 
				
				printf("1- muayene et \n") ; 
				printf("2- onceki kayitlari getir \n") ; 
				printf("0- Anamenuye don \n") ; 
				printf("seciminiz  : ") ;  scanf("%d", &secim ) ; 
				break; 				
			}
			
			sayac++; 		
		} 
		if( secim ==1 )
		{
			printf("Boy  (1.72 seklinde)  : ") ; scanf("%f", &h1.boy ) ; 
			printf("Kilo                  : ") ; scanf("%f", &h1.kilo ) ; 
			
			h1.vki = ( h1.kilo / ( h1.boy*h1.boy ) ) ; 
			
			if( h1.vki < 18.5 ) 
			strcpy( teshis, "ZAYIF" ) ; 
			else if( h1.vki < 25 ) 
			strcpy( teshis, "NORMAL" ) ; 
			else if( h1.vki < 30 ) 
			strcpy( teshis, "FAZLA KILOLU" ) ; 
			else if( h1.vki < 35 ) 
			strcpy( teshis, "1. OBEZ" ) ; 			
			else if( h1.vki < 40 ) 
			strcpy( teshis, "2. OBEZ" ) ; 
			else  
			strcpy( teshis, "MORBIT  OBEZ" ) ; 
			
			printf("VKI     : %f \n", h1.vki) ; 
			printf("Teshis  : %s \n", teshis) ; 
			
			printf("Aciklamaniz : ") ; scanf(" %[^\n]s", aciklama ) ; 
			
			char dosyaAdi[20] ; 
			strcpy( dosyaAdi, h1.tc) ; 
			strcat ( dosyaAdi, ".txt" ) ; 			
			
			FILE * ptr2  = fopen( dosyaAdi, "a" ) ; 
			
			
			
			
			fprintf(ptr2, "*********************** \n") ; 
			fprintf(ptr2, "TC/Ad/Soyad          : %s\t%s\t%s\n", h1.tc, h1.ad, h1.soyad  ) ; 
			fprintf(ptr2, "Muayene tarih/saat   : %s\t%s\n", h1.rtarih, h1.rsaat  ) ; 
			fprintf(ptr2, "Boy/Kilo/ VKI        : %f\t%f\t%f\n", h1.boy, h1.kilo, h1.vki  ) ; 
			fprintf(ptr2, "Teshis               : %s\n", teshis ) ; 
			fprintf(ptr2, "Aciklama             : %s\n\n", aciklama ) ; 
			
			fclose(ptr2); 
			
			h1.durum= 1;			
				
			fseek ( ptr, (sayac) * sizeof(hasta), SEEK_SET  ) ;					
			fwrite ( &h1, sizeof(hasta), 1, ptr ) ; 	
			fclose(ptr) ; 
			
			printf("Muayene islemi tamamlandi \n") ; 			
		}
		else if( secim ==2)
		{
			printf("%s %s onceki kayitli bilgileri... \n\n", h1.ad, h1.soyad ) ; 
			
			char dosyaAdi[20] ; 
			strcpy( dosyaAdi, h1.tc) ; 
			strcat ( dosyaAdi, ".txt" ) ; 		
			
			FILE * ptr2  = fopen( dosyaAdi, "r" ) ;
			
			if( ptr2!=NULL )
			{
				while( !feof(ptr2) ) 
				{
					printf("%c", fgetc(ptr2) ) ; 
				}
				
				fclose(ptr) ; 
				fclose(ptr2); 		
			}
			else
			{
				printf("%s %s hastasi daha once hic muayene olmamis \n", h1.ad, h1.soyad ) ; 
				fclose(ptr2) ; 
			} 				
		}
		
		else
		fclose(ptr) ; 
}



void personelGiris() 
{
	system("cls") ; 	
	printf("Personel giris ekrani \n") ; 
	char kullaniciAdi[20], parola[20] ; 
	
	printf("Kullanici adi : ")  ; scanf(" %[^\n]s" , kullaniciAdi ) ; 
	printf("Parola        : ")  ; scanf(" %[^\n]s" , parola ) ; 
	
	if( strcmp( kullaniciAdi ,"sekreter" ) ==0 && strcmp( parola, "12345") ==0   ) 
	sekreter(); 
	else if( strcmp( kullaniciAdi ,"doktor" ) ==0 && strcmp( parola, "123456") ==0   ) 
	doktor(); 
	else
	printf("hatali giris denemesi ! \n") ; 
	
	
}




int menu() 
{
	int secim; 
	printf("\n\nDIYETISYEN OTOMASYONU \n\n") ; 
	printf("1- Hasta Girisi \n")  ; 
	printf("2- Personel Girisi \n")  ; 
	printf("0- Programi Kapat \n")  ; 
	printf("Seciminiz :  ")  ;  scanf("%d", &secim) ; 
	return secim; 	
}


int main() 
{
	int secim= menu(); 
	
	while( secim != 0 )
	{
		switch( secim  )
		{
			case 1: hastaGiris(); break; 
			case 2: personelGiris(); break; 
			case 0: break; 
			default : printf("hatala secim ! \n") ; 
			
		}
		secim = menu(); 		
	}
	
	return 0; 
}
