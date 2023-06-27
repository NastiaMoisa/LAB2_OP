//
// Created by Igor on 6/25/2023.
//

#include "TextFile.h"

#include <QFile>
#include <QDebug>

TextFile::TextFile(const QString &path) : path(path) {
}

QList<QString> TextFile::readLines() {
    QFile f(this->path);
    if (!f.open(QIODevice::ReadOnly))
        throw OpenFileError();

    QTextStream s(&f);

    QList<QString> lines;
    while (!s.atEnd()) {
        lines << s.readLine();
    }
    return lines;
}

void TextFile::writeLines(const QList<QString> &lines) {
    QFile f(this->path);
    if (!f.open(QIODevice::WriteOnly))
        throw OpenFileError();

    QTextStream s(&f);
    for (auto line: lines) {
        s << line << "\n";
    }
}
