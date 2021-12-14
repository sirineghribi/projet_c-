#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "employe.h"
#include "reclamation.h"
#include "qrcode.h"
#include "arduino.h"
#include <QMessageBox>
#include <QValidator>
#include<QWidget>
#include <QTabWidget>

#include <string>
#include <vector>
#include<QDirModel>
#include <qrcode.h>
#include <string>
#include <iostream>
#include <fstream>
#include <QtSvg/QSvgRenderer>
using qrcodegen::QrCode;






#include <QtPrintSupport/QPrinter>

#include <QPixmap>

#include "QMessageBox"

#include <QIntValidator>

#include <QSqlQueryModel>

#include <QPrintDialog>

#include <QtPrintSupport/QPrinter>

#include <QSqlQuery>

#include <QMessageBox>

#include <QSqlError>

#include <iostream>

#include <QDebug>

#include <QRadioButton>

#include <QtPrintSupport/QPrinter>

#include <QPdfWriter>

#include <QPainter>

#include <QFileDialog>

#include <QTextDocument>

#include <QTextEdit>

#include <QtSql/QSqlQueryModel>

#include <QtPrintSupport/QPrinter>

#include <QVector2D>

#include <QVector>

#include <QSqlQuery>

#include<QDesktopServices>

#include<QUrl>

#include <QPixmap>

#include <QTabWidget>

#include <QValidator>



#include<QTextStream>
#include<QFile>
#include<QSqlRecord>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
#include <QPrinter>
#include <QPrintDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <iostream>
#include <QDebug>
#include <QRadioButton>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QDateTime>
#include <QPrinter>
#include "prime.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     ui->setupUi(this);
  //son=new QSound("C:/Users/sirin/Desktop/gestion_employé/son_click");
     ui->l_supp_id->setValidator(new QIntValidator(100, 9999, this));
     ui->lineEditnom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->lineEditprenom->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->lineEditsexe->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->lineEditid->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
     ui->l_date->setValidator(new QRegExpValidator(QRegExp("[0-9 /]{10}")));
     ui->lineEditcin->setValidator(new QRegExpValidator(QRegExp("[0-9 :]{8}")));
     ui->lineEdittel->setValidator(new QRegExpValidator(QRegExp("[0-9 :]{8}")));
     ui->l_sujet->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->l_etat->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+")));
     ui->l_id_rec->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
     ui->ldater->setValidator(new QRegExpValidator(QRegExp("[0-9 /]{10}")));
     ui->l_nbh->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));
     ui->l_pa->setValidator(new QRegExpValidator(QRegExp("[0-9]{8}")));




     ui->TAB_EMPLOYE->setModel(Etmp.afficher());
     ui->tab_recl->setModel(R.afficher_rec());
     ui->tab_prime->setModel(p.afficher_nbh());
/*arduino

     int ret=A.connect_arduino();// lancer la connexion à arduino
                     switch(ret)
                     {
                     case(0):qDebug()<< "arduino is availble and connected to :"<< A.getarduino_port_name();
                         break;
                     case(1):qDebug()<< "arduino is availble but not connected to :"<< A.getarduino_port_name();
                         break;
                     case(-1):qDebug()<< "arduino is not availble";
                     }
                     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));// permet de lancer
                     //le slot update_label suite à la reception du signal readyRead (reception des données).
*/


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajoutersirine_clicked()
{
  int cin=ui->lineEditcin->text().toInt();
  QString nom=ui->lineEditnom->text();
  QString prenom=ui->lineEditprenom->text();
  QString mail=ui->lineEditmail->text();
  QString adresse=ui->lineEditadresse->text();
  QString date_de_naissance=ui->l_date->text();
  int  id=ui->lineEditid->text().toInt();
  QString sexe=ui->lineEditsexe->text();
  int num_de_tel=ui->lineEdittel->text().toInt();

 Employe E (nom,prenom,sexe,date_de_naissance,mail,adresse,id,cin,num_de_tel);

bool test=E.ajouter();

if(test)
{ ui->TAB_EMPLOYE->setModel(Etmp.afficher());

    QMessageBox::information(nullptr, QObject::tr("ok"),
                             QObject::tr("ajout effectué \n"
                             "click Cancel to exit."),QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                         QObject::tr("ajout non effectué.\n"
                               "click Cancel to exit."  ),QMessageBox::Cancel);


}
void MainWindow::on_pb_suppsirine_clicked()
{
    int id=ui->l_supp_id->text().toInt();
    bool test=Etmp.supprimer(id);
    if(test)
    {ui->TAB_EMPLOYE->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression effectué\n"
                                 "click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                             QObject::tr("suppression non effectué.\n"
                                   "click Cancel to exit."  ),QMessageBox::Cancel);

}



