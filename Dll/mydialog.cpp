#include "mydialog.h"
#include "ui_mydialog.h"


QMyDialog::QMyDialog(Callback_t fn, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QMyDialog)
    , callback_fn_(fn)
{
    ui->setupUi(this);
}


QMyDialog::~QMyDialog()
{
    delete ui;
}


void QMyDialog::on_pushButton_clicked()
{
    if (callback_fn_) {
        QByteArray dial_val = QString("dial:%1").arg(ui->dial->value()).toUtf8();
        char* data[] = { dial_val.data() };
        callback_fn_(data, 1);
    }
    qApp->quit();
}
