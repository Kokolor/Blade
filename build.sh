g++ -Wall -I /usr/include/qt6 -I/usr/include/qt6/QtWidgets -I/usr/include/qt6/QtCore -I/usr/include/qt6/QtGui src/launcher/main.cpp -o launcher -lQt6Widgets -lQt6Gui -lQt6Core -fPIC
g++ -Wall -I /usr/include/qt6 -I/usr/include/qt6/QtWidgets -I/usr/include/qt6/QtCore -I/usr/include/qt6/QtGui src/launcher/main.cpp -o launcher.exe -lQt6Widgets -lQt6Gui -lQt6Core -fPIC
# rm launcher
# rm launcher.exe
