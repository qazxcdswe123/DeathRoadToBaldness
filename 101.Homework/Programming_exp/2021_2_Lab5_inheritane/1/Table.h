#ifndef TABLE_H
#define TABLE_H

class Table
{
private:
    int height;

public:
    Table(int h);
    virtual ~Table() = default;
    int getHeight() const;
};

Table::Table(int h) : height(h)
{
}

int Table::getHeight() const
{
    return height;
}

#endif