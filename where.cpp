#include "where.h"
#include "ui_where.h"

where::where(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::where)
{
    ui->setupUi(this);
    filename = "/";
    f=new cretree(filename);
}

where::~where()
{
    if(f!=NULL)
        delete f;
    delete ui;
}

void where::on_Filename_textChanged(const QString &arg1)
{
    filename=arg1;
}

void where::on_res_clicked()
{
    QFileInfo *info=new QFileInfo(filename);
    if(info->isDir())
    {
        f->model->setRootPath(filename);
        f->treeView->setRootIndex(f->model->index(filename));
        f->show();
    }
    else
    {
        QMessageBox::information(this,"Failed","Invalid input!");
    }
}
