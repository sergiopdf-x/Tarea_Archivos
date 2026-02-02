#include "publicacioneswindow.h"
#include "ui_publicacioneswindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QCloseEvent>

publicacionesWindow::publicacionesWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::publicacionesWindow)
{
    ui->setupUi(this);

    ui->tblTabla->setColumnCount(5);
    ui->tblTabla->setHorizontalHeaderLabels(
        {"Código", "Título", "Año", "Tipo", "Estado"}
        );
}

publicacionesWindow::~publicacionesWindow()
{
    delete ui;
}

void publicacionesWindow::on_btnRegistrar_clicked()
{
    Publicacion p;
    p.codigo = ui->txtCodigo->text();
    p.titulo = ui->txtTitulo->text();
    p.anio = ui->deAnio->date().year();
    p.tipo = ui->cmbTipo->currentText();
    p.prestado = false;

    lista.append(p);
    actualizarTabla();

    QMessageBox::information(this, "OK", "Publicación registrada");
}

void publicacionesWindow::on_btnPrestar_clicked()
{
    int fila = ui->tblTabla->currentRow();

    if (fila < 0) {
        QMessageBox::warning(this, "Error", "Seleccione una publicación");
        return;
    }

    lista[fila].prestado = true;
    actualizarTabla();

    QMessageBox::information(this, "OK", "Publicación prestada");
}

void publicacionesWindow::on_btnDevolver_clicked()
{
    int fila = ui->tblTabla->currentRow();

    if (fila < 0) {
        QMessageBox::warning(this, "Error", "Seleccione una publicación");
        return;
    }

    lista[fila].prestado = false;
    actualizarTabla();

    QMessageBox::information(this, "OK", "Publicación devuelta");
}

void publicacionesWindow::actualizarTabla()
{
    ui->tblTabla->setRowCount(lista.size());

    for (int i = 0; i < lista.size(); i++) {
        ui->tblTabla->setItem(i, 0, new QTableWidgetItem(lista[i].codigo));
        ui->tblTabla->setItem(i, 1, new QTableWidgetItem(lista[i].titulo));
        ui->tblTabla->setItem(i, 2, new QTableWidgetItem(QString::number(lista[i].anio)));
        ui->tblTabla->setItem(i, 3, new QTableWidgetItem(lista[i].tipo));
        ui->tblTabla->setItem(
            i, 4,
            new QTableWidgetItem(lista[i].prestado ? "Prestado" : "No Prestado")
            );
    }
}

void publicacionesWindow::guardarArchivos()
{
    QFile prestados("LibrosPrestados.txt");
    QFile stock("LibrosEnStock.txt");

    prestados.open(QIODevice::WriteOnly | QIODevice::Text);
    stock.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream outP(&prestados);
    QTextStream outS(&stock);

    for (const Publicacion &p : lista) {
        QString linea = p.codigo + " | " + p.titulo + " | " +
                        QString::number(p.anio) + " | " +
                        (p.prestado ? "Prestado" : "No Prestado");

        if (p.prestado)
            outP << linea << "\n";
        else
            outS << linea << "\n";
    }

    prestados.close();
    stock.close();
}

void publicacionesWindow::closeEvent(QCloseEvent *event)
{
    guardarArchivos();
    event->accept();
}
