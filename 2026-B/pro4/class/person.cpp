#include "../helpers/person.h"
#include "../helpers/work.h"
#include <string.h>
#include <iostream>

using namespace std;


Person::Person() {
    // al no pasarle parametros podemos generar la modificación de manera directa ya que no generamos ninguna incongruencia
    nickname = "paco24";
    age = 24;
    fullname = "Paco N.";
    weight = 60.4;
    work = Work("Sin Trabajo", 0, 0.0);
    salary = 0.0;
}

Person::Person(string nickname) {
    // al pasarle un parametro podemos generar la modificación de manera directa ya que no generamos ninguna incongruencia
    this->nickname = nickname;
    age = 24;
    fullname = "Paco N.";
    weight = 60.4;
    work = Work("Sin Trabajo", 0, 0.0);
    salary = 0.0;
}

Person::Person(string fullname, int age, float weight, string nickname) {
    // al pasarle datos con los mismos nombres usamos this y el valor para generar la asignación del valor en ese espacio de memoria
    this->nickname = nickname;
    this->fullname = fullname;
    this->age = age;
    this->weight = weight;
    work = Work("Sin Trabajo", 0, 0.0);
    salary = 0.0;
}

void Person::assignWork(Work work){
    this->salary = work.salary;
    this->work = work;
}

Person Person::operator+(Person more) {
    return Person(nickname + "_" + more.nickname);
}

Person operator-(Person a_person, Person b_person) {
    return a_person.nickname.length() < b_person.nickname.length() ? a_person : b_person;
}

void Person::viewData() {
    cout << "Nickname: " << nickname << endl;
    cout << "Full Name: " << fullname << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << endl;
    cout << "Work: " << work.role << endl;
    cout << "Colaborates: " << work.colaborates << endl;
    cout << "Salary: " << salary << endl;
}
