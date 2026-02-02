#ifndef PUBLICACIONESWINDOW_H
#define PUBLICACIONESWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>

namespace Ui {
class publicacionesWindow;
}

struct Publicacion {
    QString codigo;
    QString titulo;
    int anio;
    bool prestado;
    QString tipo;
};

class publicacionesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit publicacionesWindow(QWidget *parent = nullptr);
    ~publicacionesWindow();

private slots:
    void on_btnRegistrar_clicked();
    void on_btnPrestar_clicked();
    void on_btnDevolver_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::publicacionesWindow *ui;
    QVector<Publicacion> lista;

    void actualizarTabla();
    void guardarArchivos();
};

#endif // PUBLICACIONESWINDOW_H


