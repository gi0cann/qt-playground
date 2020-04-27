#include "mainwindow.h"
#include "ui_mainwindow.h"

QString base64_encode(QString string)
{
    QByteArray byte_array;
    byte_array.append(string);
    return byte_array.toBase64();
}

QString base64_decode(QString string)
{
    QByteArray byte_array;
    byte_array.append(string);
    return QByteArray::fromBase64(byte_array).data();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_encodePushButton_released()
{
    QString inputText = ui->SourceLineEdit->text();
    QString b64InputText = base64_encode(inputText);
    qDebug() << "Encoded Input text = " << b64InputText;
    ui->ResultTextBrowser->setText(b64InputText);
}

void MainWindow::on_decodePushButton_released()
{
    QString inputText = ui->SourceLineEdit->text();
    QString decodedInputText = base64_decode(inputText);
    qDebug() << "Decoded Input text = " << decodedInputText;
    ui->ResultTextBrowser->setText(decodedInputText);
}
