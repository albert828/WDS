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
 * @brief Contains value of the Baud Rate
 * 
 * Used in settings. Allows user to make choice which speed want to use
 */
extern uint32_t BaudRate;

namespace Ui {
class SerialOptionsDialog;
}
/**
 * @brief This class creates Widnow with Serial settings
 * 
 */
class SerialOptionsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new Serial Options Dialog object. Creates list of available
     * Ports and list with possible Baud Rates.
     * 
     * @param parent 
     */
    explicit SerialOptionsDialog(QWidget *parent = nullptr);
    /**
     * @brief Destroy the Serial Options Dialog object
     * 
     */
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
