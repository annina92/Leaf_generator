/********************************************************************************
** Form generated from reading UI file 'surface.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURFACE_H
#define UI_SURFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_surface
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *surface)
    {
        if (surface->objectName().isEmpty())
            surface->setObjectName(QStringLiteral("surface"));
        surface->resize(217, 257);
        pushButton = new QPushButton(surface);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 50, 75, 23));
        pushButton_2 = new QPushButton(surface);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 90, 75, 23));
        pushButton_3 = new QPushButton(surface);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(70, 140, 75, 23));
        pushButton_4 = new QPushButton(surface);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(70, 190, 75, 23));

        retranslateUi(surface);

        QMetaObject::connectSlotsByName(surface);
    } // setupUi

    void retranslateUi(QDialog *surface)
    {
        surface->setWindowTitle(QApplication::translate("surface", "surface", 0));
        pushButton->setText(QApplication::translate("surface", "File1", 0));
        pushButton_2->setText(QApplication::translate("surface", "File2", 0));
        pushButton_3->setText(QApplication::translate("surface", "File3", 0));
        pushButton_4->setText(QApplication::translate("surface", "File4", 0));
    } // retranslateUi

};

namespace Ui {
    class surface: public Ui_surface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACE_H
