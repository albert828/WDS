#ifndef SERIALOPTIONSDIALOG_H
#define SERIALOPTIONSDIALOG_H

#include <QDialog>

/**
 * @brief Keeps Serial Port name
 *
 * Used in settings. Allows user to make choice which port wants to use
 */
extern QString PortName;
/**
 * @brief Used in settings. Allows user to make choice which speed want to use
 */
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
    /**
     * @brief Runs when allow button clicked
     *
     * Applies changes in serial comunication options
     */
    void on_pushButton_clicked();

private:
    Ui::SerialOptionsDialog *ui;
};

#endif // SERIALOPTIONSDIALOG_H
