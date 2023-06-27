//
// Created by Igor on 6/25/2023.
//

#ifndef QT_TEST_TEXTFILE_H
#define QT_TEST_TEXTFILE_H

#include <QString>
#include <QList>

class OpenFileError : std::exception {
};

class TextFile {
private:
    QString path;

public:
    explicit TextFile(const QString &path);

    QList<QString> readLines();

    void writeLines(const QList<QString> &lines);
};


#endif //QT_TEST_TEXTFILE_H
