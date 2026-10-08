#include "../helpers/person.h"
#include "../helpers/work.h"
#include <string>

using namespace std;

Work::Work() {
    role = "Ninguno";
    colaborates = 0;
    salary = 0.0;
}

Work::Work(string role, int colaborates, float salary) {
    this->role = role;
    this->colaborates = colaborates;
    this->salary = salary;
}
