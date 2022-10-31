import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 600
    height: 600
    visible: true
    title: qsTr("Sliding Puzzle")

    menuBar: MenuBar {
        Menu {
            title: qsTr("Game")
            MenuItem {
                text: qsTr("New Game")
                onTriggered: console.log("Creating new game...")
            }
            MenuItem {
                text: qsTr("Reset Game")
                onTriggered: console.log("Reseting game...")
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
        Menu {
            title: qsTr("Difficulty")

            MenuItem {
                text: qsTr("Hard")
                onTriggered: console.log("Selected hard difficulty.")
            }
            MenuItem {
                text: qsTr("Medium")
                onTriggered: console.log("Selected medium difficulty.")
            }
            MenuItem {
                text: qsTr("Easy")
                onTriggered: {
                    console.log("Selected easy difficulty.")
                }
            }
        }
    }

    //Content Area
    Rectangle {
        id : board
        width: parent.width - 20
        height: parent.height - 20
        color: "lightgray"
        border.color: "black"
        x: 10
        y: 10

        // Insert tiles
        Repeater{
            model: controller.nPieces

            Rectangle {
                id: piece
                x: initialX
                y: initialY
                width: board.width / controller.nColumns
                height: board.height / controller.nRows
                border.color: "black"

                property int initialX: (index % controller.nColumns) * width
                property int initialY: Math.floor((index / controller.nRows)) * height

                Text {
                    id: textPiece
                    text: qsTr(controller.board[index].toString())
                    font.bold: true
                    font.pixelSize: piece.width < piece.height? piece.width / 5 : piece.height / 5
                    anchors.horizontalCenter: piece.horizontalCenter
                    anchors.verticalCenter: piece.verticalCenter
                }

                // New position of point to move...
                property point newPos

                // Calls animation...
                function move(x, y) {
                    newPos = Qt.point(x, y)
                    anim.start()
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        var emptyIndex = controller.move(index)
                        console.log(emptyIndex.toString())
                        if(emptyIndex >= 0 && emptyIndex <= controller.nPieces)
                        {
                            var ei_x = (emptyIndex % controller.nColumns) * piece.width
                            var ei_y = Math.floor((emptyIndex / controller.nRows)) * piece.height
                            move(ei_x, ei_y)
                        }
                    }
                }

                SequentialAnimation {
                    id: anim
                    SmoothedAnimation { target: piece; property: "x"; to: newPos.x; duration: 2000 }
                    SmoothedAnimation { target: piece; property: "y"; to: newPos.y; duration: 2000 }
                }
            }
        }
    }


}
