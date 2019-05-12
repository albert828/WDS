#ifndef SERIALOPTIONSDIALOG_H
#define SERIALOPTIONSDIALOG_H

#include <QDialog>

extern QString PortName;
extern uint32_t BaudRate;

namespace Ui {
class SerialOptionsDialog;
}

class SerialOptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SerialOptionsDialog(QWidget *parent = nullptr);
    ~SerialOptionsDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SerialOptionsDialog *ui;
};

#endif // SERIALOPTIONSDIALOG_H
