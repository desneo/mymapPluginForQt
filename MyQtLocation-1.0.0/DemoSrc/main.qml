import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtLocation 5.12
import QtPositioning 5.12

ApplicationWindow {
    id: root_window
    visible: true
    width: 1000
    height: 800
//    title: qsTr("【QQ交流群:647637553】"+root_loader.source)

//    Loader{
//        id: root_loader
//        anchors.fill: parent
//        source: "qrc:/GroupBPage.qml"
//        opacity: 0.99
//    }

//    menuBar: MenuBar {
//        Menu {
//            title: qsTr("GroupA")
//            Action { text: "MyMap"; onTriggered: root_loader.setSource("qrc:/AMyMap.qml"); }
//            MenuSeparator { }
//            Action { text: "MapRuler"; onTriggered: root_loader.setSource("qrc:/AMapRuler.qml"); }
//            Action { text: "MapArea"; onTriggered: root_loader.setSource("qrc:/AMapArea.qml"); }
//            Action { text: "MapBoundary1"; onTriggered: root_loader.setSource("qrc:/AMapBoundary1.qml"); }
//            Action { text: "MapBoundary2"; onTriggered: root_loader.setSource("qrc:/AMapBoundary2.qml"); }
//        }
//        Menu {
//            title: qsTr("GroupB")
//            Action { text: "GroupBPage"; onTriggered: root_loader.setSource("qrc:/GroupBPage.qml"); }
//        }
//    }
    Map {
        id: the_map
        anchors.fill: parent
        minimumZoomLevel: 16
        maximumZoomLevel: 19
        zoomLevel: 17
        center: QtPositioning.coordinate(31.97920328, 118.76228381)

        plugin: Plugin {
            name: "mymap" //"esri" "mapbox" "osm" "here"
        }

        Text {
            id: "txasda"
            text: "ditucengji:"+the_map.zoomLevel
        }
    }

}
