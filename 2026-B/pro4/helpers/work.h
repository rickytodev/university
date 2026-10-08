#ifndef WORK_H
#define WORK_H

#include <string>

using namespace std;

// declaracion adelantada para poder hacerla amiga sin incluir su archivo
class Person;

class Work {
    public:
        Work();
        Work(string role, int colaborates, float salary);

        string role;
        int colaborates;

        friend class Person;
    private:
        float salary;
};

#endif
