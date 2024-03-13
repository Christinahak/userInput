#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(400,500);
    nameLab = new QLabel("name");
    ageLab = new QLabel("age");
    dateLab = new QLabel("date");

    nameEdit = new QLineEdit();
    ageSpin = new QSpinBox();
    birthDateEdit = new QDateEdit();

    gridLay = new QGridLayout();

    QSpacerItem *verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    serializeB = new QPushButton("serialize");
    deserializeB = new QPushButton("deserialize");
    user = new User();
    connect(serializeB,SIGNAL(clicked()),this,SLOT(serialize()));
    connect(deserializeB,SIGNAL(clicked()),this,SLOT(deserialize()));
    gridLay->addWidget(nameLab, 0, 0);
    gridLay->addWidget(nameEdit, 1, 0);
    gridLay->addWidget(serializeB,1,1);
    gridLay->addWidget(deserializeB, 3, 1);
    gridLay->addWidget(ageLab, 2, 0);
    gridLay->addWidget(ageSpin, 3, 0);
    gridLay->addWidget(dateLab, 4, 0);
    gridLay->addWidget(birthDateEdit, 5, 0);
    gridLay->addItem(verticalSpacer, 6, 0);

    widget = new QWidget();
    widget->setLayout(gridLay);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::serialize() {
    user->setName(nameEdit->text());
    user->setAge(ageSpin->value());
    user->setBirthDate(birthDateEdit->date());

    QFile file(":/userInput.txt");
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Error: Unable to open file" << file.errorString();
        return;
    }

    QTextStream stream(&file);

    stream << user->getName() << '\n';
    stream << user->getAge() << '\n';
    stream << user->getBirthDate().toString();

    file.close();
}

void MainWindow::deserialize() {

    QFile file(":/userInput.txt");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Error: Unable to open file" << file.errorString();
        return;
    }

    QTextStream in(&file);

    QString name = in.readLine();
    int age = in.readLine().toInt();
    QDate birthDate = QDate::fromString(in.readLine());

    user->setName(name);
    user->setAge(age);
    user->setBirthDate(birthDate);

    file.close();

    nameEdit->setText(name);
    ageSpin->setValue(age);
    birthDateEdit->setDate(birthDate);
}



