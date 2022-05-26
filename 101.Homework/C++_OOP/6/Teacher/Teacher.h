/*
2、某学校对教师每月工资的计算规定如下:固定工资+课时补贴。教授的固定工资为5000元，每个课时补贴50元。
副教授的固定工资为3000元，每个课时补贴30元。讲师的固定工资为2000元，每个课时补贴20元。
定义教师抽象类，派生不同职称的教师类，编写程序求若干个教师的月工资。
*/

class Teacher
{
private:
    int classPerMonth;
    int salary;

public:
    Teacher(int classPerMonth, int salary);
    virtual void setSalary();
    virtual int getSalary() const;
    virtual int getTotalSalary() const = 0;
    virtual ~Teacher() = default;
};

class Professor : public Teacher
{
private:
    static int baseSalary;
    static int salaryPerClass;

public:
    Professor(int classPerMonth, int salary);
    int getTotalSalary() const override final;
    ~Professor() = default;
};

class AssociateProfessor : public Teacher
{
private:
    static int baseSalary;
    static int salaryPerClass;

public:
    AssociateProfessor(int classPerMonth, int salary);
    int getTotalSalary() const override final;
    ~AssociateProfessor() = default;
};

class Lecturer : public Teacher
{
private:
    static int baseSalary;
    static int salaryPerClass;

public:
    Lecturer(int classPerMonth, int salary);
    int getTotalSalary() const override final;
    ~Lecturer() = default;
};