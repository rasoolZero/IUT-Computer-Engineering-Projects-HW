#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Compiler.h"
#include <QDebug>
#include <QMessageBox>
#include <string>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    compiled=vector<Cell>(4096);
    temp=vector<Cell>(4096);
    ui->tableWidget->setRowCount(4096);
    for (int i = 0; i < 4096; i++){
        for (int j = 0; j < 4; j++) {
            QTableWidgetItem *item = new
            QTableWidgetItem(j==1? DEC2HEX(i).c_str() : j==3?"0000":"");
            ui->tableWidget->setItem(i, j, item);
        }
        compiled[i]=temp[i]={"",DEC2HEX(i),"","0000"};
    }
    timer.setInterval(1000);
    connect(&timer, &QTimer::timeout, this, &MainWindow::onTick);
    PC=HEX2DEC("100");
    AC=INPR=OUTR=E=IEN=FGO=FGI=R=0;
    ui->lineEdit->setText(DEC2HEX(PC).c_str());
    ui->lineEdit_2->setText(DEC2HEX(AC).c_str());
    ui->lineEdit_3->setText(DEC2HEX(INPR).c_str());
    ui->lineEdit_4->setText(DEC2HEX(OUTR).c_str());
    ui->lineEdit_5->setText(to_string(E).c_str());
    ui->ien->setText(to_string(IEN).c_str());
    ui->fgo->setText(to_string(FGO).c_str());
    ui->fgi->setText(to_string(FGI).c_str());
    ui->r->setText(to_string(R).c_str());


    scrollTimer.setInterval(100);
    scrollTimer.setSingleShot(true);
    connect(&scrollTimer, &QTimer::timeout, this, &MainWindow::scrollTable);
    scrollTimer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    AC=0;
    E=0;
    OUTR=0;
    INPR=0;
    IEN=false;
    R=false;
    PC=HEX2DEC("100");
    setLogColor(0);
    ui->plainTextEdit_2->setPlainText(INS2RTL(compiled[PC].Hex));
    ui->lineEdit->setText(DEC2HEX(PC).c_str());
    ui->lineEdit_2->setText(DEC2HEX(AC).c_str());
    ui->lineEdit_3->setText(DEC2HEX(INPR).c_str());
    ui->lineEdit_4->setText(DEC2HEX(OUTR).c_str());
    ui->lineEdit_5->setText(to_string(E).c_str());
    ui->ien->setText(to_string(IEN).c_str());
    ui->fgo->setText(to_string(FGO).c_str());
    ui->fgi->setText(to_string(FGI).c_str());
    ui->r->setText(to_string(R).c_str());
    for(int i=0;i<4096;i++){
        ui->tableWidget->item(i,0)->setText(compiled[i].label.c_str());
        ui->tableWidget->item(i,2)->setText(compiled[i].instruction.c_str());
        ui->tableWidget->item(i,3)->setText(compiled[i].Hex.c_str());
    }
    ui->pushButton_2->setDisabled(true);
    timer.start();
}


void MainWindow::on_pushButton_3_clicked()
{
    timer.stop();
    ui->pushButton_2->setDisabled(false);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(timer.isActive()){
        return;
    }
    for(int i=0;i<4096;i++){
        temp[i]={"",DEC2HEX(i),"","0000"};
    }
    string code=ui->plainTextEdit->toPlainText().toStdString();
    try{
        compiler(code);
        compiled=temp;
        for(int i=0;i<4096;i++){
            ui->tableWidget->item(i,0)->setText(compiled[i].label.c_str());
            ui->tableWidget->item(i,2)->setText(compiled[i].instruction.c_str());
            ui->tableWidget->item(i,3)->setText(compiled[i].Hex.c_str());
        }
        setLogColor(2);
        ui->plainTextEdit_2->setPlainText("Compiled Successfully");
    }
    catch(exception &error){
        setLogColor(1);
        ui->plainTextEdit_2->setPlainText(error.what());
    }
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    timer.setInterval(value*-100);
}

