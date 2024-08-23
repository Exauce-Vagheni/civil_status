#ifndef mariages_H
#define mariages_H

#include "qdatetime.h"
#include <QMainWindow>
#include <Qprinter>
#include <QprintPreviewDialog>
#include <QTextEdit>

//Appel aux classes necessaires pour la manipulation des fichiers
#include "QFile" // Classe qui va nous aider à manipuler les fichiers
#include "QDir" // Classe qui va nous aider à manipuler les repertoires
#include "QTextStream" // Classe de munipulation des fichiers temporelles


namespace Ui {
class mariages;
}

class mariages : public QMainWindow
{
    Q_OBJECT

public:
    explicit mariages(QWidget *parent = nullptr);
    ~mariages();

private slots:
    void on_save_button_clicked();

    void on_lire_fichier_clicked();

    void on_print_file_clicked();
    void print(QPrinter*printer);

private:
    Ui::mariages *ui;
    QString username=*new QString();
    QString userpostname= *new QString();
    QString typeevent=*new QString();
    QString eventdate= *new QString();
    QString lieuevent= *new QString();
    QString namefather= *new QString();
    QString namemother= *new QString();
    QString adressParents= *new QString();
    QString sexe= *new QString();
    QString filename= *new QString();
    QString file_root= *new QString();
    void clear_all();
    void LireFichier(QString nomFichier);
    void EcrireDansFichier(QString nomFichier, QString contenuTexte);
    QTextEdit *texte;
};

#endif // mariages_H
