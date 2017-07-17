#ifndef WHERE_H
#define WHERE_H

#include <QDialog>
#include <QFile>
#include <QFileInfo>
#include "cretree.h"
#include <QMessageBox>

namespace Ui {
class where;
}

class where : public QDialog
{
    Q_OBJECT

public:
    explicit where(QWidget *parent = 0);
    ~where();
    QString filename;
    cretree *f;

private slots:
    void on_res_clicked();

    void on_index_textChanged(const QString &arg1);

private:
    void on_Filename_textChanged(const QString &arg1);
    void on_Show_clicked();


private:
    Ui::where *ui;
};

#endif // WHERE_H
