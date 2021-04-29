#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<regex>
#include<iostream>
#include<string>
#include<QRegularExpression>
#include<QMessageBox>
#include<QButtonGroup>
#include<QRadioButton>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->backlogs->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QRegularExpression re("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    QRegularExpressionMatch match = re.match(ui->email->text());
    if(ui->first->text()=="" && ui->lastname->text()=="" && ui->email->text()=="" && ui->pnumber->text()=="" && ui->cgpa->text()=="" && ui->year->text()=="")
    {
        QMessageBox::warning(this,"Not Filled","Fill All Details");
        return;
    }
    if(!match.hasMatch())
    {

       QMessageBox::warning(this,"Email Is Not Valid","Please Enter The Correct Email Address");
       return;
    }
    if(ui->buttonGroup->checkedId()==-1)
    {
        QMessageBox::warning(this,"..","Please Fill Your Gender");
        return;
    }
    QMessageBox::information(this,"Succees","Registration Successfull");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->baclog->setValue(0);
    ui->cgpa->setText("");
    ui->email->setText("");
    ui->first->setText("");
    ui->lastname->setText("");
    ui->pnumber->setText("");
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    QMessageBox::information(this,"Clear","Form Cleared to new edit");
}