void MainWindow::on_pb_modifiersirine_clicked()
{
    int cin=ui->lineEditcin->text().toInt();
    QString nom=ui->lineEditnom->text();
    QString prenom=ui->lineEditprenom->text();
    QString mail=ui->lineEditmail->text();
    QString adresse=ui->lineEditadresse->text();
    QString date_de_naissance=ui->l_date->text();
    int  id=ui->lineEditid->text().toInt();
    QString sexe=ui->lineEditsexe->text();
    int num_de_tel=ui->lineEdittel->text().toInt();

   Employe E (nom,prenom,sexe,date_de_naissance,mail,adresse,id,cin,num_de_tel);
   bool test=E.modifier();

   if(test )
           {
              ui->TAB_EMPLOYE->setModel(Etmp.afficher());
               QMessageBox::information(nullptr, QObject::tr("ok"),
                           QObject::tr("update successful.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           }
           else
               QMessageBox::critical(nullptr, QObject::tr("not ok"),
                           QObject::tr("update failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_TAB_EMPLOYE_clicked(const QModelIndex &index)
{
 QString  id=ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(index.row(),6)).toString();
        ui ->l_supp_id->setText(id);

        ui->lineEditnom->setText(ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(index.row(),1)).toString());
        ui->lineEditcin->setText(ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(index.row(),0)).toString());
        ui->lineEditprenom->setText(ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(index.row(),2)).toString());
        ui->lineEditsexe->setText(ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(index.row(),3)).toString());
        ui->lineEditmail->setText(ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(index.row(),4)).toString());
        ui->lineEditadresse->setText(ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(index.row(),5)).toString());
        ui->lineEditid->setText(ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(index.row(),6)).toString());
        ui->l_date->setText(ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(index.row(),7)).toString());
        ui->lineEdittel->setText(ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(index.row(),8)).toString());

}

void MainWindow::on_pb_recherchersirine_clicked()
{
    int id=ui->l_rechercher->text().toInt();
    ui->TAB_EMPLOYE->setModel(Etmp.rechercher(id));



}
void MainWindow::on_pb_croisirine_clicked()
{
    ui->TAB_EMPLOYE->setModel(Etmp.trier_croi());
}

void MainWindow::on_pb_decrsirine_clicked()
{
    ui->TAB_EMPLOYE->setModel(Etmp.trier_decr());
}



//reclamation//
void MainWindow::on_pb_ajout_recsirine_clicked()
{
    int  id_r=ui->l_id_rec->text().toInt();
    QString date_r=ui->l_date->text();
    QString sujet=ui->l_sujet->text();
    QString etat=ui->l_etat->text();

   reclamation R (id_r,date_r,sujet,etat);

  bool test=R.ajouter_rec();
  if(test)
  { ui->tab_recl->setModel(R.afficher_rec());


      QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("ajout effectué \n"
                               "click Cancel to exit."),QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("not ok"),
                           QObject::tr("ajout non effectué.\n"
                                 "click Cancel to exit."  ),QMessageBox::Cancel);
}

