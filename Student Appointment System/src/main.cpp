/*
	Ogrenciler ve Akademisyenler icin Randevu Sistemi
	
	Ad Soyad	:	Osman DURDAG
	e-mail		:	osmandurdag@hotmail.com

*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <sstream>
#include <climits>
#include "../include/student.h"
#include "../include/academician.h"

using namespace std;

int find_academician_count();
int find_student_count();
void add_academician_from_file(Academician *academicians);
void add_academician_by_user(Academician *academicians,int academician_count);
void delete_academician(Academician *academicians,int academician_count);
void add_student_from_file(Student *students);
void add_student_by_user(Student *students,int student_count);
void delete_student(Student *students,int student_count);
void add_appointment_from_file(Student *students,Academician *academicians,int student_count,int academician_count);
void write_appointment_on_document(Student *students,int student_count,Academician *academicians,int academician_count);
void main_menu(Student *students,Academician *academicians,int &student_count,int &academician_count);
bool file_is_empty(ifstream &document);

int main(){
	int student_count, academician_count;
	Student *students;
	Academician *academicians;
	academician_count = find_academician_count();
	if(academician_count!=0){
		academicians = new Academician[academician_count];
		add_academician_from_file(academicians);
	}
	student_count = find_student_count();
	if(student_count!=0){
		students=new Student[student_count];
		add_student_from_file(students);
	}
	if(student_count!=0 && academician_count!=0){
		add_appointment_from_file(students,academicians,student_count,academician_count);
	}
	cout<<endl<<"Akademisyenler ve ogrenciler dosyalardan(varsa) okunup sisteme kaydedildi."<<endl;
	Sleep(1500);
	main_menu(students,academicians,student_count,academician_count);
	delete[] students;
	delete[] academicians;
	return 0;
}

int find_academician_count(){
	int academician_count=0;
	char data[350];
	ifstream academician_file;
	academician_file.open("./doc/academicians.txt");
	if(!academician_file || file_is_empty(academician_file)){
		academician_file.close();
		return academician_count;
	}
	while(!academician_file.eof()){
		academician_file.getline(data,300);
		academician_count++;
	}
	academician_file.close();
	return academician_count;
}

void add_academician_from_file(Academician *academicians){
	int i=0;
	ifstream academician_file;
	academician_file.open("./doc/academicians.txt");
	while(!academician_file.eof()){
	int registration_number;
	string name, surname, majors_branch, e_mail, telephone, degree;
	academician_file>>registration_number;
	academicians[i].set_registration_number(registration_number);
	academician_file>>name;
	academicians[i].set_name(name);
	academician_file>>surname;
	academicians[i].set_surname(surname);
	academician_file>>majors_branch;
	academicians[i].set_majors_branch(majors_branch);
	academician_file>>e_mail;
	academicians[i].set_e_mail(e_mail);
	academician_file>>telephone;
	academicians[i].set_telephone(telephone);
	academician_file>>degree;
	academicians[i].set_degree(degree);
	i++;
	}
	academician_file.close();
	for(int j = 0; j < i; j++){
		for(int p = j + 1; p < i; p++){
			if(academicians[j].get_registration_number() == academicians[p].get_registration_number()){
				cout<<"Dosyada ayni sicil numarasina sahip akademisyenler var."<<endl;
				cout<<"Lutfen dosyayi kontrol ettikten sonra programi tekrar calistiriniz.";
				exit(0);
			}
		}
	}
}

int find_student_count(){
	int student_count=0;
	char data[350];
	ifstream student_file;
	student_file.open("./doc/students.txt");
	if(!student_file || file_is_empty(student_file)){
		student_file.close();
		return student_count;
	}
	while(!student_file.eof()){
		student_file.getline(data,300);
		student_count++;
	}
	student_file.close();
	return student_count;
}

void add_student_from_file(Student *students){
	int i=0;
	ifstream student_file;	
	student_file.open("./doc/students.txt");
	while(!student_file.eof()){
		int student_no, registration_year;
		string name, surname, department, e_mail, telephone;
		student_file>>student_no;
		students[i].set_student_no(student_no);
		student_file>>name;
		students[i].set_name(name);
		student_file>>surname;
		students[i].set_surname(surname);
		student_file>>department;
		students[i].set_department(department);
		student_file>>registration_year;
		students[i].set_registration_year(registration_year);
		student_file>>e_mail;
		students[i].set_e_mail(e_mail);
		student_file>>telephone;
		students[i].set_telephone(telephone);
		i++;
	}
	student_file.close();
	for(int j = 0; j < i; j++){
		for(int p = j + 1; p < i; p++){
			if(students[j].get_student_no() == students[p].get_student_no()){
				cout<<"Dosyada ayni ogrenci numarasina sahip ogrenciler var."<<endl;
				cout<<"Lutfen dosyayi kontrol ettikten sonra programi tekrar calistiriniz.";
				exit(0);
			}
		}
	}
}

void add_appointment_from_file(Student *students,Academician *academicians,int student_count,int academician_count){
	ifstream appointment_file;
	appointment_file.open("./doc/appointments.txt");
	if(!appointment_file || file_is_empty(appointment_file)){
		appointment_file.close();
		return;
	}
	while(!appointment_file.eof()){
		int student_no, academician_registration_number;
		string date, begin_time, end_time;
		appointment_file>>student_no;
		appointment_file>>academician_registration_number;
		appointment_file>>date;
		appointment_file>>begin_time;
		appointment_file>>end_time;
		for(int i = 0; i < student_count; i++){
			if(students[i].get_student_no() == student_no){
				for(int j = 0; j < academician_count; j++){
					if(academicians[j].get_registration_number() == academician_registration_number){
						students[i].add_appointment_from_file(academician_registration_number, date, begin_time, end_time);
						academicians[j].add_appointment_from_file(student_no, date, begin_time, end_time);
					}
				}
			}
		}
	}
	appointment_file.close();
}

void add_student_by_user(Student *students,int student_count){
	int student_no, registration_year;
	string name, surname, department, e_mail, telephone;
	cout<<"Ogrencinin numarasi:";
	choose_num_for_add_student:cin>>student_no;
	if(!cin.good()){
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout<<"Lutfen tekrar giriniz(Yalnizca sayi):";
		goto choose_num_for_add_student;
	}
	else if(student_no < 1){
		cout<<"En kucuk deger 1 olabilir. Tekrar giriniz:";
		goto choose_num_for_add_student;
	}
	for(int i = 0;i<student_count - 1; i++){
		if(student_no == students[i].get_student_no()){
			cout<<"Bu ogrenci numarasina sahip ogrenci zaten kayitli."<<endl;
			cout<<"Lutfen tekrar giriniz:"; goto choose_num_for_add_student;
		}
	}
	students[student_count-1].set_student_no(student_no);
	cout<<"Ogrencinin adi:";
	cin>>name;
	students[student_count-1].set_name(name);
	cout<<"Ogrencinin soyadi:";
	cin>>surname;
	students[student_count-1].set_surname(surname);
	cout<<"Ogrencinin bolumu:";
	cin>>department;
	students[student_count-1].set_department(department);
	cout<<"Ogrencinin kayit yili:";
	entry_regist_year_for_add_student:cin>>registration_year;
	if(!cin.good()){
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout<<"Lutfen tekrar giriniz(Yalnizca sayi):";
		goto entry_regist_year_for_add_student;
	}
	students[student_count-1].set_registration_year(registration_year);
	cout<<"Ogrencinin e-mail adresi:";
	cin>>e_mail;
	students[student_count-1].set_e_mail(e_mail);
	cout<<"Ogrencinin telefon numarasi:";
	cin>>telephone;
	students[student_count-1].set_telephone(telephone);
}

void delete_student(Student *students,int student_count){
	ofstream student_file("./doc/students.txt");
	for(int i = 0; i < student_count; i++){
		if(i == 0){
			student_file<<students[i].get_student_no()<<" ";
			student_file<<students[i].get_name()<<" ";
			student_file<<students[i].get_surname()<<" ";
			student_file<<students[i].get_department()<<" ";
			student_file<<students[i].get_registration_year()<<" ";
			student_file<<students[i].get_e_mail()<<" ";
			student_file<<students[i].get_telephone();
		}
		else{
			student_file<<endl<<students[i].get_student_no()<<" ";
			student_file<<students[i].get_name()<<" ";
			student_file<<students[i].get_surname()<<" ";
			student_file<<students[i].get_department()<<" ";
			student_file<<students[i].get_registration_year()<<" ";
			student_file<<students[i].get_e_mail()<<" ";
			student_file<<students[i].get_telephone();
		}	
	}
	student_file.close();
}

void add_academician_by_user(Academician *academicians,int academician_count){
	int registration_number;
	string name, surname, majors_branch, e_mail, telephone, degree;
	cout<<"Akademisyenin sicil numarasi:";
	entry_regist_number_for_add_academician:cin>>registration_number;
	if(!cin.good()){
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cout<<"Lutfen tekrar giriniz(Yalnizca sayi):";
		goto entry_regist_number_for_add_academician;
	}
	else if(registration_number < 1){
		cout<<"En kucuk deger 1 olabilir. Tekrar giriniz:";
		goto entry_regist_number_for_add_academician;
	}
	for(int i = 0; i<academician_count - 1; i++){
		if(registration_number == academicians[i].get_registration_number()){
			cout<<"Bu sicil numarasina sahip akademisyen zaten kayitli."<<endl;
			cout<<"Lutfen tekrar giriniz:";goto entry_regist_number_for_add_academician;
		}
	}
	academicians[academician_count - 1].set_registration_number(registration_number);
	cout<<"Akademisyenin adi:";
	cin>>name;
	academicians[academician_count - 1].set_name(name);
	cout<<"Akademisyenin soyadi:";
	cin>>surname;
	academicians[academician_count - 1].set_surname(surname);
	cout<<"Akademisyenin anabilim dali:";
	cin>>majors_branch;
	academicians[academician_count-1].set_majors_branch(majors_branch);
	cout<<"Akademisyenin e_mail adresi:";
	cin>>e_mail;
	academicians[academician_count-1].set_e_mail(e_mail);
	cout<<"Akademisyenin telefon numarasi:";
	cin>>telephone;
	academicians[academician_count-1].set_telephone(telephone);
	cout<<"Akademisyenin unvani:";
	cin>>degree;
	academicians[academician_count-1].set_degree(degree);
	ofstream academician_file;
	academician_file.open("./doc/academicians.txt",ios::app);
	if(academician_count - 1 == 0){
		academician_file<<academicians[academician_count-1].get_registration_number()<<" ";
	}
	else{
		academician_file<<endl<<academicians[academician_count-1].get_registration_number()<<" ";
	}
	academician_file<<academicians[academician_count-1].get_name()<<" ";
	academician_file<<academicians[academician_count-1].get_surname()<<" ";
	academician_file<<academicians[academician_count-1].get_majors_branch()<<" ";
	academician_file<<academicians[academician_count-1].get_e_mail()<<" ";
	academician_file<<academicians[academician_count-1].get_telephone()<<" ";
	academician_file<<academicians[academician_count-1].get_degree();
	academician_file.close();
}

void delete_academician(Academician *academicians,int academician_count){
	ofstream academician_file("./doc/academicians.txt");
	for(int i=0;i<academician_count;i++){
		if(i==0){
			academician_file<<academicians[i].get_registration_number()<<" ";
			academician_file<<academicians[i].get_name()<<" ";
			academician_file<<academicians[i].get_surname()<<" ";
			academician_file<<academicians[i].get_majors_branch()<<" ";
			academician_file<<academicians[i].get_e_mail()<<" ";
			academician_file<<academicians[i].get_telephone()<<" ";
			academician_file<<academicians[i].get_degree();
		}
		else{
			academician_file<<endl<<academicians[i].get_registration_number()<<" ";
			academician_file<<academicians[i].get_name()<<" ";
			academician_file<<academicians[i].get_surname()<<" ";
			academician_file<<academicians[i].get_majors_branch()<<" ";
			academician_file<<academicians[i].get_e_mail()<<" ";
			academician_file<<academicians[i].get_telephone()<<" ";
			academician_file<<academicians[i].get_degree();
		}	
	}
	academician_file.close();
}

void write_appointment_on_document(Student *students,int student_count,Academician *academicians,int academician_count){
	bool first_line = true;
	ofstream appointment_file;
	appointment_file.open("./doc/appointments.txt");
	for(int i=0;i<student_count;i++){
		if(students[i].get_appointment_count()!=0){
			for(int j = 0; j < students[i].get_appointment_count(); j++){
				if(j == 0 && first_line){
					appointment_file<<students[i].get_student_no()<<" ";
					first_line=false;
				}
				else{
					appointment_file<<endl<<students[i].get_student_no()<<" ";
				}	
				for(int k = 0; k < academician_count; k++){
					if(students[i].get_appointment_person(j) == academicians[k].get_registration_number()){
						appointment_file<<academicians[k].get_registration_number()<<" ";
					}
				}
				appointment_file<<students[i].get_appointment_date(j)<<" ";
				appointment_file<<students[i].get_appointment_begin_time(j)<<" ";
				appointment_file<<students[i].get_appointment_end_time(j);
			}
		}
	}
	appointment_file.close();
}

void main_menu(Student *students,Academician *academicians,int &student_count,int &academician_count){
	int main_menu_selection;
	main_screen:system("CLS");
	cout<<"Yeni akademisyen veya ogrenci eklemek istiyorsaniz 1'e"<<endl;
	cout<<"Kayitli akademisyen veya ogrenci silmek istiyorsaniz 2'ye"<<endl;
	cout<<"Randevu sorgulamak, almak veya silmek icin 3'e"<<endl;
	cout<<"Programdan cikmak icin 0'a basiniz:";
	main_menu_entry:cin>>main_menu_selection;
	if(main_menu_selection==0){
		cout<<"Program sonlandi.";
		delete[] academicians;
		delete[] students;
		exit(0);
	}
	else if(main_menu_selection==1){
		int add_person_menu_selection;
		system("CLS");
		cout<<"Akademisyen eklemek istiyorsaniz 1'e"<<endl;
		cout<<"Ogrenci eklemek istiyorsaniz 2'ye"<<endl;
		cout<<"Onceki menuye donmek istiyorsaniz 0'a basiniz:";
		add_screen:cin>>add_person_menu_selection;
		if(add_person_menu_selection==0)
			goto main_screen;
		else if(add_person_menu_selection == 1){
			if(academician_count==0){
				academician_count++;
				academicians=new Academician[academician_count];
				add_academician_by_user(academicians, academician_count);
				cout<<academicians[academician_count - 1].get_registration_number()<<" sicil numarali akademisyen eklendi.";Sleep(1000);goto main_screen;
			}
			else{
				Academician *temp=new Academician[academician_count];
				for(int i=0;i<academician_count;i++){
					temp[i]=academicians[i];
				}
				delete[] academicians;
				academician_count++;
				academicians=new Academician[academician_count];
				for(int i=0;i<academician_count-1;i++){
					academicians[i]=temp[i];
				}
				delete[] temp;
				add_academician_by_user(academicians,academician_count);
				cout<<academicians[academician_count-1].get_registration_number()<<" sicil numarali akademisyen eklendi.";Sleep(1000);goto main_screen;
			}			
		}
		else if(add_person_menu_selection == 2){
			if(student_count == 0){
				student_count++;
				students=new Student[student_count];
				add_student_by_user(students, student_count);
				ofstream student_file;
				student_file.open("./doc/students.txt",ios::app);
				student_file<<students[student_count-1].get_student_no()<<" ";
				student_file<<students[student_count-1].get_name()<<" ";
				student_file<<students[student_count-1].get_surname()<<" ";
				student_file<<students[student_count-1].get_department()<<" ";
				student_file<<students[student_count-1].get_registration_year()<<" ";
				student_file<<students[student_count-1].get_e_mail()<<" ";
				student_file<<students[student_count-1].get_telephone();
				student_file.close();
				cout<<students[student_count-1].get_student_no()<<" numarali ogrenci eklendi.";Sleep(1000);goto main_screen;
			}
			else{
				Student *temp=new Student[student_count];
				for(int i=0;i<student_count;i++){
					temp[i]=students[i];
				}
				delete[] students;
				student_count++;
				students=new Student[student_count];
				for(int i=0;i<student_count-1;i++){
					students[i]=temp[i];
				}
				delete[] temp;
				add_student_by_user(students,student_count);
				ofstream student_file;
				student_file.open("./doc/students.txt",ios::app);
				student_file<<endl<<students[student_count-1].get_student_no()<<" ";
				student_file<<students[student_count-1].get_name()<<" ";
				student_file<<students[student_count-1].get_surname()<<" ";
				student_file<<students[student_count-1].get_department()<<" ";
				student_file<<students[student_count-1].get_registration_year()<<" ";
				student_file<<students[student_count-1].get_e_mail()<<" ";
				student_file<<students[student_count-1].get_telephone();
				student_file.close();
				cout<<students[student_count-1].get_student_no()<<" numarali ogrenci eklendi.";Sleep(1000);goto main_screen;
			}	
		}
		else{
			cout<<"Lutfen size sunulan seceneklerden birini secin."<<endl;goto add_screen;
		}
	}
	else if(main_menu_selection==2){
		int delete_selection;
		deletion_screen:system("CLS");
		cout<<"Akademisyen silmek istiyorsaniz 1'e"<<endl;
		cout<<"Ogrenci silmek istiyorsaniz 2'ye"<<endl;
		cout<<"Onceki menuye donmek icin 0'a basiniz:";
		deletion_selection:cin>>delete_selection;
		if(delete_selection==0){
			goto main_screen;
		}
		else if(delete_selection == 1){
			if(academician_count == 0){
				system("CLS");
				cout<<"Sistemde kayitli akademisyen bulunmamaktadir.";Sleep(1000);goto deletion_screen;
			}
			else{
				delete_academician_screen:int academician_selection;
				bool academician_selected;
				system("CLS");
				cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
				cout<<endl<<endl<<"\t\t\t*********AKADEMiSYENLER LiSTESi*********"<<endl<<endl;
				cout<<setw(15)<<"Sicil No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(23)<<"Anabilim Dali"<<endl<<endl;
				for(int i=0;i<academician_count;i++){
					cout<<i+1<<":) "<<setw(9)<<academicians[i].get_registration_number()<<setw(14)<<academicians[i].get_name()<<setw(18)<<academicians[i].get_surname()<<setw(21)<<academicians[i].get_majors_branch()<<endl;
				}
				cout<<endl<<"Lutfen sistemden silmek istediginiz akademisyenin listedeki numarasini giriniz:";
				delete_academician_input:cin>>academician_selection;
				if(academician_selection==0){
					goto deletion_screen;
				}
				academician_selected = false;
				for(int i=0;i<academician_count;i++){
					if(i+1 == academician_selection){
						academician_selected = true;
						cout<<endl<<academicians[i].get_registration_number()<<" sicil numarali akademisyeni silmek istiyor musunuz?(e/h)";
						char accepted;
						yes_or_no:cin>>accepted;
						switch(accepted){
							case 'e':{
								Academician *temp=new Academician[academician_count-1];
								int k=0;
								int deleted=academicians[academician_selection-1].get_registration_number();
								for(int i=0;i<academician_count;i++){
									if(i != academician_selection - 1){
										temp[k] = academicians[i];
										k++;
									}
								}
								academician_count--;
								academicians=new Academician[academician_count];
								for(int i=0;i<academician_count;i++){
									academicians[i]=temp[i];
								}
								delete[] temp;
								cout<<deleted<<" sicil numarali akademisyen sistemden silindi.";
								delete_academician(academicians,academician_count);
								write_appointment_on_document(students,student_count,academicians,academician_count);
								Sleep(1500);
								goto delete_academician_screen;
							}
							case 'h':goto delete_academician_screen;
							default:cout<<"Lutfen tekrar giriniz:";goto yes_or_no;
						}
					}
				}
				if(!academician_selected){
					cout<<"Lutfen tutarli bir giris yapiniz:";goto delete_academician_input;
				}
			}
		}
		else if(delete_selection==2){
			if(student_count == 0){
				system("CLS");
				cout<<"Sistemde kayitli ogrenci bulunmamaktadir.";Sleep(1000);goto deletion_screen;
			}
			else{
				delete_student_screen:int student_selection;
				bool student_selected;
				system("CLS");
				cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
				cout<<endl<<endl<<"\t\t\t*********OGRENCiLER LiSTESi*********"<<endl<<endl;
				cout<<setw(15)<<"Ogrenci No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(19)<<"Bolum"<<endl<<endl;
				for(int i=0;i<student_count;i++){
					cout<<i+1<<":) "<<setw(9)<<students[i].get_student_no()<<setw(14)<<students[i].get_name()<<setw(18)<<students[i].get_surname()<<setw(21)<<students[i].get_department()<<endl;
				}
				cout<<endl<<"Lutfen sistemden silmek istediginiz ogrencinin listedeki numarasini giriniz:";
				delete_student_input:cin>>student_selection;
				if(student_selection==0){
					goto deletion_screen;
				}
				student_selected=false;
				for(int i=0;i<student_count;i++){
					if(i+1 == student_selection){
						student_selected=true;
						cout<<endl<<students[i].get_student_no()<<" numarali ogrenciyi silmek istiyor musunuz?(e/h)";
						char accepted;
						yes_or_no_2:cin>>accepted;
						switch(accepted){
							case 'e':{
								Student *temp=new Student[student_count-1];
								int k=0;
								int deleted=students[student_selection-1].get_student_no();
								for(int i=0;i<student_count;i++){
									if(i!=student_selection-1){
										temp[k]=students[i];
										k++;
									}
								}
								student_count--;
								students=new Student[student_count];
								for(int i=0;i<student_count;i++){
									students[i]=temp[i];
								}
								delete[] temp;
								cout<<deleted<<" numarali ogrenci sistemden silindi.";
								delete_student(students,student_count);
								write_appointment_on_document(students,student_count,academicians,academician_count);
								Sleep(1500);
								goto delete_student_screen;
							}
							case 'h':goto delete_student_screen;
							default:cout<<"Lutfen tekrar giriniz:";goto yes_or_no_2;
						}
					}
				}
				if(!student_selected){
					cout<<"Lutfen tutarli bir giris yapiniz:";goto delete_student_input;
				}
			}
		}
		else{
			cout<<"Lutfen size sunulan seceneklerden birini giriniz:";goto deletion_screen;
		}
	}
	else if(main_menu_selection==3){
		int appointment_main_screen_selection;
		appointment_main_screen:system("CLS");
		cout<<"Randevulari listelemek icin 1'e"<<endl;
		cout<<"Randevu olusturmak icin 2'ye"<<endl;
		cout<<"Randevu silmek icin 3'e"<<endl;
		cout<<"Onceki menuye donmek icin 0'a basiniz:";
		appointment_selection:cin>>appointment_main_screen_selection;
		if(appointment_main_screen_selection==0)
			goto main_screen;
		else if(appointment_main_screen_selection==1){
			int appointment_list_selection;
			appointment_list_screen:system("CLS");
			cout<<"Kayitli butun randevulari listelemek icin 1'e"<<endl;
			cout<<"Belirli bir ogrenciye ait randevulari listelemek icin 2'ye"<<endl;
			cout<<"Belirli bir akademisyene ait randevulari listelemek icin 3'e"<<endl;
			cout<<"Onceki menuye donmek icin 0'a basiniz:";
			appointment_list_entry:cin>>appointment_list_selection;
			if(appointment_list_selection==0)
				goto appointment_main_screen;
			else if(appointment_list_selection==1){
				ifstream appointment_file;
				appointment_file.open("./doc/appointments.txt");
				if(!appointment_file || file_is_empty(appointment_file)){
					cout<<endl<<"Kayitli randevu yok."<<endl;Sleep(1000);goto appointment_main_screen;
				}
				system("CLS");
				cout<<endl<<endl<<"\t\t\t*********RANDEVU LiSTESi*********"<<endl<<endl;
				cout<<setw(15)<<"Ogrenci No"<<setw(25)<<"Akademisyen Sicil No"<<setw(10)<<"Tarih"<<setw(15)<<"Baslangic"<<setw(10)<<"Bitis"<<endl;
				while(!appointment_file.eof()){
					int student_number, academician_registry_number;
					string app_date, begin_t, end_t;
					appointment_file>>student_number;
					appointment_file>>academician_registry_number;
					appointment_file>>app_date;
					appointment_file>>begin_t;
					appointment_file>>end_t;
					cout<<setw(12)<<student_number<<setw(20)<<academician_registry_number<<setw(20)<<app_date<<setw(10)<<begin_t<<setw(13)<<end_t<<endl;
				}
				appointment_file.close();
				cout<<endl<<"Onceki menuye donmek icin bir tusa basiniz.";
				char wait_appointments_list;
				cin>>wait_appointments_list;
				goto appointment_list_screen;
			}
			else if(appointment_list_selection==2){
				student_list_screen:int select_student;
				bool selected;
				system("CLS");
				cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
				cout<<endl<<endl<<"\t\t\t*********OGRENCiLER LiSTESi*********"<<endl<<endl;
				cout<<setw(15)<<"Ogrenci No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(19)<<"Bolum"<<endl<<endl;
				for(int i=0;i<student_count;i++){
					cout<<i+1<<":) "<<setw(9)<<students[i].get_student_no()<<setw(14)<<students[i].get_name()<<setw(18)<<students[i].get_surname()<<setw(21)<<students[i].get_department()<<endl;
				}
				cout<<endl<<"Randevularini gormek istediginiz ogrencinin listedeki numarasini giriniz:";
				select_student_appointment_from_list:cin>>select_student;
				if(select_student==0){
					goto appointment_list_screen;
				}
				selected=false;
				for(int i=0;i<student_count;i++){
					if(i+1 == select_student){
						selected=true;
						if(students[i].get_appointment_count()==0){
							cout<<"Secilen ogrenciye ait kayitli randevu bulunmamaktadir."<<endl;
							cout<<"Tekrar giris yapiniz:";goto select_student_appointment_from_list;
						}
						system("CLS");
						cout<<"\t"<<students[i].get_student_no()<<" / "<<students[i].get_name()<<" "<<students[i].get_surname();
						cout<<endl<<endl<<"\t\t\t*********Randevu Listesi*********"<<endl<<endl;
						cout<<setw(15)<<" Akademisyen Sicil No"<<setw(13)<<"Tarih"<<setw(23)<<"Baslangic Saati"<<setw(15)<<"Bitis Saati"<<endl;
						for(int j=0;j<students[i].get_appointment_count();j++){
							cout<<setw(13)<<students[i].get_appointment_person(j)<<setw(23)<<students[i].get_appointment_date(j)<<setw(15)<<students[i].get_appointment_begin_time(j)<<setw(19)<<students[i].get_appointment_end_time(j)<<endl;
						}
						cout<<endl<<endl<<"Onceki menuye donmek icin bir tusa basiniz.";
						char wait_student_appointment_list;
						cin>>wait_student_appointment_list;
						goto student_list_screen;
					}
				}
				if(!selected){
					cout<<"Lutfen tutarli bir giris yapiniz:";goto select_student_appointment_from_list;
				}
				
			}
			else if(appointment_list_selection==3){
				academician_list_screen:int select_academician;
				bool selected;
				system("CLS");
				cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
				cout<<endl<<endl<<"\t\t\t*********AKADEMiSYENLER LiSTESi*********"<<endl<<endl;
				cout<<setw(15)<<"Sicil No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(23)<<"Anabilim Dali"<<endl<<endl;
				for(int i=0;i<academician_count;i++){
					cout<<i+1<<":) "<<setw(9)<<academicians[i].get_registration_number()<<setw(14)<<academicians[i].get_name()<<setw(18)<<academicians[i].get_surname()<<setw(21)<<academicians[i].get_majors_branch()<<endl;
				}
				cout<<endl<<"Randevularini gormek istediginiz akademisyenin listedeki numarasini giriniz:";
				select_academician_appointment_from_list:cin>>select_academician;
				if(select_academician==0){
					goto appointment_list_screen;
				}
				selected=false;
				for(int i=0;i<academician_count;i++){
					if(i+1==select_academician){
						selected=true;
						if(academicians[i].get_appointment_count()==0){
							cout<<"Secilen akademisyene ait kayitli randevu bulunmamaktadir."<<endl;
							cout<<"Tekrar giris yapiniz:";goto select_academician_appointment_from_list;
						}
						system("CLS");
						cout<<"\t"<<academicians[i].get_registration_number()<<" / "<<academicians[i].get_name()<<" "<<academicians[i].get_surname();
						cout<<endl<<endl<<"\t\t\t*********Randevu Listesi*********"<<endl<<endl;
						cout<<setw(15)<<" Ogrenci No"<<setw(13)<<"Tarih"<<setw(23)<<"Baslangic Saati"<<setw(15)<<"Bitis Saati"<<endl;
						for(int j=0;j<academicians[i].get_appointment_count();j++){
							cout<<setw(13)<<academicians[i].get_appointment_person(j)<<setw(17)<<academicians[i].get_appointment_date(j)<<setw(15)<<academicians[i].get_appointment_begin_time(j)<<setw(19)<<academicians[i].get_appointment_end_time(j)<<endl;
						}
						cout<<endl<<endl<<"Onceki menuye donmek icin bir tusa basiniz.";
						char wait_academician_appointment_list;
						cin>>wait_academician_appointment_list;
						goto academician_list_screen;
					}
				}
				if(!selected){
					cout<<"Lutfen tutarli bir giris yapiniz:";goto select_academician_appointment_from_list;
				}
			}
			else{
				cout<<"Lutfen size sunulan seceneklerden birini secin."<<endl;goto appointment_list_entry;
			}
		}
		else if(appointment_main_screen_selection==2){
			create_appointment_screen:int select_student;
			bool selected;
			system("CLS");
			cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
			cout<<endl<<endl<<"\t\t\t*********OGRENCiLER LiSTESi*********"<<endl<<endl;
			cout<<setw(15)<<"Ogrenci No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(19)<<"Bolum"<<endl<<endl;
			for(int i=0;i<student_count;i++){
				cout<<i+1<<":) "<<setw(9)<<students[i].get_student_no()<<setw(14)<<students[i].get_name()<<setw(18)<<students[i].get_surname()<<setw(21)<<students[i].get_department()<<endl;
			}
			cout<<endl<<"Randevu olusturmak istediginiz ogrencinin listedeki numarasini giriniz:";
			select_student_for_create_appointment:cin>>select_student;
			if(select_student==0){
				goto appointment_main_screen;
			}
			
			selected=false;
			for(int i=0;i<student_count;i++){
				if(i+1==select_student){
					selected=true;
				}
			}
			if(!selected){
				cout<<"Lutfen tutarli bir giris yapiniz:";goto select_student_for_create_appointment;
			}
			int select_academician;
			system("CLS");
			cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
			cout<<endl<<endl<<"\t\t\t*********AKADEMiSYENLER LiSTESi*********"<<endl<<endl;
			cout<<setw(15)<<"Sicil No"<<setw(10)<<"Ad"<<setw(19)<<"Soyad"<<setw(23)<<"Anabilim Dali"<<endl<<endl;
			for(int i=0;i<academician_count;i++){
				cout<<i+1<<":) "<<setw(9)<<academicians[i].get_registration_number()<<setw(14)<<academicians[i].get_name()<<setw(18)<<academicians[i].get_surname()<<setw(21)<<academicians[i].get_majors_branch()<<endl;
			}
			cout<<endl<<"Randevu almak istediginiz akademisyenin listedeki numarasini giriniz:";
			select_academician_for_create_appointment:cin>>select_academician;
			if(select_academician==0){
				goto appointment_main_screen;
			}
			selected=false;
			for(int i=0;i<academician_count;i++){
				if(i+1==select_academician){
					selected=true;
				}
			}
			if(!selected){
				cout<<"Lutfen tutarli bir giris yapiniz:";goto select_academician_for_create_appointment;
			}
			string date, begin_time;
			int appointment_length;
			cout<<"Randevu olusturmak istediginiz Tarih(gg.aa.yyyy):";
			entry_date:cin>>date;
			int day,month,year;
			day=atoi(date.substr(0,2).c_str());
			month=atoi(date.substr(3,2).c_str());
			year=atoi(date.substr(6,4).c_str());
			time_t timee = time(0);
    		tm* present_time = localtime(&timee);
			if((year<(present_time->tm_year + 1900)) || (year==(present_time->tm_year + 1900) && month < (present_time->tm_mon + 1)) || (year==(present_time->tm_year + 1900) && month == (present_time->tm_mon + 1) && day<(present_time->tm_mday))){
				cout<<"Gecmis zaman icin randevu olusturamazsiniz. Lutfen tekrar tarih giriniz:";goto entry_date;
			}
			else if(day>31 || day < 1){
				cout<<"Gun degeri tutarsiz. Lutfen tekrar tarih giriniz:";goto entry_date;
			}
			else if(month<1 || month>12){
				cout<<"Ay degeri tutarsiz. Lutfen tekrar tarih giriniz:";goto entry_date;
			}
			else if(year==(present_time->tm_year + 1900) && month == (present_time->tm_mon + 1) && day == (present_time->tm_mday) && present_time->tm_hour >= 16 ){
				cout<<"Bugun icin artik randevu alamazsiniz. Lutfen tekrar tarih giriniz:";goto entry_date;
			}
			cout<<"Baslangic saati(ss.dd):";
			entry_begin_time:cin>>begin_time;
			int begin_time_hour,begin_time_minute,end_time_hour,end_time_minute,completed_begin_time,completed_end_time;
			begin_time_hour=atoi(begin_time.substr(0,2).c_str());
			begin_time_minute=atoi(begin_time.substr(3,2).c_str());
			if(begin_time_hour<8 || (begin_time_hour==16 && begin_time_minute>30) || begin_time_hour>=17){
				cout<<"08.00 ve 16.30 saatleri arasinda randevu alinabilmektedir."<<endl<<"Lutfen tekrar giriniz:";goto entry_begin_time;
			}
			
			else if(year==(present_time->tm_year + 1900) && month == (present_time->tm_mon + 1) && day==(present_time->tm_mday) && begin_time_hour<(present_time->tm_hour)){
				cout<<"Gecmis zaman icin randevu olusturamazsiniz. Lutfen tekrar baslangic saati giriniz:";goto entry_begin_time;
			}
			else if(year==(present_time->tm_year + 1900) && month == (present_time->tm_mon + 1) && day==(present_time->tm_mday) && begin_time_hour==(present_time->tm_hour) && begin_time_minute<(present_time->tm_min)){
				cout<<"Gecmis zaman icin randevu olusturamazsiniz. Lutfen tekrar baslangic saati giriniz:";goto entry_begin_time;
			}
			cout<<"Randevu suresi(dakika):";
			entry_appointment_len:cin>>appointment_length;
			if(appointment_length < 15 || appointment_length > 60){
				cout<<"Randevu suresi 15 dakika ile 60 dakika arasinda olmalidir. Tekrar giriniz:";goto entry_appointment_len;
			}
			else if(begin_time_hour == 16 && begin_time_minute + appointment_length>60){
				cout<<"Randevu saatinize gore randevu sureniz en fazla "<<60 - begin_time_minute<<" dakika olabilir."<<endl<<"Lutfen randevu surenizi tekrar giriniz:";goto entry_appointment_len;
			}
			end_time_hour=(begin_time_minute+appointment_length)>=60?(begin_time_hour+1):(begin_time_hour);
			end_time_minute=(begin_time_minute+appointment_length)%60;
			completed_begin_time = begin_time_hour * 100 + begin_time_minute;
			completed_end_time = end_time_hour * 100 + end_time_minute;
			if(students[select_student-1].get_appointment_count()==0){
				if(academicians[select_academician-1].get_appointment_count()==0){
					students[select_student-1].add_appointment_by_user(academicians[select_academician-1].get_registration_number(),date,begin_time,appointment_length);
					academicians[select_academician-1].add_appointment_by_user(students[select_student-1].get_student_no(),date,begin_time,appointment_length);
					write_appointment_on_document(students,student_count,academicians,academician_count);
					cout<<"Randevu olusturuldu."<<endl;
					Sleep(1000);goto create_appointment_screen;
				}
				else{
					if(!academicians[select_academician-1].avoidence_to_appointment_similarity(date,completed_begin_time,completed_end_time)){
						cout<<endl<<"Secilen akademisyenin belirtilen zaman icinde randevusu bulunmakta!"<<endl;Sleep(1500);
						goto create_appointment_screen;
					}
					students[select_student-1].add_appointment_by_user(academicians[select_academician-1].get_registration_number(),date,begin_time,appointment_length);
					academicians[select_academician-1].add_appointment_by_user(students[select_student-1].get_student_no(),date,begin_time,appointment_length);
					write_appointment_on_document(students,student_count,academicians,academician_count);
					cout<<"Randevu olusturuldu."<<endl;Sleep(1000);
					goto create_appointment_screen;
				}
			}
			else{
				if(!students[select_student-1].avoidence_to_appointment_similarity(date,completed_begin_time,completed_end_time)){
					cout<<endl<<"Secilen ogrencinin belirtilen zaman icinde randevusu bulunmakta!"<<endl;Sleep(1500);
					goto create_appointment_screen;
				}
				if(academicians[select_academician-1].get_appointment_count()==0){
					academicians[select_academician-1].add_appointment_by_user(students[select_student-1].get_student_no(),date,begin_time,appointment_length);
					students[select_student-1].add_appointment_by_user(academicians[select_academician-1].get_registration_number(),date,begin_time,appointment_length);
					write_appointment_on_document(students,student_count,academicians,academician_count);
					cout<<"Randevu olusturuldu."<<endl;Sleep(1000);
					goto create_appointment_screen;
				}
				else{
					if(!academicians[select_academician-1].avoidence_to_appointment_similarity(date,completed_begin_time,completed_end_time)){
						cout<<endl<<"Secilen akademisyenin belirtilen zaman icinde randevusu bulunmakta!"<<endl;Sleep(1500);
						goto create_appointment_screen;
					}	
					academicians[select_academician-1].add_appointment_by_user(students[select_student-1].get_student_no(),date,begin_time,appointment_length);
					students[select_student-1].add_appointment_by_user(academicians[select_academician-1].get_registration_number(),date,begin_time,appointment_length);
					write_appointment_on_document(students,student_count,academicians,academician_count);
					cout<<"Randevu olusturuldu."<<endl;Sleep(1000);goto create_appointment_screen;
				}
			}
		}
		else if(appointment_main_screen_selection==3){
			delete_appointment_screen:ifstream appointment_file;
			appointment_file.open("./doc/appointments.txt");
			if(!appointment_file || file_is_empty(appointment_file)){
				cout<<endl<<"Kayitli randevu yok."<<endl;Sleep(1000);goto appointment_main_screen;
			}
			system("CLS");
			int i = 0;
			cout<<setw(80)<<"Onceki menuye donmek icin 0'a basiniz.";
			cout<<endl<<endl<<"\t\t\t*********RANDEVU LiSTESi*********"<<endl<<endl;
			cout<<setw(15)<<"Ogrenci No"<<setw(25)<<"Akademisyen Sicil No"<<setw(10)<<"Tarih"<<setw(15)<<"Baslangic"<<setw(10)<<"Bitis"<<endl;
			while(!appointment_file.eof()){
				int student_no,academician_registration_no;
				string date_of_appointment, begin_time_of_appointment, end_time_of_appointment;
				appointment_file>>student_no;
				appointment_file>>academician_registration_no;
				appointment_file>>date_of_appointment;
				appointment_file>>begin_time_of_appointment;
				appointment_file>>end_time_of_appointment;
				cout<<i+1<<":) "<<setw(9)<<student_no<<setw(19)<<academician_registration_no<<setw(20)<<date_of_appointment<<setw(10)<<begin_time_of_appointment<<setw(13)<<end_time_of_appointment<<endl;
				i++;
			}
			appointment_file.close();
			cout<<endl<<endl<<"Silmek istediginiz randevunun liste numarasini giriniz:";
			int appointment_to_be_deleted;
			select_appointment_to_be_deleted:cin>>appointment_to_be_deleted;
			if(appointment_to_be_deleted < 1 || appointment_to_be_deleted > i ){
				if(appointment_to_be_deleted==0){ // Want to return Appointment Menu
					goto appointment_main_screen;
				}
				cout<<"Lutfen tutarli bir giris yapiniz:";goto select_appointment_to_be_deleted;
			}
			cout<<appointment_to_be_deleted<<" numarali randevuyu silmek istiyor musunuz?(e/h)";
			char agree_to_operation;
			select_agree_to_operation:cin>>agree_to_operation;
			switch(agree_to_operation){
				case 'e':{
					i = 1;
					int student_no,academician_registration_no;
					string date_of_appointment,begin_time_of_appointment,end_time_of_appointment;
					appointment_file.open("./doc/appointments.txt");
					while(!appointment_file.eof()){
						appointment_file>>student_no;
						appointment_file>>academician_registration_no;
						appointment_file>>date_of_appointment;
						appointment_file>>begin_time_of_appointment;
						appointment_file>>end_time_of_appointment;
						if(i == appointment_to_be_deleted){
							break;
						}
						i++;
					}
					appointment_file.close();
					for(int j=0;j<student_count;j++){
						if(students[j].get_student_no() == student_no){
							students[j].delete_appointment(academician_registration_no, date_of_appointment, begin_time_of_appointment, end_time_of_appointment);
						}
					}
					for(int j = 0; j < academician_count; j++){
						if(academicians[j].get_registration_number() == academician_registration_no){
							academicians[j].delete_appointment(student_no,date_of_appointment,begin_time_of_appointment,end_time_of_appointment);
						}
					}
					write_appointment_on_document(students,student_count,academicians,academician_count);
					cout<<endl<<endl<<"Randevu silme islemi tamamlandi.";Sleep(1500);goto delete_appointment_screen;
				}
				case 'h':goto delete_appointment_screen;
				default:cout<<"Lutfen tekrar giriniz:";goto select_agree_to_operation;
			}
		}
		else{
			cout<<"Lutfen size sunulan seceneklerden birini secin."<<endl;goto appointment_selection;
		}
	}
	else{
		cout<<"Lutfen size sunulan seceneklerden birini secin."<<endl;goto main_menu_entry;
	}
}

bool file_is_empty(ifstream &document)
{
    return document.peek() == std::ifstream::traits_type::eof();
}
