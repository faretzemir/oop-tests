#include <iostream>
#include <stdio.h>

using namespace std;

class Staff {

protected:
	string m_name;
	float m_totalMonthlySales; // sales made in RM
	float m_salary; // fixed monthly base salary

public:
	Staff() {}
	virtual float calculateMonthlySalary() = 0;
	virtual void showStaffInfo()=0 ;
	void setTotalSales(float nSale) ;
};

void Staff::setTotalSales(float nSale){
    m_totalMonthlySales = nSale;
}

class PartTimeStaff : public Staff {
public:
	virtual float calculateMonthlySalary();
	virtual void showStaffInfo();
	PartTimeStaff(string name) ;
	friend bool operator>(PartTimeStaff s1, PartTimeStaff s2);
};

float PartTimeStaff::calculateMonthlySalary(){
    float monthlySalary;
    monthlySalary = 0.8 * m_totalMonthlySales;
    return monthlySalary;
}

void PartTimeStaff::showStaffInfo(){
    cout << endl;
    cout << "Part Time Staff" << endl;
    cout << "Name = " << m_name << endl;
    cout << "Total monthly sales (RM) = " << m_totalMonthlySales << endl;
}

PartTimeStaff::PartTimeStaff(string name){
    m_name = name;
}

bool operator>(PartTimeStaff s1, PartTimeStaff s2){
    if (s1.m_totalMonthlySales > s2.m_totalMonthlySales){
        return true;
    }
    else{
        return false;
    }
}

class FullTimeStaff : public Staff {
	float m_bonus; // calculated

public:
	virtual float calculateMonthlySalary();
	virtual void showStaffInfo();
	FullTimeStaff(string name, float salary);

};

float FullTimeStaff::calculateMonthlySalary(){
    float monthlySalary;

    if(m_totalMonthlySales > m_salary){
        m_bonus = 0.5 * m_totalMonthlySales;
    }
    else{
        m_bonus = 0;
    }

    monthlySalary = m_salary + m_bonus;
    return monthlySalary;
}

void FullTimeStaff::showStaffInfo(){
    cout << endl;
    cout << "Full Time Staff" << endl;
    cout << "Name = " << m_name << endl;
    cout << "Fixed monthly salary = " << m_salary << endl;
    cout << "Total monthly sales (RM) = " << m_totalMonthlySales;
}

FullTimeStaff::FullTimeStaff(string name, float salary){
    m_name = name;
    m_salary = salary;
}

int main() {

	Staff* ptr = new FullTimeStaff("Daniel", 3000);
	ptr->setTotalSales(10000);
	ptr->showStaffInfo();
	cout << "\nAfter adding bonus, monthly salary = " <<                
        ptr->calculateMonthlySalary() << endl;
	
	ptr = new PartTimeStaff("Jim");
	ptr->setTotalSales(24000);
	ptr->showStaffInfo();
	cout << "\nStaff salary this month =  " << 
        ptr->calculateMonthlySalary() << endl;;

	PartTimeStaff s1("Helen");
	s1.setTotalSales(400);
	PartTimeStaff s2("Kattie");
	s2.setTotalSales(150);

	if (s1 > s2)
		cout << "\n\nstaff s1 has more sales than staff s2" << endl;
	else
		cout << "\n\nstaff s2 has more or equal sales than staff s1" << endl;

	getchar();
	return 0;
}
