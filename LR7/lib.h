#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURITYCRITICAL_ATTRIBUTE
#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <string.h>
#include <vector>

using namespace std;

class Entrance_exams {
protected:
    void basetoFile(size_t t, const char* file_path);
    void basefromFile(size_t t, const char* file_path);
public:
    Entrance_exams();
    ~Entrance_exams();

    virtual void toFile() = 0;
    virtual void toFile(const char* file_path) = 0;
    virtual void fromFile() = 0;
    virtual void fromFile(const char* file_path) = 0;
    //task 4
    template <typename T> static void swapValues(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
};

class Mark : public Entrance_exams {
private:
    int value;
    int subjectID;
    int day;
    int month;
    int year;
public:
    bool evaluated;
    bool passed;
    char teacher[30];

    Mark();
    Mark(int _subjectID, int _day, int _month, int _year);
    Mark(const Mark& _mark);
    ~Mark();

    // сетери
    void setvalue(int _value);

    void setsubjectID(int _subjectID);

    void setday(int _day);

    void setmonth(int _month);

    void setyear(int _year);

    // гетери
    int getvalue();

    int getsubjectID();

    int getday();

    int getmonth();

    int getyear();

    void Copy(Mark a);

    friend class Budy;

    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;

    //task 1
    // Постфіксний оператор "++"
    Mark operator++(int) {
        Mark temp(*this);
        value++;
        return temp;
    };

    // Постфіксний оператор "--"
    Mark operator--(int) {
        Mark temp(*this);
        value--;
        return temp;
    };

    // Префіксний оператор "++"
    Mark& operator++() {
        value++;
        return *this;
    };

    // Префіксний оператор "--"
    Mark& operator--() {
        value--;
        return *this;
    };

    //task 2
        // Перевантаження бінарного оператора "+"
    Mark operator+(const Mark& other) const {
        Mark result;
        result.value = this->value + other.value;
        return result;
    }

    // Перевантаження бінарного оператора "-"
    Mark operator-(const Mark& other) const {
        Mark result;
        result.value = this->value - other.value;
        return result;
    }

    //task 3
    // Перевантаження оператора присвоєння "="
    Mark& operator=(const Mark& other) {
        if (this != &other) {
            this->Copy(other);
        }
        return *this;
    }

    // Перевантаження бінарного оператора "+="
    Mark& operator+=(const Mark& other) {
        this->value = this->value + other.value;
        return *this;
    }

    // Перевантаження бінарного оператора "-="
    Mark& operator-=(const Mark& other) {
        this->value = this->value - other.value;
        return *this;
    }

    // Перевантаження бінарного оператора "*="
    Mark& operator*=(int scalar) {
        this->value = this->value * scalar;
        return *this;
    }

    // Перевантаження бінарного оператора "*"
    friend Mark operator*(const Mark& v, int scalar) {
        Mark result(v);
        result *= scalar;
        return result;
    }
};

class Exam : public Entrance_exams {
private:
    Mark mathematics;
    Mark physics;
    Mark chemistry;
    Mark history;
    Mark literature;
public:
    Mark geography;
    Mark computerScience;
    int total_value;

    Exam();
    Exam(int _day, int _month, int _year);
    Exam(const Exam& _exam);
    ~Exam();

    // Сетери
    void setMathematics(Mark grade);

    void setPhysics(Mark grade);

    void setChemistry(Mark grade);

    void setHistory(Mark grade);

    void setLiterature(Mark grade);

    // Гетери
    Mark getMathematics();

    Mark getPhysics();

    Mark getChemistry();

    Mark getHistory();

    Mark getLiterature();

    void calculate_total_value();

    void Copy(Exam a);

    friend void displayData(const Exam& obj);
    friend void displayData(const Exam* obj);

    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;

    //task 1
// Постфіксний оператор "++"
    Exam operator++(int) {
        Exam temp(*this);
        mathematics++;
        physics++;
        chemistry++;
        history++;
        literature++;
        geography++;
        computerScience++;
        calculate_total_value();
        return temp;
    };

