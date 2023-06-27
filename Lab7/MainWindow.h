//
// Created by Igor on 6/25/2023.
//

#ifndef QT_TEST_MAINWINDOW_H
#define QT_TEST_MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow {
public:
    MainWindow();

private slots:
    Ui::MainWindow ui;

    void selectSourceFile();
    void selectDestFile();
    void filter();
};


#endif //QT_TEST_MAINWINDOW_H
