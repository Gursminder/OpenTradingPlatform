#ifndef BANKPLUGIN_H
#define BANKPLUGIN_H

#include <QObject>

#include "../CryptoCurrencyInterface.h"

class BitcoinPlugin : public QObject, public CryptoCurrencyInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.openTradingPlatform.plugin.CryptoCurrencyInterface" FILE "BitcoinPlugin.json")
    Q_INTERFACES(CryptoCurrencyInterface)
public:
    BitcoinPlugin(QObject *parent = 0);
    ~BitcoinPlugin();
public:
    virtual bool working();
    virtual QString getName() const;
    virtual QString getSymbol() const;/*symbol display*/
    virtual QString getCurrencyCode() const;/*unit letter code, 3 letter code*/
    virtual double getBitcoinFunds(const QString &address) const;
    /// \return empty is failed
    virtual QString sendBitcoinFunds(const QString &sourceAddress,const QString &destinationAddress,const double &value);
};

#endif // BANKPLUGIN_H
