/*
1、定义一个基本的银行账户类。在基本账户类的基础上派生出1年期定期账户、2年期定期账户、3年期定期账户和5年期定期账户。
定义一个n个基类指针组成的数组，随机生成n个各类派生类的对象。让每个指针指向一个派生类的对象。
这些对象可以是1年期定期账户、2年期定期账户、3年期定期账户，也可以是5年期定期账户。输出每个账户到期的利息。
*/
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount
{
private:
    double balance;

public:
    BankAccount() = default;
    explicit BankAccount(double b);
    virtual double getTotalInterest() const = 0;
    double getBalance() const;
    void setBalance(double b);
    virtual ~BankAccount() = default;
};

class OneYearAccount : public BankAccount
{
private:
    static double interest;

public:
    explicit OneYearAccount(double b);
    ~OneYearAccount() = default;
    double getTotalInterest() const override final;
};

class TwoYearAccount : public BankAccount
{
private:
    static double interest;

public:
    explicit TwoYearAccount(double b);
    ~TwoYearAccount() = default;
    double getTotalInterest() const override final;
};

class ThreeYearAccount : public BankAccount
{
private:
    static double interest;

public:
    explicit ThreeYearAccount(double b);
    ~ThreeYearAccount() = default;
    double getTotalInterest() const override final;
};

class FiveYearAccount : public BankAccount
{
private:
    static double interest;

public:
    explicit FiveYearAccount(double b);
    ~FiveYearAccount() = default;
    double getTotalInterest() const override final;
};

#endif // BANKACCOUNT_H