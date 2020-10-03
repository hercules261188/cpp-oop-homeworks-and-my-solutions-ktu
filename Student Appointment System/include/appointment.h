#ifndef APPOINTMENT_H
#define APPOINTMENT_H

using namespace std;

class Appointment{
	private:
		int person;
		string date, begin_time, end_time;
	public:
		void set_person(int personn){
			person = personn;
		}
		int get_person(){
			return person;
		}
		void set_date(string datee){
			date = datee;
		}
		string get_date(){
			return date;
		}
		void set_begin_time(string begin_timee){
			begin_time = begin_timee;
		}
		string get_begin_time(){
			return begin_time;
		}
		void set_end_time(string begin_timee,int appointment_length){
			int hour = atoi(begin_timee.substr(0,2).c_str()), minute = atoi(begin_timee.substr(3,2).c_str());
			minute += appointment_length;
			if(minute >= 60){
				hour++;
				minute %= 60;
			}
			stringstream ss;
			if(hour < 10 && minute < 10){
				ss<<"0"<<hour<<".0"<<minute;
			}
			else if(hour < 10){
				ss<<"0"<<hour<<"."<<minute;
			}
			else if(minute < 10){
				ss<<hour<<".0"<<minute;
			}
			else{
				ss<<hour<<"."<<minute;
			}
			end_time = ss.str();
		}
		string get_end_time(){
			return end_time;
		}
		void set_end_time(string end_timee){
			end_time = end_timee;
		}
};

#endif
