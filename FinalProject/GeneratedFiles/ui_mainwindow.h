/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionSet_Points;
    QAction *actionWireframe_On;
    QAction *actionWireframe_Off;
    QAction *actionSample_2;
    QAction *actionSample_Surface_1;
    QAction *actionSample_1;
    QAction *actionSample_3;
    QAction *actionSample_4;
    QAction *actionSurface_1;
    QAction *actionSurface_2;
    QAction *actionMerge;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuEdit;
    QMenu *menuOpen;
    QMenu *menuOpen_3;
    QMenu *menuOpen_Surface;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(600, 400);
        actionSet_Points = new QAction(MainWindowClass);
        actionSet_Points->setObjectName(QStringLiteral("actionSet_Points"));
        actionWireframe_On = new QAction(MainWindowClass);
        actionWireframe_On->setObjectName(QStringLiteral("actionWireframe_On"));
        actionWireframe_Off = new QAction(MainWindowClass);
        actionWireframe_Off->setObjectName(QStringLiteral("actionWireframe_Off"));
        actionSample_2 = new QAction(MainWindowClass);
        actionSample_2->setObjectName(QStringLiteral("actionSample_2"));
        actionSample_Surface_1 = new QAction(MainWindowClass);
        actionSample_Surface_1->setObjectName(QStringLiteral("actionSample_Surface_1"));
        actionSample_1 = new QAction(MainWindowClass);
        actionSample_1->setObjectName(QStringLiteral("actionSample_1"));
        actionSample_3 = new QAction(MainWindowClass);
        actionSample_3->setObjectName(QStringLiteral("actionSample_3"));
        actionSample_4 = new QAction(MainWindowClass);
        actionSample_4->setObjectName(QStringLiteral("actionSample_4"));
        actionSurface_1 = new QAction(MainWindowClass);
        actionSurface_1->setObjectName(QStringLiteral("actionSurface_1"));
        actionSurface_2 = new QAction(MainWindowClass);
        actionSurface_2->setObjectName(QStringLiteral("actionSurface_2"));
        actionMerge = new QAction(MainWindowClass);
        actionMerge->setObjectName(QStringLiteral("actionMerge"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuOpen_3 = new QMenu(menuOpen);
        menuOpen_3->setObjectName(QStringLiteral("menuOpen_3"));
        menuOpen_Surface = new QMenu(menuOpen);
        menuOpen_Surface->setObjectName(QStringLiteral("menuOpen_Surface"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuOpen->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuEdit->addAction(actionSet_Points);
        menuOpen->addAction(menuOpen_3->menuAction());
        menuOpen->addAction(menuOpen_Surface->menuAction());
        menuOpen->addAction(actionMerge);
        menuOpen_3->addAction(actionSample_3);
        menuOpen_3->addAction(actionSample_4);
        menuOpen_Surface->addAction(actionSurface_1);
        menuOpen_Surface->addAction(actionSurface_2);
        mainToolBar->addAction(actionSet_Points);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        actionSet_Points->setText(QApplication::translate("MainWindowClass", "Set Points", 0));
        actionWireframe_On->setText(QApplication::translate("MainWindowClass", "Wireframe On", 0));
        actionWireframe_Off->setText(QApplication::translate("MainWindowClass", "Wireframe Off", 0));
        actionSample_2->setText(QApplication::translate("MainWindowClass", "Sample 2", 0));
        actionSample_Surface_1->setText(QApplication::translate("MainWindowClass", "Sample Surface 1", 0));
        actionSample_1->setText(QApplication::translate("MainWindowClass", "sample 1", 0));
        actionSample_3->setText(QApplication::translate("MainWindowClass", "Sample 1", 0));
        actionSample_4->setText(QApplication::translate("MainWindowClass", "Sample 2", 0));
        actionSurface_1->setText(QApplication::translate("MainWindowClass", "Surface 1", 0));
        actionSurface_2->setText(QApplication::translate("MainWindowClass", "Surface 2", 0));
        actionMerge->setText(QApplication::translate("MainWindowClass", "Merge", 0));
        menuEdit->setTitle(QApplication::translate("MainWindowClass", "Edit", 0));
        menuOpen->setTitle(QApplication::translate("MainWindowClass", "File", 0));
        menuOpen_3->setTitle(QApplication::translate("MainWindowClass", "Open Leaf", 0));
        menuOpen_Surface->setTitle(QApplication::translate("MainWindowClass", "Open Surface", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