    // Постфіксний оператор "--"
    Exam operator--(int) {
        Exam temp(*this);
        mathematics--;
        physics--;
        chemistry--;
        history--;
        literature--;
        geography--;
        computerScience--;
        calculate_total_value();
        return temp;
    };

    // Префіксний оператор "++"
    Exam& operator++() {
        mathematics++;
        physics++;
        chemistry++;
        history++;
        literature++;
        geography++;
        computerScience++;
        calculate_total_value();
        return *this;
    };

    // Префіксний оператор "--"
    Exam& operator--() {
        mathematics--;
        physics--;
        chemistry--;
        history--;
        literature--;
        geography--;
        computerScience--;
        calculate_total_value();
        return *this;
    };

    //task 2
    // Перевантаження бінарного оператора "+"
    Exam operator+(const Exam& other) const {
        Exam result;
        result.mathematics = this->mathematics + other.mathematics;
        result.physics = this->physics + other.physics;
        result.chemistry = this->chemistry + other.chemistry;
        result.history = this->history + other.history;
        result.literature = this->literature + other.literature;
        result.geography = this->geography + other.geography;
        result.computerScience = this->computerScience + other.computerScience;
        result.calculate_total_value();
        return result;
    }

    // Перевантаження бінарного оператора "-"
    Exam operator-(const Exam& other) const {
        Exam result;
        result.mathematics = this->mathematics - other.mathematics;
        result.physics = this->physics - other.physics;
        result.chemistry = this->chemistry - other.chemistry;
        result.history = this->history - other.history;
        result.literature = this->literature - other.literature;
        result.geography = this->geography - other.geography;
        result.computerScience = this->computerScience - other.computerScience;
        result.calculate_total_value();
        return result;
    }

    //task 3
// Перевантаження оператора присвоєння "="
    Exam& operator=(const Exam& other) {
        if (this != &other) {
            this->Copy(other);
        }
        return *this;
    }

    // Перевантаження бінарного оператора "+="
    Exam& operator+=(const Exam& other) {
        this->mathematics = this->mathematics + other.mathematics;
        this->physics = this->physics + other.physics;
        this->chemistry = this->chemistry + other.chemistry;
        this->history = this->history + other.history;
        this->literature = this->literature + other.literature;
        this->geography = this->geography + other.geography;
        this->computerScience = this->computerScience + other.computerScience;
        this->calculate_total_value();
        return *this;
    }

    // Перевантаження бінарного оператора "-="
    Exam& operator-=(const Exam& other) {
        this->mathematics = this->mathematics - other.mathematics;
        this->physics = this->physics - other.physics;
        this->chemistry = this->chemistry - other.chemistry;
        this->history = this->history - other.history;
        this->literature = this->literature - other.literature;
        this->geography = this->geography - other.geography;
        this->computerScience = this->computerScience - other.computerScience;
        this->calculate_total_value();
        return *this;
    }

    // Перевантаження бінарного оператора "*="
    Exam& operator*=(int scalar) {
        this->mathematics *= scalar;
        this->physics *= scalar;
        this->chemistry *= scalar;
        this->history *= scalar;
        this->literature *= scalar;
        this->geography *= scalar;
        this->computerScience *= scalar;
        this->calculate_total_value();
        return *this;
    }

    // Перевантаження бінарного оператора "*"
    friend Exam operator*(const Exam& v, int scalar) {
        Exam result(v);
        result *= scalar;
        return result;
    }
};

class Person :public Entrance_exams {
protected:
    char first_name[30];
    char last_name[30];
    char father_name[30];
    bool gender;

    void changeGender();
    void clearEmail();
    void clearPhone_number();
public:
    char email[50];
    char phone_number[13];

    Person();
    Person(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number);
    Person(Person& _person);

    virtual ~Person();

