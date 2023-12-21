#include "GeoTileFetcherMyMap.h"

#include "GeoTiledMapReplyMyMap.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtLocation/private/qgeotilespec_p.h>
#include <QtLocation/private/qgeotilefetcher_p_p.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

GeoTileFetcherMyMap::GeoTileFetcherMyMap(
        const QVariantMap &parameters,
        QGeoMappingManagerEngine *parent)
    : QGeoTileFetcher(parent)
    , _networkManager(new QNetworkAccessManager(this))
{
    //链接地址
//    if(parameters.contains("baseUrl")){
//        _baseUrl=parameters.value("baseUrl").toString();
//    }
//    瓦片图片格式
//    if(parameters.contains("format")){
//        _format=parameters.value("format").toString();
//    }
    _format="jpeg";
}

QGeoTiledMapReply *GeoTileFetcherMyMap::getTileImage(const QGeoTileSpec &spec)
{
    QNetworkRequest request;
    request.setRawHeader("Accept", "*/*");//设置网络请求头
    //request.setHeader(QNetworkRequest::UserAgentHeader, _userAgent);
    request.setUrl(getUrl(spec));

//    qDebug()<<"GeoTileFetcherMyMap::getTileImage x-"<<spec.x()<<",y-"<<spec.y()<<",zoom-"<<spec.zoom();
//    qDebug()<<"GeoTileFetcherMyMap::getTileImage bing url:"<<request.url();

    QNetworkReply *reply = _networkManager->get(request);
//    QNetworkReply *reply;
    return new GeoTiledMapReplyMyMap(reply, spec, _format);
}

QString GeoTileFetcherMyMap::getUrl(const QGeoTileSpec &spec) const
{
    //其实小写也可以，一般系统默认是不区分大小写的
    //用的arcgis 瓦片命名格式
//    const QString zz=QString("%1").arg(spec.zoom(),2,10,QLatin1Char('0')).toUpper();
//    const QString yy=QString("%1").arg(spec.y(),8,16,QLatin1Char('0')).toUpper();
//    const QString xx=QString("%1").arg(spec.x(),8,16,QLatin1Char('0')).toUpper();

//    return QString("%1/L%2/R%3/C%4.%5")
//            .arg(_baseUrl)
//            .arg(zz)
//            .arg(yy)
//            .arg(xx)
//            .arg(_format);
    int x = spec.x();
    int y = spec.y();
    int zoom = spec.zoom();
    //TODO.调试使用
//    x = 27369;
//    y = 13381;
//    zoom = 15;

    int tileX  = x;
    int tileY  = y;


    QString quadKey;
    for (int i = zoom; i > 0; i--) {
        char digit = '0';
        const int  mask  = 1 << (i - 1);
        if ((tileX & mask) != 0) {
            digit++;
        }
        if ((tileY & mask) != 0) {
            digit++;
            digit++;
        }
        quadKey.append(digit);
    }

    int serverNum = (x + 2 * y) % 4;
    static const QString SatteliteMapUrl = QStringLiteral("http://ecn.t%1.tiles.virtualearth.net/tiles/a%2.jpeg?g=%3&mkt=%4");

    QString fullUrl = "http://ecn.t"+QString::number(serverNum)+".tiles.virtualearth.net/tiles/a"+quadKey+".jpeg?g="+"563"+"&mkt=en-US";
//    QString fullUrl = SatteliteMapUrl.arg(QString(serverNum) ,QString(quadKey) ,QString(563) , "en-US");
    return fullUrl;
//    return SatteliteMapUrl.arg(serverNum ,quadKey ,_versionBingMaps ,_language);
}

QT_END_NAMESPACE