void MainWindow::on_pb_modi_recsirine_clicked()
{
    int  id_r=ui->l_id_rec->text().toInt();
    QString date_r=ui->l_date->text();
    QString sujet=ui->l_sujet->text();
    QString etat=ui->l_etat->text();

   reclamation R (id_r,date_r,sujet,etat);

  bool test=R.modifier_rec();
  if(test)
  {ui->tab_recl->setModel(R.afficher_rec());

      QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("modification effectué \n"
                               "click Cancel to exit."),QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("not ok"),
                           QObject::tr("modification non effectué.\n"
                                 "click Cancel to exit."  ),QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimersirine_rec_clicked()
{
    int id_r=ui->l_supp_rec->text().toInt();
    bool test=R.supprimer_rec(id_r);
    if(test)
    {
        ui->tab_recl->setModel(R.afficher_rec());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression effectué\n"
                                 "click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                             QObject::tr("suppression non effectué.\n"
                                   "click Cancel to exit."  ),QMessageBox::Cancel);
}

void MainWindow::on_tab_reclsirine_clicked(const QModelIndex &index)
{
    QString  id_r=ui->tab_recl->model()->data(ui->tab_recl->model()->index(index.row(),1)).toString();
           ui ->l_supp_rec->setText(id_r);
}

void MainWindow::on_pushButton_2sirine_clicked()
{
    QString strStream;
       QTextStream out(&strStream);



                   const int rowCount = ui->TAB_EMPLOYE->model()->rowCount();
                   const int columnCount = ui->TAB_EMPLOYE->model()->columnCount();

                   out <<  "<html>\n"
                       "<head>\n"

                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                       <<  QString("<title>%60 les postes</title>\n").arg("poste")
                       <<  "</head>\n"
                       "<body bgcolor=#ffffff link=#5000A0>\n"
                       "<table border=1 cellspacing=0 cellpadding=2>\n";
                   out << "<thead><tr bgcolor=#f0f0f0>";
                   for (int column = 0; column < columnCount; column++)
                       if (! ui->TAB_EMPLOYE->isColumnHidden(column))
                           out << QString("<th>%1</th>").arg(ui->TAB_EMPLOYE->model()->headerData(column, Qt::Horizontal).toString());
                   out << "</tr></thead>\n";

                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->TAB_EMPLOYE->isColumnHidden(column)) {
                               QString data = ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(row, column)).toString().simplified();
                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                           }
                       }
                       out << "</tr>\n";
                   }
                   out <<  "</table>\n"
                       "</body>\n"
                       "</html>\n";

                   QTextDocument *document = new QTextDocument();
                   document->setHtml(strStream);

                   QPrinter printer;

                   QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                   if (dialog->exec() == QDialog::Accepted) {
                       document->print(&printer);
                   }

                   delete document;
}

void MainWindow::on_pb_reinsirine_clicked()
{
    ui->lineEditid->setText("");
           ui->lineEditcin->setText("");
          ui->lineEditnom->setText("");
           ui->lineEdittel->setText("");
           ui->lineEditmail->setText("");
           ui->lineEditsexe->setText("");
           ui->lineEditprenom->setText("");
           ui->lineEditadresse->setText("");
           ui->l_date->setText("");
}

