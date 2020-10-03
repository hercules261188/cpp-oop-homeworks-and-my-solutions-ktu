#ifndef STUDENT_H
#define STUDENT_H
#include "./human.h"

class Student:public Human{
	private:
		int student_no, registration_year;
		string department;
	public:
		Student(){
			this->set_appointment_count(0);
		}
		int get_student_no(){
			return student_no;
		}
		void set_student_no(int student_noo){
			student_no = student_noo;
		}
		int get_registration_year(){
			return registration_year;
		}
		void set_registration_year(int registration_yearr){
			registration_year = registration_yearr;
		}
		string get_department(){
			return department;
		}
		void set_department(string departmentt){
			department = departmentt;
		}
		
};

#endif
