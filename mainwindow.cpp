#include "mainwindow.h"
#include "iostream"
#include <stdio.h>
#include <string>
#include "ui_mainwindow.h"

using namespace std;

double firstNum;
bool userIsTypingSecondNumber= false;
//int s;



string perevod(int dighit){
  //  int i;
    string s;

  // int dighit10[10]={0,1,2,3,4,5,6,7,8,9};
   string dighit25[10]={/*0*/"00011",/*1*/"00101",/*2*/"00110",/*3*/"01001",/*4*/"01010",/*5*/"01100",/*6*/"10001",/*7*/"10010",/*8*/"10100",/*9*/"11000"};
   if (dighit == 0){
        s = dighit25[0];
        return s;
   }
   if (dighit == 1){
        s = dighit25[1];
        return s;
   }
   if (dighit == 2){
        s = dighit25[2];
        return s;
   }
   if (dighit == 3){
        s = dighit25[3];
        return s;
   }
   if (dighit == 4){
       s = dighit25[4];
       return s;
   }
   if (dighit == 5){
       s = dighit25[5];
       return s;
   }
   if (dighit == 6){
       s = dighit25[6];
       return s;
   }
   if (dighit == 7){
       s= dighit25[7];
       return s;
   }
   if (dighit == 8){
       s= dighit25[8];
       return s;
   }
   if (dighit == 9){
      s= dighit25[9];
      return s;
   }



   //return dighit;







    /*
    int i;
    //char s[5];
    bool boolean;

    if (dighit == 0) dighit = 12;
    else
        if(dighit > 6) dighit++;

    dighit *= 2;

    for (i=0; i<5; ++i)
    {
        if (dighit % 2) s[i] = '1';
        else s[i] = '0';

//        dighit /= 2;
    }

    boolean = true;

    for (i=1; i<6; i++)
        if (s[i] == '1') boolean = false;

    if (boolean == false) s[4] = '1';
    cout << s ;
    return dighit;*/
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_pl,SIGNAL(released()),this,SLOT(unary_operation_presed()));
    connect(ui->pushButton_mod,SIGNAL(released()),this,SLOT(unary_operation_presed()));
    connect(ui->pushButton_11,SIGNAL(released()),this,SLOT(unary_operation_presed()));

    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_mult,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_dev,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_dev->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{

    QPushButton * button = (QPushButton*)sender();
    QString newlabel, perevodLabel;
    double labelNumber;
    string str; //массив из переведенных цифр
    if((ui->pushButton_plus->isChecked() || ui->pushButton_dev->isChecked() ||
            ui->pushButton_minus->isChecked() || ui->pushButton_mult->isChecked())  && (!userIsTypingSecondNumber))
    {
        labelNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
         newlabel = QString::number(labelNumber,'g',100005);
         perevodLabel = QString::fromStdString(perevod(stoi(button->text().toUtf8().constData())));

    }
    else {
        if(ui->label->text().contains('.')&&button->text() == "0")
        {
            newlabel = ui->label ->text() + button->text();
            perevodLabel = ui->label_2->text() + QString::fromStdString(perevod(stoi(button->text().toUtf8().constData())));
        }

        else {
            labelNumber = (ui->label ->text() + button->text()).toDouble();
            newlabel = QString::number(labelNumber,'g',1005);
            perevodLabel = ui->label_2->text() + QString::fromStdString(perevod(stoi(button->text().toUtf8().constData())));
        }

    }

    int i2;
    string i1;
    std::string newlabel2 = newlabel.toUtf8().constData();
    i2 = stoi(newlabel2);
    i1 = perevod(i2);
    newlabel2 = i1;
    ui->label->setText(newlabel);
    ui->label_2->setText(perevodLabel);











    //ui->label_2->setText(QString("10001 00011"));


}


void MainWindow::on_pushButton_10_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_presed()
{
  QPushButton * button = (QPushButton*) sender();
  QString newlabel;
  double labelNumber;

  if (button->text() == "+/-")
  {
      labelNumber = ui->label->text().toDouble();
      labelNumber = labelNumber * -1;
      newlabel = QString::number(labelNumber,'g',10005);
      ui->label->setText(newlabel);
  }

  if (button->text() == "%")
  {
      labelNumber = ui->label->text().toDouble();
      labelNumber = labelNumber * 0.01;
      newlabel = QString::number(labelNumber,'g',10005);
      ui->label->setText(newlabel);
  }
  if (button->text() == "C")
  {
      labelNumber = ui->label->text().toDouble();
      labelNumber = labelNumber * 0;
      newlabel = QString::number(labelNumber,'g',10005);
      ui->label->setText(newlabel);
      ui->label_2->setText("0");
  }



}

void MainWindow::on_pushButton_equl_released()
{
    double labelNumber,secondNum;
    QString newLable, perevodLabel;

    secondNum =ui->label->text().toDouble() ;

    if (ui->pushButton_plus->isChecked())
    {
       labelNumber = firstNum + secondNum;
       newLable = QString::number(labelNumber,'g',10005);
       perevodLabel = QString::fromStdString(perevod(stoi(newLable.toUtf8().constData())));
       ui->label->setText(newLable);
       ui->label_2->setText(perevodLabel);
       ui->pushButton_plus->setChecked(false);
    }

    else if (ui->pushButton_dev->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newLable = QString::number(labelNumber,'g',10005);
        perevodLabel = QString::fromStdString(perevod(stoi(newLable.toUtf8().constData())));
        ui->label->setText(newLable);
        ui->label_2->setText(perevodLabel);
        ui->pushButton_dev->setChecked(false);
    }

    else if (ui->pushButton_minus->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newLable = QString::number(labelNumber,'g',10005);
        perevodLabel = QString::fromStdString(perevod(stoi(newLable.toUtf8().constData())));
        ui->label->setText(newLable);
        ui->label_2->setText(perevodLabel);
        ui->pushButton_minus->setChecked(false);
    }

    else if (ui->pushButton_mult->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newLable = QString::number(labelNumber,'g',10005);
        perevodLabel = QString::fromStdString(perevod(stoi(newLable.toUtf8().constData())));
        ui->label->setText(newLable);
        ui->label_2->setText(perevodLabel);
        ui->pushButton_mult->setChecked(false);
    }

    userIsTypingSecondNumber = false;
}

void MainWindow::binary_operation_pressed()
{
                  QPushButton * button = (QPushButton*) sender();
                  firstNum = ui->label->text().toDouble();
                  button->setChecked(true);


}



























