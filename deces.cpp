#include "deces.h"
#include "ui_deces.h"

deces::deces(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::deces)
{
    ui->setupUi(this);
}

deces::~deces()
{
    delete ui;
}

void deces::on_pushButton_2_clicked()
{

}

