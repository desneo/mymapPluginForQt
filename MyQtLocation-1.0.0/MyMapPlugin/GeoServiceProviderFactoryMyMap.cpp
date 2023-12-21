#include "GeoServiceProviderFactoryMyMap.h"

#include "GeoTiledMappingManagerEngineMyMap.h"
#include <QtLocation/private/qgeotiledmappingmanagerengine_p.h>

#ifdef MyMapPlugin_Static
Q_EXTERN_C Q_DECL_EXPORT const char *qt_plugin_query_metadata();
Q_EXTERN_C Q_DECL_EXPORT QT_PREPEND_NAMESPACE(QObject) *qt_plugin_instance();

const QT_PREPEND_NAMESPACE(QStaticPlugin) qt_static_plugin_GeoServiceProviderFactoryMyMap()
{
    QT_PREPEND_NAMESPACE(QStaticPlugin) plugin = { qt_plugin_instance, qt_plugin_query_metadata};
    return plugin;
}
#endif

QT_BEGIN_NAMESPACE
QGeoMappingManagerEngine *GeoServiceProviderFactoryMyMap::createMappingManagerEngine(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    return new GeoTiledMappingManagerEngineMyMap(parameters, error, errorString);
}

QT_END_NAMESPACE
