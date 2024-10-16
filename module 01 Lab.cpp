#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Базовый класс Сотрудник
class Employee {
protected:
    string name;
    int id;
    string role;

public:
    Employee(const string& name, int id, const string& role)
        : name(name), id(id), role(role) {}

    virtual ~Employee() = default;

    virtual double getSalary() const = 0; // Чисто виртуальный метод

    virtual void showInfo() const {
        cout << "Имя: " << name << ", ID: " << id << ", Роль: " << role << endl;
    }
};

// Производный класс Рабочий
class Worker : public Employee {
private:
    double rate;
    int hours;

public:
    Worker(const string& name, int id, double rate, int hours)
        : Employee(name, id, "Рабочий"), rate(rate), hours(hours) {}

    double getSalary() const override {
        return rate * hours;
    }

    void showInfo() const override {
        Employee::showInfo();
        cout << "Ставка: " << rate << ", Часы: " << hours << endl;
    }
};

// Производный класс Менеджер
class Manager : public Employee {
private:
    double baseSalary;
    double bonus;

public:
    Manager(const string& name, int id, double baseSalary, double bonus)
        : Employee(name, id, "Менеджер"), baseSalary(baseSalary), bonus(bonus) {}

    double getSalary() const override {
        return baseSalary + bonus;
    }

    void showInfo() const override {
        Employee::showInfo();
        cout << "Зарплата: " << baseSalary << ", Премия: " << bonus << endl;
    }
};

// Функция для добавления сотрудников и отображения информации о них
void processEmployees() {
    vector<shared_ptr<Employee>> employees;

    employees.push_back(make_shared<Worker>("Иван", 101, 500.0, 160));
    employees.push_back(make_shared<Manager>("Анна", 102, 60000.0, 15000.0));
    employees.push_back(make_shared<Worker>("Петр", 103, 550.0, 170));
    employees.push_back(make_shared<Manager>("Екатерина", 104, 65000.0, 20000.0));

    for (const auto& employee : employees) {
        employee->showInfo();
        cout << "Зарплата: " << employee->getSalary() << "\n" << endl;
    }
}

int main() {
    processEmployees();
    return 0;
}
