#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "publicacioneswindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_btnIngresar_clicked()
{
    QString usuario = ui->leUsuario->text();
    QString contrasena = ui->leContra->text();

    if(usuario == "admin" && contrasena == "1234"){
        QMessageBox::information(this,"Login","Acceso permitido");

        publicacionesWindow *p = new publicacionesWindow();
        p->show();
        this->close();

    }else{
        QMessageBox::warning(this,"Error","Acceso denegado");
    }
}
