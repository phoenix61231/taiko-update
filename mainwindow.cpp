#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QTime>
#include <ctime>
#include <QMessageBox>
#include <QtCore>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->drum->hide();
    ui->mid->hide();
    ui->around->hide();
    ui->target->hide();
    ui->timer->hide();
    ui->score->hide();
    ui->tips->hide();
    ui->lcdNumbertimer->hide();
    ui->lcdNumberscore->hide();
    ui->lcdNumbertimer->display(30);

    ui->goodl->hide();
    ui->goods->hide();
    ui->notbadl->hide();
    ui->notbads->hide();

    ui->redtaiko->hide();
    ui->bluetaiko->hide();
    ui->redtaikol->hide();
    ui->bluetaikol->hide();
    ui->blacksoul->hide();

    ui->bluesoul->hide();
    ui->greensoul->hide();
    ui->yellowsoul->hide();

    ui->lcdcorrectrate->hide();
    ui->lcdniceplay->hide();
    ui->lcdnotbadplay->hide();
    ui->lcdnan->hide();
    ui->lcdscore->hide();
    ui->scoreboard->hide();

    ui->lcdcorrectrate->setPalette(Qt::black);
    ui->lcdniceplay->setPalette(Qt::black);
    ui->lcdnotbadplay->setPalette(Qt::black);
    ui->lcdnan->setPalette(Qt::black);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *)
{
    if(ui->lcdNumbertimer->intValue() > 0){
        ui->lcdNumbertimer->display(ui->lcdNumbertimer->value() - 1);
    }
    else{
        ui->lcdNumbertimer->display(0);
    }
}

void MainWindow::on_Start_clicked()
{
    x = 2;
    y = 1;

    score = 0;
    nicecount = 0;
    notbadcount = 0;
    nancount = 0;
    allcount =0;

    ui->Start->hide();
    ui->Startmob->hide();
    ui->drum->show();
    ui->target->show();
    ui->timer->show();
    ui->score->show();
    ui->tips->show();
    ui->lcdNumbertimer->show();
    ui->lcdNumberscore->show();
    ui->blacksoul->show();
    srand(time(NULL));
    QTime t;
    QObject::startTimer(1000);
    while(1){
        allcount++;
        i = rand()%4;
        scoretmp = score;
        switch(i){
        case 0:
            ui->redtaiko->show();
            while(ui->redtaiko->x() >=0){
                ui->redtaiko->move(QPoint(ui->redtaiko->x()-x, ui->redtaiko->y()));
                t.start();
                while(t.elapsed()<4)
                    QCoreApplication::processEvents();
            }
            ui->redtaiko->hide();
            ui->redtaiko->move(QPoint(500,ui->redtaiko->y()));
            break;

        case 1:
            ui->bluetaiko->show();
            while(ui->bluetaiko->x() >=0){
                ui->bluetaiko->move(QPoint(ui->bluetaiko->x()-y, ui->bluetaiko->y()));
                t.start();
                while(t.elapsed()<4)
                    QCoreApplication::processEvents();

            }
            ui->bluetaiko->hide();
            ui->bluetaiko->move(QPoint(500,ui->bluetaiko->y()));
            break;
        case 2:
            ui->redtaikol->show();
            while(ui->redtaikol->x() >=0){
                ui->redtaikol->move(QPoint(ui->redtaikol->x()-y, ui->redtaikol->y()));
                t.start();
                while(t.elapsed()<4)
                    QCoreApplication::processEvents();

            }
            ui->redtaikol->hide();
            ui->redtaikol->move(QPoint(500,ui->redtaikol->y()));
            break;
        default:
            ui->bluetaikol->show();
            while(ui->bluetaikol->x() >=0){
                ui->bluetaikol->move(QPoint(ui->bluetaikol->x()-y, ui->bluetaikol->y()));
                t.start();
                while(t.elapsed()<4)
                    QCoreApplication::processEvents();

            }
            ui->bluetaikol->hide();
            ui->bluetaikol->move(QPoint(500,ui->bluetaikol->y()));
            break;
        }
        if(score>scoretmp){
            count++;
        }
        else{
        count = 0;
        ui->bluesoul->hide();
        ui->greensoul->hide();
        ui->yellowsoul->hide();

        }
        switch(count){
        case 10:
            ui->bluesoul->show();
            break;
        case 20:
            ui->greensoul->show();
            break;
        case 30:
            ui->yellowsoul->show();
            break;
        }
        t.start();
        while(t.elapsed()<30)
            QCoreApplication::processEvents();
        if(ui->lcdNumbertimer->intValue() == 0){

                ui->lcdcorrectrate->show();
                ui->lcdniceplay->show();
                ui->lcdnotbadplay->show();
                ui->lcdnan->show();
                ui->lcdscore->show();
                ui->scoreboard->show();
                rate = 100*(nicecount+notbadcount)/allcount;
                nancount = allcount-nicecount-notbadcount;
                ui->lcdcorrectrate->display(rate);
                ui->lcdniceplay->display(nicecount);
                ui->lcdnotbadplay->display(notbadcount);
                ui->lcdnan->display(nancount);
                ui->lcdscore->display(score);
                break;

         }

    }

}

