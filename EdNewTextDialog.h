//===========================================================================================================
// Class for dialog window to set new text for label of node
//
#ifndef EDNEWTEXTDIALOG_H
#define EDNEWTEXTDIALOG_H

#include <QDialog>

namespace Ui {
class EdNewTextDialog;
}

class EdNewTextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EdNewTextDialog(QWidget *parent = nullptr);
    ~EdNewTextDialog();

    // EAF - 20210228 - These public functions are used to get and set the text grabbed from the edit box
    // EAF - in this dialog
    QString getNewText()
    { return m_strText; }

    void    setNewText(QString strNew)
    {
        m_strText = QString(strNew);
    }

protected:
    void    showEvent(QShowEvent *event) override;

private slots:
    void    slot_btnOK_clicked();
    void    slot_btnCancel_clicked();

private:
    Ui::EdNewTextDialog *ui;

    QString     m_strText;
};

#endif // EDNEWTEXTDIALOG_H