    // сетери
    void setFirstName(const char* _first_name);

    void setLastName(const char* _last_name);

    void setFatherName(const char* _father_name);

    void setGender(bool _gender);

    // гетери 
    char* getFirstName();

    char* getLastName();

    char* getFatherName();

    bool getGender();

    virtual void task4() const = 0;

    virtual void Copy(Person& a) = 0;


};

class Applicant :public Person {
public:
    Exam exam_score;

    Applicant();
    Applicant(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number);
    Applicant(const Applicant& _applicant);
    ~Applicant() override;

    void Copy(Person& a) override;

    void task4() const override { cout << "Applicant task 4" << endl; };

    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;

    //task 1
    // Постфіксний оператор "++"
    Applicant operator++(int) {
        Applicant temp(*this);
        exam_score++;
        return temp;
    };

    // Постфіксний оператор "--"
    Applicant operator--(int) {
        Applicant temp(*this);
        exam_score--;
        return temp;
    };

    // Префіксний оператор "++"
    Applicant& operator++() {
        exam_score++;
        return *this;
    };

    // Префіксний оператор "--"
    Applicant& operator--() {
        exam_score--;
        return *this;
    };

    //task 2
    // Перевантаження бінарного оператора "+"
    Applicant operator+(const Applicant& other) const {
        Applicant result;
        result.exam_score = this->exam_score + other.exam_score;
        return result;
    }

    // Перевантаження бінарного оператора "-"
    Applicant operator-(const Applicant& other) const {
        Applicant result;
        result.exam_score = this->exam_score - other.exam_score;
        return result;
    }

    //task 3
    // Перевантаження оператора присвоєння "="
    Applicant& operator=(const Applicant& other) {
        if (this != &other) {
            strncpy(first_name, other.first_name, sizeof(first_name) - 1);
            strncpy(last_name, other.last_name, sizeof(last_name) - 1);
            strncpy(father_name, other.father_name, sizeof(father_name) - 1);
            gender = other.gender;
            strncpy(email, other.email, sizeof(email) - 1);
            strncpy(phone_number, other.phone_number, sizeof(phone_number) - 1);
        }
        return *this;
    }

    // Перевантаження бінарного оператора "+="
    Applicant& operator+=(const Applicant& other) {
        this->exam_score = this->exam_score + other.exam_score;
        return *this;
    }

    // Перевантаження бінарного оператора "-="
    Applicant& operator-=(const Applicant& other) {
        this->exam_score = this->exam_score - other.exam_score;
        return *this;
    }

    // Перевантаження бінарного оператора "*="
    Applicant& operator*=(int scalar) {
        this->exam_score = this->exam_score * scalar;
        return *this;
    }

    // Перевантаження бінарного оператора "*"
    friend Applicant operator*(const Applicant& v, int scalar) {
        Applicant result(v);
        result *= scalar;
        return result;
    }
};

class Teacher : public Person {
public:
    int subjectID;

    Teacher();
    Teacher(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number, int _subjectID);
    Teacher(const Teacher& _teacher);
    ~Teacher() override;

    void evaluation(Mark _mark, int valule);

    void evaluation(Exam _exam, int valule);

    void evaluation(Applicant _applicant, int valule);

    void Copy(Person& a) override;

    void task4() const override { cout << "Teacher task 4" << endl; };
    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;

    //task 1
    // Постфіксний оператор "++"
    Teacher operator++(int) {
        Teacher temp(*this);
        subjectID++;
        return temp;
    };

    // Постфіксний оператор "--"
    Teacher operator--(int) {
        Teacher temp(*this);
        subjectID--;
        return temp;
    };

    // Префіксний оператор "++"
    Teacher& operator++() {
        subjectID++;
        return *this;
    };

    // Префіксний оператор "--"
    Teacher& operator--() {
        subjectID--;
        return *this;
    };

