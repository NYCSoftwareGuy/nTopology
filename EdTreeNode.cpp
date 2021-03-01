//===========================================================================================================
// This is the code that establishes what a tree node does. The following can be found with this code:
// A label at near the top of the frame (used frame to draw border)
// - A right mouse click will bring up an option to change the text of the label
// - Length of text for label is limited to 20 characters
// A slider bar that goes from 0 to 10000 and a disabled edit box that will display the position of the
// slider bar
// - A right mouse click will bring up and option to enable or disable the slider bar
// - If the slider bar is disabled, the edit box becomes enabled and user can type in any data they wished
//
#include "EdTreeNode.h"
#include "EdNewTextDialog.h"

#include <QMenu>
#include <QAction>
#include <QPoint>

//===========================================================================================================
// Constructor - Items are set and drawn here.
//
EdTreeNode::EdTreeNode(QWidget *parent) : QFrame(parent)
  , m_bSliderEnabled(true)
  , m_strLabelBackColor(QString("black"))
  , m_strLabelTextColor(QString("white"))
{
    this->setFrameShape(QFrame::Box);
    this->setLineWidth(1);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setStyleSheet("QFrame { background-color : lightgray; }");

    int iWidth = this->width();
    m_MainLabel.setParent(this);
    m_MainLabel.setGeometry(10,2,iWidth - 10,16);
    m_MainLabel.setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    m_MainLabel.setText(QString("Tree Node"));
    QString strStyle = QString("QLabel { background-color : %1; color : %2; }")
            .arg(m_strLabelBackColor)
            .arg(m_strLabelTextColor);
    m_MainLabel.setStyleSheet(strStyle);

    m_slider.setParent(this);
    m_slider.setOrientation(Qt::Horizontal);
    m_slider.setGeometry(10,22,iWidth - 10,20);
    m_slider.setMinimum(0);
    m_slider.setMaximum(10000);
    m_slider.setValue(0);
    m_slider.setVisible(m_bSliderEnabled);
    m_slider.setEnabled(m_bSliderEnabled);

    m_lineEdit.setParent(this);
    m_lineEdit.setGeometry(10,45,iWidth - 10,20);
    m_lineEdit.setVisible(true);
    m_lineEdit.setEnabled(!m_bSliderEnabled);
    m_lineEdit.setText("0");

    // EAF - 20210228 - Code here sets the right mouse click to create a drop down menu
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint)),
            this, SLOT(slot_customContextMenuRequested(const QPoint)));

    // EAF - 20210228 - Code here connects signal of when value changed to slider
    connect(&m_slider, SIGNAL(valueChanged(int)), this, SLOT(slot_sliderChanged(int)));
    update();
}

//===========================================================================================================
// paintEvent - No special code done here for moment
//
void    EdTreeNode::paintEvent(QPaintEvent *aEvent)
{
    QFrame::paintEvent(aEvent);
}

//===========================================================================================================
// slot_customContextMenuRequested creates drop down menu at point of right mouse click
//
void    EdTreeNode::slot_customContextMenuRequested(const QPoint currPos)
{
    QMenu   objMenu(this);
    QAction *ptrAction;

    ptrAction = objMenu.addAction("Swap Label Color");
    ptrAction->setToolTip("Swap black/white colors of Node Text");
    connect(ptrAction, SIGNAL(triggered()), this, SLOT(slot_SwapNodeColor()));

    objMenu.addSeparator();

    ptrAction = objMenu.addAction("Change Node Text");
    ptrAction->setToolTip("Change Text of Node");
    connect(ptrAction, SIGNAL(triggered()), this, SLOT(slot_ChangeNodeText()));

    objMenu.addSeparator();

    ptrAction = objMenu.addAction("Use Slider");
    ptrAction->setCheckable(true);
    ptrAction->setChecked(m_bSliderEnabled);
    connect(ptrAction, SIGNAL(triggered()), this, SLOT(slot_ChangeSliderEnable()));

    objMenu.exec(this->mapToGlobal(currPos));
}

//===========================================================================================================
// slot_SwapNodeColor will change black to white and white to black.
//
void    EdTreeNode::slot_SwapNodeColor()
{
    if (m_strLabelBackColor.compare(QString("white")) == 0)
    {
        m_strLabelBackColor = QString("black");
        m_strLabelTextColor = QString("white");
    }
    else {
        m_strLabelBackColor = QString("white");
        m_strLabelTextColor = QString("black");
    }

    QString strStyle = QString("QLabel { background-color : %1; color : %2; }")
            .arg(m_strLabelBackColor)
            .arg(m_strLabelTextColor);
    m_MainLabel.setStyleSheet(strStyle);
    m_MainLabel.update();
}

//===========================================================================================================
// slot_ChangeNodeText calls up a dialog box to allow user to change label text of node
//
void    EdTreeNode::slot_ChangeNodeText()
{
    QString strLabel = m_MainLabel.text();
    EdNewTextDialog   dlg(this);
    dlg.setNewText(strLabel);
    if (dlg.exec())
    {
        strLabel = dlg.getNewText();
        m_MainLabel.setText(strLabel);
        m_MainLabel.update();
    }
}

//===========================================================================================================
// slot_ChangeSliderEnable either enables or disables slider and activates the edit box depending on slider
// condition
//
void    EdTreeNode::slot_ChangeSliderEnable()
{
    m_bSliderEnabled = !m_bSliderEnabled;

    m_slider.setVisible(m_bSliderEnabled);
    m_slider.setEnabled(m_bSliderEnabled);

    m_lineEdit.setEnabled(!m_bSliderEnabled);
    if (m_bSliderEnabled)
    {
        int iValue = m_slider.value();
        slot_sliderChanged(iValue);
    }
}

//===========================================================================================================
// slot_sliderChanged is called when slider value changes
//
void    EdTreeNode::slot_sliderChanged(int iNewValue)
{
    double  dbValue = (double)(iNewValue / 100.0);
    QString strText = QString("%1").arg(dbValue);
    m_lineEdit.setText(strText);
}
