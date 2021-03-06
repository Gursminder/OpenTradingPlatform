#include <QCoreApplication>
#include <QHostAddress>
#include <QLibrary>

#include "fundssocket.h"
#include "websockethandler.h"
#include "sqlhandler.h"
#include "translationmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TranslationManager* langManager = new TranslationManager();
    langManager->loadConfig("lang.ini");

    FundsSocket* socket = new FundsSocket();
    socket->loadConfig("config.ini");

    SqlHandler* sqlHandler = new SqlHandler();
    sqlHandler->loadConfig("config.ini");

    WebsocketHandler* wsHandler = new WebsocketHandler();
    wsHandler->setTranslationManager(langManager);
    wsHandler->setSqlHandler(sqlHandler);
    wsHandler->createRequest();
    wsHandler->startServer(8080, QtWebsocket::Tcp);

    return a.exec();
}
