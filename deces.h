#ifndef DECES_H
#define DECES_H

#include <QMainWindow>

namespace Ui {
class deces;
}

class deces : public QMainWindow
{
    Q_OBJECT

public:
    explicit deces(QWidget *parent = nullptr);
    ~deces();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::deces *ui;
};

#endif // DECES_H