void MainWindow::onTick(){
    ui->lineEdit->setText(DEC2HEX(PC).c_str());
    ui->lineEdit_2->setText(DEC2HEX(AC).c_str());
    ui->lineEdit_3->setText(DEC2HEX(INPR).c_str());
    ui->lineEdit_4->setText(DEC2HEX(OUTR).c_str());
    ui->lineEdit_5->setText(to_string(E).c_str());
    ui->ien->setText(to_string(IEN).c_str());
    ui->fgo->setText(to_string(FGO).c_str());
    ui->fgi->setText(to_string(FGI).c_str());
    ui->r->setText(to_string(R).c_str());
    if(R){
        ui->tableWidget->item(0,3)->setText(DEC2HEX(PC).c_str());
        PC=0;
        IEN=R=false;
        setLogColor(0);
        ui->plainTextEdit_2->setPlainText("M[0] <- PC, PC <- 1, IEN<-0, R<-0");
    }
    else{
        setLogColor(0);
        ui->plainTextEdit_2->setPlainText(INS2RTL(ui->tableWidget->item(PC,3)->text().toStdString()));
        step(ui->tableWidget->item(PC,3)->text().toStdString());
    }

    PC++;
    PC=PC%4096;

}

QString MainWindow::INS2RTL(std::string ins){
    if(ins[0]=='0' || ins[0]=='8')
        return "AC <- AC & M[AR]";
    if(ins[0]=='1' || ins[0]=='9')
        return "AC <-AC + M[AR], E <- Cout";
    if(ins[0]=='2' || ins[0]=='a' || ins[0]=='A')
        return "AC <- M[AR]";
    if(ins[0]=='3' || ins[0]=='b' || ins[0]=='B')
        return "M[AR] <-AC";
    if(ins[0]=='4' || ins[0]=='c' || ins[0]=='C')
        return "PC <-AR";
    if(ins[0]=='5' || ins[0]=='d' || ins[0]=='D')
        return "M[AR] <- PC, PC <-AR + 1";
    if(ins[0]=='6' || ins[0]=='e' || ins[0]=='E')
        return "M[AR] <- M[AR] + 1 ,If M[AR] + 1 = 0 then PC <- PC + 1";
    if(ins=="7800")
        return "AC <- 0";
    if(ins=="7400")
        return "E <- 0";
    if(ins=="7200")
        return "AC <- ~AC";
    if(ins=="7100")
        return "E <- ~E";
    if(ins=="7080")
        return "AC <- shr AC, AC(15) <- E , E <- AC(0)";
    if(ins=="7040")
        return "AC <- shr AC, AC(0) <- E , E <- AC(15)";
    if(ins=="7020")
        return "AC <- AC + 1";
    if(ins=="7010")
        return "If (AC(15) = 0) then (PC <- PC + 1 )";
    if(ins=="7008")
        return "If (AC(15) = 1) then (PC <- PC + 1 )";
    if(ins=="7004")
        return "If (AC = 0) then (PC <- PC + 1 )";
    if(ins=="7002")
        return "If (E = 0) then (PC <- PC + 1 )";
    if(ins=="7001")
        return "S <- 0";
    if(ins=="f800" || ins=="F800")
        return "AC(0-7) <- INPR, FGI <- 0";
    if(ins=="f400" || ins=="F400")
        return "OUTR <- AC(0-7), FGO <- 0";
    if(ins=="f200" || ins=="F200")
        return "If (FGI = 1) then (PC <- PC + 1)";
    if(ins=="f100" || ins=="F100")
        return "If (FGO = 1) then (PC <- PC + 1)";
    if(ins=="f080" || ins=="F080")
        return "IEN <- 1";
    if(ins=="f040" || ins=="F040")
        return "IEN <- 0";
    return "";
}


