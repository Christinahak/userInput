#include "user.h"

User::User(QObject *parent)
    : QObject{parent}
{
    birthDate = new QDate();
    name = new QString();
}

User::~User() {
    delete name;
    delete birthDate;
}

void User::setName(const QString& name) {
    *this->name =  name;
}

void User::setAge(int age) {
    this->age = age;
}

void User::setBirthDate(QDate date) {
    *birthDate = date;
}

QString User::getName() const {
    return *name;
}

int User::getAge() const {
    return age;
}

QDate User::getBirthDate() const {
    return *birthDate;
}
