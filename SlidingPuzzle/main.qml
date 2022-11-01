import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 600
    height: 600
    visible: true
    title: qsTr("Sliding Puzzle")

    property string difficulty: "default"

    MenuBar {
            Menu {
                title: qsTr("Game")
                MenuItem {
                    text: qsTr("Reset Game")
                    onTriggered: controller.resetGame()
                }
                MenuItem {
                    text: qsTr("New Game")
                    onTriggered: controller.createBoard(difficulty)
                }
                MenuItem {
                    text: qsTr("Exit")
                    onTriggered: Qt.quit()
                }
            }
            Menu {
                title: qsTr("Difficulty")
                MenuItem{
                    text: qsTr("Easy")
                    onTriggered: difficulty = "easy"
                }
                MenuItem{
                    text: qsTr("Medium")
                    onTriggered: difficulty = "medium"
                }
                MenuItem{
                    text: qsTr("Hard")
                    onTriggered: difficulty = "hard"
                }
                MenuItem{
                    text: qsTr("Random")
                    onTriggered: difficulty = "random"
                }
            }
        }

    // Board rectangle.
    Rectangle {
        id : board
        width: parent.width - 100
        height: parent.height - 100
        color: "lightgray"
        border.color: "black"
        x: 50
        y: 50

        // Size of each piece.
        property int pieceWidth: width / controller.nCols
        property int pieceHeight: height / controller.nRows

        // Loop for each piece...
        Repeater {
            model: controller.nPieces

            // Create Piece...
            Rectangle {
                // Set current piece position
                x: (index % controller.nCols) * width
                y: Math.floor((index / controller.nRows)) * height

                // Piece dimensions.
                width: board.pieceWidth
                height: board.pieceHeight

                // Property defining if this piece is the last one (VOID_PIECE).
                property bool voidPiece: controller.board[index] === controller.voidPiece

                border.color: "black"
                color: voidPiece ? "lightgray" : "lightblue"

                // Piece content.
                Text {
                    text: voidPiece ? "" : controller.board[index]
                    anchors.centerIn: parent
                    font.pixelSize: 30
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked:
                    {
                        var win = controller.pieceClicked(index)
                        if(win)
                        {
                            console.log("Congratulations! You just won the game!")
                            Qt.quit()
                        }
                    }
                }
            }

        }
    }

}
