#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "./work.h"

using namespace std;

class Person {
    public:
        string nickname;
        Work work; // atributo que usa una clase como tipo de dato

        Person();
        Person(string nickname);
        Person(string fullname, int age, float weight, string nickname);

        void assignWork(Work work);
        void viewData();

        Person operator+(Person more_nickname);
        friend Person operator-(Person a_nickname, Person b_nicname);
    private:
        float salary;
        float weight;
        string fullname;
        int age;
};

#endif
