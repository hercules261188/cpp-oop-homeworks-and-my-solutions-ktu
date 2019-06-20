/*
	Ogrenciler ve Akademisyenler icin Randevu Sistemi
	
	Ad Soyad	:	Osman DURDAG
	e-mail		:	osmandurdag@hotmail.com

*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <sstream>
using namespace std;

class Randevu{
	private:
		int kisi;
		string tarih,baslangic_saat,bitis_saat;
	public:
		void set_kisi(int a){
			kisi=a;
		}
		int get_kisi(){
			return kisi;
		}
		void set_tarih(string a){
			tarih=a;
		}
		string get_tarih(){
			return tarih;
		}
		void set_baslangic_saat(string a){
			baslangic_saat=a;
		}
		string get_baslangic_saat(){
			return baslangic_saat;
		}
		void set_bitis_saat(string a,int b){
			int saat = atoi(a.substr(0,2).c_str()),dakika=atoi(a.substr(3,2).c_str());
			dakika+=b;
			if(dakika>=60){
				saat++;
				dakika %= 60;
			}
			stringstream ss;
			if(saat < 10 && dakika<10){
				ss<<"0"<<saat<<".0"<<dakika;
			}
			else if(saat<10){
				ss<<"0"<<saat<<"."<<dakika;
			}
			else if(dakika<10){
				ss<<saat<<".0"<<dakika;
			}
			else{
				ss<<saat<<"."<<dakika;
			}
			bitis_saat=ss.str();
		}
		string get_bitis_saat(){
			return bitis_saat;
		}
		void set_bitis_saat(string a){
			bitis_saat=a;
		}
};

class insan{
	private:
		string ad,soyad,e_mail,telefon;
		int randevu_say;
	protected:
		string get_ad2(){
			return ad;
		}
		void set_ad2(string a){
			ad=a;
		}
		string get_soyad2(){
			return soyad;
		}
		void set_soyad2(string a){
			soyad=a;
		}
		string get_e_mail2(){
			return e_mail;
		}
		void set_e_mail2(string a){
			e_mail=a;
		}
		string get_telefon2(){
			return telefon;
		}
		void set_telefon2(string a){
			telefon=a;
		}
		int get_randevu_say2(){
			return randevu_say;
		}
		void set_randevu_say2(int a){
			randevu_say=a;
		}
};

class Ogrenci:public insan{
	private:
		int no,kayit_yil;
		string bolum;
	public:
		Ogrenci();
		Randevu *r;
		int getno(){
			return no;
		}
		void setno(int a){
			no=a;
		}
		int getkayit_yil(){
			return kayit_yil;
		}
		void setkayit_yil(int a){
			kayit_yil=a;
		}
		string get_bolum(){
			return bolum;
		}
		void set_bolum(string a){
			bolum=a;
		}
		string get_ad(){
			return get_ad2();
		}
		void set_ad(string a){
			set_ad2(a);
		}
		string get_soyad(){
			return get_soyad2();
		}
		void set_soyad(string a){
			set_soyad2(a);
		}
		string get_e_mail(){
			return get_e_mail2();
		}
		void set_e_mail(string a){
			set_e_mail2(a);
		}
		string get_telefon(){
			return get_telefon2();
		}
		void set_telefon(string a){
			set_telefon2(a);
		}
		int get_randevu_say(){
			return get_randevu_say2();
		}
		void set_randevu_say(int a){
			set_randevu_say2(a);
		}
		
};


class Akademisyen:public insan{
	private:
		int sicil_no;
		string anabilim_dali,unvan;
	public:
		Akademisyen();
		Randevu *r;
		void setsicil_no(int a){
			sicil_no=a;
		}
		int getsicil_no(){
			return sicil_no;
		}
		void setanabilim_dali(string a){
			anabilim_dali=a;
		}
		string getanabilim_dali(){
			return anabilim_dali;
		}
		void setunvan(string a){
			unvan=a;
		}
		string getunvan(){
			return unvan;
		}
		string get_ad(){
			return get_ad2();
		}
		void set_ad(string a){
			set_ad2(a);
		}
		string get_soyad(){
			return get_soyad2();
		}
		void set_soyad(string a){
			set_soyad2(a);
		}
		string get_e_mail(){
			return get_e_mail2();
		}
		void set_e_mail(string a){
			set_e_mail2(a);
		}
		string get_telefon(){
			return get_telefon2();
		}
		void set_telefon(string a){
			set_telefon2(a);
		}
		int get_randevu_say(){
			return get_randevu_say2();
		}
		void set_randevu_say(int a){
			set_randevu_say2(a);
		}
};

Akademisyen::Akademisyen(){
	set_randevu_say(0);
}
Ogrenci::Ogrenci(){
	set_randevu_say(0);
}
int akademisyen_say();
int ogrenci_say();
void akademisyen_ekle(Akademisyen *akademisyenler);
void akademisyen_ekle2(Akademisyen *akademisyenler,int akademisyen_sayi);
void akademisyen_sil(Akademisyen *akademisyenler,int akademisyen_sayi);
void ogrenci_ekle(Ogrenci *ogrenciler);
void ogrenci_ekle2(Ogrenci *ogrenciler,int ogrenci_sayi);
void ogrenci_sil(Ogrenci *ogrenciler,int ogrenci_sayi);
void randevu_dosyadan_varsa_ekle(Ogrenci *ogrenciler,Akademisyen *akademisyenler,int ogrenci_sayi,int akademisyen_sayi);
void randevu_belge_yaz(Ogrenci *ogrenciler,int ogrenci_sayi,Akademisyen *akademisyenler,int akademisyen_sayi);
void karsilama_ekrani(Ogrenci *ogrenciler,Akademisyen *akademisyenler,int &ogrenci_sayi,int &akademisyen_sayi);
bool is_empty(ifstream &belge);

int main(){		///////////////////////////////	ogrenci, akademisyenleri dosyalari varsa ve bos degilse once sayilarini sayip sonra sayilari kadar nesne dizisi olusturup randevulari da varsa yine dosyadan ekledim.
	int ogrenci_sayi,akademisyen_sayi;
	Ogrenci *ogrenciler;
	Akademisyen *akademisyenler;
	akademisyen_sayi=akademisyen_say();
	if(akademisyen_sayi!=0){
		akademisyenler=new Akademisyen[akademisyen_sayi];
		akademisyen_ekle(akademisyenler);
	}
	ogrenci_sayi=ogrenci_say();
	if(ogrenci_sayi!=0){
		ogrenciler=new Ogrenci[ogrenci_sayi];
		ogrenci_ekle(ogrenciler);
	}
	if(ogrenci_sayi!=0 && akademisyen_sayi!=0){
		randevu_dosyadan_varsa_ekle(ogrenciler,akademisyenler,ogrenci_sayi,akademisyen_sayi);
	}
	cout<<endl<<"Akademisyenler ve ogrenciler dosyalardan(varsa) okunup sisteme kaydedildi."<<endl;
	Sleep(1500);
	karsilama_ekrani(ogrenciler,akademisyenler,ogrenci_sayi,akademisyen_sayi);
	delete[] ogrenciler;
	delete[] akademisyenler;
	return 0;
}

int akademisyen_say(){
	int akademisyen_say=0;
	char data[350];
	ifstream aka_belge;
	aka_belge.open("akademisyen.txt");
	if(!aka_belge || is_empty(aka_belge)){
		aka_belge.close();
		return akademisyen_say;
	}
	while(!aka_belge.eof()){
		aka_belge.getline(data,300);
		akademisyen_say++;
	}
	aka_belge.close();
	return akademisyen_say;
}

void akademisyen_ekle(Akademisyen *akademisyenler){
	int i=0;
	ifstream aka_belge;
	aka_belge.open("akademisyen.txt");
	while(!aka_belge.eof()){
	int sicil;
	string ad,soyad,anabilim_dali,e_mail,telefon,unvan;
	aka_belge>>sicil;
	akademisyenler[i].setsicil_no(sicil);
	aka_belge>>ad;
	akademisyenler[i].set_ad(ad);
	aka_belge>>soyad;
	akademisyenler[i].set_soyad(soyad);
	aka_belge>>anabilim_dali;
	akademisyenler[i].setanabilim_dali(anabilim_dali);
	aka_belge>>e_mail;
	akademisyenler[i].set_e_mail(e_mail);
	aka_belge>>telefon;
	akademisyenler[i].set_telefon(telefon);
	aka_belge>>unvan;
	akademisyenler[i].setunvan(unvan);
	i++;
	}
	aka_belge.close();
	for(int j=0;j<i;j++){
		for(int p=j+1;p<i;p++){
			if(akademisyenler[j].getsicil_no()==akademisyenler[p].getsicil_no()){
				cout<<"Dosyada ayni sicil numarasina sahip akademisyenler var."<<endl;
				cout<<"Lutfen dosyayi kontrol ettikten sonra programi tekrar calistiriniz.";
				exit(0);
			}
		}
	}
}

int ogrenci_say(){
	int ogrenci_say=0;
	char data[350];
	ifstream ogr_belge;
	ogr_belge.open("ogrenci.txt");
	if(!ogr_belge || is_empty(ogr_belge)){
		ogr_belge.close();
		return ogrenci_say;
	}
	while(!ogr_belge.eof()){
		ogr_belge.getline(data,300);
		ogrenci_say++;
	}
	ogr_belge.close();
	return ogrenci_say;
}

void ogrenci_ekle(Ogrenci *ogrenciler){
	int i=0;
	ifstream ogr_belge;	
	ogr_belge.open("ogrenci.txt");
	while(!ogr_belge.eof()){
		int num,kayit_yil;
		string ad,soyad,bolum,e_mail,telefon;
		ogr_belge>>num;
		ogrenciler[i].setno(num);
		ogr_belge>>ad;
		ogrenciler[i].set_ad(ad);
		ogr_belge>>soyad;
		ogrenciler[i].set_soyad(soyad);
		ogr_belge>>bolum;
		ogrenciler[i].set_bolum(bolum);
		ogr_belge>>kayit_yil;
		ogrenciler[i].setkayit_yil(kayit_yil);
		ogr_belge>>e_mail;
		ogrenciler[i].set_e_mail(e_mail);
		ogr_belge>>telefon;
		ogrenciler[i].set_telefon(telefon);
		i++;
	}
	ogr_belge.close();
	for(int j=0;j<i;j++){
		for(int p=j+1;p<i;p++){
			if(ogrenciler[j].getno()==ogrenciler[p].getno()){
				cout<<"Dosyada ayni ogrenci numarasina sahip ogrenciler var."<<endl;
				cout<<"Lutfen dosyayi kontrol ettikten sonra programi tekrar calistiriniz.";
				exit(0);
			}
		}
	}
}

void randevu_dosyadan_varsa_ekle(Ogrenci *ogrenciler,Akademisyen *akademisyenler,int ogrenci_sayi,int akademisyen_sayi){
	ifstream randevu_belge;
	randevu_belge.open("randevu.txt");
	if(!randevu_belge || is_empty(randevu_belge)){
		randevu_belge.close();
		return;
	}
	while(!randevu_belge.eof()){
		int ogr_no,aka_sicil;
		string tarih,bsl_saat,bts_saat;
		randevu_belge>>ogr_no;
		randevu_belge>>aka_sicil;
		randevu_belge>>tarih;
		randevu_belge>>bsl_saat;
		randevu_belge>>bts_saat;
		for(int i=0;i<ogrenci_sayi;i++){
			if(ogrenciler[i].getno()==ogr_no){
				for(int j=0;j<akademisyen_sayi;j++){
					if(akademisyenler[j].getsicil_no()==aka_sicil){
						if(ogrenciler[i].get_randevu_say()==0){
							ogrenciler[i].r=new Randevu[1];
							ogrenciler[i].r[0].set_kisi(aka_sicil);
							ogrenciler[i].r[0].set_tarih(tarih);
							ogrenciler[i].r[0].set_baslangic_saat(bsl_saat);
							ogrenciler[i].r[0].set_bitis_saat(bts_saat);
							ogrenciler[i].set_randevu_say(1);
							if(akademisyenler[j].get_randevu_say()==0){
								akademisyenler[j].r=new Randevu[1];
								akademisyenler[j].r[0].set_kisi(ogr_no);
								akademisyenler[j].r[0].set_tarih(tarih);
								akademisyenler[j].r[0].set_baslangic_saat(bsl_saat);
								akademisyenler[j].r[0].set_bitis_saat(bts_saat);
								akademisyenler[j].set_randevu_say(1);
							}
							else{
								Randevu *temp=new Randevu[akademisyenler[j].get_randevu_say()];
								for(int k=0;k<(akademisyenler[j].get_randevu_say());k++){
									temp[k].set_kisi(akademisyenler[j].r[k].get_kisi());
									temp[k].set_tarih(akademisyenler[j].r[k].get_tarih());
									temp[k].set_baslangic_saat(akademisyenler[j].r[k].get_baslangic_saat());
									temp[k].set_bitis_saat(akademisyenler[j].r[k].get_bitis_saat());
								}
								akademisyenler[j].set_randevu_say(akademisyenler[j].get_randevu_say()+1);
								akademisyenler[j].r=new Randevu[akademisyenler[j].get_randevu_say()];
								for(int k=0;k<(akademisyenler[j].get_randevu_say()-1);k++){
									akademisyenler[j].r[k].set_kisi(temp[k].get_kisi());
									akademisyenler[j].r[k].set_tarih(temp[k].get_tarih());
									akademisyenler[j].r[k].set_baslangic_saat(temp[k].get_baslangic_saat());
									akademisyenler[j].r[k].set_bitis_saat(temp[k].get_bitis_saat());
								}
								delete[] temp;
								akademisyenler[j].r[akademisyenler[j].get_randevu_say()-1].set_kisi(ogr_no);
								akademisyenler[j].r[akademisyenler[j].get_randevu_say()-1].set_tarih(tarih);
								akademisyenler[j].r[akademisyenler[j].get_randevu_say()-1].set_baslangic_saat(bsl_saat);
								akademisyenler[j].r[akademisyenler[j].get_randevu_say()-1].set_bitis_saat(bts_saat);
							}
						}
						else{
							Randevu *temp=new Randevu[ogrenciler[i].get_randevu_say()];
							for(int k=0;k<(ogrenciler[i].get_randevu_say());k++){
								temp[k].set_kisi(ogrenciler[i].r[k].get_kisi());
								temp[k].set_tarih(ogrenciler[i].r[k].get_tarih());
								temp[k].set_baslangic_saat(ogrenciler[i].r[k].get_baslangic_saat());
								temp[k].set_bitis_saat(ogrenciler[i].r[k].get_bitis_saat());
							}
							ogrenciler[i].set_randevu_say(ogrenciler[i].get_randevu_say()+1);
							ogrenciler[i].r=new Randevu[ogrenciler[i].get_randevu_say()];
							for(int k=0;k<(ogrenciler[i].get_randevu_say()-1);k++){
								ogrenciler[i].r[k].set_kisi(temp[k].get_kisi());
								ogrenciler[i].r[k].set_tarih(temp[k].get_tarih());
								ogrenciler[i].r[k].set_baslangic_saat(temp[k].get_baslangic_saat());
								ogrenciler[i].r[k].set_bitis_saat(temp[k].get_bitis_saat());
							}
							delete[] temp;
							ogrenciler[i].r[ogrenciler[i].get_randevu_say()-1].set_kisi(aka_sicil);
							ogrenciler[i].r[ogrenciler[i].get_randevu_say()-1].set_tarih(tarih);
							ogrenciler[i].r[ogrenciler[i].get_randevu_say()-1].set_baslangic_saat(bsl_saat);
							ogrenciler[i].r[ogrenciler[i].get_randevu_say()-1].set_bitis_saat(bts_saat);
							if(akademisyenler[j].get_randevu_say()==0){
								akademisyenler[j].r=new Randevu[1];
								akademisyenler[j].r[0].set_kisi(ogr_no);
								akademisyenler[j].r[0].set_tarih(tarih);
								akademisyenler[j].r[0].set_baslangic_saat(bsl_saat);
								akademisyenler[j].r[0].set_bitis_saat(bts_saat);
								akademisyenler[j].set_randevu_say(1);
							}
							else{
								Randevu *temp=new Randevu[akademisyenler[j].get_randevu_say()];
								for(int k=0;k<(akademisyenler[j].get_randevu_say());k++){
									temp[k].set_kisi(akademisyenler[j].r[k].get_kisi());
									temp[k].set_tarih(akademisyenler[j].r[k].get_tarih());
									temp[k].set_baslangic_saat(akademisyenler[j].r[k].get_baslangic_saat());
									temp[k].set_bitis_saat(akademisyenler[j].r[k].get_bitis_saat());
								}
								akademisyenler[j].set_randevu_say(akademisyenler[j].get_randevu_say()+1);
								akademisyenler[j].r=new Randevu[akademisyenler[j].get_randevu_say()];
								for(int k=0;k<(akademisyenler[j].get_randevu_say()-1);k++){
									akademisyenler[j].r[k].set_kisi(temp[k].get_kisi());
									akademisyenler[j].r[k].set_tarih(temp[k].get_tarih());
									akademisyenler[j].r[k].set_baslangic_saat(temp[k].get_baslangic_saat());
									akademisyenler[j].r[k].set_bitis_saat(temp[k].get_bitis_saat());
								}
								delete[] temp;
								akademisyenler[j].r[akademisyenler[j].get_randevu_say()-1].set_kisi(ogr_no);
								akademisyenler[j].r[akademisyenler[j].get_randevu_say()-1].set_tarih(tarih);
								akademisyenler[j].r[akademisyenler[j].get_randevu_say()-1].set_baslangic_saat(bsl_saat);
								akademisyenler[j].r[akademisyenler[j].get_randevu_say()-1].set_bitis_saat(bts_saat);
							}
						}
					}
				}
			}
		}
	}
	randevu_belge.close();
}

void ogrenci_ekle2(Ogrenci *ogrenciler,int ogrenci_sayi){
	int num,kayit_yil;
	string ad,soyad,bolum,e_mail,telefon;
	cout<<"Ogrencinin numarasi:";
	ogr_ekle_num_sec:cin>>num;
	if(!cin.good()){
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout<<"Lutfen tekrar giriniz(Yalnizca sayi):";
		goto ogr_ekle_num_sec;
	}
	else if(num<1){
		cout<<"En kucuk deger 1 olabilir. Tekrar giriniz:";
		goto ogr_ekle_num_sec;
	}
	for(int i=0;i<ogrenci_sayi-1;i++){
		if(num==ogrenciler[i].getno()){
			cout<<"Bu ogrenci numarasina sahip ogrenci zaten kayitli."<<endl;
			cout<<"Lutfen tekrar giriniz:";goto ogr_ekle_num_sec;
		}
	}
	ogrenciler[ogrenci_sayi-1].setno(num);
	cout<<"Ogrencinin adi:";
	cin>>ad;
	ogrenciler[ogrenci_sayi-1].set_ad(ad);
	cout<<"Ogrencinin soyadi:";
	cin>>soyad;
	ogrenciler[ogrenci_sayi-1].set_soyad(soyad);
	cout<<"Ogrencinin bolumu:";
	cin>>bolum;
	ogrenciler[ogrenci_sayi-1].set_bolum(bolum);
	cout<<"Ogrencinin kayit yili:";
	ogr_ekle_kayit_yil:cin>>kayit_yil;
	if(!cin.good()){
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout<<"Lutfen tekrar giriniz(Yalnizca sayi):";
		goto ogr_ekle_kayit_yil;
	}
	ogrenciler[ogrenci_sayi-1].setkayit_yil(kayit_yil);
	cout<<"Ogrencinin e-mail adresi:";
	cin>>e_mail;
	ogrenciler[ogrenci_sayi-1].set_e_mail(e_mail);
	cout<<"Ogrencinin telefon numarasi:";
	cin>>telefon;
	ogrenciler[ogrenci_sayi-1].set_telefon(telefon);
}

void ogrenci_sil(Ogrenci *ogrenciler,int ogrenci_sayi){
	ofstream ogr_belge("ogrenci.txt");
	for(int i=0;i<ogrenci_sayi;i++){
		if(i==0){
			ogr_belge<<ogrenciler[i].getno()<<" ";
			ogr_belge<<ogrenciler[i].get_ad()<<" ";
			ogr_belge<<ogrenciler[i].get_soyad()<<" ";
			ogr_belge<<ogrenciler[i].get_bolum()<<" ";
			ogr_belge<<ogrenciler[i].getkayit_yil()<<" ";
			ogr_belge<<ogrenciler[i].get_e_mail()<<" ";
			ogr_belge<<ogrenciler[i].get_telefon();
		}
		else{
			ogr_belge<<endl<<ogrenciler[i].getno()<<" ";
			ogr_belge<<ogrenciler[i].get_ad()<<" ";
			ogr_belge<<ogrenciler[i].get_soyad()<<" ";
			ogr_belge<<ogrenciler[i].get_bolum()<<" ";
			ogr_belge<<ogrenciler[i].getkayit_yil()<<" ";
			ogr_belge<<ogrenciler[i].get_e_mail()<<" ";
			ogr_belge<<ogrenciler[i].get_telefon();
		}	
	}
	ogr_belge.close();
}

void akademisyen_ekle2(Akademisyen *akademisyenler,int akademisyen_sayi){
	int sicil;
	string ad,soyad,anabilim_dali,e_mail,telefon,unvan;
	cout<<"Akademisyenin sicil numarasi:";
	aka_ekle_sicil_sec:cin>>sicil;
	if(!cin.good()){
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout<<"Lutfen tekrar giriniz(Yalnizca sayi):";
		goto aka_ekle_sicil_sec;
	}
	else if(sicil<1){
		cout<<"En kucuk deger 1 olabilir. Tekrar giriniz:";
		goto aka_ekle_sicil_sec;
	}
	for(int i=0;i<akademisyen_sayi-1;i++){
		if(sicil==akademisyenler[i].getsicil_no()){
			cout<<"Bu sicil numarasina sahip akademisyen zaten kayitli."<<endl;
			cout<<"Lutfen tekrar giriniz:";goto aka_ekle_sicil_sec;
		}
	}
	akademisyenler[akademisyen_sayi-1].setsicil_no(sicil);
	cout<<"Akademisyenin adi:";
	cin>>ad;
	akademisyenler[akademisyen_sayi-1].set_ad(ad);
	cout<<"Akademisyenin soyadi:";
	cin>>soyad;
	akademisyenler[akademisyen_sayi-1].set_soyad(soyad);
	cout<<"Akademisyenin anabilim dali:";
	cin>>anabilim_dali;
	akademisyenler[akademisyen_sayi-1].setanabilim_dali(anabilim_dali);
	cout<<"Akademisyenin e_mail adresi:";
	cin>>e_mail;
	akademisyenler[akademisyen_sayi-1].set_e_mail(e_mail);
	cout<<"Akademisyenin telefon numarasi:";
	cin>>telefon;
	akademisyenler[akademisyen_sayi-1].set_telefon(telefon);
	cout<<"Akademisyenin unvani:";
	cin>>unvan;
	akademisyenler[akademisyen_sayi-1].setunvan(unvan);	
	ofstream aka_belge;
	aka_belge.open("akademisyen.txt",ios::app);
	aka_belge<<endl<<akademisyenler[akademisyen_sayi-1].getsicil_no()<<" ";
	aka_belge<<akademisyenler[akademisyen_sayi-1].get_ad()<<" ";
	aka_belge<<akademisyenler[akademisyen_sayi-1].get_soyad()<<" ";
	aka_belge<<akademisyenler[akademisyen_sayi-1].getanabilim_dali()<<" ";
	aka_belge<<akademisyenler[akademisyen_sayi-1].get_e_mail()<<" ";
	aka_belge<<akademisyenler[akademisyen_sayi-1].get_telefon()<<" ";
	aka_belge<<akademisyenler[akademisyen_sayi-1].getunvan();
	aka_belge.close();
}

void akademisyen_sil(Akademisyen *akademisyenler,int akademisyen_sayi){
	ofstream aka_belge("akademisyen.txt");
	for(int i=0;i<akademisyen_sayi;i++){
		if(i==0){
			aka_belge<<akademisyenler[i].getsicil_no()<<" ";
			aka_belge<<akademisyenler[i].get_ad()<<" ";
			aka_belge<<akademisyenler[i].get_soyad()<<" ";
			aka_belge<<akademisyenler[i].getanabilim_dali()<<" ";
			aka_belge<<akademisyenler[i].get_e_mail()<<" ";
			aka_belge<<akademisyenler[i].get_telefon()<<" ";
			aka_belge<<akademisyenler[i].getunvan();
		}
		else{
			aka_belge<<endl<<akademisyenler[i].getsicil_no()<<" ";
			aka_belge<<akademisyenler[i].get_ad()<<" ";
			aka_belge<<akademisyenler[i].get_soyad()<<" ";
			aka_belge<<akademisyenler[i].getanabilim_dali()<<" ";
			aka_belge<<akademisyenler[i].get_e_mail()<<" ";
			aka_belge<<akademisyenler[i].get_telefon()<<" ";
			aka_belge<<akademisyenler[i].getunvan();
		}	
	}
	aka_belge.close();
}

void randevu_belge_yaz(Ogrenci *ogrenciler,int ogrenci_sayi,Akademisyen *akademisyenler,int akademisyen_sayi){
	int p=0;
	ofstream randevu_belge;
	randevu_belge.open("randevu.txt");
	for(int i=0;i<ogrenci_sayi;i++){
		if(ogrenciler[i].get_randevu_say()!=0){
			for(int j=0;j<ogrenciler[i].get_randevu_say();j++){
				if(j==0 && p==0){
					randevu_belge<<ogrenciler[i].getno()<<" ";
					for(int k=0;k<akademisyen_sayi;k++){
						if(ogrenciler[i].r[j].get_kisi()==akademisyenler[k].getsicil_no()){
							randevu_belge<<akademisyenler[k].getsicil_no()<<" ";
						}
					}
					randevu_belge<<ogrenciler[i].r[j].get_tarih()<<" ";
					randevu_belge<<ogrenciler[i].r[j].get_baslangic_saat()<<" ";
					randevu_belge<<ogrenciler[i].r[j].get_bitis_saat();
				}
				else{
					randevu_belge<<endl<<ogrenciler[i].getno()<<" ";
					for(int k=0;k<akademisyen_sayi;k++){
						if(ogrenciler[i].r[j].get_kisi()==akademisyenler[k].getsicil_no()){
							randevu_belge<<akademisyenler[k].getsicil_no()<<" ";
						}
					}
					randevu_belge<<ogrenciler[i].r[j].get_tarih()<<" ";
					randevu_belge<<ogrenciler[i].r[j].get_baslangic_saat()<<" ";
					randevu_belge<<ogrenciler[i].r[j].get_bitis_saat();
				}	
			}
		}p++;
	}
	randevu_belge.close();
}

void karsilama_ekrani(Ogrenci *ogrenciler,Akademisyen *akademisyenler,int &ogrenci_sayi,int &akademisyen_sayi){
	int sorgu_ana_ekran;
	ana_ekran:system("CLS");
	cout<<"Yeni akademisyen veya ogrenci eklemek istiyorsaniz 1'e"<<endl;
	cout<<"Kayitli akademisyen veya ogrenci silmek istiyorsaniz 2'ye"<<endl;
	cout<<"Randevu sorgulamak, almak veya silmek icin 3'e"<<endl;
	cout<<"Programdan cikmak icin 0'a basiniz:";
	ana_ekran_giris:cin>>sorgu_ana_ekran;
	if(sorgu_ana_ekran==0){
		cout<<"Program sonlandi.";
		delete[] akademisyenler;
		delete[] ogrenciler;
		exit(0);
	}
	else if(sorgu_ana_ekran==1){
		int ekle_sorgu;
		system("CLS");
		cout<<"Akademisyen eklemek istiyorsaniz 1'e"<<endl;
		cout<<"Ogrenci eklemek istiyorsaniz 2'ye"<<endl;
		cout<<"Onceki menuye donmek istiyorsaniz 0'a basiniz:";
		ekle_giris:cin>>ekle_sorgu;
		if(ekle_sorgu==0)
			goto ana_ekran;
		else if(ekle_sorgu==1){
			if(akademisyen_sayi==0){
				akademisyenler=new Akademisyen[1];
				akademisyen_ekle2(akademisyenler,akademisyen_sayi+1);
				akademisyen_sayi++;
				ofstream aka_belge;
				aka_belge.open("akademisyen.txt",ios::app);
				aka_belge<<akademisyenler[akademisyen_sayi-1].getsicil_no()<<" ";
				aka_belge<<akademisyenler[akademisyen_sayi-1].get_ad()<<" ";
				aka_belge<<akademisyenler[akademisyen_sayi-1].get_soyad()<<" ";
				aka_belge<<akademisyenler[akademisyen_sayi-1].getanabilim_dali()<<" ";
				aka_belge<<akademisyenler[akademisyen_sayi-1].get_e_mail()<<" ";
				aka_belge<<akademisyenler[akademisyen_sayi-1].get_telefon()<<" ";
				aka_belge<<akademisyenler[akademisyen_sayi-1].getunvan();
				aka_belge.close();
				cout<<akademisyenler[akademisyen_sayi-1].getsicil_no()<<" sicil numarali akademisyen eklendi.";Sleep(1000);goto ana_ekran;
			}
			else{
				Akademisyen *temp=new Akademisyen[akademisyen_sayi];
				for(int i=0;i<akademisyen_sayi;i++){
					temp[i]=akademisyenler[i];
				}
				delete[] akademisyenler;
				akademisyen_sayi++;
				akademisyenler=new Akademisyen[akademisyen_sayi];
				for(int i=0;i<akademisyen_sayi-1;i++){
					akademisyenler[i]=temp[i];
				}
				delete[] temp;
				akademisyen_ekle2(akademisyenler,akademisyen_sayi);
				cout<<akademisyenler[akademisyen_sayi-1].getsicil_no()<<" sicil numarali akademisyen eklendi.";Sleep(1000);goto ana_ekran;
			}			
		}
		else if(ekle_sorgu==2){
			if(ogrenci_sayi==0){
				ogrenciler=new Ogrenci[1];
				ogrenci_ekle2(ogrenciler,ogrenci_sayi+1);
				ogrenci_sayi++;
				ofstream ogr_belge;
				ogr_belge.open("ogrenci.txt",ios::app);
				ogr_belge<<ogrenciler[ogrenci_sayi-1].getno()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].get_ad()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].get_soyad()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].get_bolum()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].getkayit_yil()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].get_e_mail()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].get_telefon();
				ogr_belge.close();
				cout<<ogrenciler[ogrenci_sayi-1].getno()<<" numarali ogrenci eklendi.";Sleep(1000);goto ana_ekran;
			}
			else{
				Ogrenci *temp=new Ogrenci[ogrenci_sayi];
				for(int i=0;i<ogrenci_sayi;i++){
					temp[i]=ogrenciler[i];
				}
				delete[] ogrenciler;
				ogrenci_sayi++;
				ogrenciler=new Ogrenci[ogrenci_sayi];
				for(int i=0;i<ogrenci_sayi-1;i++){
					ogrenciler[i]=temp[i];
				}
				delete[] temp;
				ogrenci_ekle2(ogrenciler,ogrenci_sayi);
				ofstream ogr_belge;
				ogr_belge.open("ogrenci.txt",ios::app);
				ogr_belge<<endl<<ogrenciler[ogrenci_sayi-1].getno()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].get_ad()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].get_soyad()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].get_bolum()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].getkayit_yil()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].get_e_mail()<<" ";
				ogr_belge<<ogrenciler[ogrenci_sayi-1].get_telefon();
				ogr_belge.close();
				cout<<ogrenciler[ogrenci_sayi-1].getno()<<" numarali ogrenci eklendi.";Sleep(1000);goto ana_ekran;
			}	
		}
		else{
			cout<<"Lutfen size sunulan seceneklerden birini secin."<<endl;goto ekle_giris;
		}
	}
	else if(sorgu_ana_ekran==2){
		int sil_sorgu;
		sil_etiket:system("CLS");
		cout<<"Akademisyen silmek istiyorsaniz 1'e"<<endl;
		cout<<"Ogrenci silmek istiyorsaniz 2'ye"<<endl;
		cout<<"Onceki menuye donmek icin 0'a basiniz:";
		sil_giris:cin>>sil_sorgu;
		if(sil_sorgu==0){
			goto ana_ekran;
		}
		else if(sil_sorgu==1){
			if(akademisyen_sayi==0){
				system("CLS");
				cout<<"Sistemde kayitli akademisyen bulunmamaktadir.";Sleep(1000);goto sil_etiket;
			}
			else{
				aka_sil_baslangic:int aka_sec;
				bool secim;
				system("CLS");
				cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
				cout<<endl<<endl<<"\t\t\t*********AKADEMiSYENLER LiSTESi*********"<<endl<<endl;
				cout<<setw(15)<<"Sicil No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(23)<<"Anabilim Dali"<<endl<<endl;
				for(int i=0;i<akademisyen_sayi;i++){
					cout<<i+1<<":) "<<setw(9)<<akademisyenler[i].getsicil_no()<<setw(14)<<akademisyenler[i].get_ad()<<setw(18)<<akademisyenler[i].get_soyad()<<setw(21)<<akademisyenler[i].getanabilim_dali()<<endl;
				}
				cout<<endl<<"Lutfen sistemden silmek istediginiz akademisyenin listedeki numarasini giriniz:";
				aka_sil:cin>>aka_sec;
				if(aka_sec==0){
					goto sil_etiket;
				}
				secim=false;
				for(int i=0;i<akademisyen_sayi;i++){
					if(i+1==aka_sec){
						secim=true;
						cout<<endl<<akademisyenler[i].getsicil_no()<<" sicil numarali akademisyeni silmek istiyor musunuz?(e/h)";
						char sec;
						e_h_sec:cin>>sec;
						switch(sec){
							case 'e':{
								Akademisyen *temp=new Akademisyen[akademisyen_sayi-1];
								int k=0;
								int silinen=akademisyenler[aka_sec-1].getsicil_no();
								for(int i=0;i<akademisyen_sayi;i++){
									if(i!=aka_sec-1){
										temp[k]=akademisyenler[i];
										k++;
									}
								}
								akademisyen_sayi--;
								akademisyenler=new Akademisyen[akademisyen_sayi];
								for(int i=0;i<akademisyen_sayi;i++){
									akademisyenler[i]=temp[i];
								}
								delete[] temp;
								cout<<silinen<<" sicil numarali akademisyen sistemden silindi.";
								akademisyen_sil(akademisyenler,akademisyen_sayi);
								randevu_belge_yaz(ogrenciler,ogrenci_sayi,akademisyenler,akademisyen_sayi);
								Sleep(1500);
								goto aka_sil_baslangic;
							}
							case 'h':goto aka_sil_baslangic;
							default:cout<<"Lutfen tekrar giriniz:";goto e_h_sec;
						}
					}
				}
				if(!secim){
					cout<<"Lutfen tutarli bir giris yapiniz:";goto aka_sil;
				}
			}
		}
		else if(sil_sorgu==2){
			if(ogrenci_sayi==0){
				system("CLS");
				cout<<"Sistemde kayitli ogrenci bulunmamaktadir.";Sleep(1000);goto sil_etiket;
			}
			else{
				ogr_sil_baslangic:int ogr_sec;
				bool secim;
				system("CLS");
				cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
				cout<<endl<<endl<<"\t\t\t*********OGRENCiLER LiSTESi*********"<<endl<<endl;
				cout<<setw(15)<<"Ogrenci No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(19)<<"Bolum"<<endl<<endl;
				for(int i=0;i<ogrenci_sayi;i++){
					cout<<i+1<<":) "<<setw(9)<<ogrenciler[i].getno()<<setw(14)<<ogrenciler[i].get_ad()<<setw(18)<<ogrenciler[i].get_soyad()<<setw(21)<<ogrenciler[i].get_bolum()<<endl;
				}
				cout<<endl<<"Lutfen sistemden silmek istediginiz ogrencinin listedeki numarasini giriniz:";
				ogr_sil:cin>>ogr_sec;
				if(ogr_sec==0){
					goto sil_etiket;
				}
				secim=false;
				for(int i=0;i<ogrenci_sayi;i++){
					if(i+1==ogr_sec){
						secim=true;
						cout<<endl<<ogrenciler[i].getno()<<" numarali ogrenciyi silmek istiyor musunuz?(e/h)";
						char sec;
						e_h_sec2:cin>>sec;
						switch(sec){
							case 'e':{
								Ogrenci *temp=new Ogrenci[ogrenci_sayi-1];
								int k=0;
								int silinen=ogrenciler[ogr_sec-1].getno();
								for(int i=0;i<ogrenci_sayi;i++){
									if(i!=ogr_sec-1){
										temp[k]=ogrenciler[i];
										k++;
									}
								}
								ogrenci_sayi--;
								ogrenciler=new Ogrenci[ogrenci_sayi];
								for(int i=0;i<ogrenci_sayi;i++){
									ogrenciler[i]=temp[i];
								}
								delete[] temp;
								cout<<silinen<<" numarali ogrenci sistemden silindi.";
								ogrenci_sil(ogrenciler,ogrenci_sayi);
								randevu_belge_yaz(ogrenciler,ogrenci_sayi,akademisyenler,akademisyen_sayi);
								Sleep(1500);
								goto ogr_sil_baslangic;
							}
							case 'h':goto ogr_sil_baslangic;
							default:cout<<"Lutfen tekrar giriniz:";goto e_h_sec2;
						}
					}
				}
				if(!secim){
					cout<<"Lutfen tutarli bir giris yapiniz:";goto ogr_sil;
				}
			}
		}
		else{
			cout<<"Lutfen size sunulan seceneklerden birini giriniz:";goto sil_giris;
		}
	}
	else if(sorgu_ana_ekran==3){
		int randevu_ana_sorgu;
		randevu_baslangic:system("CLS");
		cout<<"Randevulari listelemek icin 1'e"<<endl;
		cout<<"Randevu olusturmak icin 2'ye"<<endl;
		cout<<"Randevu silmek icin 3'e"<<endl;
		cout<<"Onceki menuye donmek icin 0'a basiniz:";
		randevu_secim:cin>>randevu_ana_sorgu;
		if(randevu_ana_sorgu==0)
			goto ana_ekran;
		else if(randevu_ana_sorgu==1){
			int randevu_liste_sorgu;
			randevu_liste:system("CLS");
			cout<<"Kayitli butun randevulari listelemek icin 1'e"<<endl;
			cout<<"Belirli bir ogrenciye ait randevulari listelemek icin 2'ye"<<endl;
			cout<<"Belirli bir akademisyene ait randevulari listelemek icin 3'e"<<endl;
			cout<<"Onceki menuye donmek icin 0'a basiniz:";
			randevu_liste_secim:cin>>randevu_liste_sorgu;
			if(randevu_liste_sorgu==0)
				goto randevu_baslangic;
			else if(randevu_liste_sorgu==1){
				ifstream belge;
				belge.open("randevu.txt");
				if(!belge || is_empty(belge)){
					cout<<endl<<"Kayitli randevu yok."<<endl;Sleep(1000);goto randevu_baslangic;
				}
				system("CLS");
				cout<<endl<<endl<<"\t\t\t*********RANDEVU LiSTESi*********"<<endl<<endl;
				cout<<setw(15)<<"Ogrenci No"<<setw(25)<<"Akademisyen Sicil No"<<setw(10)<<"Tarih"<<setw(15)<<"Baslangic"<<setw(10)<<"Bitis"<<endl;
				while(!belge.eof()){
					int ogr_no,aka_sicil;
					string tarih,basla,bitis;
					belge>>ogr_no;
					belge>>aka_sicil;
					belge>>tarih;
					belge>>basla;
					belge>>bitis;
					cout<<setw(12)<<ogr_no<<setw(20)<<aka_sicil<<setw(20)<<tarih<<setw(10)<<basla<<setw(13)<<bitis<<endl;
				}
				belge.close();
				cout<<endl<<"Onceki menuye donmek icin bir tusa basiniz.";
				char randevu_tumliste_beklet;
				cin>>randevu_tumliste_beklet;
				goto randevu_liste;
			}
			else if(randevu_liste_sorgu==2){
				ogr_liste_baslangic:int ogr_sec;
				bool secim;
				system("CLS");
				cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
				cout<<endl<<endl<<"\t\t\t*********OGRENCiLER LiSTESi*********"<<endl<<endl;
				cout<<setw(15)<<"Ogrenci No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(19)<<"Bolum"<<endl<<endl;
				for(int i=0;i<ogrenci_sayi;i++){
					cout<<i+1<<":) "<<setw(9)<<ogrenciler[i].getno()<<setw(14)<<ogrenciler[i].get_ad()<<setw(18)<<ogrenciler[i].get_soyad()<<setw(21)<<ogrenciler[i].get_bolum()<<endl;
				}
				cout<<endl<<"Randevularini gormek istediginiz ogrencinin listedeki numarasini giriniz:";
				ogrenci_randevu_listeden_sec:cin>>ogr_sec;
				if(ogr_sec==0){
					goto randevu_liste;
				}
				secim=false;
				for(int i=0;i<ogrenci_sayi;i++){
					if(i+1==ogr_sec){
						secim=true;
						if(ogrenciler[i].get_randevu_say()==0){
							cout<<"Secilen ogrenciye ait kayitli randevu bulunmamaktadir."<<endl;
							cout<<"Tekrar giris yapiniz:";goto ogrenci_randevu_listeden_sec;
						}
						system("CLS");
						cout<<"\t"<<ogrenciler[i].getno()<<" / "<<ogrenciler[i].get_ad()<<" "<<ogrenciler[i].get_soyad();
						cout<<endl<<endl<<"\t\t\t*********Randevu Listesi*********"<<endl<<endl;
						cout<<setw(15)<<" Akademisyen Sicil No"<<setw(13)<<"Tarih"<<setw(23)<<"Baslangic Saati"<<setw(15)<<"Bitis Saati"<<endl;
						for(int j=0;j<ogrenciler[i].get_randevu_say();j++){
							cout<<setw(13)<<ogrenciler[i].r[j].get_kisi()<<setw(23)<<ogrenciler[i].r[j].get_tarih()<<setw(15)<<ogrenciler[i].r[j].get_baslangic_saat()<<setw(19)<<ogrenciler[i].r[j].get_bitis_saat()<<endl;
						}
						cout<<endl<<endl<<"Onceki menuye donmek icin bir tusa basiniz.";
						char randevu_ogrlist_beklet;
						cin>>randevu_ogrlist_beklet;
						goto ogr_liste_baslangic;
					}
				}
				if(!secim){
					cout<<"Lutfen tutarli bir giris yapiniz:";goto ogrenci_randevu_listeden_sec;
				}
				
			}
			else if(randevu_liste_sorgu==3){
				aka_liste_baslangic:int aka_sec;
				bool secim;
				system("CLS");
				cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
				cout<<endl<<endl<<"\t\t\t*********AKADEMiSYENLER LiSTESi*********"<<endl<<endl;
				cout<<setw(15)<<"Sicil No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(23)<<"Anabilim Dali"<<endl<<endl;
				for(int i=0;i<akademisyen_sayi;i++){
					cout<<i+1<<":) "<<setw(9)<<akademisyenler[i].getsicil_no()<<setw(14)<<akademisyenler[i].get_ad()<<setw(18)<<akademisyenler[i].get_soyad()<<setw(21)<<akademisyenler[i].getanabilim_dali()<<endl;
				}
				cout<<endl<<"Randevularini gormek istediginiz akademisyenin listedeki numarasini giriniz:";
				akademisyen_randevu_listeden_sec:cin>>aka_sec;
				if(aka_sec==0){
					goto randevu_liste;
				}
				secim=false;
				for(int i=0;i<akademisyen_sayi;i++){
					if(i+1==aka_sec){
						secim=true;
						if(akademisyenler[i].get_randevu_say()==0){
							cout<<"Secilen akademisyene ait kayitli randevu bulunmamaktadir."<<endl;
							cout<<"Tekrar giris yapiniz:";goto akademisyen_randevu_listeden_sec;
						}
						system("CLS");
						cout<<"\t"<<akademisyenler[i].getsicil_no()<<" / "<<akademisyenler[i].get_ad()<<" "<<akademisyenler[i].get_soyad();
						cout<<endl<<endl<<"\t\t\t*********Randevu Listesi*********"<<endl<<endl;
						cout<<setw(15)<<" Ogrenci No"<<setw(13)<<"Tarih"<<setw(23)<<"Baslangic Saati"<<setw(15)<<"Bitis Saati"<<endl;
						for(int j=0;j<akademisyenler[i].get_randevu_say();j++){
							cout<<setw(13)<<akademisyenler[i].r[j].get_kisi()<<setw(17)<<akademisyenler[i].r[j].get_tarih()<<setw(15)<<akademisyenler[i].r[j].get_baslangic_saat()<<setw(19)<<akademisyenler[i].r[j].get_bitis_saat()<<endl;
						}
						cout<<endl<<endl<<"Onceki menuye donmek icin bir tusa basiniz.";
						char randevu_akalist_beklet;
						cin>>randevu_akalist_beklet;
						goto aka_liste_baslangic;
					}
				}
				if(!secim){
					cout<<"Lutfen tutarli bir giris yapiniz:";goto akademisyen_randevu_listeden_sec;
				}
			}
			else{
				cout<<"Lutfen size sunulan seceneklerden birini secin."<<endl;goto randevu_liste_secim;
			}
		}
		else if(randevu_ana_sorgu==2){
			randevu_olustur_baslangic:int ogrenci_sec;
			bool secim;
			system("CLS");
			cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
			cout<<endl<<endl<<"\t\t\t*********OGRENCiLER LiSTESi*********"<<endl<<endl;
			cout<<setw(15)<<"Ogrenci No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(19)<<"Bolum"<<endl<<endl;
			for(int i=0;i<ogrenci_sayi;i++){
				cout<<i+1<<":) "<<setw(9)<<ogrenciler[i].getno()<<setw(14)<<ogrenciler[i].get_ad()<<setw(18)<<ogrenciler[i].get_soyad()<<setw(21)<<ogrenciler[i].get_bolum()<<endl;
			}
			cout<<endl<<"Randevu olusturmak istediginiz ogrencinin listedeki numarasini giriniz:";
			ogrenci_sec_randevu_olustur:cin>>ogrenci_sec;
			if(ogrenci_sec==0){
				goto randevu_baslangic;
			}
			secim=false;
			for(int i=0;i<ogrenci_sayi;i++){
				if(i+1==ogrenci_sec){
					secim=true;
				}
			}
			if(!secim){
				cout<<"Lutfen tutarli bir giris yapiniz:";goto ogrenci_sec_randevu_olustur;
			}
			int akademisyen_sec;
			system("CLS");
			cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
			cout<<endl<<endl<<"\t\t\t*********AKADEMiSYENLER LiSTESi*********"<<endl<<endl;
			cout<<setw(15)<<"Sicil No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(23)<<"Anabilim Dali"<<endl<<endl;
			for(int i=0;i<akademisyen_sayi;i++){
				cout<<i+1<<":) "<<setw(9)<<akademisyenler[i].getsicil_no()<<setw(14)<<akademisyenler[i].get_ad()<<setw(18)<<akademisyenler[i].get_soyad()<<setw(21)<<akademisyenler[i].getanabilim_dali()<<endl;
			}
			cout<<endl<<"Randevu almak istediginiz akademisyenin listedeki numarasini giriniz:";
			akademisyen_sec_randevu_olustur:cin>>akademisyen_sec;
			if(akademisyen_sec==0){
				goto randevu_baslangic;
			}
			secim=false;
			for(int i=0;i<akademisyen_sayi;i++){
				if(i+1==akademisyen_sec){
					secim=true;
				}
			}
			if(!secim){
				cout<<"Lutfen tutarli bir giris yapiniz:";goto akademisyen_sec_randevu_olustur;
			}
			string tarih,baslangic_saat;
			int randevu_sure;
			cout<<"Randevu olusturmak istediginiz Tarih(gg.aa.yyyy):";
			tarih_gir:cin>>tarih;
			int gun,ay,yil;
			gun=atoi(tarih.substr(0,2).c_str());
			ay=atoi(tarih.substr(3,2).c_str());
			yil=atoi(tarih.substr(6,4).c_str());
			time_t zaman = time(0);
    		tm* simdiki_zaman = localtime(&zaman);
			if((yil<(simdiki_zaman->tm_year + 1900)) || (yil==(simdiki_zaman->tm_year + 1900) && ay < (simdiki_zaman->tm_mon + 1)) || (yil==(simdiki_zaman->tm_year + 1900) && ay == (simdiki_zaman->tm_mon + 1) && gun<(simdiki_zaman->tm_mday))){
				cout<<"Gecmis zaman icin randevu olusturamazsiniz. Lutfen tekrar tarih giriniz:";goto tarih_gir;
			}
			else if(gun>31 || gun < 1){
				cout<<"Gun degeri tutarsiz. Lutfen tekrar tarih giriniz:";goto tarih_gir;
			}
			else if(ay<1 || ay>12){
				cout<<"Ay degeri tutarsiz. Lutfen tekrar tarih giriniz:";goto tarih_gir;
			}
			else if(yil==(simdiki_zaman->tm_year + 1900) && ay == (simdiki_zaman->tm_mon + 1) && gun == (simdiki_zaman->tm_mday) && simdiki_zaman->tm_hour >= 16 ){
				cout<<"Bugun icin artik randevu alamazsiniz. Lutfen tekrar tarih giriniz:";goto tarih_gir;
			}
			cout<<"Baslangic saati(ss.dd):";
			baslangic_saat_gir:cin>>baslangic_saat;
			int bsl_saat_saat,bsl_saat_dakika,bts_saat_saat,bts_saat_dakika,bsl_tum_saat,bts_tum_saat;
			bsl_saat_saat=atoi(baslangic_saat.substr(0,2).c_str());
			bsl_saat_dakika=atoi(baslangic_saat.substr(3,2).c_str());
			if(bsl_saat_saat<8 || (bsl_saat_saat==16 && bsl_saat_dakika>30) || bsl_saat_saat>=17){
				cout<<"08.00 ve 16.30 saatleri arasinda randevu alinabilmektedir."<<endl<<"Lutfen tekrar giriniz:";goto baslangic_saat_gir;
			}
			
			else if(yil==(simdiki_zaman->tm_year + 1900) && ay == (simdiki_zaman->tm_mon + 1) && gun==(simdiki_zaman->tm_mday) && bsl_saat_saat<(simdiki_zaman->tm_hour)){
				cout<<"Gecmis zaman icin randevu olusturamazsiniz. Lutfen tekrar baslangic saati giriniz:";goto baslangic_saat_gir;
			}
			else if(yil==(simdiki_zaman->tm_year + 1900) && ay == (simdiki_zaman->tm_mon + 1) && gun==(simdiki_zaman->tm_mday) && bsl_saat_saat==(simdiki_zaman->tm_hour) && bsl_saat_dakika<(simdiki_zaman->tm_min)){
				cout<<"Gecmis zaman icin randevu olusturamazsiniz. Lutfen tekrar baslangic saati giriniz:";goto baslangic_saat_gir;
			}
			cout<<"Randevu suresi(dakika):";
			randevu_sure_gir:cin>>randevu_sure;
			if(randevu_sure < 15 || randevu_sure > 60){
				cout<<"Randevu suresi 15 dakika ile 60 dakika arasinda olmalidir. Tekrar giriniz:";goto randevu_sure_gir;
			}
			else if(bsl_saat_saat==16 && bsl_saat_dakika+randevu_sure>60){
				cout<<"Randevu saatinize gore randevu sureniz en fazla "<<60-bsl_saat_dakika<<" dakika olabilir."<<endl<<"Lutfen randevu surenizi tekrar giriniz:";goto randevu_sure_gir;
			}
			bts_saat_saat=(bsl_saat_dakika+randevu_sure)>=60?(bsl_saat_saat+1):(bsl_saat_saat);
			bts_saat_dakika=(bsl_saat_dakika+randevu_sure)%60;
			bsl_tum_saat=bsl_saat_saat*100+bsl_saat_dakika;
			bts_tum_saat=bts_saat_saat*100+bts_saat_dakika;
			if(ogrenciler[ogrenci_sec-1].get_randevu_say()==0){
				if(akademisyenler[akademisyen_sec-1].get_randevu_say()==0){
					ogrenciler[ogrenci_sec-1].r=new Randevu[1];
					ogrenciler[ogrenci_sec-1].r[0].set_kisi(akademisyenler[akademisyen_sec-1].getsicil_no());
					ogrenciler[ogrenci_sec-1].r[0].set_tarih(tarih);
					ogrenciler[ogrenci_sec-1].r[0].set_baslangic_saat(baslangic_saat);
					ogrenciler[ogrenci_sec-1].r[0].set_bitis_saat(baslangic_saat,randevu_sure);
					ogrenciler[ogrenci_sec-1].set_randevu_say(ogrenciler[ogrenci_sec-1].get_randevu_say()+1);
					akademisyenler[akademisyen_sec-1].r=new Randevu[1];
					akademisyenler[akademisyen_sec-1].r[0].set_kisi(ogrenciler[ogrenci_sec-1].getno());
					akademisyenler[akademisyen_sec-1].r[0].set_tarih(tarih);
					akademisyenler[akademisyen_sec-1].r[0].set_baslangic_saat(baslangic_saat);
					akademisyenler[akademisyen_sec-1].r[0].set_bitis_saat(baslangic_saat,randevu_sure);
					akademisyenler[akademisyen_sec-1].set_randevu_say(akademisyenler[akademisyen_sec-1].get_randevu_say()+1);
					randevu_belge_yaz(ogrenciler,ogrenci_sayi,akademisyenler,akademisyen_sayi);
					cout<<"Randevu olusturuldu."<<endl;
					Sleep(1000);goto randevu_olustur_baslangic;
				}
				else{
					for(int i=0;i<akademisyenler[akademisyen_sec-1].get_randevu_say();i++){
						if(akademisyenler[akademisyen_sec-1].r[i].get_tarih()==tarih){
							int kayitli_bsl_saat,kayitli_bsl_dakika,kayitli_bts_saat,kayitli_bts_dakika,kayitli_bsl_tum_saat,kayitli_bts_tum_saat;
							kayitli_bsl_saat=atoi(akademisyenler[akademisyen_sec-1].r[i].get_baslangic_saat().substr(0,2).c_str());
							kayitli_bsl_dakika=atoi(akademisyenler[akademisyen_sec-1].r[i].get_baslangic_saat().substr(3,2).c_str());
							kayitli_bts_saat=atoi(akademisyenler[akademisyen_sec-1].r[i].get_bitis_saat().substr(0,2).c_str());
							kayitli_bts_dakika=atoi(akademisyenler[akademisyen_sec-1].r[i].get_bitis_saat().substr(3,2).c_str());
							kayitli_bsl_tum_saat=kayitli_bsl_saat*100+kayitli_bsl_dakika;
							kayitli_bts_tum_saat=kayitli_bts_saat*100+kayitli_bts_dakika;
							if((bsl_tum_saat>=kayitli_bsl_tum_saat && bsl_tum_saat<kayitli_bts_tum_saat) || (bts_tum_saat>kayitli_bsl_tum_saat && bts_tum_saat<=kayitli_bts_tum_saat)){
								cout<<endl<<"Secilen akademisyenin belirtilen zaman icinde randevusu bulunmakta!"<<endl;Sleep(1500);
								goto randevu_olustur_baslangic;
							}
						}
					}
					ogrenciler[ogrenci_sec-1].r=new Randevu[1];
					ogrenciler[ogrenci_sec-1].r[0].set_kisi(akademisyenler[akademisyen_sec-1].getsicil_no());
					ogrenciler[ogrenci_sec-1].r[0].set_tarih(tarih);
					ogrenciler[ogrenci_sec-1].r[0].set_baslangic_saat(baslangic_saat);
					ogrenciler[ogrenci_sec-1].r[0].set_bitis_saat(baslangic_saat,randevu_sure);
					ogrenciler[ogrenci_sec-1].set_randevu_say(ogrenciler[ogrenci_sec-1].get_randevu_say()+1);
					Randevu *temp=new Randevu[akademisyenler[akademisyen_sec-1].get_randevu_say()];
					for(int i=0;i<akademisyenler[akademisyen_sec-1].get_randevu_say();i++){
						temp[i].set_kisi(akademisyenler[akademisyen_sec-1].r[i].get_kisi());
						temp[i].set_tarih(akademisyenler[akademisyen_sec-1].r[i].get_tarih());
						temp[i].set_baslangic_saat(akademisyenler[akademisyen_sec-1].r[i].get_baslangic_saat());
						temp[i].set_bitis_saat(akademisyenler[akademisyen_sec-1].r[i].get_baslangic_saat(),randevu_sure);
					}
					akademisyenler[akademisyen_sec-1].set_randevu_say(akademisyenler[akademisyen_sec-1].get_randevu_say()+1);
					akademisyenler[akademisyen_sec-1].r=new Randevu[akademisyenler[akademisyen_sec-1].get_randevu_say()];
					for(int i=0;i<akademisyenler[akademisyen_sec-1].get_randevu_say()-1;i++){
						akademisyenler[akademisyen_sec-1].r[i].set_kisi(temp[i].get_kisi());
						akademisyenler[akademisyen_sec-1].r[i].set_tarih(temp[i].get_tarih());
						akademisyenler[akademisyen_sec-1].r[i].set_baslangic_saat(temp[i].get_baslangic_saat());
						akademisyenler[akademisyen_sec-1].r[i].set_bitis_saat(temp[i].get_baslangic_saat(),randevu_sure);
					}
					delete[] temp;
					akademisyenler[akademisyen_sec-1].r[akademisyenler[akademisyen_sec-1].get_randevu_say()-1].set_kisi(ogrenciler[ogrenci_sec-1].getno());
					akademisyenler[akademisyen_sec-1].r[akademisyenler[akademisyen_sec-1].get_randevu_say()-1].set_tarih(tarih);
					akademisyenler[akademisyen_sec-1].r[akademisyenler[akademisyen_sec-1].get_randevu_say()-1].set_baslangic_saat(baslangic_saat);
					akademisyenler[akademisyen_sec-1].r[akademisyenler[akademisyen_sec-1].get_randevu_say()-1].set_bitis_saat(baslangic_saat,randevu_sure);
					randevu_belge_yaz(ogrenciler,ogrenci_sayi,akademisyenler,akademisyen_sayi);
					cout<<"Randevu olusturuldu."<<endl;Sleep(1000);
					goto randevu_olustur_baslangic;
				}
			}
			else{
				for(int i=0;i<ogrenciler[ogrenci_sec-1].get_randevu_say();i++){
						if(ogrenciler[ogrenci_sec-1].r[i].get_tarih()==tarih){
							int kayitli_bsl_saat,kayitli_bsl_dakika,kayitli_bts_saat,kayitli_bts_dakika,kayitli_bsl_tum_saat,kayitli_bts_tum_saat;
							kayitli_bsl_saat=atoi(ogrenciler[ogrenci_sec-1].r[i].get_baslangic_saat().substr(0,2).c_str());
							kayitli_bsl_dakika=atoi(ogrenciler[ogrenci_sec-1].r[i].get_baslangic_saat().substr(3,2).c_str());
							kayitli_bts_saat=atoi(ogrenciler[ogrenci_sec-1].r[i].get_bitis_saat().substr(0,2).c_str());
							kayitli_bts_dakika=atoi(ogrenciler[ogrenci_sec-1].r[i].get_bitis_saat().substr(3,2).c_str());
							kayitli_bsl_tum_saat=kayitli_bsl_saat*100+kayitli_bsl_dakika;
							kayitli_bts_tum_saat=kayitli_bts_saat*100+kayitli_bts_dakika;
							if((bsl_tum_saat>=kayitli_bsl_tum_saat && bsl_tum_saat<kayitli_bts_tum_saat) || (bts_tum_saat>kayitli_bsl_tum_saat && bts_tum_saat<=kayitli_bts_tum_saat)){
								cout<<endl<<"Secilen ogrencinin belirtilen zaman icinde randevusu bulunmakta!"<<endl;Sleep(1500);
								goto randevu_olustur_baslangic;
							}	
						}
					}
				if(akademisyenler[akademisyen_sec-1].get_randevu_say()==0){
					akademisyenler[akademisyen_sec-1].r=new Randevu[1];
					akademisyenler[akademisyen_sec-1].r[0].set_kisi(ogrenciler[ogrenci_sec-1].getno());
					akademisyenler[akademisyen_sec-1].r[0].set_tarih(tarih);
					akademisyenler[akademisyen_sec-1].r[0].set_baslangic_saat(baslangic_saat);
					akademisyenler[akademisyen_sec-1].r[0].set_bitis_saat(baslangic_saat,randevu_sure);
					akademisyenler[akademisyen_sec-1].set_randevu_say(akademisyenler[akademisyen_sec-1].get_randevu_say()+1);
					Randevu *temp=new Randevu[ogrenciler[ogrenci_sec-1].get_randevu_say()];
					for(int i=0;i<ogrenciler[ogrenci_sec-1].get_randevu_say();i++){
						temp[i].set_kisi(ogrenciler[ogrenci_sec-1].r[i].get_kisi());
						temp[i].set_tarih(ogrenciler[ogrenci_sec-1].r[i].get_tarih());
						temp[i].set_baslangic_saat(ogrenciler[ogrenci_sec-1].r[i].get_baslangic_saat());
						temp[i].set_bitis_saat(ogrenciler[ogrenci_sec-1].r[i].get_baslangic_saat(),randevu_sure);
					}
					ogrenciler[ogrenci_sec-1].set_randevu_say(ogrenciler[ogrenci_sec-1].get_randevu_say()+1);
					ogrenciler[ogrenci_sec-1].r=new Randevu[ogrenciler[ogrenci_sec-1].get_randevu_say()];
					for(int i=0;i<ogrenciler[ogrenci_sec-1].get_randevu_say()-1;i++){
						ogrenciler[ogrenci_sec-1].r[i].set_kisi(temp[i].get_kisi());
						ogrenciler[ogrenci_sec-1].r[i].set_tarih(temp[i].get_tarih());
						ogrenciler[ogrenci_sec-1].r[i].set_baslangic_saat(temp[i].get_baslangic_saat());
						ogrenciler[ogrenci_sec-1].r[i].set_bitis_saat(temp[i].get_baslangic_saat(),randevu_sure);
					}
					delete[] temp;
					ogrenciler[ogrenci_sec-1].r[ogrenciler[ogrenci_sec-1].get_randevu_say()-1].set_kisi(akademisyenler[akademisyen_sec-1].getsicil_no());
					ogrenciler[ogrenci_sec-1].r[ogrenciler[ogrenci_sec-1].get_randevu_say()-1].set_tarih(tarih);
					ogrenciler[ogrenci_sec-1].r[ogrenciler[ogrenci_sec-1].get_randevu_say()-1].set_baslangic_saat(baslangic_saat);
					ogrenciler[ogrenci_sec-1].r[ogrenciler[ogrenci_sec-1].get_randevu_say()-1].set_bitis_saat(baslangic_saat,randevu_sure);
					randevu_belge_yaz(ogrenciler,ogrenci_sayi,akademisyenler,akademisyen_sayi);
					cout<<"Randevu olusturuldu."<<endl;Sleep(1000);
					goto randevu_olustur_baslangic;
				}
				else{
					for(int i=0;i<akademisyenler[akademisyen_sec-1].get_randevu_say();i++){
						if(akademisyenler[akademisyen_sec-1].r[i].get_tarih()==tarih){
							int kayitli_bsl_saat,kayitli_bsl_dakika,kayitli_bts_saat,kayitli_bts_dakika,kayitli_bsl_tum_saat,kayitli_bts_tum_saat;
							kayitli_bsl_saat=atoi(akademisyenler[akademisyen_sec-1].r[i].get_baslangic_saat().substr(0,2).c_str());
							kayitli_bsl_dakika=atoi(akademisyenler[akademisyen_sec-1].r[i].get_baslangic_saat().substr(3,2).c_str());
							kayitli_bts_saat=atoi(akademisyenler[akademisyen_sec-1].r[i].get_bitis_saat().substr(0,2).c_str());
							kayitli_bts_dakika=atoi(akademisyenler[akademisyen_sec-1].r[i].get_bitis_saat().substr(3,2).c_str());
							kayitli_bsl_tum_saat=kayitli_bsl_saat*100+kayitli_bsl_dakika;
							kayitli_bts_tum_saat=kayitli_bts_saat*100+kayitli_bts_dakika;
							if((bsl_tum_saat>=kayitli_bsl_tum_saat && bsl_tum_saat<kayitli_bts_tum_saat) || (bts_tum_saat>kayitli_bsl_tum_saat && bts_tum_saat<=kayitli_bts_tum_saat)){
								cout<<endl<<"Secilen akademisyenin belirtilen zaman icinde randevusu bulunmakta!"<<endl;Sleep(1500);
								goto randevu_olustur_baslangic;
							}
						}
					}
					Randevu *temp=new Randevu[ogrenciler[ogrenci_sec-1].get_randevu_say()];
					for(int i=0;i<ogrenciler[ogrenci_sec-1].get_randevu_say();i++){
						temp[i].set_kisi(ogrenciler[ogrenci_sec-1].r[i].get_kisi());
						temp[i].set_tarih(ogrenciler[ogrenci_sec-1].r[i].get_tarih());
						temp[i].set_baslangic_saat(ogrenciler[ogrenci_sec-1].r[i].get_baslangic_saat());
						temp[i].set_bitis_saat(ogrenciler[ogrenci_sec-1].r[i].get_baslangic_saat(),randevu_sure);
					}
					ogrenciler[ogrenci_sec-1].set_randevu_say(ogrenciler[ogrenci_sec-1].get_randevu_say()+1);
					ogrenciler[ogrenci_sec-1].r=new Randevu[ogrenciler[ogrenci_sec-1].get_randevu_say()];
					for(int i=0;i<ogrenciler[ogrenci_sec-1].get_randevu_say()-1;i++){
						ogrenciler[ogrenci_sec-1].r[i].set_kisi(temp[i].get_kisi());
						ogrenciler[ogrenci_sec-1].r[i].set_tarih(temp[i].get_tarih());
						ogrenciler[ogrenci_sec-1].r[i].set_baslangic_saat(temp[i].get_baslangic_saat());
						ogrenciler[ogrenci_sec-1].r[i].set_bitis_saat(temp[i].get_baslangic_saat(),randevu_sure);
					}
					delete[] temp;
					ogrenciler[ogrenci_sec-1].r[ogrenciler[ogrenci_sec-1].get_randevu_say()-1].set_kisi(akademisyenler[akademisyen_sec-1].getsicil_no());
					ogrenciler[ogrenci_sec-1].r[ogrenciler[ogrenci_sec-1].get_randevu_say()-1].set_tarih(tarih);
					ogrenciler[ogrenci_sec-1].r[ogrenciler[ogrenci_sec-1].get_randevu_say()-1].set_baslangic_saat(baslangic_saat);
					ogrenciler[ogrenci_sec-1].r[ogrenciler[ogrenci_sec-1].get_randevu_say()-1].set_bitis_saat(baslangic_saat,randevu_sure);
					temp=new Randevu[akademisyenler[akademisyen_sec-1].get_randevu_say()];
					for(int i=0;i<akademisyenler[akademisyen_sec-1].get_randevu_say();i++){
						temp[i].set_kisi(akademisyenler[akademisyen_sec-1].r[i].get_kisi());
						temp[i].set_tarih(akademisyenler[akademisyen_sec-1].r[i].get_tarih());
						temp[i].set_baslangic_saat(akademisyenler[akademisyen_sec-1].r[i].get_baslangic_saat());
						temp[i].set_bitis_saat(akademisyenler[akademisyen_sec-1].r[i].get_baslangic_saat(),randevu_sure);
					}
					akademisyenler[akademisyen_sec-1].set_randevu_say(akademisyenler[akademisyen_sec-1].get_randevu_say()+1);
					akademisyenler[akademisyen_sec-1].r=new Randevu[akademisyenler[akademisyen_sec-1].get_randevu_say()];
					for(int i=0;i<akademisyenler[akademisyen_sec-1].get_randevu_say()-1;i++){
						akademisyenler[akademisyen_sec-1].r[i].set_kisi(temp[i].get_kisi());
						akademisyenler[akademisyen_sec-1].r[i].set_tarih(temp[i].get_tarih());
						akademisyenler[akademisyen_sec-1].r[i].set_baslangic_saat(temp[i].get_baslangic_saat());
						akademisyenler[akademisyen_sec-1].r[i].set_bitis_saat(temp[i].get_baslangic_saat(),randevu_sure);
					}
					delete[] temp;
					akademisyenler[akademisyen_sec-1].r[akademisyenler[akademisyen_sec-1].get_randevu_say()-1].set_kisi(ogrenciler[ogrenci_sec-1].getno());
					akademisyenler[akademisyen_sec-1].r[akademisyenler[akademisyen_sec-1].get_randevu_say()-1].set_tarih(tarih);
					akademisyenler[akademisyen_sec-1].r[akademisyenler[akademisyen_sec-1].get_randevu_say()-1].set_baslangic_saat(baslangic_saat);
					akademisyenler[akademisyen_sec-1].r[akademisyenler[akademisyen_sec-1].get_randevu_say()-1].set_bitis_saat(baslangic_saat,randevu_sure);
					randevu_belge_yaz(ogrenciler,ogrenci_sayi,akademisyenler,akademisyen_sayi);
					cout<<"Randevu olusturuldu."<<endl;Sleep(1000);goto randevu_olustur_baslangic;
				}
			}
		}
		else if(randevu_ana_sorgu==3){
			randevu_sil_baslangic:ifstream belge;
			belge.open("randevu.txt");
			if(!belge || is_empty(belge)){
				cout<<endl<<"Kayitli randevu yok."<<endl;Sleep(1000);goto randevu_baslangic;
			}
			system("CLS");
			int i=0;
			cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
			cout<<endl<<endl<<"\t\t\t*********RANDEVU LiSTESi*********"<<endl<<endl;
			cout<<setw(15)<<"Ogrenci No"<<setw(25)<<"Akademisyen Sicil No"<<setw(10)<<"Tarih"<<setw(15)<<"Baslangic"<<setw(10)<<"Bitis"<<endl;
			while(!belge.eof()){
				int ogr_no,aka_sicil;
				string tarih,basla,bitis;
				belge>>ogr_no;
				belge>>aka_sicil;
				belge>>tarih;
				belge>>basla;
				belge>>bitis;
				cout<<i+1<<":) "<<setw(9)<<ogr_no<<setw(19)<<aka_sicil<<setw(20)<<tarih<<setw(10)<<basla<<setw(13)<<bitis<<endl;
				i++;
			}
			belge.close();
			cout<<endl<<endl<<"Silmek istediginiz randevunun liste numarasini giriniz:";
			int silinen_randevu;
			silinen_randevu_sec:cin>>silinen_randevu;
			if(silinen_randevu < 1 || silinen_randevu>i ){
				if(silinen_randevu==0){
					goto randevu_baslangic;
				}
				cout<<"Lutfen tutarli bir giris yapiniz:";goto silinen_randevu_sec;
			}
			cout<<silinen_randevu<<" numarali randevuyu silmek istiyor musunuz?(e/h)";
			char randevu_onay;
			randevu_onay_sec:cin>>randevu_onay;
			switch(randevu_onay){
				case 'e':{
					i=1;
					int ogr_no,aka_sicil;
					string tarih,basla,bitis;
					belge.open("randevu.txt");
					while(!belge.eof()){
						belge>>ogr_no;
						belge>>aka_sicil;
						belge>>tarih;
						belge>>basla;
						belge>>bitis;
						if(i==silinen_randevu){
							break;
						}
						i++;
					}
					belge.close();
					for(int j=0;j<ogrenci_sayi;j++){
						if(ogrenciler[j].getno()==ogr_no){
							Randevu *temp=new Randevu[ogrenciler[j].get_randevu_say()-1];
							int p=0;
							for(int k=0;k<ogrenciler[j].get_randevu_say();k++){
								if(ogrenciler[j].r[k].get_kisi()==aka_sicil && ogrenciler[j].r[k].get_tarih()==tarih && ogrenciler[j].r[k].get_baslangic_saat()==basla && ogrenciler[j].r[k].get_bitis_saat()==bitis){
									continue;
								}
								temp[p].set_kisi(ogrenciler[j].r[k].get_kisi());
								temp[p].set_tarih(ogrenciler[j].r[k].get_tarih());
								temp[p].set_baslangic_saat(ogrenciler[j].r[k].get_baslangic_saat());
								temp[p].set_bitis_saat(ogrenciler[j].r[k].get_bitis_saat());
								p++;
							}
							ogrenciler[j].set_randevu_say(ogrenciler[j].get_randevu_say()-1);
							ogrenciler[j].r=new Randevu[ogrenciler[j].get_randevu_say()];
							for(int k=0;k<ogrenciler[j].get_randevu_say();k++){
								ogrenciler[j].r[k].set_kisi(temp[k].get_kisi());
								ogrenciler[j].r[k].set_tarih(temp[k].get_tarih());
								ogrenciler[j].r[k].set_baslangic_saat(temp[k].get_baslangic_saat());
								ogrenciler[j].r[k].set_bitis_saat(temp[k].get_bitis_saat());
							}
							delete[] temp;
						}
					}
					for(int j=0;j<akademisyen_sayi;j++){
						if(akademisyenler[j].getsicil_no()==aka_sicil){
							Randevu *temp=new Randevu[akademisyenler[j].get_randevu_say()-1];
							int p=0;
							for(int k=0;k<akademisyenler[j].get_randevu_say();k++){
								if(akademisyenler[j].r[k].get_kisi()==ogr_no && akademisyenler[j].r[k].get_tarih()==tarih && akademisyenler[j].r[k].get_baslangic_saat()==basla && akademisyenler[j].r[k].get_bitis_saat()==bitis){
									continue;
								}
								temp[p].set_kisi(akademisyenler[j].r[k].get_kisi());
								temp[p].set_tarih(akademisyenler[j].r[k].get_tarih());
								temp[p].set_baslangic_saat(akademisyenler[j].r[k].get_baslangic_saat());
								temp[p].set_bitis_saat(akademisyenler[j].r[k].get_bitis_saat());
								p++;
							}
							akademisyenler[j].set_randevu_say(akademisyenler[j].get_randevu_say()-1);
							akademisyenler[j].r=new Randevu[akademisyenler[j].get_randevu_say()];
							for(int k=0;k<akademisyenler[j].get_randevu_say();k++){
								akademisyenler[j].r[k].set_kisi(temp[k].get_kisi());
								akademisyenler[j].r[k].set_tarih(temp[k].get_tarih());
								akademisyenler[j].r[k].set_baslangic_saat(temp[k].get_baslangic_saat());
								akademisyenler[j].r[k].set_bitis_saat(temp[k].get_bitis_saat());
							}
							delete[] temp;
						}
					}
					randevu_belge_yaz(ogrenciler,ogrenci_sayi,akademisyenler,akademisyen_sayi);
					cout<<endl<<endl<<"Randevu silme islemi tamamlandi.";Sleep(1500);goto randevu_sil_baslangic;
				}
				case 'h':goto randevu_sil_baslangic;
				default:cout<<"Lutfen tekrar giriniz:";goto randevu_onay_sec;
			}
		}
		else{
			cout<<"Lutfen size sunulan seceneklerden birini secin."<<endl;goto randevu_secim;
		}
	}
	else{
		cout<<"Lutfen size sunulan seceneklerden birini secin."<<endl;goto ana_ekran_giris;
	}
}

bool is_empty(ifstream &belge)
{
    return belge.peek() == std::ifstream::traits_type::eof();
}
