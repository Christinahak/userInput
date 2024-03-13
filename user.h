#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDate>
#include <QString>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    ~User();
    void setName(const QString& name);
    void setAge(int age);
    void setBirthDate(QDate date);
    QString getName() const;
    int getAge() const;
    QDate getBirthDate() const;
private:
    QString* name;
    int age;
    QDate* birthDate;

};

#endif // USER_H
