/****************************************************************************
**
** Copyright (C) 2013 Jolla Ltd.
** Contact: lorn.potter@jollamobile.com
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
****************************************************************************/

#ifndef QOFONOSupplimentaryServices_H
#define QOFONOSupplimentaryServices_H

#include <QObject>
#include <QDBusVariant>
#include "qofono_global.h"
//! This class is used to access ofono supplementary services API
/*!
 * The API is documented in
 * http://git.kernel.org/?p=network/ofono/ofono.git;a=blob_plain;f=doc/supplementaryservices-api.txt
 */

class QOfonoSupplementaryServicesPrivate;
class QOFONOSHARED_EXPORT QOfonoSupplementaryServices : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString modemPath READ modemPath WRITE setModemPath)
   Q_PROPERTY(QString state READ state)

public:
    explicit QOfonoSupplementaryServices(QObject *parent = 0);
    ~QOfonoSupplementaryServices();

    QString modemPath() const;
    void setModemPath(const QString &path);

    QString state() const;

Q_SIGNALS:
    void notificationReceived(const QString &message);
    void requestReceived(const QString &message);

    void stateChanged(const QString &state);

public slots:
    
private:
    QOfonoSupplementaryServicesPrivate *d_ptr;
private slots:
    void propertyChanged(const QString &property,const QDBusVariant &value);
};

#endif // QOFONOSupplimentaryServices_H
