#include "gestion.h"
#include "ui_form.h"
#include <QApplication>
#include "ui_naissances.h"
#include "QMessageBox"
#include "QDialog"
#include "home.h"
#include "naissances.h"
gestion::gestion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::gestion)
{
    ui->setupUi(this);
}

gestion::~gestion()
{
    delete ui;
}


void gestion::on_pushButton_clicked()
{
    username=ui->name->text();
    userpostname=ui->postname->text();
    eventdate=ui->dateevent->text();
    typeevent=ui->typeevent->currentText();
    QMessageBox::information(this,"RESULTAT", "Enregistrement effectué avec succès pour cet événement");


    ui->fullcomplete->append("NOM COMPLET: "+username+" "+userpostname);
    ui->fullcomplete->append(" TYPE DE L'EVENEMENT: "+typeevent);
    ui->fullcomplete->append(" DATE DE L'EVENEMENT: "+eventdate);
    ui->fullcomplete->setEnabled(false);

    if(typeevent=="MARIAGE"){
        EcrireDansFichier("mariages/"+username+" "+userpostname+".txt","CERTIFICAT DE MARIAGE \n Nom: "+username +"\n Postnom: "+userpostname+"\n"+" Date de l'evenement: "+eventdate+"\n ");
    }
    else if(typeevent=="DECES"){
        EcrireDansFichier("deces/"+username+" "+userpostname+".txt","CERTIFICAT DE DECES \n Nom: "+username +"\n Postnom: "+userpostname+"\n"+" Date de l'evenement: "+eventdate+"\n ");

    }else{
        EcrireDansFichier("naissances/"+username+" "+userpostname+".txt","CERTIFICAT DE NAISSANCE \n Nom: "+username +"\n Postnom: "+userpostname+"\n"+" Date de l'evenement: "+eventdate+"\n ");

    }
    clear_all();
    //redirection vers une page quelconque
    naissances* myhome= new naissances;
    myhome->show();
    close();
}
//Methode qui lit le contenu d'un fichier
void gestion::LireFichier(QString nomFichier){
    QFile FichierTexte(nomFichier);
    QString contenuFichier;
    QTextStream notreStream(&FichierTexte); //Créer un Stream et le relier à notre fichier
    if(FichierTexte.open(QIODevice::ReadOnly)==true){ //Test si le fichier vient d'être ouvert
        contenuFichier=notreStream.readAll();
        ui->fullcomplete->setText(contenuFichier);
    }
    FichierTexte.close();
}

void gestion::EcrireDansFichier(QString nomFichier, QString contenuTexte){
    QFile fichierExerc(nomFichier); //Creons un object de type fichier que nous allons manipuler

    //Manipuler le fichier
    if(fichierExerc.open(QIODevice::ReadWrite | QIODevice::Truncate )){ //QIODevice.Truncate //Ouvrir le fichier avec quelques propriétés
        QTextStream txtStream(&fichierExerc); //Création d'un object Stream=temporaire et liason au fichier réel que nous avons créé: fichierExerc

        //  txtStream << "EXERCICE SUR LES FICHIERS \n"; // Envoie du texte dans le Stream et ce qui envoie le texte là dans le fichier car le Strean et le fichier sont réliés
        //  txtStream << "L1 INFO"; // Envoie du texte dans le Stream et ce qui envoie le texte là dans le fichier car le Strean et le fichier sont réliés
        txtStream << contenuTexte; // toPlainText est la méthode qui renvoie le contenu d'un TextEdit
    }
    fichierExerc.close(); // Fermeture de l'object Fichier
}


void gestion::on_pushButton_2_clicked()
{
    if(ui->naiss->isChecked()){
        LireFichier("naissances/"+(ui->name_fichier->text())+".txt");
    }else if(ui->dec->isChecked()){
        LireFichier("deces/"+(ui->name_fichier->text())+".txt");
    }else if(ui->mar->isChecked()){
        LireFichier("mariages/"+(ui->name_fichier->text())+".txt");
    }
}
void gestion::clear_all(){
    ui->name->clear();
    ui->postname->clear();
}


void gestion::on_pushButton_3_clicked()
{
    texte=new QTextEdit();
    QString text;
    text=ui->fullcomplete->toPlainText();
    texte->setText(text);
    QPrinter imprimer;
    imprimer.setOrientation(QPrinter::Portrait);
    QPrintPreviewDialog dialog(&imprimer,this);
    connect(&dialog,SIGNAL(paintRequested(QPrinter*)),this,SLOT(print(QPrinter*)));
    dialog.showMaximized();
    dialog.exec();
}
void gestion::print(QPrinter *printer){
    texte->print(printer);
}

