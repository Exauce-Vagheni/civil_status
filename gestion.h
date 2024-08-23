#ifndef GESTION_H
#define GESTION_H

#include "qdatetime.h"
#include <QMainWindow>
#include <Qprinter>
#include <QprintPreviewDialog>
#include <QTextEdit>

//Appel aux classes necessaires pour la manipulation des fichiers
#include "QFile" // Classe qui va nous aider à manipuler les fichiers
#include "QDir" // Classe qui va nous aider à manipuler les repertoires
#include "QTextStream" // Classe de munipulation des fichiers temporelles

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class gestion; }
QT_END_NAMESPACE

class gestion : public QMainWindow
{
    Q_OBJECT

public:
    gestion(QWidget *parent = nullptr);
    ~gestion();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void print(QPrinter*printer);

    void on_pushButton_3_clicked();

private:
    Ui::gestion *ui;
    QString username=*new QString();
    QString userpostname= *new QString();
    QString typeevent=*new QString();
    QString eventdate= *new QString();
    QString lieuevent= *new QString();
    QString namefather= *new QString();
    QString namemother= *new QString();
    QString adressParents= *new QString();
    QString sexe= *new QString();
    void clear_all();
    void LireFichier(QString nomFichier);
    void EcrireDansFichier(QString nomFichier, QString contenuTexte);
    QTextEdit *texte;
};
#endif // GESTION_H
