#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QKeyEvent>
#include <QWheelEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Hide the cursor on launch
    QApplication::setOverrideCursor(Qt::BlankCursor);

    // Setup the UI from the .ui file
    ui->setupUi(this);

    // Initialize custom main_menu widget if defined correctly in .ui
    ui->main_menu->initialize(ui);

    // Allow window to be resized and moved (but do not fullscreen)
    this->setWindowFlags(Qt::Window);  // Enables move, resize, minimize/maximize
    this->resize(1024, 768);           // Optional: Default size
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    // Preserve any existing key event logic
    QMainWindow::keyPressEvent(e);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    // Optional: if you want to handle scroll or zoom behavior
    QMainWindow::wheelEvent(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}