    //task 2
    // Перевантаження бінарного оператора "+"
    Teacher operator+(const Teacher& other) const {
        Teacher result;
        result.subjectID = this->subjectID + other.subjectID;
        return result;
    }

    // Перевантаження бінарного оператора "-"
    Teacher operator-(const Teacher& other) const {
        Teacher result;
        result.subjectID = this->subjectID - other.subjectID;
        return result;
    }

    //task 3
    // Перевантаження оператора присвоєння "="
    Teacher& operator=(const Teacher& other) {
        if (this != &other) {
            strncpy(first_name, other.first_name, sizeof(first_name) - 1);
            strncpy(last_name, other.last_name, sizeof(last_name) - 1);
            strncpy(father_name, other.father_name, sizeof(father_name) - 1);
            gender = other.gender;
            strncpy(email, other.email, sizeof(email) - 1);
            strncpy(phone_number, other.phone_number, sizeof(phone_number) - 1);
        }
        return *this;
    }

    // Перевантаження бінарного оператора "+="
    Teacher& operator+=(const Teacher& other) {
        this->subjectID = this->subjectID + other.subjectID;
        return *this;
    }

    // Перевантаження бінарного оператора "-="
    Teacher& operator-=(const Teacher& other) {
        this->subjectID = this->subjectID - other.subjectID;
        return *this;
    }

    // Перевантаження бінарного оператора "*="
    Teacher& operator*=(int scalar) {
        this->subjectID = this->subjectID * scalar;
        return *this;
    }

    // Перевантаження бінарного оператора "*"
    friend Teacher operator*(const Teacher& v, int scalar) {
        Teacher result(v);
        result *= scalar;
        return result;
    }
};

class Rector : public Person {
public:
    Rector();
    Rector(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number);
    Rector(Rector& _rector);
    ~Rector() override;

    void Copy(Person& a) override;
    void exercisesPolicyMaking();



    void task4() const override { cout << "Rector task 4" << endl; };
    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;
};

class Guardian :public Person {
public:
    Guardian();
    Guardian(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number);
    Guardian(Guardian& _rector);
    ~Guardian() override;

    void Copy(Person& a) override;
    void guard();



    void task4() const override { cout << "Guardian task 4" << endl; };
    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;
};

class Cleaner :public Person {
public:
    Cleaner();
    Cleaner(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number);
    Cleaner(Cleaner& _rector);
    ~Cleaner() override;

    void Copy(Person& a) override;
    void clean();

    void task4() const override { cout << "Cleaner task 4" << endl; };
    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;
};

class Lector : private Teacher {
public:
    Lector();
    Lector(const char* _first_name, const char* _last_name, const char* _father_name, bool _gender, const char* _email, const char* _phone_number, int _subjectID);
    Lector(Teacher& _teacher);
    ~Lector();

    //seter
    void setFirstName(const char* _first_name);

    void setLastName(const char* _last_name);

    void setFatherName(const char* _father_name);

    void setGender(bool _gender);

    // гетери 
    char* getFirstName();

    char* getLastName();

    char* getFatherName();

    bool getGender();

    int getSubjectID();

    void setSubjectID(int value);

    void Copy(Teacher a);
};


class A : virtual public Applicant {
public:
    A();
    ~A();
};

class B : virtual public Teacher {
public:
    B();
    ~B();
};

class C : virtual public Lector {
public:
    C();
    ~C();
};

class ABC : public A, public B, public C {
public:
    ABC();
    ~ABC();
};
//task 6
class Faculty : public Entrance_exams {
private:
    char name[50];
    char code[5];
    int foundation_year;
    vector<Applicant*> applicants;
    vector<Teacher*> teachers;
public:
    char dean_first_name[30];
    char dean_last_name[30];
    char dean_father_name[30];

    Faculty();
    Faculty(const char* _name, const char* _code, const char* _dean_first_name, const char* _dean_last_name, const char* _dean_father_name, int _foundation_year);
    Faculty(const Faculty& _faculty);
    ~Faculty();

