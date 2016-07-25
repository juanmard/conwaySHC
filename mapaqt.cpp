#include "mapaqt.hpp"
#include "conversor.hpp"
#include <QMessageBox>

namespace SHC
{
    MapaQt::MapaQt(QWidget *parent) :
      QWidget(parent),
      timer(new QTimer(this)),
      generations(-1),
      universeSize(81*6),
      mapa(*new SHC::Mapa(81*6,81*6)),
      xZoom(100),
      yZoom(100),
      anchoZoom (300),
      altoZoom (300)
    {
        timer->setInterval(300);
        m_masterColor = "#000";
        connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));

        SHC::Conversor conversor;
        conversor.setMapa(mapa);
        conversor.convertir();
    }

    void MapaQt::paintEvent (QPaintEvent *)
    {
        QPainter p(this);
        paintMap(p);
    }

    void MapaQt::paintMap (QPainter &p)
    {
        //unsigned int anchomap, altomap;
        //anchomap = mapa.numcol()-posx;//*50/100;
        //altomap = mapa.numfil()-posy;//*50/100;
        double cellWidth = (double)width()/anchoZoom;
        double cellHeight = (double)height()/altoZoom;
        for(unsigned int k=1; k <= anchoZoom; k++)
        {
            for(unsigned int j=1; j <= altoZoom; j++)
            {
                if(mapa[j-1+yZoom][k-1+xZoom] == SHC::Celda::full)
                {
                    qreal left = (qreal)(cellWidth*j-cellWidth); // margin from left
                    qreal top  = (qreal)(cellHeight*k-cellHeight); // margin from top
                    QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                    p.fillRect(r, QBrush(m_masterColor)); // fill cell with brush of main color
                }
            }
        }
    }

    void MapaQt::startGame(const int &number)
    {
        generations = number;
        timer->start();
    }

    void MapaQt::stopGame()
    {
        timer->stop();
    }

    void MapaQt::clear() {}

    int MapaQt::cellNumber() {return 0;}

    void MapaQt::setCellNumber(const int &s){}

    void MapaQt::resetUniverse(){}

    QString MapaQt::dump(){return *new QString();}

    void MapaQt::setDump(const QString &data){}

    int MapaQt::interval()
    {
        return timer->interval();
    }

    void MapaQt::setInterval(int msec)
    {
        timer->setInterval(msec);
    }

    bool MapaQt::isAlive (int k, int j)
    {
        int power = 0;
        power += mapa[j+1][k].valorada();
        power += mapa[j-1][k].valorada();
        power += mapa[j][k+1].valorada();
        power += mapa[j][k-1].valorada();
        power += mapa[j+1][k-1].valorada();
        power += mapa[j-1][k+1].valorada();
        power += mapa[j-1][k-1].valorada();
        power += mapa[j+1][k+1].valorada();

        if (((mapa[j][k].valorada()==1) && (power == 2)) || (power == 3))
        {
               return true;
        }
        return false;
    }

    void MapaQt::newGeneration()
    {
        if(generations < 0)
        {
            generations++;
        }

        int altoMapa = mapa.numfil()-1;
        int anchoMapa = mapa.numcol()-1;
        for(int k=1; k < altoMapa; k++)
        {
            for(int j=1; j < anchoMapa; j++)
            {
                if (isAlive(k,j))
                {
                    mapa[j][k] = SHC::Celda::next_full;
                }
                else
                {
                    mapa[j][k] = SHC::Celda::next_empty;
                }
            }
        }

        // Se actualiza el estado del universo.
        for(int k=0; k < altoMapa; k++)
        {
            for(int j=0; j < anchoMapa; j++)
            {
                mapa[j][k].update();
            }
        }

        // Se actualiza el widget.
        update();

        // Se calculan las generaciones.
        generations--;
        if(generations == 0)
        {
            stopGame();
            gameEnds(true);
            QMessageBox::information(this,
                                     tr("Game finished."),
                                     tr("Iterations finished."),
                                     QMessageBox::Ok,
                                     QMessageBox::Cancel);
        }

    }

    void MapaQt::mousePressEvent(QMouseEvent *e){}

    void MapaQt::mouseMoveEvent(QMouseEvent *e){}

    void MapaQt::paintGrid(QPainter &p){}

    void MapaQt::paintUniverse(QPainter &p){}

    QColor MapaQt::masterColor(){return QColor();}

    void MapaQt::setMasterColor(const QColor &color){}
}
