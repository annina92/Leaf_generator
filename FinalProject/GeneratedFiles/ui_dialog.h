/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *Point1x;
    QLineEdit *Point1y;
    QLineEdit *Point2x;
    QLineEdit *Point3x;
    QLineEdit *Point4x;
    QLineEdit *Point5x;
    QLineEdit *Point2y;
    QLineEdit *Point3y;
    QLineEdit *Point4y;
    QLineEdit *Point5y;
    QLabel *label_6;
    QLineEdit *Point6x;
    QLineEdit *Point6y;
    QLineEdit *Point7x;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *Point8x;
    QLineEdit *Point7y;
    QLineEdit *Point8y;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(472, 339);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 119, 33, 16));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(9, 145, 33, 16));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(9, 171, 33, 16));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(9, 197, 33, 16));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(9, 223, 33, 16));
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 60, 16, 16));
        label_10 = new QLabel(Dialog);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(260, 60, 16, 16));
        Point1x = new QLineEdit(Dialog);
        Point1x->setObjectName(QStringLiteral("Point1x"));
        Point1x->setGeometry(QRect(48, 119, 133, 20));
        Point1y = new QLineEdit(Dialog);
        Point1y->setObjectName(QStringLiteral("Point1y"));
        Point1y->setGeometry(QRect(262, 119, 133, 20));
        Point2x = new QLineEdit(Dialog);
        Point2x->setObjectName(QStringLiteral("Point2x"));
        Point2x->setGeometry(QRect(48, 145, 133, 20));
        Point3x = new QLineEdit(Dialog);
        Point3x->setObjectName(QStringLiteral("Point3x"));
        Point3x->setGeometry(QRect(48, 171, 133, 20));
        Point4x = new QLineEdit(Dialog);
        Point4x->setObjectName(QStringLiteral("Point4x"));
        Point4x->setGeometry(QRect(48, 197, 133, 20));
        Point5x = new QLineEdit(Dialog);
        Point5x->setObjectName(QStringLiteral("Point5x"));
        Point5x->setGeometry(QRect(48, 223, 133, 20));
        Point2y = new QLineEdit(Dialog);
        Point2y->setObjectName(QStringLiteral("Point2y"));
        Point2y->setGeometry(QRect(262, 145, 133, 20));
        Point3y = new QLineEdit(Dialog);
        Point3y->setObjectName(QStringLiteral("Point3y"));
        Point3y->setGeometry(QRect(262, 171, 133, 20));
        Point4y = new QLineEdit(Dialog);
        Point4y->setObjectName(QStringLiteral("Point4y"));
        Point4y->setGeometry(QRect(262, 197, 133, 20));
        Point5y = new QLineEdit(Dialog);
        Point5y->setObjectName(QStringLiteral("Point5y"));
        Point5y->setGeometry(QRect(262, 223, 133, 20));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(9, 249, 33, 16));
        Point6x = new QLineEdit(Dialog);
        Point6x->setObjectName(QStringLiteral("Point6x"));
        Point6x->setGeometry(QRect(48, 249, 133, 20));
        Point6y = new QLineEdit(Dialog);
        Point6y->setObjectName(QStringLiteral("Point6y"));
        Point6y->setGeometry(QRect(262, 249, 133, 20));
        Point7x = new QLineEdit(Dialog);
        Point7x->setObjectName(QStringLiteral("Point7x"));
        Point7x->setGeometry(QRect(48, 275, 133, 20));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(9, 275, 33, 16));
        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(9, 301, 33, 16));
        Point8x = new QLineEdit(Dialog);
        Point8x->setObjectName(QStringLiteral("Point8x"));
        Point8x->setGeometry(QRect(48, 301, 133, 20));
        Point7y = new QLineEdit(Dialog);
        Point7y->setObjectName(QStringLiteral("Point7y"));
        Point7y->setGeometry(QRect(262, 275, 133, 20));
        Point8y = new QLineEdit(Dialog);
        Point8y->setObjectName(QStringLiteral("Point8y"));
        Point8y->setGeometry(QRect(262, 301, 133, 20));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(360, 30, 75, 23));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 60, 75, 23));

        retranslateUi(Dialog);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Dialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        label->setText(QApplication::translate("Dialog", "Point 1", 0));
        label_2->setText(QApplication::translate("Dialog", "Point 2", 0));
        label_3->setText(QApplication::translate("Dialog", "Point 3", 0));
        label_4->setText(QApplication::translate("Dialog", "Point 4", 0));
        label_5->setText(QApplication::translate("Dialog", "Point 5", 0));
        label_9->setText(QApplication::translate("Dialog", "x", 0));
        label_10->setText(QApplication::translate("Dialog", "y", 0));
        label_6->setText(QApplication::translate("Dialog", "Point 6", 0));
        label_7->setText(QApplication::translate("Dialog", "Point 7", 0));
        label_8->setText(QApplication::translate("Dialog", "Point 8", 0));
        pushButton->setText(QApplication::translate("Dialog", "Update", 0));
        pushButton_2->setText(QApplication::translate("Dialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
