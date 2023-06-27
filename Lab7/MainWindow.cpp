//
// Created by Igor on 6/25/2023.
//

#include "MainWindow.h"
#include "TextFile.h"

#include <QFileDialog>
#include <QMessageBox>

QString DEFAULT_PATH("Шлях до файлу");

QList<QString> filterLines(QList<QString> &lines, const QString &word) {
    QList<QString> fLines;
    for (auto line: lines) {
        if (line.split(" ").contains(word))
            fLines << line;
    }
    return fLines;
}

MainWindow::MainWindow() {
    ui.setupUi(this);

    QObject::connect(ui.inputFileButton, &QPushButton::pressed,
                     this, &MainWindow::selectSourceFile);
    QObject::connect(ui.outputFileButton, &QPushButton::pressed,
                     this, &MainWindow::selectDestFile);
    QObject::connect(ui.saveFileButton, &QPushButton::pressed,
                     this, &MainWindow::filter);
}

void MainWindow::selectSourceFile() {
    auto path = QFileDialog::getOpenFileName(nullptr, nullptr, nullptr, "Text files (*.txt)");
    if (path.isEmpty()) return;
    ui.pathInputFile->setText(path);
}

void MainWindow::selectDestFile() {
    auto path = QFileDialog::getSaveFileName(nullptr, nullptr, nullptr, "Text files (*.txt)");
    if (path.isEmpty()) return;
    ui.pathOutputFile->setText(path);
}

void MainWindow::filter() {
    if (ui.pathInputFile->text() == DEFAULT_PATH) {
        QMessageBox::critical(this, "Оберіть файл", "Оберіть файл буласка");
        return;
    }
    if (ui.pathOutputFile->text() == DEFAULT_PATH) {
        QMessageBox::critical(this, "Оберіть файл", "Оберіть файл буласка");
        return;
    }

    TextFile src(ui.pathInputFile->text());
    TextFile dst(ui.pathOutputFile->text());

    QList<QString> lines;
    try {
        lines = src.readLines();
    } catch (OpenFileError &e) {
        QMessageBox::critical(this, "Не магу відкрити файл", "Не магу відкрити файл");
        return;
    }

    lines = filterLines(lines, ui.filterWord->text());

    try {
        dst.writeLines(lines);
    } catch (OpenFileError &e) {
        QMessageBox::critical(this, "Не магу записати файл", "Не магу записати файл");
        return;
    }
}
