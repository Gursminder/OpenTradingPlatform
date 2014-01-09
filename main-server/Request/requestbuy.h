#ifndef REQUESTBUY_H
#define REQUESTBUY_H

#include "request.h"

class RequestBuy :  public Request
{
public:
    RequestBuy();
    ~RequestBuy();

    bool handle(Client* cl, QJsonObject arg);
    QString getName();
};

#endif // REQUESTBUY_H
