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
    ui->Output->append( QString("Setting up") );
    sample.setup(100000); // defaults: NSTEP=100, sigma=0.5, trajfile="traj.dat"
    ui->Output->append( QString("Running VMC ...") );
    sample.evaluate();
    ui->Output->append( QString("All done.") );
}
