#include <iostream>

class employee {
    friend void setSalary(employee&, unsigned int);
public:
    employee(unsigned int monthlySalary) :salary{ monthlySalary } {};
    unsigned int getSalary()const { return salary; }
private:
    unsigned int salary;
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        

void setSalary(employee& person,unsigned int newSalary) {
    person.salary = newSalary;
}

int main()
{
    employee Jane(5000);
    std::cout << "Salary after initialization: " << Jane.getSalary() << std::endl;
    setSalary(Jane, 2000);
    std::cout<<"Salary after call setSalary function: "<<Jane.getSalary();
    
}
