#include "naissances.h"
#include "ui_naissances.h"
#include "QMessageBox"
#include "QDialog"
naissances::naissances(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::naissances)
{
    ui->setupUi(this);
}

naissances::~naissances()
{
    delete ui;
}


void naissances::on_save_button_clicked()
{
    username=ui->name->text();
    userpostname=ui->postname->text();
    eventdate=ui->dateevent->text();
    QMessageBox::information(this,"RESULTAT", "Enregistrement effectué avec succès pour cet événement");
    lieuevent=ui->lieunaiss->text();
    namefather=ui->father->text();
    namemother=ui->mother->text();
    adressParents=ui->adress->text();
    sexe=ui->gender->currentText();
    ui->fullcomplete->append("NOM COMPLET: "+username+" "+userpostname);
    ui->fullcomplete->append("LIEU DE NAISSANCE: "+lieuevent);
    ui->fullcomplete->append(" DATE DE NAISSANCE: "+eventdate);
    ui->fullcomplete->append("NOM DU PERE: "+namefather);
    ui->fullcomplete->append("NOM DE LA MERE: "+namefather);
    ui->fullcomplete->append("ADRESSE DES PARENTS: "+adressParents);
    ui->fullcomplete->append("SEXE: "+sexe);

    ui->fullcomplete->setEnabled(false);
        EcrireDansFichier("naissances/"+username+" "+userpostname+".txt","CERTIFICAT DE NAISSANCE \n NOM: "+username +"\n POSTNOM: "+userpostname+"\n"+"DATE DE NAISSANCE: "+eventdate+"\n "+"LIEU DE NAISSANCE: "+lieuevent+"\n "+"NOM DU PERE: "+namefather+"\n "+"NOM DE LA MERE: "+namemother+"\n "+"ADRESSE DES PARENTS: "+adressParents+"\n "+"SEXE: "+adressParents+"\n ");

    clear_all();
}
//Methode qui lit le contenu d'un fichier
void naissances::LireFichier(QString nomFichier){
    QFile FichierTexte(nomFichier);
    QString contenuFichier;
    QTextStream notreStream(&FichierTexte); //Créer un Stream et le relier à notre fichier
    if(FichierTexte.open(QIODevice::ReadOnly)==true){ //Test si le fichier vient d'être ouvert
        contenuFichier=notreStream.readAll();
        ui->fullcomplete->setText(contenuFichier);
    }
    FichierTexte.close();
}

void naissances::EcrireDansFichier(QString nomFichier, QString contenuTexte){
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


void naissances::on_lire_fichier_clicked()
{
    file_root="naissances/"+ui->name_fichier->text()+".txt";
    QFile filename(file_root);
    if(filename.exists()){
        LireFichier(file_root);
        ui->print_file->setEnabled(true);
     }else{
        QMessageBox::critical(this,"NON TROUVE", "Le certificat recherché n'a pa été trouvé");
        ui->fullcomplete->setText("Certificat introuvable");
     }
}
void naissances::clear_all(){
    ui->name->clear();
    ui->postname->clear();
}


void naissances::on_print_file_clicked()
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
void naissances::print(QPrinter *printer){
    texte->print(printer);
}

