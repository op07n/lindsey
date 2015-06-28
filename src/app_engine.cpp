#include "app_engine.hpp"

#include <QCoreApplication>
#include <QObject>
#include <QQmlContext>
#include <QQmlEngine>
#include <QUrl>
#include <QStringList>

ApplicationEngine::ApplicationEngine()
{
    load(QUrl("qrc:/lindsey_window.qml"));
    
    const QUrl homeUrl = ApplicationEngine::homeUrl();
    QMetaObject::invokeMethod(rootObjects().first(), "setHomeUrl", Q_ARG(QVariant, homeUrl));
    QMetaObject::invokeMethod(rootObjects().first(), "loadUrl", Q_ARG(QVariant, homeUrl));
}

QUrl ApplicationEngine::homeUrl()
{
    QUrl ret;
    QStringList args(qApp->arguments());
    args.takeFirst();
    Q_FOREACH (const QString& arg, args) {
        if (arg.startsWith(QLatin1Char('-')))
             continue;
        ret = QUrl::fromUserInput(arg);
        if (ret.isValid())
            return ret;
    }
    
    return QUrl(QStringLiteral("http://www.kipr.org"));
}