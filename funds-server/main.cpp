#include <QCoreApplication>

#include "fundserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FundServer server;
    return a.exec();
}