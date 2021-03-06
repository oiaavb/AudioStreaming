#ifndef ABSTRACTCLIENT_H
#define ABSTRACTCLIENT_H

#include <QtCore>
#include <QtNetwork>
#include "common.h"
#include "audiostreaminglibcore.h"

class AbstractClient : public QObject
{
    Q_OBJECT
public:
    explicit AbstractClient(QObject *parent = nullptr);

signals:
    void connected(PeerData,QString);
    void connectedToServer(QByteArray);
    void connectedToPeer(PeerData,QString);
    void disconnected(PeerData);
    void readyRead(PeerData);
    void pending(QHostAddress,QString);
    void error(QString);

public slots:
    virtual void abort() = 0;
    virtual void connectToHost(const QString &host, quint16 port,
                               const QByteArray &negotiation_string,
                               const QString &id,
                               const QByteArray &password) = 0;
    virtual void connectToPeer(const QString &peer_id) = 0;
    virtual void stop() = 0;
    virtual int write(const QByteArray &data) = 0;
    virtual void acceptSslCertificate() = 0;
    virtual void acceptConnection() = 0;
    virtual void rejectConnection() = 0;
};

#endif // ABSTRACTCLIENT_H
