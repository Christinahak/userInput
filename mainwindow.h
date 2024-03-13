#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QDateEdit>
#include <QGridLayout>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel* nameLab;
    QLabel* ageLab;
    QLabel* dateLab;

    QLineEdit* nameEdit;
    QSpinBox* ageSpin;
    QDateEdit* birthDateEdit;

    QPushButton* serializeB;
    QPushButton* deserializeB;

    QSpacerItem* buttonSpacel;
    QSpacerItem* buttonSpacer;

    QWidget* widget;

    QGridLayout* gridLay;
    Ui::MainWindow *ui;

    User* user;

private slots:
    void serialize();
    void deserialize();
};
#endif // MAINWINDOW_H