    // сетери
    void setName(const char* _name);

    void setCode(const char* _code);

    void setFoundationYear(int _foundation_year);

    void setApplicants(const vector<Applicant*> newVector);

    void setTeachers(const vector<Teacher*> newVector);

    // гетери 
    char* getName();

    char* getCode();

    int getFoundationYear();

    vector<Applicant*> getApplicants();

    vector<Teacher*> getTeachers();

    void registration(Applicant* _faculty);

    void Copy(Faculty a);

    Faculty getdefaultFaculty();

    void toFile() override;
    void toFile(const char* file_path)override;
    void fromFile()override;
    void fromFile(const char* file_path)override;


    //task 1
    // Постфіксний оператор "++"
    Faculty operator++(int) {
        Faculty temp(*this);
        foundation_year++;
        return temp;
    };

    // Постфіксний оператор "--"
    Faculty operator--(int) {
        Faculty temp(*this);
        foundation_year--;
        return temp;
    };

    // Префіксний оператор "++"
    Faculty& operator++() {
        foundation_year++;
        return *this;
    };

    // Префіксний оператор "--"
    Faculty& operator--() {
        foundation_year--;
        return *this;
    };

    //task 2
    // Перевантаження бінарного оператора "+"
    Faculty operator+(const Faculty& other) const {
        Faculty result;
        result.foundation_year = this->foundation_year + other.foundation_year;
        return result;
    }

    // Перевантаження бінарного оператора "-"
    Faculty operator-(const Faculty& other) const {
        Faculty result;
        result.foundation_year = this->foundation_year - other.foundation_year;
        return result;
    }

    //task 3
    // Перевантаження оператора присвоєння "="
    Faculty& operator=(const Faculty& other) {
        if (this != &other) {
            strncpy(name, other.name, sizeof(name) - 1);
            strncpy(code, other.code, sizeof(code) - 1);
            strncpy(dean_first_name, other.dean_first_name, sizeof(dean_first_name) - 1);
            strncpy(dean_last_name, other.dean_last_name, sizeof(dean_last_name) - 1);
            strncpy(dean_father_name, other.dean_father_name, sizeof(dean_father_name) - 1);
            foundation_year = other.foundation_year;
            applicants = other.applicants;
            teachers = other.teachers;
        }
        return *this;
    }

    // Перевантаження бінарного оператора "+="
    Faculty& operator+=(const Faculty& other) {
        this->foundation_year = this->foundation_year + other.foundation_year;
        return *this;
    }

    // Перевантаження бінарного оператора "-="
    Faculty& operator-=(const Faculty& other) {
        this->foundation_year = this->foundation_year - other.foundation_year;
        return *this;
    }

    // Перевантаження бінарного оператора "*="
    Faculty& operator*=(int scalar) {
        this->foundation_year = this->foundation_year * scalar;
        return *this;
    }

    // Перевантаження бінарного оператора "*"
    friend Faculty operator*(const Faculty& v, int scalar) {
        Faculty result(v);
        result *= scalar;
        return result;
    }

    // Перевантаження оператора "[]"
    Applicant& operator[](int index) {
        if (index >= 0 && index < applicants.size());
        return *applicants[index];
        return *applicants[0];
    }
};

void displayData(const Exam& obj);
void displayData(const Exam* obj);

class Budy {
public:
    static int howmany;
    static void displayData(const Mark& obj);
};

//task 5
template <typename T>
class Pair {
public:
    T data1;
    T data2;

    // Конструктор класу
    Pair(T d1, T d2) : data1(d1), data2(d2) {}

    // Метод для обчислення суми значень даних
    T calculateSum() {
        return data1 + data2;
    }

    // Метод для обміну значень двох даних
    void swapData() {
        T temp = data1;
        data1 = data2;
        data2 = temp;
    }

    // Метод для збільшення першого значення на друге
    void increaseValue() {
        data1 += data2;
    }
};
