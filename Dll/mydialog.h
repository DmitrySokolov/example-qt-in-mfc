#ifndef QMYDIALOG_H
#define QMYDIALOG_H


#include <QDialog>
#include "mydialog_api.h"


QT_BEGIN_NAMESPACE
namespace Ui { class QMyDialog; }
QT_END_NAMESPACE


class QMyDialog : public QDialog
{
    Q_OBJECT

public:
    QMyDialog(Callback_t fn, QWidget *parent = nullptr);
    ~QMyDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::QMyDialog*  ui;
    Callback_t      callback_fn_;
};


#endif // QMYDIALOG_H
