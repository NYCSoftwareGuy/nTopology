//===========================================================================================================
// Class for dialog box. Separate buttons are used and connected on their clicked signal to execute
// standard dialog commands.
//
#include "EdNewTextDialog.h"
#include "ui_EdNewTextDialog.h"

#include <QMessageBox>

//===========================================================================================================
// Constructor
//
EdNewTextDialog::EdNewTextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EdNewTextDialog)
{
    ui->setupUi(this);

    connect(ui->btnOK, SIGNAL(clicked()), this, SLOT(slot_btnOK_clicked()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(slot_btnCancel_clicked()));
}

//===========================================================================================================
// Destructor
//
EdNewTextDialog::~EdNewTextDialog()
{
    delete ui;
}

//===========================================================================================================
// Override of show event to show text from current node
//
void    EdNewTextDialog::showEvent(QShowEvent *event)
{
    ui->editNewText->setText(m_strText);

    QDialog::showEvent(event);
}
//===========================================================================================================
// slot_btnOK_clicked will check for text availability and length before returning
//
void    EdNewTextDialog::slot_btnOK_clicked()
{
    QString strText = ui->editNewText->text();
    QMessageBox msgBox;
    int iLength = strText.length();
    if (iLength == 0)
    {
        msgBox.critical(this,
                        QString("No Text Entered"),
                        QString("No Text was Entered. At least one Character Needs to be Entered."));
        return;
    }
    if (iLength > 20)
    {
        msgBox.critical(this,
                        QString("Text Too Long"),
                        QString("Text Over 20 Characters. Shorten It."));
        return;
    }
    m_strText = QString(strText);
    this->accept();
}

//===========================================================================================================
// slot_btnCancel_clicked is for when user cancels name change
//
void    EdNewTextDialog::slot_btnCancel_clicked()
{
    this->reject();
}