void MainWindow::on_pb_rein_recsirine_clicked()
{
    ui->l_id_rec->setText("");
           ui->ldater->setText("");
          ui->l_etat->setText("");
           ui->l_sujet->setText("");
}
//prime
void MainWindow::on_pb_affectersirine_clicked()
{
    int  nbh_supp =ui->l_nbh->text().toInt();
int primes=ui->l_pa->text().toInt();
    prime p(nbh_supp,primes);
   bool test=p.ajouter_nbh_supp();
  if(test)
  {

ui->tab_prime->setModel(p.afficher_nbh());
      QMessageBox::information(nullptr, QObject::tr("ok"),
                               QObject::tr("ajout effectué \n"
                               "click Cancel to exit."),QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("not ok"),
                           QObject::tr("ajout non effectué.\n"
                                 "click Cancel to exit."  ),QMessageBox::Cancel);

}

void MainWindow::on_pb_rein_psirine_clicked()
{
    ui->l_pa->setText("");
    ui->l_nbh->setText("");
}




void MainWindow::on_pb_calculsirine_clicked()
{

    prime p;
        ui->tab_somme->setModel(p.calcul_prime());


}

void MainWindow::on_pbnbh_suppsirine_clicked()
{
    ui->tab_somme->setModel(p.calcul_nbh());
}



void MainWindow::on_pb_excelsirine_clicked()
{

    QTableView *table;
            table = ui->TAB_EMPLOYE;
            QString filters("CSV files (.csv);;All files (.*)");
            QString defaultFilter("CSV files (*.csv)");
            QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                               filters, &defaultFilter);
            QFile file(fileName);
            QAbstractItemModel *model =  table->model();
            if (file.open(QFile::WriteOnly | QFile::Truncate))
            {
                QTextStream data(&file);
                QStringList strList;
                for (int i = 0; i < model->columnCount(); i++)
                {
                    if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                        strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                    else
                        strList.append("");
                }
                data << strList.join(";") << "\n";
                for (int i = 0; i < model->rowCount(); i++)
                {
                    strList.clear();
                    for (int j = 0; j < model->columnCount(); j++)
                    {
                        if (model->data(model->index(i, j)).toString().length() > 0)
                            strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                        else
                            strList.append("");
                    }
                    data << strList.join(";") + "\n";
                }
                file.close();
}
}



void MainWindow::on_pb_codesirine_clicked()
{
    if(ui->TAB_EMPLOYE->currentIndex().row()==-1)
                  QMessageBox::information(nullptr, QObject::tr("QrCode"),
                                           QObject::tr("Veuillez Choisir un employe du Tableau.\n"
                                                       "Click Ok to exit."), QMessageBox::Ok);
              else
              {
                   int ID_E=ui->TAB_EMPLOYE->model()->data(ui->TAB_EMPLOYE->model()->index(ui->TAB_EMPLOYE->currentIndex().row(),0)).toInt();
                   const QrCode qr = QrCode::encodeText(std::to_string(ID_E).c_str(), QrCode::Ecc::LOW);
                   std::ofstream myfile;
                   myfile.open ("qrcode.svg") ;
                   myfile << qr.toSvgString(1);
                   myfile.close();
                   QSvgRenderer svgRenderer(QString("qrcode.svg"));
                   QPixmap pix( QSize(120, 120) );
                   QPainter pixPainter( &pix );
                   svgRenderer.render( &pixPainter );
                   ui->label_code->setPixmap(pix);
              }
}
//QMediaPlayer * sound = new QMediaPlayer();
//sound->setmedia(QUrl("qrc:/images/son_click.mp3"));
//sound->play();

void MainWindow::on_radioButton_joursirine_toggled(bool )
{
    this->setStyleSheet("font: 8pt \"Pacifico\";");


            QList<QPushButton *> butts = this->findChildren<QPushButton *>();

            for (int i=0; i<butts.size();i++)
            {
                butts.at(i)->setStyleSheet("QPushButton { background-color: grey; }");
            }
            QList<QTabWidget *> tabs = this->findChildren<QTabWidget *>();

            for (int i=0; i<tabs.size();i++)
            {
                tabs.at(i)->setStyleSheet("QTabBar::tab { background-color: grey;}");
            }
}

void MainWindow::on_radioButton_nuitsirine_toggled(bool )
{
    this->setStyleSheet("font: 8pt \"Pacifico\";"
                                "background-color: rgb(43, 40, 38);"
                                "color: rgb(255, 255, 255);");



            QList<QPushButton *> butts = this->findChildren<QPushButton *>();

            for (int i=0; i<butts.size();i++)
            {
                butts.at(i)->setStyleSheet("QPushButton { background-color: #444444; }");
            }


            QList<QTabWidget *> tabs = this->findChildren<QTabWidget *>();

            for (int i=0; i<tabs.size();i++)
            {
                tabs.at(i)->setStyleSheet("QTabBar::tab { background-color: rgb(68, 68, 68);}");
            }
}
