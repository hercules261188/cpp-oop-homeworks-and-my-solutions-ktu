#ifndef HUMAN_H
#define HUMAN_H
#include "./appointment.h"

class Human{
	private:
		string name, surname, e_mail, telephone;
		Appointment *appointment_array;
		int appointment_count;
	public:
		string get_name(){
			return name;
		}
		void set_name(string namee){
			name = namee;
		}
		string get_surname(){
			return surname;
		}
		void set_surname(string surnamee){
			surname = surnamee;
		}
		string get_e_mail(){
			return e_mail;
		}
		void set_e_mail(string e_maill){
			e_mail = e_maill;
		}
		string get_telephone(){
			return telephone;
		}
		void set_telephone(string telephonee){
			telephone = telephonee;
		}
		int get_appointment_count(){
			return appointment_count;
		}
		void set_appointment_count(int appointment_countt){
			appointment_count = appointment_countt;
		}
		void add_appointment_from_file(int person, string date, string begin_time,string end_time){
			if(appointment_count == 0){
				appointment_array = new Appointment[1];
				appointment_array[0].set_person(person);
				appointment_array[0].set_date(date);
				appointment_array[0].set_begin_time(begin_time);
				appointment_array[0].set_end_time(end_time);
				appointment_count++;
			}
			else{
				Appointment *temp = new Appointment[appointment_count];
				for(int i = 0; i < appointment_count; i++){
					temp[i]=appointment_array[i];
				}
				appointment_array = new Appointment[appointment_count + 1];
				for(int i = 0; i < appointment_count; i++){
					appointment_array[i] = temp[i];
				}
				delete[] temp;
				appointment_array[appointment_count].set_person(person);
				appointment_array[appointment_count].set_date(date);
				appointment_array[appointment_count].set_begin_time(begin_time);
				appointment_array[appointment_count].set_end_time(end_time);
				appointment_count++;
			}
		}
		void add_appointment_by_user(int person, string date, string begin_time, int appointment_length){
			if(appointment_count == 0){
				appointment_array = new Appointment[1];
				appointment_array[0].set_person(person);
				appointment_array[0].set_date(date);
				appointment_array[0].set_begin_time(begin_time);
				appointment_array[0].set_end_time(begin_time,appointment_length);
				appointment_count++;
			}
			else{
				Appointment *temp = new Appointment[appointment_count];
				for(int i = 0; i < appointment_count; i++){
					temp[i]=appointment_array[i];
				}
				appointment_array = new Appointment[appointment_count + 1];
				for(int i = 0; i < appointment_count; i++){
					appointment_array[i] = temp[i];
				}
				delete[] temp;
				appointment_array[appointment_count].set_person(person);
				appointment_array[appointment_count].set_date(date);
				appointment_array[appointment_count].set_begin_time(begin_time);
				appointment_array[appointment_count].set_end_time(begin_time,appointment_length);
				appointment_count++;
			}
		}
		void delete_appointment(int person, string date_of_appointment, string begin_time_of_appointment, string end_time_of_appointment){
			Appointment *temp=new Appointment[appointment_count-1];
			int p = 0;
			for(int k = 0; k < appointment_count; k++){
				if(appointment_array[k].get_person() == person && appointment_array[k].get_date() == date_of_appointment && appointment_array[k].get_begin_time() == begin_time_of_appointment && appointment_array[k].get_end_time() == end_time_of_appointment){
					continue;
				}
				temp[p].set_person(appointment_array[k].get_person());
				temp[p].set_date(appointment_array[k].get_date());
				temp[p].set_begin_time(appointment_array[k].get_begin_time());
				temp[p].set_end_time(appointment_array[k].get_end_time());
				p++;
			}
			appointment_count--;
			appointment_array = new Appointment[appointment_count];
			for(int k=0;k<appointment_count;k++){
				appointment_array[k].set_person(temp[k].get_person());
				appointment_array[k].set_date(temp[k].get_date());
				appointment_array[k].set_begin_time(temp[k].get_begin_time());
				appointment_array[k].set_end_time(temp[k].get_end_time());
			}
			delete[] temp;
		}
		int get_appointment_person(int appointment_index){
			return appointment_array[appointment_index].get_person();
		}
		string get_appointment_date(int appointment_index){
			return appointment_array[appointment_index].get_date();
		}
		string get_appointment_begin_time(int appointment_index){
			return appointment_array[appointment_index].get_begin_time();
		}
		string get_appointment_end_time(int appointment_index){
			return appointment_array[appointment_index].get_end_time();
		}
		bool avoidence_to_appointment_similarity(string date,int completed_begin_time, int completed_end_time){
			for(int i = 0; i < appointment_count; i++){
				if(appointment_array[i].get_date() == date){
					int registered_begin_hour, registered_begin_minute, registered_end_hour, registered_end_minute, registered_completed_begin_time, registered_completed_end_time;
					registered_begin_hour=atoi(appointment_array[i].get_begin_time().substr(0,2).c_str());
					registered_begin_minute=atoi(appointment_array[i].get_begin_time().substr(3,2).c_str());
					registered_end_hour=atoi(appointment_array[i].get_end_time().substr(0,2).c_str());
					registered_end_minute=atoi(appointment_array[i].get_end_time().substr(0,2).substr(3,2).c_str());
					registered_completed_begin_time = registered_begin_hour * 100 + registered_begin_minute;
					registered_completed_end_time = registered_end_hour * 100 + registered_end_minute;
					if((completed_begin_time >= registered_completed_begin_time && completed_begin_time < registered_completed_end_time) || (registered_completed_end_time > registered_completed_begin_time && completed_end_time <= registered_completed_end_time)){
						return false;
					}
					else{
						return true;
					}
				}
			}
		}
};

#endif