void MainWindow::step(string ins){
    if(IEN && (FGO || FGI)){
        R=true;
    }
    if(ins[0]=='0' || ins[0]=='8'){
        string address=ins.substr(1,string::npos);
        if(ins[0]=='8')
            address=ui->tableWidget->item(HEX2DEC(address),3)->text().toStdString();
        string valueInHex=ui->tableWidget->item(HEX2DEC(address),3)->text().toStdString();
        AC = AC & HEX2DEC(valueInHex);
    }
    if(ins[0]=='1' || ins[0]=='9'){
        string address=ins.substr(1,string::npos);
        if(ins[0]=='9')
            address=ui->tableWidget->item(HEX2DEC(address),3)->text().toStdString();
        string valueInHex=ui->tableWidget->item(HEX2DEC(address),3)->text().toStdString();
        int sum=HEX2DEC(valueInHex)+AC;
        string sumInHex=DEC2HEX(sum);
        E=sumInHex.size()==5;
        sumInHex = sumInHex.size()==5? sumInHex.substr(1,string::npos) :sumInHex;
        AC=HEX2DEC(sumInHex);
    }
    if(ins[0]=='2' || ins[0]=='a' || ins[0]=='A'){
        string address=ins.substr(1,string::npos);
        if(ins[0]=='a' || ins[0]=='A')
            address=ui->tableWidget->item(HEX2DEC(address),3)->text().toStdString();
        string valueInHex=ui->tableWidget->item(HEX2DEC(address),3)->text().toStdString();
        AC=HEX2DEC(valueInHex);
    }
    if(ins[0]=='3' || ins[0]=='b' || ins[0]=='B'){
        string address=ins.substr(1,string::npos);
        if(ins[0]=='b' || ins[0]=='B')
            address=ui->tableWidget->item(HEX2DEC(address),3)->text().toStdString();
        ui->tableWidget->item(HEX2DEC(address),3)->setText(DEC2HEX(AC).c_str());
    }
    if(ins[0]=='4' || ins[0]=='c' || ins[0]=='C'){
        string address=ins.substr(1,string::npos);
        if(ins[0]=='c' || ins[0]=='C')
            address=ui->tableWidget->item(HEX2DEC(address),3)->text().toStdString();
        PC=HEX2DEC(address)-1;
    }
    if(ins[0]=='5' || ins[0]=='d' || ins[0]=='D'){
        string address=ins.substr(1,string::npos);
        if(ins[0]=='d' || ins[0]=='D')
            address=ui->tableWidget->item(HEX2DEC(address),3)->text().toStdString();
        ui->tableWidget->item(HEX2DEC(address),3)->setText(DEC2HEX(PC+1).c_str());
        PC=HEX2DEC(address);
    }
    if(ins[0]=='6' || ins[0]=='e' || ins[0]=='E'){
        string address=ins.substr(1,string::npos);
        if(ins[0]=='d' || ins[0]=='D')
            address=ui->tableWidget->item(HEX2DEC(address),3)->text().toStdString();
        string valueInHex=ui->tableWidget->item(HEX2DEC(address),3)->text().toStdString();
        valueInHex=DEC2HEX(HEX2DEC(valueInHex)+1);
        valueInHex = valueInHex.size()==5? valueInHex.substr(1,string::npos) :valueInHex;
        ui->tableWidget->item(HEX2DEC(address),3)->setText(valueInHex.c_str());
        if(HEX2DEC(valueInHex)==0)
            PC++;
    }
    if(ins=="7800"){
        AC=0;
    }
    if(ins=="7400"){
        E=0;
    }
    if(ins=="7200"){
        string AChex=DEC2HEX(~AC);
        while(AChex.size()<4)
            AChex="0"+AChex;
        AChex=AChex.substr(AChex.size()-4,string::npos);
        AC=HEX2DEC(AChex);
    }
    if(ins=="7100"){
        E=!E;
    }
    if(ins=="7080"){
        int newE=AC&1U;
        AC = AC >> 1;
        AC ^= (-E ^ AC) & (1UL << 15);
        string AChex=DEC2HEX(AC);
        while(AChex.size()<4)
            AChex="0"+AChex;
        AChex=AChex.substr(AChex.size()-4,string::npos);
        AC=HEX2DEC(AChex);
        E=newE;
    }
    if(ins=="7040"){
        int newE=(AC >> 15) & 1U;;
        AC = AC << 1;
        AC ^= (-E ^ AC) & 1UL;
        string AChex=DEC2HEX(AC);
        while(AChex.size()<4)
            AChex="0"+AChex;
        AChex=AChex.substr(AChex.size()-4,string::npos);
        AC=HEX2DEC(AChex);
        E=newE;
    }
    if(ins=="7020"){
        AC++;
        string AChex=DEC2HEX(AC);
        while(AChex.size()<4)
            AChex="0"+AChex;
        AChex=AChex.substr(AChex.size()-4,string::npos);
        AC=HEX2DEC(AChex);
    }
    if(ins=="7010"){
        if(((AC >> 15) & 1U)==0)
            PC++;
    }
    if(ins=="7008"){
        if(((AC >> 15) & 1U))
            PC++;
    }
    if(ins=="7004"){
        if(AC==0)
            PC++;
    }
    if(ins=="7002"){
        if(E==0)
            PC++;
    }
    if(ins=="7001"){
        timer.stop();
        ui->pushButton_2->setDisabled(false);
    }
    if(ins=="f800" || ins=="F800"){
        string acHex=DEC2HEX(AC);
        while(acHex.size()<4)
            acHex="0"+acHex;
        string l8bitAcHex=acHex.substr(0,2);
        string inputHex=DEC2HEX(INPR);
        if(inputHex.size()<2)
            inputHex="0"+inputHex;
        acHex=l8bitAcHex+inputHex.substr(inputHex.size()-2,string::npos);
        AC=HEX2DEC(acHex);
        FGI=false;
    }
    if(ins=="f400" || ins=="F400"){
        string acHex=DEC2HEX(AC);
        while(acHex.size()<3)
            acHex="0"+acHex;
        string r8bitAcHex=acHex.substr(acHex.size()-2);
        string ch;
        OUTR=HEX2DEC(r8bitAcHex);
        FGO=false;
    }
    if(ins=="f200" || ins=="F200"){
        if(FGI)
            PC++;
    }
    if(ins=="f100" || ins=="F100"){
        if(FGO)
            PC++;
    }
    if(ins=="f080" || ins=="F080"){
        IEN=true;
    }
    if(ins=="f040" || ins=="F040"){
        IEN=false;
    }
}

