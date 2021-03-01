//===========================================================================================================
// EdTreeNode class that demonstrates how a node can be done. It is a custom widget that inherits a
// QFrame
//
#ifndef EDTREENODE_H
#define EDTREENODE_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QLine>

class EdTreeNode : public QFrame
{
    Q_OBJECT

public:
    explicit EdTreeNode(QWidget *parent = nullptr);

private slots:
    void    slot_SwapNodeColor();
    void    slot_ChangeNodeText();
    void    slot_ChangeSliderEnable();
    void    slot_customContextMenuRequested(const QPoint currPos);
    void    slot_sliderChanged(int iNewValue);

protected:
    void    paintEvent(QPaintEvent *aEvent) override;

private:
    // EAF - 20210228 - Note that drag and drop could be implemented here.
    // EAF - Also at constructor, setAcceptDrop is called

    QLabel      m_MainLabel;
    QLineEdit   m_lineEdit;
    QSlider     m_slider;

    // EAF - 20210228 - I would use these lines to draw connection to children nodes
    QLine       m_lineLeft;
    QLine       m_lineRight;

    bool        m_bSliderEnabled;
    QString     m_strLabelBackColor;
    QString     m_strLabelTextColor;
};

#endif // EDTREENODE_H
