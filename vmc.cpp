#include "vmc.h"
#include "ui_vmc.h"


VMC::VMC(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VMC)
{
    ui->setupUi(this);
}

VMC::~VMC()
{
    delete ui;
}

void VMC::on_Start_clicked()
{
    ui->Output->clear();
    int NSTEP = ui->NSTEP->text().toInt();
    double sigma = ui->sigma->text().toDouble();
    ui->Output->append( QString("Setting up a run of %1, with sigma=%2").arg(NSTEP).arg(sigma) );
    
    Metropolis sample;
    sample.setup(NSTEP,sigma); // defaults: NSTEP=100, sigma=0.5, trajfile="traj.dat"
    ui->Output->append( QString("Running VMC ...") );
    sample.evaluate();
    ui->Output->append( QString("All done.") );
}