void MainWindow::on_restart_clicked()
{

    score = 0;
    nicecount = 0;
    notbadcount = 0;
    nancount = 0;
    allcount =0;

    ui->lcdcorrectrate->hide();
    ui->lcdniceplay->hide();
    ui->lcdnotbadplay->hide();
    ui->lcdnan->hide();
    ui->lcdscore->hide();
    ui->scoreboard->hide();

    ui->redtaiko->hide();
    ui->redtaiko->move(QPoint(500,ui->redtaiko->y()));
    ui->redtaikol->hide();
    ui->redtaikol->move(QPoint(500,ui->redtaikol->y()));
    ui->bluetaiko->hide();
    ui->bluetaiko->move(QPoint(500,ui->bluetaiko->y()));
    ui->bluetaikol->hide();
    ui->bluetaikol->move(QPoint(500,ui->bluetaikol->y()));
    ui->lcdNumbertimer->display(30);
    ui->lcdNumberscore->display(score);

    ui->Start->clicked();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Q){
        ui->mid->show();

        QTime t;

        if(ui->redtaiko->x()<100 && ui->redtaiko->x()>70){
            ui->redtaiko->hide();
            ui->redtaiko->move(QPoint(0, ui->redtaiko->y()));
            ui->goods->show();
            score = score + 2;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->goods->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            nicecount++;
        }
        if(ui->redtaiko->x()<120 && ui->redtaiko->x()>100){
            ui->redtaiko->hide();
            ui->redtaiko->move(QPoint(0, ui->redtaiko->y()));
            ui->notbads->show();
            score = score + 1;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->notbads->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            notbadcount++;
        }
        if(ui->redtaiko->x()<70 && ui->redtaiko->x()>50){
            ui->redtaiko->hide();
            ui->redtaiko->move(QPoint(0, ui->redtaiko->y()));
            ui->notbads->show();
            score = score + 1;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->notbads->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            notbadcount++;
        }
        if(ui->redtaikol->x()<100 && ui->redtaikol->x()>70){
            ui->redtaikol->hide();
            ui->redtaikol->move(QPoint(0, ui->redtaikol->y()));
            ui->goodl->show();
            score = score + 3;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->goodl->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            nicecount++;
        }
        if(ui->redtaikol->x()<110 && ui->redtaikol->x()>100){
            ui->redtaikol->hide();
            ui->redtaikol->move(QPoint(0, ui->redtaikol->y()));
            ui->goodl->show();
            score = score + 2;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->goodl->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            notbadcount++;
        }
        if(ui->redtaikol->x()<70 && ui->redtaikol->x()>50){
            ui->redtaikol->hide();
            ui->redtaikol->move(QPoint(0, ui->redtaikol->y()));
            ui->goodl->show();
            score = score + 2;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->goodl->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            notbadcount++;
        }


    }
    if(event->key() == Qt::Key_P){
        ui->around->show();

        QTime t;

        if(ui->bluetaiko->x()<100 && ui->bluetaiko->x()>70){
            ui->bluetaiko->hide();
            ui->bluetaiko->move(QPoint(0, ui->bluetaiko->y()));
            ui->goods->show();
            score = score + 2;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->goods->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            nicecount++;
        }
        if(ui->bluetaiko->x()<120 && ui->bluetaiko->x()>100){
            ui->bluetaiko->hide();
            ui->bluetaiko->move(QPoint(0, ui->bluetaiko->y()));
            ui->notbads->show();
            score = score + 1;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->notbads->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            notbadcount++;
        }
        if(ui->bluetaiko->x()<70 && ui->bluetaiko->x()>50){
            ui->bluetaiko->hide();
            ui->bluetaiko->move(QPoint(0, ui->bluetaiko->y()));
            ui->notbads->show();
            score = score + 1;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->notbads->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            notbadcount++;
        }
        if(ui->bluetaikol->x()<100 && ui->bluetaikol->x()>70){
            ui->bluetaikol->hide();
            ui->bluetaikol->move(QPoint(0, ui->bluetaikol->y()));
            ui->goodl->show();
            score = score + 3;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->goodl->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            nicecount++;
        }
        if(ui->bluetaikol->x()<110 && ui->bluetaikol->x()>100){
            ui->bluetaikol->hide();
            ui->bluetaikol->move(QPoint(0, ui->bluetaikol->y()));
            ui->notbadl->show();
            score = score + 2;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->notbadl->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            notbadcount++;
        }
        if(ui->bluetaikol->x()<70 && ui->bluetaikol->x()>50){
            ui->bluetaikol->hide();
            ui->bluetaikol->move(QPoint(0, ui->bluetaikol->y()));
            ui->notbadl->show();
            score = score + 2;
            ui->lcdNumberscore->display(score);
            t.start();
            while(t.elapsed()<50)
                QCoreApplication::processEvents();
            ui->notbadl->hide();
            t.start();
            while(t.elapsed()<150)
                QCoreApplication::processEvents();
            notbadcount++;
        }

    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Q){
        ui->mid->hide();

    }
    if(event->key() == Qt::Key_P){
        ui->around->hide();
    }
}

void MainWindow::on_exit_clicked()
{
    this->close();

}