void MainWindow::on_actionHelp_2_triggered()
{
    Help * h = new Help(this);
    h->show();
}


void MainWindow::on_inputToggle_clicked()
{
    FGI=!FGI;
    ui->fgi->setText(to_string(FGI).c_str());
    if(ui->lineEdit_6->text().size()==0)
        INPR=0;
    else{
        INPR=ui->lineEdit_6->text().at(0).unicode()&0xff;
    }
    ui->lineEdit_3->setText(DEC2HEX(INPR).c_str());
}


void MainWindow::on_outputToggle_clicked()
{
    FGO=!FGO;
    ui->fgo->setText(to_string(FGO).c_str());

}
void MainWindow::setLogColor(int choice){
    if(choice==0){ // neutral
        ui->plainTextEdit_2->setStyleSheet("color: #000000");
    }
    if(choice==1){ // error
        ui->plainTextEdit_2->setStyleSheet("color: #FF0000");
    }
    if(choice==2){ // success
        ui->plainTextEdit_2->setStyleSheet("color: #00FF00");
    }
}

void MainWindow::scrollTable(){
    ui->tableWidget->scrollTo( ui->tableWidget->model()->index(HEX2DEC("109"),0) );
}

void MainWindow::on_pushButton_4_clicked()
{
    QString output="";
        for(int i = 0;i<ui->tableWidget->rowCount();i++){
                       output+=ui->tableWidget->item(i,3)->text();
                       output+=" ";
               }
        QMessageBox box(this);
        box.setWindowTitle("Export");

        box.setDetailedText(output);
        QAbstractButton *detailsButton = NULL;

            foreach (QAbstractButton *button, box.buttons()) {
                if (box.buttonRole(button) == QMessageBox::ActionRole) {
                    detailsButton = button;
                    break;
                }
            }

            if (detailsButton) {
                detailsButton->click();
            }
        box.setText("Export Result:");
        box.exec();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox box(this);
    box.setWindowTitle("Mano Basic Computer Simulator");
    box.setText("Designed and Developed By :\n\n    Rasool Kamkar - 9826653\n    Ali Ahangarpoor - 9817923");
    box.setStyleSheet("font-size:14");
    box.exec();
}

