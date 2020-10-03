#ifndef ACADEMICIAN_H
#define ACADEMICIAN_H
#include "./human.h"

class Academician:public Human{
	private:
		int registration_number;
		string majors_branch, degree;
	public:
		Academician(){
			this->set_appointment_count(0);
		}
		void set_registration_number(int registration_numberr){
			registration_number = registration_numberr;
		}
		int get_registration_number(){
			return registration_number;
		}
		void set_majors_branch(string majors_branchh){
			majors_branch = majors_branchh;
		}
		string get_majors_branch(){
			return majors_branch;
		}
		void set_degree(string degreee){
			degree = degreee;
		}
		string get_degree(){
			return degree;
		}
};

#endif
